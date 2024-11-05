#!/bin/bash
#
# Build win32 binaries of VST2/3 and LV2 plugin
#

PROJECT_VERSION="$(git describe --abbrev=0 2>/dev/null)"

if [[ -z "$PROJECT_VERSION" ]]; then
    echo "WARNING: No git tags found. Can't create binary distribution archive"
    echo "Hint: Use 'git tag -a <version>' to create a project version."
    echo
fi

set -e

# Preparation
_FLAGS="-DPTW32_STATIC_LIB -Werror"
_ARCH=i686-w64-mingw32
_PREFIX="/usr/${_ARCH}"
export PATH=${_PREFIX}/bin:$PATH
export AR=${_ARCH}-ar
export CC=${_ARCH}-gcc
export CXX=${_ARCH}-g++
export PKG_CONFIG_PATH=${_PREFIX}/lib/pkgconfig
export WIN32=true
export CFLAGS="${_FLAGS}"
export CXXFLAGS="${_FLAGS}"
export LDFLAGS="-static"
export CROSS_COMPILING=true

# Start clean
make clean > /dev/null
make -C dpf clean > /dev/null
rm -rf bin-w32

# Build now
make HAVE_CAIRO=false HAVE_JACK=false BUILD_VST2=true
mv bin bin-w32

set +e

# Make Zip archive of binaries
if [[ -n "$PROJECT_VERSION" ]]; then
    CHECKOUT="$(pwd)"
    REPO_URL="$(git remote get-url origin)"
    PROJECT_NAME="${REPO_URL##*/}"
    SRCDIR="$PROJECT_NAME-${PROJECT_VERSION#v}"
    ZIP_NAME="$SRCDIR-win32.zip"
    mkdir -p dist
    rm -f dist/$ZIP_NAME && zip -r dist/$ZIP_NAME bin-w32
fi
