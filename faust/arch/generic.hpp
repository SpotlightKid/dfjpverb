{% block HeaderDescription %}
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

{% block HeaderPrologue %}
{% if fdrversioninfo is undefined or fdrversioninfo < (0, 2, 0) %}
{{fail("This template is not compatible with faustdoctor version < 0.2.0.")}}
{% endif %}
{% if not (Identifier is defined and
           Identifier == cid(Identifier)) %}
{{fail("`Identifier` is undefined or invalid.")}}
{% endif %}
{% endblock %}

#pragma once
#ifndef {{Identifier}}_Faust_pp_Gen_HPP_
#define {{Identifier}}_Faust_pp_Gen_HPP_

#include <memory>
#include <string>

class {{Identifier}} {
public:
    {{Identifier}}();
    ~{{Identifier}}();

    void init(float sample_rate);
    void clear() noexcept;

    void process(
        {%+ for i in range(inputs) %}const float *in{{i}}, {% endfor +%}
        {%+ for i in range(outputs) %}float *out{{i}}, {% endfor +%}
        unsigned count) noexcept;

    enum { NumInputs = {{inputs}} };
    enum { NumOutputs = {{outputs}} };
    enum { NumActives = {{active|length}} };
    enum { NumPassives = {{passive|length}} };
    enum { NumParameters = {{active|length + passive|length}} };

    enum Parameter {
        {% for w in active + passive %}
        p_{{w.symbol}},
        {% endfor %}
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

    {% for w in active + passive %}
    float get_{{w.symbol}}() const noexcept;
    {% endfor %}
    {% for w in active %}
    void set_{{w.symbol}}(float value) noexcept;
    {% endfor %}

public:
    class BasicDsp;

private:
    std::unique_ptr<BasicDsp> fDsp;

{% block ClassExtraDecls %}
{% endblock %}
};

{% block HeaderEpilogue %}
{% endblock %}

#endif // {{Identifier}}_Faust_pp_Gen_HPP_
