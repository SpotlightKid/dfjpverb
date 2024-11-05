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
        return d_version(0, 1, 0);
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
    //    {1.0f, ...}   // array of DFJPverb::NumParameters float param values
    //},
    {
        "Lush Pad (Insert)",
        {
            7.9f,       // p_t60
            3.0f,       // p_size
            0.4f,       // p_damp
            0.12f,      // p_early_diff
            394.0f,     // p_low_cutoff
            2166.0f,    // p_high_cutoff
            1.0f,       // p_low
            0.9f,       // p_mid
            0.7f,       // p_high
            0.1f,       // p_mod_depth
            2.0f,       // p_mod_freq
            0.0f,       // p_dry
            -12.0f      // p_wet
        }
    },
    {"Lush Pad (Send)", {7.9f, 3.0f, 0.4f, 0.12f, 394.0f, 2166.0f, 1.0f, 0.9f, 0.7f, 0.1f, 2.0f, -90.0f, 0.0f}}
};

const uint presetCount = sizeof(factoryPresets) / sizeof(Preset);

// -----------------------------------------------------------------------

END_NAMESPACE_DISTRHO

#endif  // #ifndef PLUGIN_DFJPVERB_H
