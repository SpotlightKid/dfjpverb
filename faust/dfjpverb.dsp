declare name "DFJPverb";
declare description "A lush algorithmic reverb designed to sound great with synthetic sound sources";
declare author "Julian Parker, Till Bovermann, Christopher Arndt";
declare copyright "Julian Parker, bug fixes and minor interface changes by Till Bovermann, DPF version by Christopher Arndt";
declare license "GPL-2.0-or-later";
declare version "0.1.0";

import("stdfaust.lib");

jpverb_ui = re.jpverb(t60, damp, size, early_diff, mod_depth, mod_freq, low, mid, high, low_cutoff, high_cutoff)
with {
    rev_group(x) = vgroup("[0] JP Verb",x);
    invSqrt2 = 1 / sqrt(2);
    mix_group(x) = rev_group(hgroup("[0] Reverb",x));
    t60 = mix_group(hslider("[1] Time (T60) [symbol:t60] [style:knob] [tooltip: Time in seconds for the reverb to decay by 60db when damp == 0. Does not effect early reflections (0.1..60 s).]", 1, 0.1, 60, 0.1));
    size = mix_group(hslider("[2] Size [symbol:size] [style:knob] [tooltip: Scales size of delay-lines within the reverberator, producing the impression of a larger or smaller space. Values below 1 can sound metallic (0.5..5).]", 1, 0.5, 5, 0.01));
    damp = mix_group(hslider("[3] Hi-Freq Damping [symbol:damp] [style:knob] [tooltip: Damping of high-frequencies as the reverb decays. 0 is no damping, 1 is very strong damping (0..1).]", 0, 0, 0.999, 0.0001));
    early_diff = mix_group(hslider("[4] Early Reflections Shape [symbol:early_diff] [style:knob] [tooltip: Shape of early reflections. Values of >= ~0.707 produce smooth exponential decay. Lower values produce a slower build-up of echoes (0..0.99).]", invSqrt2, 0, 0.99, 0.001));

    eq_group(x) = rev_group(hgroup("[1] EQ",x));
    low_cutoff = eq_group(hslider("[1] Low/Mid-Band Crossover Frequency [symbol:low_cutoff] [style:knob] [unit:Hz] [scale:log] [tooltip: Frequency at which the crossover between the low and mid bands of the reverb occurs (100..6000 Hz)]", 500, 100, 6000, 0.1));
    high_cutoff = eq_group(hslider("[2] Mid/High-Band Crossover Frequency [symbol:high_cutoff] [style:knob] [unit:Hz] [scale:log] [tooltip: Frequency at which the crossover between the mid and high bands of the reverb occurs (1000..10000 Hz)]", 2000, 1000, 10000, 0.1));
    low = eq_group(hslider("[3] Low-Band Multiplier [symbol:low] [style:knob] [tooltip: Multiplier for the reverberation time within the low band (0..1)]", 1, 0, 1, 0.01));
    mid = eq_group(hslider("[4] Mid-Band Multiplier [symbol:mid] [style:knob] [tooltip: Multiplier for the reverberation time within the mid band (0..1)]", 1, 0, 1, 0.01));
    high = eq_group(hslider("[5] High-Band Multiplier [symbol:high] [style:knob] [tooltip: Multiplier for the reverberation time within the high band (0..1)]", 1, 0, 1, 0.01));

    mod_group(x) = rev_group(hgroup("[2] Modulation",x));
    mod_depth = mod_group(hslider("[1] Modulation Depth [symbol:mod_depth] [style:knob] [tooltip: Depth of delay-line modulation. Use in combination with Modulation Frequency to set amount of chorusing within the structure (0..1).]", 0.1, 0, 1, 0.001));
    mod_freq = mod_group(hslider("[2] Modulation Frequency [symbol:mod_freq] [style:knob] [unit:Hz] [tooltip: Frequency of delay-line modulation (0..10 Hz)]", 2, 0, 10, 0.010));
};


out_mixer(fx, in_l, in_r) = fx(in_l, in_r) : *(wet_amount), *(wet_amount) :  +(in_l * dry_amount), +(in_r * dry_amount)
with {
    out_group(x) = hgroup("[4] Output", x);
    dry_amount = out_group(hslider("[1] Dry Gain [abbrev:Dry] [symbol:dry] [unit:dB] [style:knob] [tooltip: Gain of dry (input) signal. Should be set to -90 when using the reverb as a send effect (-90..10 dB).]", 0, -90, 10, 0.1) : ba.db2linear);
    wet_amount = out_group(hslider("[2] Wet Gain [abbrev:Wet] [symbol:wet] [unit:dB] [style:knob] [tooltip: Gain of wet (reverb) signal (-90..10 dB)]", -12, -90, 10, 0.1) : ba.db2linear);
};

process = out_mixer(jpverb_ui);
