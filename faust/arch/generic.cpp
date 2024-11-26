{% block ImplementationDescription %}
//------------------------------------------------------------------------------
// This file was generated using the Faust compiler (https://faust.grame.fr),
// and the Faust post-processor (https://github.com/SpotlightKid/faustdoctor).
//
// Source: {{filename}}
// Name: {{name}}
// Author: {{author}}
// Copyright: {{copyright}}
// License: {{license}}
// Version: {{version}}
// FAUST version: {{faustversion}}
// FAUST compilation options: {{meta.compile_options}}
//------------------------------------------------------------------------------
{% endblock %}

{% block ImplementationPrologue %}
{% if fdrversioninfo is undefined or fdrversioninfo < (0, 2, 0) %}
{{fail("This template is not compatible with faustdoctor version < 0.2.0.")}}
{% endif %}
{% if not (Identifier is defined and
           Identifier == cid(Identifier)) %}
{{fail("`Identifier` is undefined or invalid.")}}
{% endif %}
{% endblock %}

{% block ImplementationIncludeHeader %}
#include "{{Identifier}}.hpp"
{% endblock %}
{% block ImplementationIncludeExtra %}
{% endblock %}
#include <utility>
#include <cmath>

class {{Identifier}}::BasicDsp {
public:
    virtual ~BasicDsp() {}
};

//------------------------------------------------------------------------------
// Begin the Faust code section

namespace {

template <class T> inline T min(T a, T b) { return (a < b) ? a : b; }
template <class T> inline T max(T a, T b) { return (a > b) ? a : b; }

class Meta {
public:
    // dummy
    void declare(...) {}
};

class UI {
public:
    // dummy
    void openHorizontalBox(...) {}
    void openVerticalBox(...) {}
    void closeBox(...) {}
    void declare(...) {}
    void addButton(...) {}
    void addCheckButton(...) {}
    void addVerticalSlider(...) {}
    void addHorizontalSlider(...) {}
    void addVerticalBargraph(...) {}
    void addHorizontalBargraph(...) {}
};

typedef {{Identifier}}::BasicDsp dsp;

} // namespace

#define FAUSTDR_VIRTUAL // do not declare any methods virtual
#define FAUSTDR_PRIVATE public // do not hide any members
#define FAUSTDR_PROTECTED public // do not hide any members

// define the DSP in the anonymous namespace
#define FAUSTDR_BEGIN_NAMESPACE namespace {
#define FAUSTDR_END_NAMESPACE }

{% block ImplementationFaustCode %}
#if defined(__GNUC__)
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

#ifndef FAUSTDR_PRIVATE
#   define FAUSTDR_PRIVATE private
#endif
#ifndef FAUSTDR_PROTECTED
#   define FAUSTDR_PROTECTED protected
#endif
#ifndef FAUSTDR_VIRTUAL
#   define FAUSTDR_VIRTUAL virtual
#endif

{{ classcode | replace('\t', '    ') }}

#if defined(__GNUC__)
#   pragma GCC diagnostic pop
#endif
{% endblock %}

//------------------------------------------------------------------------------
// End the Faust code section

{% block ImplementationBeforeClassDefs %}
{% endblock %}

{{Identifier}}::{{Identifier}}()
{
{% block ImplementationSetupDsp %}
    {{classname}} *dsp = new {{classname}};
    fDsp.reset(dsp);
    dsp->instanceResetUserInterface();
{% endblock %}
}

{{Identifier}}::~{{Identifier}}()
{
}

void {{Identifier}}::init(float sample_rate)
{
{% block ImplementationInitDsp %}
    {{classname}} &dsp = static_cast<{{classname}} &>(*fDsp);
    dsp.classInit(sample_rate);
    dsp.instanceConstants(sample_rate);
    clear();
{% endblock %}
}

void {{Identifier}}::clear() noexcept
{
{% block ImplementationClearDsp %}
    {{classname}} &dsp = static_cast<{{classname}} &>(*fDsp);
    dsp.instanceClear();
{% endblock %}
}

