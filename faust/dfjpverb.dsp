declare name "DFJPverb";
declare description "A lush algorithmic reverb designed to sound great with synthetic sound sources";
declare author "Christopher Arndt";
declare license "GPL2+ license";

import("stdfaust.lib");

gain = hslider("[0]Gain [symbol: gain][abbrev: gain][unit: dB]", -6.0, -90.0, 30.0, 0.1):si.smoo;

process = _ * ba.db2linear(gain);
