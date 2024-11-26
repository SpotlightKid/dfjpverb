/*
 * DF JPverb audio effect based on DISTRHO Plugin Framework (DPF)
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (C) 2022-2024 Christopher Arndt <info@chrisarndt.de>
 */

#ifndef PLUGIN_DFJPVERB_H
#define PLUGIN_DFJPVERB_H

#include "DistrhoPlugin.hpp"
#include "DFJPverb.hpp"

START_NAMESPACE_DISTRHO

#ifndef MIN
#define MIN(a,b) ( (a) < (b) ? (a) : (b) )
#endif

#ifndef MAX
#define MAX(a,b) ( (a) > (b) ? (a) : (b) )
#endif

#ifndef CLAMP
#define CLAMP(v, min, max) (MIN((max), MAX((min), (v))))
#endif

// -----------------------------------------------------------------------

class PluginDFJPverb : public Plugin {
public:
    PluginDFJPverb();

    ~PluginDFJPverb();

protected:
    // -------------------------------------------------------------------
    // Information

    const char* getLabel() const noexcept override {
        return "DFJPverb";
    }

    const char* getDescription() const override {
        return "A lush algorithmic reverb designed to sound great with synthetic sound sources";
    }

    const char* getMaker() const noexcept override {
        return "chrisarndt.de";
    }

    const char* getHomePage() const override {
        return DISTRHO_PLUGIN_URI;
    }

    const char* getLicense() const noexcept override {
        return "https://spdx.org/licenses/GPL-2.0-or-later";
    }

    uint32_t getVersion() const noexcept override {
        return d_version(0, 2, 2);
    }

    // Go to:
    //
    // http://service.steinberg.de/databases/plugin.nsf/plugIn
    //
    // Get a proper plugin UID and fill it in here!
    int64_t getUniqueId() const noexcept override {
        return d_cconst('d', 'f', 'j', 'v');
    }

    // -------------------------------------------------------------------
    // Init

    void initParameter(uint32_t index, Parameter& parameter) override;
    void initProgramName(uint32_t index, String& programName) override;
    void initPortGroup(uint32_t groupId, PortGroup& portGroup) override;

    // -------------------------------------------------------------------
    // Internal data

    float getParameterValue(uint32_t index) const override;
    void setParameterValue(uint32_t index, float value) override;
    void loadProgram(uint32_t index) override;

    // -------------------------------------------------------------------
    // Optional

    // Optional callback to inform the plugin about a sample rate change.
    void sampleRateChanged(double newSampleRate) override;

    // -------------------------------------------------------------------
    // Process

    void activate() override;
    void run(const float**, float** outputs, uint32_t frames) override;

    // -------------------------------------------------------------------

private:
    double          fSampleRate;
    DFJPverb*     dsp;

    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginDFJPverb)
};

struct Preset {
    const char* name;
    float params[DFJPverb::NumParameters];
};

const Preset factoryPresets[] = {
    //{
    //    "Preset name", // preset name
    //    {1.0, ...}     // array of DFJPverb::NumParameters float param values
    //},
    {"Defaults", {
        1.0,     // p_t60
        1.0,     // p_size
        0.0,     // p_damp
        0.707,   // p_early_diff
        500.0,   // p_low_cutoff
        2000.0,  // p_high_cutoff
        1.0,     // p_low
        1.0,     // p_mid
        1.0,     // p_high
        0.1,     // p_mod_depth
        2.0,     // p_mod_freq
        0.0,     // p_dry
        -12.0    // p_wet
    }},
    {"Lush Pad (Insert)", {
        7.9, 3.0, 0.4, 0.12, 394.0, 2166.0, 1.0, 0.9, 0.7, 0.1, 2.0, 0.0, -12.0
    }},
    {"Lush Pad (Send)", {
        7.9, 3.0, 0.4, 0.12, 394.0, 2166.0, 1.0, 0.9, 0.7, 0.1, 2.0, -90.0, 0.0
    }},
    {"Dreamverb", {
        60.0, 2.79381, 0.31443, 0.42188, 2450.08225, 1024.02198, 0.84375,
        0.70619, 0.0, 0.46392, 0.10309, 0.0, -3.6
    }},
    {"Factory Preset 1", {
        16.0, 0.94922, 0.67188, 0.42188, 2450.08225, 4450.79406, 0.84375,
        0.55469, 0.0, 0.17969, 2.0, 0.0, -3.6
    }},
    {"Factory Preset 2", {
        60.0, 0.94922, 0.67188, 0.42188, 2450.08225, 4450.79406, 0.84375,
        0.55469, 0.0, 0.17969, 2.0, 0.0, -3.6
    }},
    {"Factory Preset 3", {
        4.03756, 0.61719, 0.28906, 0.76563, 681.56676, 7233.94163, 0.60938,
        0.51563, 0.22656, 0.0, 2.0, 0.0, -8.4
    }},
    {"Factory Preset 4", {
        1.64833, 0.5, 0.875, 0.70316, 100.0, 5829.41535, 0.84375, 0.55469,
        0.0, 0.17969, 2.0, 0.0, -3.6
    }},
};

const uint presetCount = sizeof(factoryPresets) / sizeof(Preset);

// -----------------------------------------------------------------------

END_NAMESPACE_DISTRHO

#endif  // #ifndef PLUGIN_DFJPVERB_H
