#!/bin/bash
#
# Build source distribution archive with all git sub-modules included
#

PROJECT_VERSION="$(git describe --abbrev=0 2>/dev/null)"

if [[ -z "$PROJECT_VERSION" ]]; then
    echo "ERROR: No git tags found. Can't create source distribution archve."
    echo "Hint: Use 'git tag -a <version>' to create a project version."
    exit 1
fi

set -e

CHECKOUT="$(pwd)"
REPO_URL="$(git remote get-url origin)"
PROJECT_NAME="${REPO_URL##*/}"
PROJECT_NAME="${PROJECT_NAME%.git}"
SRCDIR="$PROJECT_NAME-${PROJECT_VERSION#v}"
TARBALL_NAME="$SRCDIR-source.tar.gz"
BUILDDIR="build/${PROJECT_VERSION#v}"

mkdir -p "$BUILDDIR" dist
cd "$BUILDDIR"
rm -rf "$SRCDIR"
git clone --recursive --branch "$PROJECT_VERSION" --single-branch "$CHECKOUT" "$SRCDIR"
cd "$SRCDIR"
for fn in .git .gitmodules .gitignore; do
    find . -name $fn -type f -print0 | xargs -0 rm -f
done
rm -rf .git
cd ..
tar -zcvf "$CHECKOUT/dist/$TARBALL_NAME" "$SRCDIR"

gpg --armor --detach-sign --yes "$CHECKOUT/dist/$TARBALL_NAME"
cd "$CHECKOUT"
rm -rf "$BUILDDIR"
ls -l dist