void {{Identifier}}::process(
    {%+ for i in range(inputs) %}const float *in{{i}}, {% endfor +%}
    {%+ for i in range(outputs) %}float *out{{i}}, {% endfor +%}
    unsigned count) noexcept
{
{% block ImplementationProcessDsp %}
    {{classname}} &dsp = static_cast<{{classname}} &>(*fDsp);
    float *inputs[] = {
        {%+ for i in range(inputs) %}const_cast<float *>(in{{i}}), {% endfor +%}
    };
    float *outputs[] = {
        {%+ for i in range(outputs) %}out{{i}}, {% endfor +%}
    };
    dsp.compute(count, inputs, outputs);
{% endblock %}
}

int {{Identifier}}::parameter_group(unsigned index) noexcept
{
    switch (index) {
    {% for w in active + passive %}{% if w.group != -1 %}
    case {{loop.index0}}:
        return {{w.group}};
    {% endif %}{% endfor %}
    default:
        return -1;
    }
}

const char *{{Identifier}}::parameter_group_label(unsigned group_id) noexcept
{
    switch (group_id) {
    {% for label, _ in groups %}
    case {{loop.index0}}:
        return {{ cstr(label) }};
    {% endfor %}
    default:
        return 0;
    }
}

const char *{{Identifier}}::parameter_group_symbol(unsigned group_id) noexcept
{
    switch (group_id) {
    {% for label, _ in groups %}
    case {{loop.index0}}:
        return {{ cstr(cid(label)) }};
    {% endfor %}
    default:
        return 0;
    }
}


int {{Identifier}}::parameter_order(unsigned index) noexcept
{
    switch (index) {
    {% for w in active + passive %}{% if w.order != -1 %}
    case {{loop.index0}}:
        return {{w.order}};
    {% endif %}{% endfor %}
    default:
        return -1;
    }
}

const char *{{Identifier}}::parameter_label(unsigned index) noexcept
{
    switch (index) {
    {% for w in active + passive %}
    case {{loop.index0}}:
        return {{cstr(w.label)}};
    {% endfor %}
    default:
        return 0;
    }
}

const char *{{Identifier}}::parameter_short_label(unsigned index) noexcept
{
    switch (index) {
    {% for w in active + passive %}
    case {{loop.index0}}:
        return {{cstr(w.meta.abbrev|default(w.label)|truncate(16, true))}};
    {% endfor %}
    default:
        return 0;
    }
}

const char *{{Identifier}}::parameter_description(unsigned index) noexcept
{
    switch (index) {
    {% for w in active + passive %}{% if w.tooltip %}
    case {{loop.index0}}:
        return {{cstr(w.tooltip)}};
    {% endif %}{% endfor %}
    default:
        return 0;
    }
}

const char *{{Identifier}}::parameter_style(unsigned index) noexcept
{
    switch (index) {
    {% for w in active + passive %}{% if w.style != "knob" %}
    case {{loop.index0}}: {
        return {{cstr(w.style)}};
    }
    {% endif %}{% endfor %}
    default:
        return "knob";
    }
}

const char *{{Identifier}}::parameter_symbol(unsigned index) noexcept
{
    switch (index) {
    {% for w in active + passive %}
    case {{loop.index0}}:
        return {{cstr(w.symbol)}};
    {% endfor %}
    default:
        return 0;
    }
}

const char *{{Identifier}}::parameter_unit(unsigned index) noexcept
{
    switch (index) {
    {% for w in active + passive %}
    case {{loop.index0}}:
        return {{cstr(w.unit)}};
    {% endfor %}
    default:
        return 0;
    }
}

const {{Identifier}}::ParameterRange *{{Identifier}}::parameter_range(unsigned index) noexcept
{
    switch (index) {
    {% for w in active + passive %}
    case {{loop.index0}}: {
        static const ParameterRange range = { {{w.init}}, {{w.min}}, {{w.max}} };
        return &range;
    }
    {% endfor %}
    default:
        return 0;
    }
}

