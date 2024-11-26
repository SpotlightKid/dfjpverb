//------------------------------------------------------------------------------
// This file was generated using the Faust compiler (https://faust.grame.fr),
// and the Faust post-processor (https://github.com/SpotlightKid/faustdoctor).
//
// Source: dfjpverb.dsp
// Name: DFJPverb
// Author: Julian Parker, Till Bovermann, Christopher Arndt
// Copyright: Julian Parker, bug fixes and minor interface changes by Till Bovermann, DPF version by Christopher Arndt
// License: GPL-2.0-or-later
// Version: 0.1.0
// FAUST version: 2.76.0
// FAUST compilation options: -a /home/chris/tmp/tmpx_5fx_1g.cpp -lang cpp -ct 1 -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
//------------------------------------------------------------------------------


#pragma once
#ifndef DFJPverb_Faust_pp_Gen_HPP_
#define DFJPverb_Faust_pp_Gen_HPP_

#include <memory>
#include <string>

class DFJPverb {
public:
    DFJPverb();
    ~DFJPverb();

    void init(float sample_rate);
    void clear() noexcept;

    void process(
        const float *in0, const float *in1, 
        float *out0, float *out1, 
        unsigned count) noexcept;

    enum { NumInputs = 2 };
    enum { NumOutputs = 2 };
    enum { NumActives = 13 };
    enum { NumPassives = 0 };
    enum { NumParameters = 13 };

    enum Parameter {
        p_t60,
        p_size,
        p_damp,
        p_early_diff,
        p_low_cutoff,
        p_high_cutoff,
        p_low,
        p_mid,
        p_high,
        p_mod_depth,
        p_mod_freq,
        p_dry,
        p_wet,
    };

    struct ParameterRange {
        float init;
        float min;
        float max;
    };

    struct ParameterScalePoint {
        std::string label;
        float value;
    };

    int parameter_group(unsigned index) noexcept;
    int parameter_order(unsigned index) noexcept;
    static const char *parameter_group_label(unsigned group_id) noexcept;
    static const char *parameter_group_symbol(unsigned group_id) noexcept;
    static const char *parameter_label(unsigned index) noexcept;
    static const char *parameter_short_label(unsigned index) noexcept;
    static const char *parameter_description(unsigned index) noexcept;
    static const char *parameter_style(unsigned index) noexcept;
    static const char *parameter_symbol(unsigned index) noexcept;
    static const char *parameter_unit(unsigned index) noexcept;
    static const ParameterRange *parameter_range(unsigned index) noexcept;
    unsigned parameter_scale_point_count(unsigned index) noexcept;
    static const ParameterScalePoint *parameter_scale_point(unsigned index, unsigned point) noexcept;
    static bool parameter_is_trigger(unsigned index) noexcept;
    static bool parameter_is_boolean(unsigned index) noexcept;
    static bool parameter_is_enum(unsigned index) noexcept;
    static bool parameter_is_integer(unsigned index) noexcept;
    static bool parameter_is_logarithmic(unsigned index) noexcept;

    float get_parameter(unsigned index) const noexcept;
    void set_parameter(unsigned index, float value) noexcept;

    float get_t60() const noexcept;
    float get_size() const noexcept;
    float get_damp() const noexcept;
    float get_early_diff() const noexcept;
    float get_low_cutoff() const noexcept;
    float get_high_cutoff() const noexcept;
    float get_low() const noexcept;
    float get_mid() const noexcept;
    float get_high() const noexcept;
    float get_mod_depth() const noexcept;
    float get_mod_freq() const noexcept;
    float get_dry() const noexcept;
    float get_wet() const noexcept;
    void set_t60(float value) noexcept;
    void set_size(float value) noexcept;
    void set_damp(float value) noexcept;
    void set_early_diff(float value) noexcept;
    void set_low_cutoff(float value) noexcept;
    void set_high_cutoff(float value) noexcept;
    void set_low(float value) noexcept;
    void set_mid(float value) noexcept;
    void set_high(float value) noexcept;
    void set_mod_depth(float value) noexcept;
    void set_mod_freq(float value) noexcept;
    void set_dry(float value) noexcept;
    void set_wet(float value) noexcept;

public:
    class BasicDsp;

private:
    std::unique_ptr<BasicDsp> fDsp;

};


#endif // DFJPverb_Faust_pp_Gen_HPP_