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
    mix_group(x) = rev_group(hgroup("[0] Mix",x));
    t60 = mix_group(hslider("[1] Time (T60) [symbol:t60] [style:knob]", 1, 0.1, 60, 0.1));
    size = mix_group(hslider("[2] Size [symbol:size] [style:knob]", 1, 0.5, 5, 0.01));
    damp = mix_group(hslider("[3] Hi-Freq Damping [symbol:damp] [style:knob]", 0, 0, 0.999, 0.0001));
    early_diff = mix_group(hslider("[4] Early Reflections Shape [symbol:early_diff] [style:knob]", invSqrt2, 0, 0.990, 0.001));

    eq_group(x) = rev_group(hgroup("[1] EQ",x));
    low_cutoff = eq_group(hslider("[1] Low/Mid-Band Crossover Frequency [symbol:low_cutoff] [style:knob] [unit:Hz] [scale:log]", 500, 100, 6000, 0.1));
    high_cutoff = eq_group(hslider("[2] Mid/High-Band Crossover Frequency [symbol:high_cutoff] [style:knob] [unit:Hz] [scale:log]", 2000, 1000, 10000, 0.1));
    low = eq_group(hslider("[3] Low-Band Multiplier [symbol:low] [style:knob]", 1, 0, 1, 0.01));
    mid = eq_group(hslider("[4] Mid-Band Multiplier [symbol:mid] [style:knob]", 1, 0, 1, 0.01));
    high = eq_group(hslider("[5] High-Band Multiplier [symbol:high] [style:knob]", 1, 0, 1, 0.01));

    mod_group(x) = rev_group(hgroup("[2] Modulation",x));
    mod_depth = mod_group(hslider("[1] Modulation Depth [symbol:mod_depth] [style:knob]", 0.1, 0, 1, 0.001));
    mod_freq = mod_group(hslider("[2] Modulation Frequency [symbol:mod_freq] [style:knob] [unit:Hz]", 2, 0, 10, 0.010));
};


out_mixer(fx, in_l, in_r) = fx(in_l, in_r) : *(wet_amount), *(wet_amount) :  +(in_l * dry_amount), +(in_r * dry_amount)
with {
    out_group(x) = hgroup("[4] Output", x);
    dry_amount = out_group(hslider("[1] Dry Gain [abbrev:Dry] [symbol:dry] [unit:dB] [style:knob]", 0, -90, 10, 0.1) : ba.db2linear);
    wet_amount = out_group(hslider("[2] Wet Gain [abbrev:Wet] [symbol:wet] [unit:dB] [style:knob]", -12, -90, 10, 0.1) : ba.db2linear);
};

process = out_mixer(jpverb_ui);