unsigned {{Identifier}}::parameter_scale_point_count(unsigned index) noexcept
{
    switch (index) {
    {% for w in active + passive %}{% if w.style in ["menu", "radio"] %}
    case {{loop.index0}}:
        return {{ w.entries | length }};
    {% endif %}{% endfor %}
    default:
        return 0;
    }
}

const {{Identifier}}::ParameterScalePoint *{{Identifier}}::parameter_scale_point(unsigned index, unsigned point) noexcept
{
    {% set ns = namespace(has_points=false) %}
    switch (index) {
    {% for w in active + passive %}{% if w.entries %}
    {% set ns.has_points = true %}
    case {{loop.index0}}:
        switch (point) {
        {% for label, value in w.entries %}
        case {{loop.index0}}: {
            static const ParameterScalePoint scale_point = { {{cstr(label)}}, {{value}} };
            return &scale_point;
        }
        {% endfor %}
        default:
            return 0;
        }
    {% endif %}{% endfor %}
    default:
        return 0;
    }
    {% if not ns.has_points %}(void) point;{% endif %}
}

bool {{Identifier}}::parameter_is_trigger(unsigned index) noexcept
{
    switch (index) {
    {% for w in active + passive %}{% if w.type in ["button"] or
                                         w.meta.trigger is defined %}
    case {{loop.index0}}:
        return true;
    {% endif %}{% endfor %}
    default:
        return false;
    }
}

bool {{Identifier}}::parameter_is_boolean(unsigned index) noexcept
{
    switch (index) {
    {% for w in active + passive %}{% if w.type in ["button", "checkbox"] or
                                         w.meta.boolean is defined %}
    case {{loop.index0}}:
        return true;
    {% endif %}{% endfor %}
    default:
        return false;
    }
}

bool {{Identifier}}::parameter_is_enum(unsigned index) noexcept
{
    switch (index) {
    {% for w in active + passive %}{% if w.meta.style is defined and (w.meta.style.startswith("menu{") or w.meta.style.startswith("radio{")) %}
    case {{loop.index0}}:
        return true;
    {% endif %}{% endfor %}
    default:
        return false;
    }
}

bool {{Identifier}}::parameter_is_integer(unsigned index) noexcept
{
    switch (index) {
    {% for w in active + passive %}{% if w.type in ["button", "checkbox"] or
                                         w.meta.integer is defined or
                                         w.meta.boolean is defined %}
    case {{loop.index0}}:
        return true;
    {% endif %}{% endfor %}
    default:
        return false;
    }
}

bool {{Identifier}}::parameter_is_logarithmic(unsigned index) noexcept
{
    switch (index) {
    {% for w in active + passive %}{% if w.scale == "log" %}
    case {{loop.index0}}:
        return true;
    {% endif %}{% endfor %}
    default:
        return false;
    }
}

float {{Identifier}}::get_parameter(unsigned index) const noexcept
{
    {{classname}} &dsp = static_cast<{{classname}} &>(*fDsp);
    switch (index) {
    {% for w in active + passive %}
    case {{loop.index0}}:
        return dsp.{{w.varname}};
    {% endfor %}
    default:
        (void)dsp;
        return 0;
    }
}

void {{Identifier}}::set_parameter(unsigned index, float value) noexcept
{
    {{classname}} &dsp = static_cast<{{classname}} &>(*fDsp);
    switch (index) {
    {% for w in active %}
    case {{loop.index0}}:
        dsp.{{w.varname}} = value;
        break;
    {% endfor %}
    default:
        (void)dsp;
        (void)value;
        break;
    }
}

{% for w in active + passive %}
float {{Identifier}}::get_{{w.symbol}}() const noexcept
{
    {{classname}} &dsp = static_cast<{{classname}} &>(*fDsp);
    return dsp.{{w.varname}};
}

{% endfor %}
{% for w in active %}
void {{Identifier}}::set_{{w.symbol}}(float value) noexcept
{
    {{classname}} &dsp = static_cast<{{classname}} &>(*fDsp);
    dsp.{{w.varname}} = value;
}

{% endfor %}

{% block ImplementationEpilogue %}
{% endblock %}
