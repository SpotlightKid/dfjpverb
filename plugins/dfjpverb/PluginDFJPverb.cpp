/*
 * DF JPverb audio effect based on DISTRHO Plugin Framework (DPF)
 *
 * SPDX-License-Identifier: GPL2+
 *
 * Copyright (C) 2022 Christopher Arndt <info@chrisarndt.de>
 */

#include "PluginDFJPverb.hpp"

START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------

PluginDFJPverb::PluginDFJPverb()
    : Plugin(DFJPverb::NumParameters, presetCount, 0)  // # of params, # of programs, 0 states
{
    dsp = new DFJPverb;
    fSampleRate = getSampleRate();

    for (unsigned p = 0; p < DFJPverb::NumParameters; ++p) {
        Parameter param;
        initParameter(p, param);
        setParameterValue(p, param.ranges.def);
    }
}

PluginDFJPverb::~PluginDFJPverb() {
    delete dsp;
}

// -----------------------------------------------------------------------
// Init

void PluginDFJPverb::initParameter(uint32_t index, Parameter& parameter) {
    if (index >= DFJPverb::NumParameters)
        return;

    const DFJPverb::ParameterRange* range = dsp->parameter_range(index);
    parameter.name = dsp->parameter_label(index);
    parameter.shortName = dsp->parameter_short_label(index);
    parameter.symbol = dsp->parameter_symbol(index);
    parameter.unit = dsp->parameter_unit(index);
    parameter.ranges.min = range->min;
    parameter.ranges.max = range->max;
    parameter.ranges.def = range->init;
    parameter.hints = kParameterIsAutomatable;

    if (dsp->parameter_is_boolean(index))
        parameter.hints |= kParameterIsBoolean;
    if (dsp->parameter_is_integer(index))
        parameter.hints |= kParameterIsInteger;
    if (dsp->parameter_is_logarithmic(index))
        parameter.hints |= kParameterIsLogarithmic;
    if (dsp->parameter_is_trigger(index))
        parameter.hints |= kParameterIsTrigger;
}

/**
  Set the name of the program @a index.
  This function will be called once, shortly after the plugin is created.
*/
void PluginDFJPverb::initProgramName(uint32_t index, String& programName) {
    if (index < presetCount) {
        programName = factoryPresets[index].name;
    }
}

// -----------------------------------------------------------------------
// Internal data

/**
  Optional callback to inform the plugin about a sample rate change.
*/
void PluginDFJPverb::sampleRateChanged(double newSampleRate) {
    fSampleRate = newSampleRate;
    dsp->init(newSampleRate);
}

/**
  Get the current value of a parameter.
*/
float PluginDFJPverb::getParameterValue(uint32_t index) const {
    return dsp->get_parameter(index);
}

/**
  Change a parameter value.
*/
void PluginDFJPverb::setParameterValue(uint32_t index, float value) {
    if (index >= DFJPverb::NumParameters)
        return;

    const DFJPverb::ParameterRange* range = dsp->parameter_range(index);
    dsp->set_parameter(index, CLAMP(value, range->min, range->max));
}

/**
  Load a program.
  The host may call this function from any context,
  including realtime processing.
*/
void PluginDFJPverb::loadProgram(uint32_t index) {
    if (index < presetCount) {
        for (int i=0; i < DFJPverb::NumParameters; i++) {
            setParameterValue(i, factoryPresets[index].params[i]);
        }
    }
}

// -----------------------------------------------------------------------
// Process

/**
  Plugin is activated.
*/
void PluginDFJPverb::activate() {
    fSampleRate = getSampleRate();
    dsp->init(fSampleRate);
}


void PluginDFJPverb::run(const float** inputs, float** outputs,
                         uint32_t frames) {
    dsp->process(inputs[0], inputs[1], outputs[0], outputs[1], (unsigned)frames);
}

// -----------------------------------------------------------------------

Plugin* createPlugin() {
    return new PluginDFJPverb();
}

// -----------------------------------------------------------------------

END_NAMESPACE_DISTRHO
