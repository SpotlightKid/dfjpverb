/*
 * DF JPverb audio effect based on DISTRHO Plugin Framework (DPF)
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (C) 2022-2024 Christopher Arndt <info@chrisarndt.de>
 */

#ifndef DISTRHO_PLUGIN_INFO_H
#define DISTRHO_PLUGIN_INFO_H

#define DISTRHO_PLUGIN_BRAND "chrisarndt.de"
#define DISTRHO_PLUGIN_NAME  "DFJPverb"
#define DISTRHO_PLUGIN_URI   "https://chrisarndt.de/plugins/dfjpverb"
#define DISTRHO_PLUGIN_CLAP_ID "de.chrisarndt.dfjpverb"

#define DISTRHO_PLUGIN_HAS_UI        0
#define DISTRHO_UI_USE_NANOVG        0

#define DISTRHO_PLUGIN_IS_RT_SAFE       1
#define DISTRHO_PLUGIN_NUM_INPUTS       2
#define DISTRHO_PLUGIN_NUM_OUTPUTS      2
#define DISTRHO_PLUGIN_WANT_TIMEPOS     0
#define DISTRHO_PLUGIN_WANT_PROGRAMS    1
#define DISTRHO_PLUGIN_WANT_MIDI_INPUT  0
#define DISTRHO_PLUGIN_WANT_MIDI_OUTPUT 0

// See http://lv2plug.in/ns/lv2core#ref-classes
#define DISTRHO_PLUGIN_LV2_CATEGORY "lv2:ReverbPlugin"
#define DISTRHO_PLUGIN_VST3_CATEGORIES "Fx|Reverb|Stereo"
#define DISTRHO_PLUGIN_CLAP_FEATURES "audio-effect", "reverb", "stereo"

#endif // DISTRHO_PLUGIN_INFO_H
