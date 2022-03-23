# DF JPverb

A lush algorithmic reverb designed to sound great with synthetic sound sources

## Formats

All plugins in this collection come in the following plug-in formats:

* LADSPA
* LV2
* VST2

The plugins depend on the host to provide a generic UI to control parameters.


## Compiling

Make sure you have installed the required build tools and libraries (see
section "Prerequisites" below) and then clone this repository (including
sub-modules) and simply run `make` in the project's root directory:

    $ git clone --recursive https://github.com/SpotlightKid/dfjpverb.git
    $ cd dfjpverb
    $ make


## Installation

To install all plugin formats to their appropriate system-wide location, run
the following command (root priviledges may be required):

    make install

The makefiles support the usual `PREFIX` and `DESTDIR` variables to change the
installation prefix and set an installation root directory (defaulty: empty).
`PREFIX` defaults to `/usr/local`, but on macOS and Windows it is not used,
since the system-wide installation directories for plugins are fixed.

Use make's `-n` option to see where the plugins would be installed without
actually installing them.

You can also set the installation directory for each plugin format with a
dedicated makefile variable.

* LADSPA: `LADSPA_DIR` (`<prefix>/lib/ladspa`)
* LV2: `LV2_DIR` (`<prefix>/lib/lv2`)
* VST2: `VST_DIR` (`<prefix>/lib/vst`)

Example: `make DESTDIR=/tmp/build-root VST_DIR=/usr/lib/lxvst install`

To install the plugins only for your current user account, run
`make install-user`.

Again, you can also set the installation directory for each plugin format with
a dedicated makefile variable.

* LADSPA: `USER_LADSPA_DIR` (`$HOME/.ladspa`)
* LV2: `USER_LV2_DIR` (`$HOME/.lv2`)
* VST2: `USER_VST_DIR` (`$HOME/.vst`)

*Note: The given default values for all of the above listed environment
variables differ depending on the target OS.*


## Prerequisites

* The GCC C++ compiler, library and the usual associated software build tools
  (`make`, etc.).

  Debian / Ubuntu users should install the `build-essential` package
  to get these, Arch users the `base-devel` package group.

* `patch`

* [pkgconf]

* The [faustpp] pre-processor and [FAUST] (optional)

The [LV2], [LADSPA] and [VST2] (vestige) headers are included in the [DPF]
framework, which is integrated as a Git sub-module. These need not be
installed separately to build the software in the respective plug-in formats.

`faustpp` and FAUST are only needed to re-generate C++ source and headers files
if the FAUST DSP source files in the `faust` directory are changed.


## Author

This software was created by *Christopher Arndt*.


## Acknowledgements

The DSP code is generated from the FAUST sources via the [faustpp]
pre-processor.

The project is built using the DISTRHO Plugin Framework ([DPF]) and set up
with the [cookiecutter-dpf-faust] project template.


[cookiecutter-dpf-faust]: https://github.com/SpotlightKid/cookiecutter-dpf-faust
[DPF]: https://github.com/DISTRHO/DPF
[FAUST]: https://faust.grame.fr/
[faustpp]: https://github.com/jpcima/faustpp.git
[LADSPA]: http://www.ladspa.org/
[LV2]: http://lv2plug.in/
[pkgconf]: https://github.com/pkgconf/pkgconf
[VST2]: https://en.wikipedia.org/wiki/Virtual_Studio_Technology
