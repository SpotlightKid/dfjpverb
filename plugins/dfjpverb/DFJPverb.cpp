
//------------------------------------------------------------------------------
// This file was generated using the Faust compiler (https://faust.grame.fr),
// and the Faust post-processor (https://github.com/jpcima/faustpp).
//
// Source: dfjpverb.dsp
// Name: DFJPverb
// Author: Julian Parker, Till Bovermann, Christopher Arndt
// Copyright: Julian Parker, bug fixes and minor interface changes by Till Bovermann, DPF version by Christopher Arndt
// License: GPL-2.0-or-later
// Version: 0.1.0
//------------------------------------------------------------------------------







#include "DFJPverb.hpp"



#include <utility>
#include <cmath>

class DFJPverb::BasicDsp {
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

typedef DFJPverb::BasicDsp dsp;

} // namespace

#define FAUSTPP_VIRTUAL // do not declare any methods virtual
#define FAUSTPP_PRIVATE public // do not hide any members
#define FAUSTPP_PROTECTED public // do not hide any members

// define the DSP in the anonymous namespace
#define FAUSTPP_BEGIN_NAMESPACE namespace {
#define FAUSTPP_END_NAMESPACE }


#if defined(__GNUC__)
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

#ifndef FAUSTPP_PRIVATE
#   define FAUSTPP_PRIVATE private
#endif
#ifndef FAUSTPP_PROTECTED
#   define FAUSTPP_PROTECTED protected
#endif
#ifndef FAUSTPP_VIRTUAL
#   define FAUSTPP_VIRTUAL virtual
#endif

#ifndef FAUSTPP_BEGIN_NAMESPACE
#   define FAUSTPP_BEGIN_NAMESPACE
#endif
#ifndef FAUSTPP_END_NAMESPACE
#   define FAUSTPP_END_NAMESPACE
#endif

FAUSTPP_BEGIN_NAMESPACE

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

FAUSTPP_END_NAMESPACE
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>
FAUSTPP_BEGIN_NAMESPACE

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif

const static int imydspSIG0Wave0[2048] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997,1009,1013,1019,1021,1031,1033,1039,1049,1051,1061,1063,1069,1087,1091,1093,1097,1103,1109,1117,1123,1129,1151,1153,1163,1171,1181,1187,1193,1201,1213,1217,1223,1229,1231,1237,1249,1259,1277,1279,1283,1289,1291,1297,1301,1303,1307,1319,1321,1327,1361,1367,1373,1381,1399,1409,1423,1427,1429,1433,1439,1447,1451,1453,1459,1471,1481,1483,1487,1489,1493,1499,1511,1523,1531,1543,1549,1553,1559,1567,1571,1579,1583,1597,1601,1607,1609,1613,1619,1621,1627,1637,1657,1663,1667,1669,1693,1697,1699,1709,1721,1723,1733,1741,1747,1753,1759,1777,1783,1787,1789,1801,1811,1823,1831,1847,1861,1867,1871,1873,1877,1879,1889,1901,1907,1913,1931,1933,1949,1951,1973,1979,1987,1993,1997,1999,2003,2011,2017,2027,2029,2039,2053,2063,2069,2081,2083,2087,2089,2099,2111,2113,2129,2131,2137,2141,2143,2153,2161,2179,2203,2207,2213,2221,2237,2239,2243,2251,2267,2269,2273,2281,2287,2293,2297,2309,2311,2333,2339,2341,2347,2351,2357,2371,2377,2381,2383,2389,2393,2399,2411,2417,2423,2437,2441,2447,2459,2467,2473,2477,2503,2521,2531,2539,2543,2549,2551,2557,2579,2591,2593,2609,2617,2621,2633,2647,2657,2659,2663,2671,2677,2683,2687,2689,2693,2699,2707,2711,2713,2719,2729,2731,2741,2749,2753,2767,2777,2789,2791,2797,2801,2803,2819,2833,2837,2843,2851,2857,2861,2879,2887,2897,2903,2909,2917,2927,2939,2953,2957,2963,2969,2971,2999,3001,3011,3019,3023,3037,3041,3049,3061,3067,3079,3083,3089,3109,3119,3121,3137,3163,3167,3169,3181,3187,3191,3203,3209,3217,3221,3229,3251,3253,3257,3259,3271,3299,3301,3307,3313,3319,3323,3329,3331,3343,3347,3359,3361,3371,3373,3389,3391,3407,3413,3433,3449,3457,3461,3463,3467,3469,3491,3499,3511,3517,3527,3529,3533,3539,3541,3547,3557,3559,3571,3581,3583,3593,3607,3613,3617,3623,3631,3637,3643,3659,3671,3673,3677,3691,3697,3701,3709,3719,3727,3733,3739,3761,3767,3769,3779,3793,3797,3803,3821,3823,3833,3847,3851,3853,3863,3877,3881,3889,3907,3911,3917,3919,3923,3929,3931,3943,3947,3967,3989,4001,4003,4007,4013,4019,4021,4027,4049,4051,4057,4073,4079,4091,4093,4099,4111,4127,4129,4133,4139,4153,4157,4159,4177,4201,4211,4217,4219,4229,4231,4241,4243,4253,4259,4261,4271,4273,4283,4289,4297,4327,4337,4339,4349,4357,4363,4373,4391,4397,4409,4421,4423,4441,4447,4451,4457,4463,4481,4483,4493,4507,4513,4517,4519,4523,4547,4549,4561,4567,4583,4591,4597,4603,4621,4637,4639,4643,4649,4651,4657,4663,4673,4679,4691,4703,4721,4723,4729,4733,4751,4759,4783,4787,4789,4793,4799,4801,4813,4817,4831,4861,4871,4877,4889,4903,4909,4919,4931,4933,4937,4943,4951,4957,4967,4969,4973,4987,4993,4999,5003,5009,5011,5021,5023,5039,5051,5059,5077,5081,5087,5099,5101,5107,5113,5119,5147,5153,5167,5171,5179,5189,5197,5209,5227,5231,5233,5237,5261,5273,5279,5281,5297,5303,5309,5323,5333,5347,5351,5381,5387,5393,5399,5407,5413,5417,5419,5431,5437,5441,5443,5449,5471,5477,5479,5483,5501,5503,5507,5519,5521,5527,5531,5557,5563,5569,5573,5581,5591,5623,5639,5641,5647,5651,5653,5657,5659,5669,5683,5689,5693,5701,5711,5717,5737,5741,5743,5749,5779,5783,5791,5801,5807,5813,5821,5827,5839,5843,5849,5851,5857,5861,5867,5869,5879,5881,5897,5903,5923,5927,5939,5953,5981,5987,6007,6011,6029,6037,6043,6047,6053,6067,6073,6079,6089,6091,6101,6113,6121,6131,6133,6143,6151,6163,6173,6197,6199,6203,6211,6217,6221,6229,6247,6257,6263,6269,6271,6277,6287,6299,6301,6311,6317,6323,6329,6337,6343,6353,6359,6361,6367,6373,6379,6389,6397,6421,6427,6449,6451,6469,6473,6481,6491,6521,6529,6547,6551,6553,6563,6569,6571,6577,6581,6599,6607,6619,6637,6653,6659,6661,6673,6679,6689,6691,6701,6703,6709,6719,6733,6737,6761,6763,6779,6781,6791,6793,6803,6823,6827,6829,6833,6841,6857,6863,6869,6871,6883,6899,6907,6911,6917,6947,6949,6959,6961,6967,6971,6977,6983,6991,6997,7001,7013,7019,7027,7039,7043,7057,7069,7079,7103,7109,7121,7127,7129,7151,7159,7177,7187,7193,7207,7211,7213,7219,7229,7237,7243,7247,7253,7283,7297,7307,7309,7321,7331,7333,7349,7351,7369,7393,7411,7417,7433,7451,7457,7459,7477,7481,7487,7489,7499,7507,7517,7523,7529,7537,7541,7547,7549,7559,7561,7573,7577,7583,7589,7591,7603,7607,7621,7639,7643,7649,7669,7673,7681,7687,7691,7699,7703,7717,7723,7727,7741,7753,7757,7759,7789,7793,7817,7823,7829,7841,7853,7867,7873,7877,7879,7883,7901,7907,7919,7927,7933,7937,7949,7951,7963,7993,8009,8011,8017,8039,8053,8059,8069,8081,8087,8089,8093,8101,8111,8117,8123,8147,8161,8167,8171,8179,8191,8209,8219,8221,8231,8233,8237,8243,8263,8269,8273,8287,8291,8293,8297,8311,8317,8329,8353,8363,8369,8377,8387,8389,8419,8423,8429,8431,8443,8447,8461,8467,8501,8513,8521,8527,8537,8539,8543,8563,8573,8581,8597,8599,8609,8623,8627,8629,8641,8647,8663,8669,8677,8681,8689,8693,8699,8707,8713,8719,8731,8737,8741,8747,8753,8761,8779,8783,8803,8807,8819,8821,8831,8837,8839,8849,8861,8863,8867,8887,8893,8923,8929,8933,8941,8951,8963,8969,8971,8999,9001,9007,9011,9013,9029,9041,9043,9049,9059,9067,9091,9103,9109,9127,9133,9137,9151,9157,9161,9173,9181,9187,9199,9203,9209,9221,9227,9239,9241,9257,9277,9281,9283,9293,9311,9319,9323,9337,9341,9343,9349,9371,9377,9391,9397,9403,9413,9419,9421,9431,9433,9437,9439,9461,9463,9467,9473,9479,9491,9497,9511,9521,9533,9539,9547,9551,9587,9601,9613,9619,9623,9629,9631,9643,9649,9661,9677,9679,9689,9697,9719,9721,9733,9739,9743,9749,9767,9769,9781,9787,9791,9803,9811,9817,9829,9833,9839,9851,9857,9859,9871,9883,9887,9901,9907,9923,9929,9931,9941,9949,9967,9973,10007,10009,10037,10039,10061,10067,10069,10079,10091,10093,10099,10103,10111,10133,10139,10141,10151,10159,10163,10169,10177,10181,10193,10211,10223,10243,10247,10253,10259,10267,10271,10273,10289,10301,10303,10313,10321,10331,10333,10337,10343,10357,10369,10391,10399,10427,10429,10433,10453,10457,10459,10463,10477,10487,10499,10501,10513,10529,10531,10559,10567,10589,10597,10601,10607,10613,10627,10631,10639,10651,10657,10663,10667,10687,10691,10709,10711,10723,10729,10733,10739,10753,10771,10781,10789,10799,10831,10837,10847,10853,10859,10861,10867,10883,10889,10891,10903,10909,10937,10939,10949,10957,10973,10979,10987,10993,11003,11027,11047,11057,11059,11069,11071,11083,11087,11093,11113,11117,11119,11131,11149,11159,11161,11171,11173,11177,11197,11213,11239,11243,11251,11257,11261,11273,11279,11287,11299,11311,11317,11321,11329,11351,11353,11369,11383,11393,11399,11411,11423,11437,11443,11447,11467,11471,11483,11489,11491,11497,11503,11519,11527,11549,11551,11579,11587,11593,11597,11617,11621,11633,11657,11677,11681,11689,11699,11701,11717,11719,11731,11743,11777,11779,11783,11789,11801,11807,11813,11821,11827,11831,11833,11839,11863,11867,11887,11897,11903,11909,11923,11927,11933,11939,11941,11953,11959,11969,11971,11981,11987,12007,12011,12037,12041,12043,12049,12071,12073,12097,12101,12107,12109,12113,12119,12143,12149,12157,12161,12163,12197,12203,12211,12227,12239,12241,12251,12253,12263,12269,12277,12281,12289,12301,12323,12329,12343,12347,12373,12377,12379,12391,12401,12409,12413,12421,12433,12437,12451,12457,12473,12479,12487,12491,12497,12503,12511,12517,12527,12539,12541,12547,12553,12569,12577,12583,12589,12601,12611,12613,12619,12637,12641,12647,12653,12659,12671,12689,12697,12703,12713,12721,12739,12743,12757,12763,12781,12791,12799,12809,12821,12823,12829,12841,12853,12889,12893,12899,12907,12911,12917,12919,12923,12941,12953,12959,12967,12973,12979,12983,13001,13003,13007,13009,13033,13037,13043,13049,13063,13093,13099,13103,13109,13121,13127,13147,13151,13159,13163,13171,13177,13183,13187,13217,13219,13229,13241,13249,13259,13267,13291,13297,13309,13313,13327,13331,13337,13339,13367,13381,13397,13399,13411,13417,13421,13441,13451,13457,13463,13469,13477,13487,13499,13513,13523,13537,13553,13567,13577,13591,13597,13613,13619,13627,13633,13649,13669,13679,13681,13687,13691,13693,13697,13709,13711,13721,13723,13729,13751,13757,13759,13763,13781,13789,13799,13807,13829,13831,13841,13859,13873,13877,13879,13883,13901,13903,13907,13913,13921,13931,13933,13963,13967,13997,13999,14009,14011,14029,14033,14051,14057,14071,14081,14083,14087,14107,14143,14149,14153,14159,14173,14177,14197,14207,14221,14243,14249,14251,14281,14293,14303,14321,14323,14327,14341,14347,14369,14387,14389,14401,14407,14411,14419,14423,14431,14437,14447,14449,14461,14479,14489,14503,14519,14533,14537,14543,14549,14551,14557,14561,14563,14591,14593,14621,14627,14629,14633,14639,14653,14657,14669,14683,14699,14713,14717,14723,14731,14737,14741,14747,14753,14759,14767,14771,14779,14783,14797,14813,14821,14827,14831,14843,14851,14867,14869,14879,14887,14891,14897,14923,14929,14939,14947,14951,14957,14969,14983,15013,15017,15031,15053,15061,15073,15077,15083,15091,15101,15107,15121,15131,15137,15139,15149,15161,15173,15187,15193,15199,15217,15227,15233,15241,15259,15263,15269,15271,15277,15287,15289,15299,15307,15313,15319,15329,15331,15349,15359,15361,15373,15377,15383,15391,15401,15413,15427,15439,15443,15451,15461,15467,15473,15493,15497,15511,15527,15541,15551,15559,15569,15581,15583,15601,15607,15619,15629,15641,15643,15647,15649,15661,15667,15671,15679,15683,15727,15731,15733,15737,15739,15749,15761,15767,15773,15787,15791,15797,15803,15809,15817,15823,15859,15877,15881,15887,15889,15901,15907,15913,15919,15923,15937,15959,15971,15973,15991,16001,16007,16033,16057,16061,16063,16067,16069,16073,16087,16091,16097,16103,16111,16127,16139,16141,16183,16187,16189,16193,16217,16223,16229,16231,16249,16253,16267,16273,16301,16319,16333,16339,16349,16361,16363,16369,16381,16411,16417,16421,16427,16433,16447,16451,16453,16477,16481,16487,16493,16519,16529,16547,16553,16561,16567,16573,16603,16607,16619,16631,16633,16649,16651,16657,16661,16673,16691,16693,16699,16703,16729,16741,16747,16759,16763,16787,16811,16823,16829,16831,16843,16871,16879,16883,16889,16901,16903,16921,16927,16931,16937,16943,16963,16979,16981,16987,16993,17011,17021,17027,17029,17033,17041,17047,17053,17077,17093,17099,17107,17117,17123,17137,17159,17167,17183,17189,17191,17203,17207,17209,17231,17239,17257,17291,17293,17299,17317,17321,17327,17333,17341,17351,17359,17377,17383,17387,17389,17393,17401,17417,17419,17431,17443,17449,17467,17471,17477,17483,17489,17491,17497,17509,17519,17539,17551,17569,17573,17579,17581,17597,17599,17609,17623,17627,17657,17659,17669,17681,17683,17707,17713,17729,17737,17747,17749,17761,17783,17789,17791,17807,17827,17837,17839,17851,17863};
class mydspSIG0 {
	
  FAUSTPP_PRIVATE:
	
	int imydspSIG0Wave0_idx;
	
  public:
	
	int getNumInputsmydspSIG0() {
		return 0;
	}
	int getNumOutputsmydspSIG0() {
		return 1;
	}
	
	void instanceInitmydspSIG0(int sample_rate) {
		imydspSIG0Wave0_idx = 0;
	}
	
	void fillmydspSIG0(int count, int* table) {
		for (int i1 = 0; i1 < count; i1 = i1 + 1) {
			table[i1] = imydspSIG0Wave0[imydspSIG0Wave0_idx];
			imydspSIG0Wave0_idx = (1 + imydspSIG0Wave0_idx) % 2048;
		}
	}

};

static mydspSIG0* newmydspSIG0() { return (mydspSIG0*)new mydspSIG0(); }
static void deletemydspSIG0(mydspSIG0* dsp) { delete dsp; }

static float mydsp_faustpower2_f(float value) {
	return value * value;
}
static int itbl0mydspSIG0[2048];

class mydsp : public dsp {
	
 FAUSTPP_PRIVATE:
	
	FAUSTFLOAT fHslider0;
	int iVec0[2];
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	float fRec10[2];
	float fRec12[2];
	float fRec16[2];
	int IOTA0;
	float fVec1[16384];
	float fVec2[2];
	float fRec15[2];
	float fRec13[2];
	float fRec18[2];
	float fVec3[16384];
	float fVec4[2];
	float fRec17[2];
	float fRec14[2];
	float fRec22[2];
	float fVec5[16384];
	float fVec6[2];
	float fRec21[2];
	float fRec19[2];
	float fRec24[2];
	float fVec7[16384];
	float fVec8[2];
	float fRec23[2];
	float fRec20[2];
	float fRec28[2];
	float fVec9[16384];
	float fVec10[2];
	float fRec27[2];
	float fRec25[2];
	float fRec30[2];
	float fVec11[16384];
	float fVec12[2];
	float fRec29[2];
	float fRec26[2];
	float fRec34[2];
	float fVec13[16384];
	float fVec14[2];
	float fRec33[2];
	float fRec31[2];
	float fRec36[2];
	float fVec15[16384];
	float fVec16[2];
	float fRec35[2];
	float fRec32[2];
	float fRec40[2];
	float fVec17[16384];
	float fVec18[2];
	float fRec39[2];
	float fRec37[2];
	float fRec42[2];
	float fVec19[16384];
	float fVec20[2];
	float fRec41[2];
	float fRec38[2];
	float fVec21[1024];
	FAUSTFLOAT fHslider5;
	float fConst2;
	float fRec43[2];
	float fRec44[2];
	FAUSTFLOAT fHslider6;
	float fVec22[16384];
	float fVec23[2];
	float fRec11[2];
	float fRec48[2];
	float fRec50[2];
	float fVec24[1024];
	float fVec25[16384];
	float fVec26[2];
	float fRec49[2];
	float fVec27[16384];
	float fVec28[2];
	float fRec47[2];
	float fRec45[2];
	float fRec52[2];
	float fVec29[16384];
	float fVec30[2];
	float fRec51[2];
	float fRec46[2];
	float fRec56[2];
	float fVec31[16384];
	float fVec32[2];
	float fRec55[2];
	float fRec53[2];
	float fRec58[2];
	float fVec33[16384];
	float fVec34[2];
	float fRec57[2];
	float fRec54[2];
	float fRec62[2];
	float fVec35[16384];
	float fVec36[2];
	float fRec61[2];
	float fRec59[2];
	float fRec64[2];
	float fVec37[16384];
	float fVec38[2];
	float fRec63[2];
	float fRec60[2];
	float fRec68[2];
	float fVec39[16384];
	float fVec40[2];
	float fRec67[2];
	float fRec65[2];
	float fRec70[2];
	float fVec41[16384];
	float fVec42[2];
	float fRec69[2];
	float fRec66[2];
	float fRec74[2];
	float fVec43[16384];
	float fVec44[2];
	float fRec73[2];
	float fRec71[2];
	float fRec76[2];
	float fVec45[16384];
	float fVec46[2];
	float fRec75[2];
	float fRec72[2];
	float fVec47[16384];
	float fVec48[16384];
	float fVec49[2];
	float fRec9[2];
	float fRec8[2];
	float fRec7[3];
	float fRec6[3];
	float fVec50[2];
	float fRec5[2];
	float fRec4[3];
	float fRec3[3];
	FAUSTFLOAT fHslider7;
	float fRec79[2];
	float fRec78[3];
	float fRec77[3];
	FAUSTFLOAT fHslider8;
	float fRec83[2];
	float fRec82[3];
	float fRec81[3];
	float fRec80[3];
	FAUSTFLOAT fHslider9;
	FAUSTFLOAT fHslider10;
	float fVec51[1024];
	float fRec2[2];
	FAUSTFLOAT fHslider11;
	float fRec95[2];
	float fVec52[16384];
	float fVec53[16384];
	float fVec54[2];
	float fRec94[2];
	float fRec93[2];
	float fRec92[3];
	float fRec91[3];
	float fVec55[2];
	float fRec90[2];
	float fRec89[3];
	float fRec88[3];
	float fRec98[2];
	float fRec97[3];
	float fRec96[3];
	float fRec102[2];
	float fRec101[3];
	float fRec100[3];
	float fRec99[3];
	float fVec56[1024];
	float fRec87[2];
	float fVec57[16384];
	float fVec58[2];
	float fRec86[2];
	float fRec84[2];
	float fRec104[2];
	float fVec59[16384];
	float fVec60[2];
	float fRec103[2];
	float fRec85[2];
	float fVec61[16384];
	float fVec62[2];
	float fRec107[2];
	float fRec105[2];
	float fVec63[16384];
	float fVec64[2];
	float fRec108[2];
	float fRec106[2];
	float fVec65[16384];
	float fVec66[2];
	float fRec111[2];
	float fRec109[2];
	float fRec113[2];
	float fVec67[16384];
	float fVec68[2];
	float fRec112[2];
	float fRec110[2];
	float fRec117[2];
	float fVec69[16384];
	float fVec70[2];
	float fRec116[2];
	float fRec114[2];
	float fVec71[16384];
	float fVec72[2];
	float fRec118[2];
	float fRec115[2];
	float fRec0[2];
	float fRec1[2];
	FAUSTFLOAT fHslider12;
	
 public:
	mydsp() {
	}
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.2.0");
		m->declare("author", "Julian Parker, Till Bovermann, Christopher Arndt");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/tabulateNd", "Copyright (C) 2023 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics.lib/version", "1.19.1");
		m->declare("compile_options", "-a /home/chris/tmp/tmpkuxug3v2.cpp -lang cpp -ct 1 -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("copyright", "Julian Parker, bug fixes and minor interface changes by Till Bovermann, DPF version by Christopher Arndt");
		m->declare("delays.lib/fdelay1a:author", "Julius O. Smith III");
		m->declare("delays.lib/fdelay4:author", "Julius O. Smith III");
		m->declare("delays.lib/fdelayltv:author", "Julius O. Smith III");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.1.0");
		m->declare("description", "A lush algorithmic reverb designed to sound great with synthetic sound sources");
		m->declare("filename", "dfjpverb.dsp");
		m->declare("filters.lib/filterbank:author", "Julius O. Smith III");
		m->declare("filters.lib/filterbank:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/filterbank:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highpass_plus_lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass_plus_lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highpass_plus_lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/nlf2:author", "Julius O. Smith III");
		m->declare("filters.lib/nlf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/nlf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "1.3.0");
		m->declare("license", "GPL-2.0-or-later");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.8.0");
		m->declare("name", "DFJPverb");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "1.5.1");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("reverbs.lib/jpverb:author", "Julian Parker, bug fixes and minor interface changes by Till Bovermann");
		m->declare("reverbs.lib/jpverb:license", "GPL2+");
		m->declare("reverbs.lib/name", "Faust Reverb Library");
		m->declare("reverbs.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "1.6.0");
		m->declare("version", "0.1.0");
	}

	FAUSTPP_VIRTUAL int getNumInputs() {
		return 2;
	}
	FAUSTPP_VIRTUAL int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
		mydspSIG0* sig0 = newmydspSIG0();
		sig0->instanceInitmydspSIG0(sample_rate);
		sig0->fillmydspSIG0(2048, itbl0mydspSIG0);
		deletemydspSIG0(sig0);
	}
	
	FAUSTPP_VIRTUAL void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = 3.1415927f / fConst0;
		fConst2 = 6.2831855f / fConst0;
	}
	
	FAUSTPP_VIRTUAL void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.0f);
		fHslider1 = FAUSTFLOAT(0.0f);
		fHslider2 = FAUSTFLOAT(5e+02f);
		fHslider3 = FAUSTFLOAT(2e+03f);
		fHslider4 = FAUSTFLOAT(1.0f);
		fHslider5 = FAUSTFLOAT(2.0f);
		fHslider6 = FAUSTFLOAT(0.1f);
		fHslider7 = FAUSTFLOAT(1.0f);
		fHslider8 = FAUSTFLOAT(1.0f);
		fHslider9 = FAUSTFLOAT(1.0f);
		fHslider10 = FAUSTFLOAT(1.0f);
		fHslider11 = FAUSTFLOAT(0.70710677f);
		fHslider12 = FAUSTFLOAT(-12.0f);
	}
	
	FAUSTPP_VIRTUAL void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			fRec10[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fRec12[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			fRec16[l3] = 0.0f;
		}
		IOTA0 = 0;
		for (int l4 = 0; l4 < 16384; l4 = l4 + 1) {
			fVec1[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			fVec2[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			fRec15[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			fRec13[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = l8 + 1) {
			fRec18[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 16384; l9 = l9 + 1) {
			fVec3[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = l10 + 1) {
			fVec4[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			fRec17[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = l12 + 1) {
			fRec14[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 2; l13 = l13 + 1) {
			fRec22[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 16384; l14 = l14 + 1) {
			fVec5[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = l15 + 1) {
			fVec6[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = l16 + 1) {
			fRec21[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = l17 + 1) {
			fRec19[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2; l18 = l18 + 1) {
			fRec24[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 16384; l19 = l19 + 1) {
			fVec7[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = l20 + 1) {
			fVec8[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 2; l21 = l21 + 1) {
			fRec23[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 2; l22 = l22 + 1) {
			fRec20[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 2; l23 = l23 + 1) {
			fRec28[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 16384; l24 = l24 + 1) {
			fVec9[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 2; l25 = l25 + 1) {
			fVec10[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 2; l26 = l26 + 1) {
			fRec27[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 2; l27 = l27 + 1) {
			fRec25[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 2; l28 = l28 + 1) {
			fRec30[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 16384; l29 = l29 + 1) {
			fVec11[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 2; l30 = l30 + 1) {
			fVec12[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 2; l31 = l31 + 1) {
			fRec29[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 2; l32 = l32 + 1) {
			fRec26[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 2; l33 = l33 + 1) {
			fRec34[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 16384; l34 = l34 + 1) {
			fVec13[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 2; l35 = l35 + 1) {
			fVec14[l35] = 0.0f;
		}
		for (int l36 = 0; l36 < 2; l36 = l36 + 1) {
			fRec33[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 2; l37 = l37 + 1) {
			fRec31[l37] = 0.0f;
		}
		for (int l38 = 0; l38 < 2; l38 = l38 + 1) {
			fRec36[l38] = 0.0f;
		}
		for (int l39 = 0; l39 < 16384; l39 = l39 + 1) {
			fVec15[l39] = 0.0f;
		}
		for (int l40 = 0; l40 < 2; l40 = l40 + 1) {
			fVec16[l40] = 0.0f;
		}
		for (int l41 = 0; l41 < 2; l41 = l41 + 1) {
			fRec35[l41] = 0.0f;
		}
		for (int l42 = 0; l42 < 2; l42 = l42 + 1) {
			fRec32[l42] = 0.0f;
		}
		for (int l43 = 0; l43 < 2; l43 = l43 + 1) {
			fRec40[l43] = 0.0f;
		}
		for (int l44 = 0; l44 < 16384; l44 = l44 + 1) {
			fVec17[l44] = 0.0f;
		}
		for (int l45 = 0; l45 < 2; l45 = l45 + 1) {
			fVec18[l45] = 0.0f;
		}
		for (int l46 = 0; l46 < 2; l46 = l46 + 1) {
			fRec39[l46] = 0.0f;
		}
		for (int l47 = 0; l47 < 2; l47 = l47 + 1) {
			fRec37[l47] = 0.0f;
		}
		for (int l48 = 0; l48 < 2; l48 = l48 + 1) {
			fRec42[l48] = 0.0f;
		}
		for (int l49 = 0; l49 < 16384; l49 = l49 + 1) {
			fVec19[l49] = 0.0f;
		}
		for (int l50 = 0; l50 < 2; l50 = l50 + 1) {
			fVec20[l50] = 0.0f;
		}
		for (int l51 = 0; l51 < 2; l51 = l51 + 1) {
			fRec41[l51] = 0.0f;
		}
		for (int l52 = 0; l52 < 2; l52 = l52 + 1) {
			fRec38[l52] = 0.0f;
		}
		for (int l53 = 0; l53 < 1024; l53 = l53 + 1) {
			fVec21[l53] = 0.0f;
		}
		for (int l54 = 0; l54 < 2; l54 = l54 + 1) {
			fRec43[l54] = 0.0f;
		}
		for (int l55 = 0; l55 < 2; l55 = l55 + 1) {
			fRec44[l55] = 0.0f;
		}
		for (int l56 = 0; l56 < 16384; l56 = l56 + 1) {
			fVec22[l56] = 0.0f;
		}
		for (int l57 = 0; l57 < 2; l57 = l57 + 1) {
			fVec23[l57] = 0.0f;
		}
		for (int l58 = 0; l58 < 2; l58 = l58 + 1) {
			fRec11[l58] = 0.0f;
		}
		for (int l59 = 0; l59 < 2; l59 = l59 + 1) {
			fRec48[l59] = 0.0f;
		}
		for (int l60 = 0; l60 < 2; l60 = l60 + 1) {
			fRec50[l60] = 0.0f;
		}
		for (int l61 = 0; l61 < 1024; l61 = l61 + 1) {
			fVec24[l61] = 0.0f;
		}
		for (int l62 = 0; l62 < 16384; l62 = l62 + 1) {
			fVec25[l62] = 0.0f;
		}
		for (int l63 = 0; l63 < 2; l63 = l63 + 1) {
			fVec26[l63] = 0.0f;
		}
		for (int l64 = 0; l64 < 2; l64 = l64 + 1) {
			fRec49[l64] = 0.0f;
		}
		for (int l65 = 0; l65 < 16384; l65 = l65 + 1) {
			fVec27[l65] = 0.0f;
		}
		for (int l66 = 0; l66 < 2; l66 = l66 + 1) {
			fVec28[l66] = 0.0f;
		}
		for (int l67 = 0; l67 < 2; l67 = l67 + 1) {
			fRec47[l67] = 0.0f;
		}
		for (int l68 = 0; l68 < 2; l68 = l68 + 1) {
			fRec45[l68] = 0.0f;
		}
		for (int l69 = 0; l69 < 2; l69 = l69 + 1) {
			fRec52[l69] = 0.0f;
		}
		for (int l70 = 0; l70 < 16384; l70 = l70 + 1) {
			fVec29[l70] = 0.0f;
		}
		for (int l71 = 0; l71 < 2; l71 = l71 + 1) {
			fVec30[l71] = 0.0f;
		}
		for (int l72 = 0; l72 < 2; l72 = l72 + 1) {
			fRec51[l72] = 0.0f;
		}
		for (int l73 = 0; l73 < 2; l73 = l73 + 1) {
			fRec46[l73] = 0.0f;
		}
		for (int l74 = 0; l74 < 2; l74 = l74 + 1) {
			fRec56[l74] = 0.0f;
		}
		for (int l75 = 0; l75 < 16384; l75 = l75 + 1) {
			fVec31[l75] = 0.0f;
		}
		for (int l76 = 0; l76 < 2; l76 = l76 + 1) {
			fVec32[l76] = 0.0f;
		}
		for (int l77 = 0; l77 < 2; l77 = l77 + 1) {
			fRec55[l77] = 0.0f;
		}
		for (int l78 = 0; l78 < 2; l78 = l78 + 1) {
			fRec53[l78] = 0.0f;
		}
		for (int l79 = 0; l79 < 2; l79 = l79 + 1) {
			fRec58[l79] = 0.0f;
		}
		for (int l80 = 0; l80 < 16384; l80 = l80 + 1) {
			fVec33[l80] = 0.0f;
		}
		for (int l81 = 0; l81 < 2; l81 = l81 + 1) {
			fVec34[l81] = 0.0f;
		}
		for (int l82 = 0; l82 < 2; l82 = l82 + 1) {
			fRec57[l82] = 0.0f;
		}
		for (int l83 = 0; l83 < 2; l83 = l83 + 1) {
			fRec54[l83] = 0.0f;
		}
		for (int l84 = 0; l84 < 2; l84 = l84 + 1) {
			fRec62[l84] = 0.0f;
		}
		for (int l85 = 0; l85 < 16384; l85 = l85 + 1) {
			fVec35[l85] = 0.0f;
		}
		for (int l86 = 0; l86 < 2; l86 = l86 + 1) {
			fVec36[l86] = 0.0f;
		}
		for (int l87 = 0; l87 < 2; l87 = l87 + 1) {
			fRec61[l87] = 0.0f;
		}
		for (int l88 = 0; l88 < 2; l88 = l88 + 1) {
			fRec59[l88] = 0.0f;
		}
		for (int l89 = 0; l89 < 2; l89 = l89 + 1) {
			fRec64[l89] = 0.0f;
		}
		for (int l90 = 0; l90 < 16384; l90 = l90 + 1) {
			fVec37[l90] = 0.0f;
		}
		for (int l91 = 0; l91 < 2; l91 = l91 + 1) {
			fVec38[l91] = 0.0f;
		}
		for (int l92 = 0; l92 < 2; l92 = l92 + 1) {
			fRec63[l92] = 0.0f;
		}
		for (int l93 = 0; l93 < 2; l93 = l93 + 1) {
			fRec60[l93] = 0.0f;
		}
		for (int l94 = 0; l94 < 2; l94 = l94 + 1) {
			fRec68[l94] = 0.0f;
		}
		for (int l95 = 0; l95 < 16384; l95 = l95 + 1) {
			fVec39[l95] = 0.0f;
		}
		for (int l96 = 0; l96 < 2; l96 = l96 + 1) {
			fVec40[l96] = 0.0f;
		}
		for (int l97 = 0; l97 < 2; l97 = l97 + 1) {
			fRec67[l97] = 0.0f;
		}
		for (int l98 = 0; l98 < 2; l98 = l98 + 1) {
			fRec65[l98] = 0.0f;
		}
		for (int l99 = 0; l99 < 2; l99 = l99 + 1) {
			fRec70[l99] = 0.0f;
		}
		for (int l100 = 0; l100 < 16384; l100 = l100 + 1) {
			fVec41[l100] = 0.0f;
		}
		for (int l101 = 0; l101 < 2; l101 = l101 + 1) {
			fVec42[l101] = 0.0f;
		}
		for (int l102 = 0; l102 < 2; l102 = l102 + 1) {
			fRec69[l102] = 0.0f;
		}
		for (int l103 = 0; l103 < 2; l103 = l103 + 1) {
			fRec66[l103] = 0.0f;
		}
		for (int l104 = 0; l104 < 2; l104 = l104 + 1) {
			fRec74[l104] = 0.0f;
		}
		for (int l105 = 0; l105 < 16384; l105 = l105 + 1) {
			fVec43[l105] = 0.0f;
		}
		for (int l106 = 0; l106 < 2; l106 = l106 + 1) {
			fVec44[l106] = 0.0f;
		}
		for (int l107 = 0; l107 < 2; l107 = l107 + 1) {
			fRec73[l107] = 0.0f;
		}
		for (int l108 = 0; l108 < 2; l108 = l108 + 1) {
			fRec71[l108] = 0.0f;
		}
		for (int l109 = 0; l109 < 2; l109 = l109 + 1) {
			fRec76[l109] = 0.0f;
		}
		for (int l110 = 0; l110 < 16384; l110 = l110 + 1) {
			fVec45[l110] = 0.0f;
		}
		for (int l111 = 0; l111 < 2; l111 = l111 + 1) {
			fVec46[l111] = 0.0f;
		}
		for (int l112 = 0; l112 < 2; l112 = l112 + 1) {
			fRec75[l112] = 0.0f;
		}
		for (int l113 = 0; l113 < 2; l113 = l113 + 1) {
			fRec72[l113] = 0.0f;
		}
		for (int l114 = 0; l114 < 16384; l114 = l114 + 1) {
			fVec47[l114] = 0.0f;
		}
		for (int l115 = 0; l115 < 16384; l115 = l115 + 1) {
			fVec48[l115] = 0.0f;
		}
		for (int l116 = 0; l116 < 2; l116 = l116 + 1) {
			fVec49[l116] = 0.0f;
		}
		for (int l117 = 0; l117 < 2; l117 = l117 + 1) {
			fRec9[l117] = 0.0f;
		}
		for (int l118 = 0; l118 < 2; l118 = l118 + 1) {
			fRec8[l118] = 0.0f;
		}
		for (int l119 = 0; l119 < 3; l119 = l119 + 1) {
			fRec7[l119] = 0.0f;
		}
		for (int l120 = 0; l120 < 3; l120 = l120 + 1) {
			fRec6[l120] = 0.0f;
		}
		for (int l121 = 0; l121 < 2; l121 = l121 + 1) {
			fVec50[l121] = 0.0f;
		}
		for (int l122 = 0; l122 < 2; l122 = l122 + 1) {
			fRec5[l122] = 0.0f;
		}
		for (int l123 = 0; l123 < 3; l123 = l123 + 1) {
			fRec4[l123] = 0.0f;
		}
		for (int l124 = 0; l124 < 3; l124 = l124 + 1) {
			fRec3[l124] = 0.0f;
		}
		for (int l125 = 0; l125 < 2; l125 = l125 + 1) {
			fRec79[l125] = 0.0f;
		}
		for (int l126 = 0; l126 < 3; l126 = l126 + 1) {
			fRec78[l126] = 0.0f;
		}
		for (int l127 = 0; l127 < 3; l127 = l127 + 1) {
			fRec77[l127] = 0.0f;
		}
		for (int l128 = 0; l128 < 2; l128 = l128 + 1) {
			fRec83[l128] = 0.0f;
		}
		for (int l129 = 0; l129 < 3; l129 = l129 + 1) {
			fRec82[l129] = 0.0f;
		}
		for (int l130 = 0; l130 < 3; l130 = l130 + 1) {
			fRec81[l130] = 0.0f;
		}
		for (int l131 = 0; l131 < 3; l131 = l131 + 1) {
			fRec80[l131] = 0.0f;
		}
		for (int l132 = 0; l132 < 1024; l132 = l132 + 1) {
			fVec51[l132] = 0.0f;
		}
		for (int l133 = 0; l133 < 2; l133 = l133 + 1) {
			fRec2[l133] = 0.0f;
		}
		for (int l134 = 0; l134 < 2; l134 = l134 + 1) {
			fRec95[l134] = 0.0f;
		}
		for (int l135 = 0; l135 < 16384; l135 = l135 + 1) {
			fVec52[l135] = 0.0f;
		}
		for (int l136 = 0; l136 < 16384; l136 = l136 + 1) {
			fVec53[l136] = 0.0f;
		}
		for (int l137 = 0; l137 < 2; l137 = l137 + 1) {
			fVec54[l137] = 0.0f;
		}
		for (int l138 = 0; l138 < 2; l138 = l138 + 1) {
			fRec94[l138] = 0.0f;
		}
		for (int l139 = 0; l139 < 2; l139 = l139 + 1) {
			fRec93[l139] = 0.0f;
		}
		for (int l140 = 0; l140 < 3; l140 = l140 + 1) {
			fRec92[l140] = 0.0f;
		}
		for (int l141 = 0; l141 < 3; l141 = l141 + 1) {
			fRec91[l141] = 0.0f;
		}
		for (int l142 = 0; l142 < 2; l142 = l142 + 1) {
			fVec55[l142] = 0.0f;
		}
		for (int l143 = 0; l143 < 2; l143 = l143 + 1) {
			fRec90[l143] = 0.0f;
		}
		for (int l144 = 0; l144 < 3; l144 = l144 + 1) {
			fRec89[l144] = 0.0f;
		}
		for (int l145 = 0; l145 < 3; l145 = l145 + 1) {
			fRec88[l145] = 0.0f;
		}
		for (int l146 = 0; l146 < 2; l146 = l146 + 1) {
			fRec98[l146] = 0.0f;
		}
		for (int l147 = 0; l147 < 3; l147 = l147 + 1) {
			fRec97[l147] = 0.0f;
		}
		for (int l148 = 0; l148 < 3; l148 = l148 + 1) {
			fRec96[l148] = 0.0f;
		}
		for (int l149 = 0; l149 < 2; l149 = l149 + 1) {
			fRec102[l149] = 0.0f;
		}
		for (int l150 = 0; l150 < 3; l150 = l150 + 1) {
			fRec101[l150] = 0.0f;
		}
		for (int l151 = 0; l151 < 3; l151 = l151 + 1) {
			fRec100[l151] = 0.0f;
		}
		for (int l152 = 0; l152 < 3; l152 = l152 + 1) {
			fRec99[l152] = 0.0f;
		}
		for (int l153 = 0; l153 < 1024; l153 = l153 + 1) {
			fVec56[l153] = 0.0f;
		}
		for (int l154 = 0; l154 < 2; l154 = l154 + 1) {
			fRec87[l154] = 0.0f;
		}
		for (int l155 = 0; l155 < 16384; l155 = l155 + 1) {
			fVec57[l155] = 0.0f;
		}
		for (int l156 = 0; l156 < 2; l156 = l156 + 1) {
			fVec58[l156] = 0.0f;
		}
		for (int l157 = 0; l157 < 2; l157 = l157 + 1) {
			fRec86[l157] = 0.0f;
		}
		for (int l158 = 0; l158 < 2; l158 = l158 + 1) {
			fRec84[l158] = 0.0f;
		}
		for (int l159 = 0; l159 < 2; l159 = l159 + 1) {
			fRec104[l159] = 0.0f;
		}
		for (int l160 = 0; l160 < 16384; l160 = l160 + 1) {
			fVec59[l160] = 0.0f;
		}
		for (int l161 = 0; l161 < 2; l161 = l161 + 1) {
			fVec60[l161] = 0.0f;
		}
		for (int l162 = 0; l162 < 2; l162 = l162 + 1) {
			fRec103[l162] = 0.0f;
		}
		for (int l163 = 0; l163 < 2; l163 = l163 + 1) {
			fRec85[l163] = 0.0f;
		}
		for (int l164 = 0; l164 < 16384; l164 = l164 + 1) {
			fVec61[l164] = 0.0f;
		}
		for (int l165 = 0; l165 < 2; l165 = l165 + 1) {
			fVec62[l165] = 0.0f;
		}
		for (int l166 = 0; l166 < 2; l166 = l166 + 1) {
			fRec107[l166] = 0.0f;
		}
		for (int l167 = 0; l167 < 2; l167 = l167 + 1) {
			fRec105[l167] = 0.0f;
		}
		for (int l168 = 0; l168 < 16384; l168 = l168 + 1) {
			fVec63[l168] = 0.0f;
		}
		for (int l169 = 0; l169 < 2; l169 = l169 + 1) {
			fVec64[l169] = 0.0f;
		}
		for (int l170 = 0; l170 < 2; l170 = l170 + 1) {
			fRec108[l170] = 0.0f;
		}
		for (int l171 = 0; l171 < 2; l171 = l171 + 1) {
			fRec106[l171] = 0.0f;
		}
		for (int l172 = 0; l172 < 16384; l172 = l172 + 1) {
			fVec65[l172] = 0.0f;
		}
		for (int l173 = 0; l173 < 2; l173 = l173 + 1) {
			fVec66[l173] = 0.0f;
		}
		for (int l174 = 0; l174 < 2; l174 = l174 + 1) {
			fRec111[l174] = 0.0f;
		}
		for (int l175 = 0; l175 < 2; l175 = l175 + 1) {
			fRec109[l175] = 0.0f;
		}
		for (int l176 = 0; l176 < 2; l176 = l176 + 1) {
			fRec113[l176] = 0.0f;
		}
		for (int l177 = 0; l177 < 16384; l177 = l177 + 1) {
			fVec67[l177] = 0.0f;
		}
		for (int l178 = 0; l178 < 2; l178 = l178 + 1) {
			fVec68[l178] = 0.0f;
		}
		for (int l179 = 0; l179 < 2; l179 = l179 + 1) {
			fRec112[l179] = 0.0f;
		}
		for (int l180 = 0; l180 < 2; l180 = l180 + 1) {
			fRec110[l180] = 0.0f;
		}
		for (int l181 = 0; l181 < 2; l181 = l181 + 1) {
			fRec117[l181] = 0.0f;
		}
		for (int l182 = 0; l182 < 16384; l182 = l182 + 1) {
			fVec69[l182] = 0.0f;
		}
		for (int l183 = 0; l183 < 2; l183 = l183 + 1) {
			fVec70[l183] = 0.0f;
		}
		for (int l184 = 0; l184 < 2; l184 = l184 + 1) {
			fRec116[l184] = 0.0f;
		}
		for (int l185 = 0; l185 < 2; l185 = l185 + 1) {
			fRec114[l185] = 0.0f;
		}
		for (int l186 = 0; l186 < 16384; l186 = l186 + 1) {
			fVec71[l186] = 0.0f;
		}
		for (int l187 = 0; l187 < 2; l187 = l187 + 1) {
			fVec72[l187] = 0.0f;
		}
		for (int l188 = 0; l188 < 2; l188 = l188 + 1) {
			fRec118[l188] = 0.0f;
		}
		for (int l189 = 0; l189 < 2; l189 = l189 + 1) {
			fRec115[l189] = 0.0f;
		}
		for (int l190 = 0; l190 < 2; l190 = l190 + 1) {
			fRec0[l190] = 0.0f;
		}
		for (int l191 = 0; l191 < 2; l191 = l191 + 1) {
			fRec1[l191] = 0.0f;
		}
	}
	
	FAUSTPP_VIRTUAL void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	
	FAUSTPP_VIRTUAL void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	FAUSTPP_VIRTUAL mydsp* clone() {
		return new mydsp();
	}
	
	FAUSTPP_VIRTUAL int getSampleRate() {
		return fSampleRate;
	}
	
	FAUSTPP_VIRTUAL void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("DFJPverb");
		ui_interface->declare(0, "0", "");
		ui_interface->openVerticalBox("JP Verb");
		ui_interface->declare(0, "0", "");
		ui_interface->openHorizontalBox("Mix");
		ui_interface->declare(&fHslider10, "1", "");
		ui_interface->declare(&fHslider10, "style", "knob");
		ui_interface->declare(&fHslider10, "symbol", "t60");
		ui_interface->addHorizontalSlider("Time (T60)", &fHslider10, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.1f), FAUSTFLOAT(6e+01f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider4, "2", "");
		ui_interface->declare(&fHslider4, "style", "knob");
		ui_interface->declare(&fHslider4, "symbol", "size");
		ui_interface->addHorizontalSlider("Size", &fHslider4, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.5f), FAUSTFLOAT(5.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider1, "3", "");
		ui_interface->declare(&fHslider1, "style", "knob");
		ui_interface->declare(&fHslider1, "symbol", "damp");
		ui_interface->addHorizontalSlider("Hi-Freq Damping", &fHslider1, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.999f), FAUSTFLOAT(0.0001f));
		ui_interface->declare(&fHslider11, "4", "");
		ui_interface->declare(&fHslider11, "style", "knob");
		ui_interface->declare(&fHslider11, "symbol", "early_diff");
		ui_interface->addHorizontalSlider("Early Reflections Shape", &fHslider11, FAUSTFLOAT(0.70710677f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.99f), FAUSTFLOAT(0.001f));
		ui_interface->closeBox();
		ui_interface->declare(0, "1", "");
		ui_interface->openHorizontalBox("EQ");
		ui_interface->declare(&fHslider2, "1", "");
		ui_interface->declare(&fHslider2, "scale", "log");
		ui_interface->declare(&fHslider2, "style", "knob");
		ui_interface->declare(&fHslider2, "symbol", "low_cutoff");
		ui_interface->declare(&fHslider2, "unit", "Hz");
		ui_interface->addHorizontalSlider("Low/Mid-Band Crossover Frequency", &fHslider2, FAUSTFLOAT(5e+02f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(6e+03f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider3, "2", "");
		ui_interface->declare(&fHslider3, "scale", "log");
		ui_interface->declare(&fHslider3, "style", "knob");
		ui_interface->declare(&fHslider3, "symbol", "high_cutoff");
		ui_interface->declare(&fHslider3, "unit", "Hz");
		ui_interface->addHorizontalSlider("Mid/High-Band Crossover Frequency", &fHslider3, FAUSTFLOAT(2e+03f), FAUSTFLOAT(1e+03f), FAUSTFLOAT(1e+04f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider7, "3", "");
		ui_interface->declare(&fHslider7, "style", "knob");
		ui_interface->declare(&fHslider7, "symbol", "low");
		ui_interface->addHorizontalSlider("Low-Band Multiplier", &fHslider7, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider8, "4", "");
		ui_interface->declare(&fHslider8, "style", "knob");
		ui_interface->declare(&fHslider8, "symbol", "mid");
		ui_interface->addHorizontalSlider("Mid-Band Multiplier", &fHslider8, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider9, "5", "");
		ui_interface->declare(&fHslider9, "style", "knob");
		ui_interface->declare(&fHslider9, "symbol", "high");
		ui_interface->addHorizontalSlider("High-Band Multiplier", &fHslider9, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("Modulation");
		ui_interface->declare(&fHslider6, "1", "");
		ui_interface->declare(&fHslider6, "style", "knob");
		ui_interface->declare(&fHslider6, "symbol", "mod_depth");
		ui_interface->addHorizontalSlider("Modulation Depth", &fHslider6, FAUSTFLOAT(0.1f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider5, "2", "");
		ui_interface->declare(&fHslider5, "style", "knob");
		ui_interface->declare(&fHslider5, "symbol", "mod_freq");
		ui_interface->declare(&fHslider5, "unit", "Hz");
		ui_interface->addHorizontalSlider("Modulation Frequency", &fHslider5, FAUSTFLOAT(2.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->declare(0, "4", "");
		ui_interface->openHorizontalBox("Output");
		ui_interface->declare(&fHslider0, "1", "");
		ui_interface->declare(&fHslider0, "abbrev", "Dry");
		ui_interface->declare(&fHslider0, "style", "knob");
		ui_interface->declare(&fHslider0, "symbol", "dry");
		ui_interface->declare(&fHslider0, "unit", "dB");
		ui_interface->addHorizontalSlider("Dry Gain", &fHslider0, FAUSTFLOAT(0.0f), FAUSTFLOAT(-9e+01f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider12, "2", "");
		ui_interface->declare(&fHslider12, "abbrev", "Wet");
		ui_interface->declare(&fHslider12, "style", "knob");
		ui_interface->declare(&fHslider12, "symbol", "wet");
		ui_interface->declare(&fHslider12, "unit", "dB");
		ui_interface->addHorizontalSlider("Wet Gain", &fHslider12, FAUSTFLOAT(-12.0f), FAUSTFLOAT(-9e+01f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->closeBox();
	}
	
	FAUSTPP_VIRTUAL void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = std::pow(1e+01f, 0.05f * float(fHslider0));
		float fSlow1 = float(fHslider1);
		float fSlow2 = std::tan(fConst1 * float(fHslider2));
		float fSlow3 = mydsp_faustpower2_f(fSlow2);
		float fSlow4 = 2.0f * (1.0f - 1.0f / fSlow3);
		float fSlow5 = 1.0f / fSlow2;
		float fSlow6 = (fSlow5 + -0.618034f) / fSlow2 + 1.0f;
		float fSlow7 = 1.0f / ((fSlow5 + 0.618034f) / fSlow2 + 1.0f);
		float fSlow8 = (fSlow5 + -1.618034f) / fSlow2 + 1.0f;
		float fSlow9 = (fSlow5 + 1.618034f) / fSlow2 + 1.0f;
		float fSlow10 = 1.0f / fSlow9;
		float fSlow11 = std::tan(fConst1 * float(fHslider3));
		float fSlow12 = mydsp_faustpower2_f(fSlow11);
		float fSlow13 = 2.0f * (1.0f - 1.0f / fSlow12);
		float fSlow14 = 1.0f / fSlow11;
		float fSlow15 = (fSlow14 + -0.618034f) / fSlow11 + 1.0f;
		float fSlow16 = (fSlow14 + 0.618034f) / fSlow11 + 1.0f;
		float fSlow17 = 1.0f / fSlow16;
		float fSlow18 = (fSlow14 + -1.618034f) / fSlow11 + 1.0f;
		float fSlow19 = (fSlow14 + 1.618034f) / fSlow11 + 1.0f;
		float fSlow20 = 1.0f / fSlow19;
		float fSlow21 = float(fHslider4);
		int iSlow22 = itbl0mydspSIG0[int(134.0f * fSlow21)];
		float fSlow23 = 0.005f * float(iSlow22);
		int iSlow24 = itbl0mydspSIG0[int(54.0f * fSlow21)];
		float fSlow25 = 0.005f * float(iSlow24);
		int iSlow26 = itbl0mydspSIG0[int(1e+01f * fSlow21)];
		float fSlow27 = 0.0001f * float(iSlow26);
		int iSlow28 = itbl0mydspSIG0[int(1.1e+02f * fSlow21)];
		float fSlow29 = 0.0001f * float(iSlow28);
		int iSlow30 = itbl0mydspSIG0[int(4e+01f * fSlow21)];
		float fSlow31 = 0.0001f * float(iSlow30);
		int iSlow32 = itbl0mydspSIG0[int(1.4e+02f * fSlow21)];
		float fSlow33 = 0.0001f * float(iSlow32);
		int iSlow34 = itbl0mydspSIG0[int(7e+01f * fSlow21)];
		float fSlow35 = 0.0001f * float(iSlow34);
		int iSlow36 = itbl0mydspSIG0[int(1.7e+02f * fSlow21)];
		float fSlow37 = 0.0001f * float(iSlow36);
		int iSlow38 = itbl0mydspSIG0[int(1e+02f * fSlow21)];
		float fSlow39 = 0.0001f * float(iSlow38);
		int iSlow40 = itbl0mydspSIG0[int(2e+02f * fSlow21)];
		float fSlow41 = 0.0001f * float(iSlow40);
		int iSlow42 = itbl0mydspSIG0[int(1.3e+02f * fSlow21)];
		float fSlow43 = 0.0001f * float(iSlow42);
		int iSlow44 = itbl0mydspSIG0[int(2.3e+02f * fSlow21)];
		float fSlow45 = 0.0001f * float(iSlow44);
		float fSlow46 = fConst2 * float(fHslider5);
		float fSlow47 = std::cos(fSlow46);
		float fSlow48 = std::sin(fSlow46);
		float fSlow49 = 5e+01f * float(fHslider6);
		int iSlow50 = itbl0mydspSIG0[int(125.0f * fSlow21)];
		float fSlow51 = 0.0001f * float(iSlow50);
		int iSlow52 = itbl0mydspSIG0[int(204.0f * fSlow21)];
		float fSlow53 = 0.005f * float(iSlow52);
		int iSlow54 = itbl0mydspSIG0[int(25.0f * fSlow21)];
		float fSlow55 = 0.0001f * float(iSlow54);
		int iSlow56 = itbl0mydspSIG0[int(155.0f * fSlow21)];
		float fSlow57 = 0.0001f * float(iSlow56);
		int iSlow58 = itbl0mydspSIG0[int(55.0f * fSlow21)];
		float fSlow59 = 0.0001f * float(iSlow58);
		int iSlow60 = itbl0mydspSIG0[int(185.0f * fSlow21)];
		float fSlow61 = 0.0001f * float(iSlow60);
		int iSlow62 = itbl0mydspSIG0[int(85.0f * fSlow21)];
		float fSlow63 = 0.0001f * float(iSlow62);
		int iSlow64 = itbl0mydspSIG0[int(215.0f * fSlow21)];
		float fSlow65 = 0.0001f * float(iSlow64);
		int iSlow66 = itbl0mydspSIG0[int(115.0f * fSlow21)];
		float fSlow67 = 0.0001f * float(iSlow66);
		int iSlow68 = itbl0mydspSIG0[int(245.0f * fSlow21)];
		float fSlow69 = 0.0001f * float(iSlow68);
		int iSlow70 = itbl0mydspSIG0[int(145.0f * fSlow21)];
		float fSlow71 = 0.0001f * float(iSlow70);
		float fSlow72 = 1.0f - fSlow14;
		float fSlow73 = 1.0f / (fSlow14 + 1.0f);
		float fSlow74 = 1.0f - fSlow5;
		float fSlow75 = 1.0f / (fSlow5 + 1.0f);
		float fSlow76 = float(fHslider7);
		float fSlow77 = 1.0f / (fSlow3 * fSlow9);
		float fSlow78 = float(fHslider8) / fSlow3;
		float fSlow79 = (fSlow5 + -1.618034f) / fSlow2 + 1.0f;
		float fSlow80 = 1.0f / ((fSlow5 + 1.618034f) / fSlow2 + 1.0f);
		float fSlow81 = 1.0f / (fSlow12 * fSlow19);
		float fSlow82 = 1.0f / (fSlow12 * fSlow16);
		float fSlow83 = float(fHslider9);
		float fSlow84 = std::pow(1e+01f, -(0.51f * ((1.25f * fSlow21 + -0.25f) / float(fHslider10))));
		float fSlow85 = 1.0f - fSlow1;
		float fSlow86 = float(fHslider11);
		float fSlow87 = std::sin(fSlow86);
		int iSlow88 = itbl0mydspSIG0[int(34.0f * fSlow21)];
		float fSlow89 = 0.005f * float(iSlow88);
		float fSlow90 = std::cos(fSlow86);
		int iSlow91 = itbl0mydspSIG0[int(2.4e+02f * fSlow21)];
		float fSlow92 = 0.0001f * float(iSlow91);
		int iSlow93 = itbl0mydspSIG0[int(1.9e+02f * fSlow21)];
		float fSlow94 = 0.0001f * float(iSlow93);
		int iSlow95 = itbl0mydspSIG0[int(175.0f * fSlow21)];
		float fSlow96 = 0.0001f * float(iSlow95);
		float fSlow97 = std::pow(1e+01f, 0.05f * float(fHslider12));
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			float fTemp0 = float(input0[i0]);
			iVec0[0] = 1;
			int iTemp1 = 1 - iVec0[1];
			fRec10[0] = 0.995f * (fRec10[1] + float(iSlow22 * iTemp1)) + fSlow23;
			float fTemp2 = fRec10[0] + -1.49999f;
			float fTemp3 = std::floor(fTemp2);
			fRec12[0] = 0.995f * (fRec12[1] + float(iSlow24 * iTemp1)) + fSlow25;
			float fTemp4 = fRec12[0] + -1.49999f;
			float fTemp5 = std::floor(fTemp4);
			fRec16[0] = 0.9999f * (fRec16[1] + float(iSlow26 * iTemp1)) + fSlow27;
			float fTemp6 = fRec16[0] + -1.49999f;
			float fTemp7 = std::floor(fTemp6);
			float fTemp8 = 0.7602446f * fRec1[1];
			float fTemp9 = 0.6496369f * fRec14[1];
			float fTemp10 = 0.7602446f * fRec0[1] - 0.6496369f * fRec13[1];
			fVec1[IOTA0 & 16383] = 0.70710677f * fTemp10 + 0.70710677f * (fTemp9 - fTemp8);
			float fTemp11 = fVec1[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp6)))) & 16383];
			fVec2[0] = fTemp11;
			fRec15[0] = fVec2[1] - (fTemp7 + (2.0f - fRec16[0])) * (fRec15[1] - fTemp11) / (fRec16[0] - fTemp7);
			fRec13[0] = fRec15[0];
			fRec18[0] = 0.9999f * (fRec18[1] + float(iSlow28 * iTemp1)) + fSlow29;
			float fTemp12 = fRec18[0] + -1.49999f;
			float fTemp13 = std::floor(fTemp12);
			fVec3[IOTA0 & 16383] = 0.70710677f * fTemp10 + 0.70710677f * (fTemp8 - fTemp9);
			float fTemp14 = fVec3[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp12)))) & 16383];
			fVec4[0] = fTemp14;
			fRec17[0] = fVec4[1] - (fTemp13 + (2.0f - fRec18[0])) * (fRec17[1] - fTemp14) / (fRec18[0] - fTemp13);
			fRec14[0] = fRec17[0];
			float fTemp15 = 0.7602446f * fRec13[1] + 0.6496369f * fRec0[1];
			fRec22[0] = 0.9999f * (fRec22[1] + float(iSlow30 * iTemp1)) + fSlow31;
			float fTemp16 = fRec22[0] + -1.49999f;
			float fTemp17 = std::floor(fTemp16);
			float fTemp18 = 0.7602446f * fRec14[1] + 0.6496369f * fRec1[1];
			float fTemp19 = 0.7602446f * fTemp18;
			float fTemp20 = 0.6496369f * fRec20[1];
			float fTemp21 = 0.7602446f * fTemp15 - 0.6496369f * fRec19[1];
			fVec5[IOTA0 & 16383] = 0.70710677f * fTemp21 + 0.70710677f * (fTemp20 - fTemp19);
			float fTemp22 = fVec5[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp16)))) & 16383];
			fVec6[0] = fTemp22;
			fRec21[0] = fVec6[1] - (fTemp17 + (2.0f - fRec22[0])) * (fRec21[1] - fTemp22) / (fRec22[0] - fTemp17);
			fRec19[0] = fRec21[0];
			fRec24[0] = 0.9999f * (fRec24[1] + float(iSlow32 * iTemp1)) + fSlow33;
			float fTemp23 = fRec24[0] + -1.49999f;
			float fTemp24 = std::floor(fTemp23);
			fVec7[IOTA0 & 16383] = 0.70710677f * fTemp21 + 0.70710677f * (fTemp19 - fTemp20);
			float fTemp25 = fVec7[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp23)))) & 16383];
			fVec8[0] = fTemp25;
			fRec23[0] = fVec8[1] - (fTemp24 + (2.0f - fRec24[0])) * (fRec23[1] - fTemp25) / (fRec24[0] - fTemp24);
			fRec20[0] = fRec23[0];
			float fTemp26 = 0.7602446f * fRec19[1] + 0.6496369f * fTemp15;
			fRec28[0] = 0.9999f * (fRec28[1] + float(iSlow34 * iTemp1)) + fSlow35;
			float fTemp27 = fRec28[0] + -1.49999f;
			float fTemp28 = std::floor(fTemp27);
			float fTemp29 = 0.7602446f * fRec20[1] + 0.6496369f * fTemp18;
			float fTemp30 = 0.7602446f * fTemp29;
			float fTemp31 = 0.6496369f * fRec26[1];
			float fTemp32 = 0.7602446f * fTemp26 - 0.6496369f * fRec25[1];
			fVec9[IOTA0 & 16383] = 0.70710677f * fTemp32 + 0.70710677f * (fTemp31 - fTemp30);
			float fTemp33 = fVec9[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp27)))) & 16383];
			fVec10[0] = fTemp33;
			fRec27[0] = fVec10[1] - (fTemp28 + (2.0f - fRec28[0])) * (fRec27[1] - fTemp33) / (fRec28[0] - fTemp28);
			fRec25[0] = fRec27[0];
			fRec30[0] = 0.9999f * (fRec30[1] + float(iSlow36 * iTemp1)) + fSlow37;
			float fTemp34 = fRec30[0] + -1.49999f;
			float fTemp35 = std::floor(fTemp34);
			fVec11[IOTA0 & 16383] = 0.70710677f * fTemp32 + 0.70710677f * (fTemp30 - fTemp31);
			float fTemp36 = fVec11[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp34)))) & 16383];
			fVec12[0] = fTemp36;
			fRec29[0] = fVec12[1] - (fTemp35 + (2.0f - fRec30[0])) * (fRec29[1] - fTemp36) / (fRec30[0] - fTemp35);
			fRec26[0] = fRec29[0];
			float fTemp37 = 0.7602446f * fRec25[1] + 0.6496369f * fTemp26;
			fRec34[0] = 0.9999f * (fRec34[1] + float(iSlow38 * iTemp1)) + fSlow39;
			float fTemp38 = fRec34[0] + -1.49999f;
			float fTemp39 = std::floor(fTemp38);
			float fTemp40 = 0.7602446f * fRec26[1] + 0.6496369f * fTemp29;
			float fTemp41 = 0.7602446f * fTemp40;
			float fTemp42 = 0.6496369f * fRec32[1];
			float fTemp43 = 0.7602446f * fTemp37 - 0.6496369f * fRec31[1];
			fVec13[IOTA0 & 16383] = 0.70710677f * fTemp43 + 0.70710677f * (fTemp42 - fTemp41);
			float fTemp44 = fVec13[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp38)))) & 16383];
			fVec14[0] = fTemp44;
			fRec33[0] = fVec14[1] - (fTemp39 + (2.0f - fRec34[0])) * (fRec33[1] - fTemp44) / (fRec34[0] - fTemp39);
			fRec31[0] = fRec33[0];
			fRec36[0] = 0.9999f * (fRec36[1] + float(iSlow40 * iTemp1)) + fSlow41;
			float fTemp45 = fRec36[0] + -1.49999f;
			float fTemp46 = std::floor(fTemp45);
			fVec15[IOTA0 & 16383] = 0.70710677f * fTemp43 + 0.70710677f * (fTemp41 - fTemp42);
			float fTemp47 = fVec15[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp45)))) & 16383];
			fVec16[0] = fTemp47;
			fRec35[0] = fVec16[1] - (fTemp46 + (2.0f - fRec36[0])) * (fRec35[1] - fTemp47) / (fRec36[0] - fTemp46);
			fRec32[0] = fRec35[0];
			float fTemp48 = 0.7602446f * fRec31[1] + 0.6496369f * fTemp37;
			fRec40[0] = 0.9999f * (fRec40[1] + float(iSlow42 * iTemp1)) + fSlow43;
			float fTemp49 = fRec40[0] + -1.49999f;
			float fTemp50 = std::floor(fTemp49);
			float fTemp51 = 0.7602446f * fRec32[1] + 0.6496369f * fTemp40;
			float fTemp52 = 0.7602446f * fTemp51;
			float fTemp53 = 0.6496369f * fRec38[1];
			float fTemp54 = 0.7602446f * fTemp48 - 0.6496369f * fRec37[1];
			fVec17[IOTA0 & 16383] = 0.70710677f * fTemp54 + 0.70710677f * (fTemp53 - fTemp52);
			float fTemp55 = fVec17[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp49)))) & 16383];
			fVec18[0] = fTemp55;
			fRec39[0] = fVec18[1] - (fTemp50 + (2.0f - fRec40[0])) * (fRec39[1] - fTemp55) / (fRec40[0] - fTemp50);
			fRec37[0] = fRec39[0];
			fRec42[0] = 0.9999f * (fRec42[1] + float(iSlow44 * iTemp1)) + fSlow45;
			float fTemp56 = fRec42[0] + -1.49999f;
			float fTemp57 = std::floor(fTemp56);
			fVec19[IOTA0 & 16383] = 0.70710677f * fTemp54 + 0.70710677f * (fTemp52 - fTemp53);
			float fTemp58 = fVec19[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp56)))) & 16383];
			fVec20[0] = fTemp58;
			fRec41[0] = fVec20[1] - (fTemp57 + (2.0f - fRec42[0])) * (fRec41[1] - fTemp58) / (fRec42[0] - fTemp57);
			fRec38[0] = fRec41[0];
			float fTemp59 = 0.7602446f * fRec37[1] + 0.6496369f * fTemp48;
			fVec21[IOTA0 & 1023] = fTemp59;
			fRec43[0] = fSlow48 * fRec44[1] + fSlow47 * fRec43[1];
			fRec44[0] = float(iTemp1) + fSlow47 * fRec44[1] - fSlow48 * fRec43[1];
			float fTemp60 = fSlow49 * (fRec44[0] + 1.0f);
			float fTemp61 = fTemp60 + 3.500005f;
			int iTemp62 = int(fTemp61);
			int iTemp63 = std::min<int>(512, std::max<int>(0, iTemp62 + 4));
			float fTemp64 = std::floor(fTemp61);
			float fTemp65 = fTemp60 + (2.0f - fTemp64);
			float fTemp66 = fTemp60 + (3.0f - fTemp64);
			float fTemp67 = fTemp60 + (4.0f - fTemp64);
			float fTemp68 = fTemp60 + (5.0f - fTemp64);
			float fTemp69 = fTemp68 * fTemp67;
			float fTemp70 = fTemp69 * fTemp66;
			float fTemp71 = fTemp70 * fTemp65;
			int iTemp72 = std::min<int>(512, std::max<int>(0, iTemp62 + 3));
			int iTemp73 = std::min<int>(512, std::max<int>(0, iTemp62 + 2));
			int iTemp74 = std::min<int>(512, std::max<int>(0, iTemp62 + 1));
			int iTemp75 = std::min<int>(512, std::max<int>(0, iTemp62));
			float fTemp76 = fTemp60 + (1.0f - fTemp64);
			fVec22[IOTA0 & 16383] = fTemp76 * (fTemp65 * (fTemp66 * (0.041666668f * fVec21[(IOTA0 - iTemp75) & 1023] * fTemp67 - 0.16666667f * fTemp68 * fVec21[(IOTA0 - iTemp74) & 1023]) + 0.25f * fTemp69 * fVec21[(IOTA0 - iTemp73) & 1023]) - 0.16666667f * fTemp70 * fVec21[(IOTA0 - iTemp72) & 1023]) + 0.041666668f * fTemp71 * fVec21[(IOTA0 - iTemp63) & 1023];
			float fTemp77 = fVec22[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp4)))) & 16383];
			fVec23[0] = fTemp77;
			fRec11[0] = fVec23[1] - (fTemp5 + (2.0f - fRec12[0])) * (fRec11[1] - fTemp77) / (fRec12[0] - fTemp5);
			fRec48[0] = 0.9999f * (fRec48[1] + float(iSlow50 * iTemp1)) + fSlow51;
			float fTemp78 = fRec48[0] + -1.49999f;
			float fTemp79 = std::floor(fTemp78);
			fRec50[0] = 0.995f * (fRec50[1] + float(iSlow52 * iTemp1)) + fSlow53;
			float fTemp80 = fRec50[0] + -1.49999f;
			float fTemp81 = std::floor(fTemp80);
			float fTemp82 = 0.7602446f * fRec38[1] + 0.6496369f * fTemp51;
			fVec24[IOTA0 & 1023] = fTemp82;
			float fTemp83 = fSlow49 * (fRec44[0] + -1.0f);
			float fTemp84 = 3.500005f - fTemp83;
			int iTemp85 = int(fTemp84);
			float fTemp86 = fTemp83 + std::floor(fTemp84);
			float fTemp87 = 2.0f - fTemp86;
			float fTemp88 = 3.0f - fTemp86;
			float fTemp89 = 4.0f - fTemp86;
			float fTemp90 = 5.0f - fTemp86;
			float fTemp91 = fTemp90 * fTemp89;
			float fTemp92 = fTemp91 * fTemp88;
			fVec25[IOTA0 & 16383] = (1.0f - fTemp86) * (fTemp87 * (fTemp88 * (0.041666668f * fVec24[(IOTA0 - std::min<int>(512, std::max<int>(0, iTemp85))) & 1023] * fTemp89 - 0.16666667f * fTemp90 * fVec24[(IOTA0 - std::min<int>(512, std::max<int>(0, iTemp85 + 1))) & 1023]) + 0.25f * fTemp91 * fVec24[(IOTA0 - std::min<int>(512, std::max<int>(0, iTemp85 + 2))) & 1023]) - 0.16666667f * fTemp92 * fVec24[(IOTA0 - std::min<int>(512, std::max<int>(0, iTemp85 + 3))) & 1023]) + 0.041666668f * fTemp92 * fTemp87 * fVec24[(IOTA0 - std::min<int>(512, std::max<int>(0, iTemp85 + 4))) & 1023];
			float fTemp93 = fVec25[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp80)))) & 16383];
			fVec26[0] = fTemp93;
			fRec49[0] = fVec26[1] - (fTemp81 + (2.0f - fRec50[0])) * (fRec49[1] - fTemp93) / (fRec50[0] - fTemp81);
			float fTemp94 = 0.7602446f * fRec49[0];
			float fTemp95 = 0.6496369f * fRec46[1];
			float fTemp96 = 0.7602446f * fRec11[0] - 0.6496369f * fRec45[1];
			fVec27[IOTA0 & 16383] = 0.70710677f * fTemp96 + 0.70710677f * (fTemp95 - fTemp94);
			float fTemp97 = fVec27[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp78)))) & 16383];
			fVec28[0] = fTemp97;
			fRec47[0] = fVec28[1] - (fTemp79 + (2.0f - fRec48[0])) * (fRec47[1] - fTemp97) / (fRec48[0] - fTemp79);
			fRec45[0] = fRec47[0];
			fRec52[0] = 0.9999f * (fRec52[1] + float(iSlow54 * iTemp1)) + fSlow55;
			float fTemp98 = fRec52[0] + -1.49999f;
			float fTemp99 = std::floor(fTemp98);
			fVec29[IOTA0 & 16383] = 0.70710677f * fTemp96 + 0.70710677f * (fTemp94 - fTemp95);
			float fTemp100 = fVec29[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp98)))) & 16383];
			fVec30[0] = fTemp100;
			fRec51[0] = fVec30[1] - (fTemp99 + (2.0f - fRec52[0])) * (fRec51[1] - fTemp100) / (fRec52[0] - fTemp99);
			fRec46[0] = fRec51[0];
			float fTemp101 = 0.7602446f * fRec45[1] + 0.6496369f * fRec11[0];
			fRec56[0] = 0.9999f * (fRec56[1] + float(iSlow56 * iTemp1)) + fSlow57;
			float fTemp102 = fRec56[0] + -1.49999f;
			float fTemp103 = std::floor(fTemp102);
			float fTemp104 = 0.7602446f * fRec46[1] + 0.6496369f * fRec49[0];
			float fTemp105 = 0.7602446f * fTemp104;
			float fTemp106 = 0.6496369f * fRec54[1];
			float fTemp107 = 0.7602446f * fTemp101 - 0.6496369f * fRec53[1];
			fVec31[IOTA0 & 16383] = 0.70710677f * fTemp107 + 0.70710677f * (fTemp106 - fTemp105);
			float fTemp108 = fVec31[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp102)))) & 16383];
			fVec32[0] = fTemp108;
			fRec55[0] = fVec32[1] - (fTemp103 + (2.0f - fRec56[0])) * (fRec55[1] - fTemp108) / (fRec56[0] - fTemp103);
			fRec53[0] = fRec55[0];
			fRec58[0] = 0.9999f * (fRec58[1] + float(iSlow58 * iTemp1)) + fSlow59;
			float fTemp109 = fRec58[0] + -1.49999f;
			float fTemp110 = std::floor(fTemp109);
			float fTemp111 = fRec58[0] - fTemp110;
			fVec33[IOTA0 & 16383] = 0.70710677f * fTemp107 + 0.70710677f * (fTemp105 - fTemp106);
			int iTemp112 = std::min<int>(8192, std::max<int>(0, int(fTemp109)));
			float fTemp113 = fVec33[(IOTA0 - iTemp112) & 16383];
			fVec34[0] = fTemp113;
			float fTemp114 = fTemp110 + (2.0f - fRec58[0]);
			fRec57[0] = fVec34[1] - fTemp114 * (fRec57[1] - fTemp113) / fTemp111;
			fRec54[0] = fRec57[0];
			float fTemp115 = 0.7602446f * fRec53[1] + 0.6496369f * fTemp101;
			fRec62[0] = 0.9999f * (fRec62[1] + float(iSlow60 * iTemp1)) + fSlow61;
			float fTemp116 = fRec62[0] + -1.49999f;
			float fTemp117 = std::floor(fTemp116);
			float fTemp118 = 0.7602446f * fRec54[1] + 0.6496369f * fTemp104;
			float fTemp119 = 0.7602446f * fTemp118;
			float fTemp120 = 0.6496369f * fRec60[1];
			float fTemp121 = 0.7602446f * fTemp115 - 0.6496369f * fRec59[1];
			fVec35[IOTA0 & 16383] = 0.70710677f * fTemp121 + 0.70710677f * (fTemp120 - fTemp119);
			float fTemp122 = fVec35[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp116)))) & 16383];
			fVec36[0] = fTemp122;
			fRec61[0] = fVec36[1] - (fTemp117 + (2.0f - fRec62[0])) * (fRec61[1] - fTemp122) / (fRec62[0] - fTemp117);
			fRec59[0] = fRec61[0];
			fRec64[0] = 0.9999f * (fRec64[1] + float(iSlow62 * iTemp1)) + fSlow63;
			float fTemp123 = fRec64[0] + -1.49999f;
			float fTemp124 = std::floor(fTemp123);
			float fTemp125 = fRec64[0] - fTemp124;
			fVec37[IOTA0 & 16383] = 0.70710677f * fTemp121 + 0.70710677f * (fTemp119 - fTemp120);
			int iTemp126 = std::min<int>(8192, std::max<int>(0, int(fTemp123)));
			float fTemp127 = fVec37[(IOTA0 - iTemp126) & 16383];
			fVec38[0] = fTemp127;
			float fTemp128 = fTemp124 + (2.0f - fRec64[0]);
			fRec63[0] = fVec38[1] - fTemp128 * (fRec63[1] - fTemp127) / fTemp125;
			fRec60[0] = fRec63[0];
			float fTemp129 = 0.7602446f * fRec59[1] + 0.6496369f * fTemp115;
			fRec68[0] = 0.9999f * (fRec68[1] + float(iSlow64 * iTemp1)) + fSlow65;
			float fTemp130 = fRec68[0] + -1.49999f;
			float fTemp131 = std::floor(fTemp130);
			float fTemp132 = fRec68[0] - fTemp131;
			float fTemp133 = 0.7602446f * fRec60[1] + 0.6496369f * fTemp118;
			float fTemp134 = 0.7602446f * fTemp133;
			float fTemp135 = 0.6496369f * fRec66[1];
			float fTemp136 = 0.7602446f * fTemp129 - 0.6496369f * fRec65[1];
			fVec39[IOTA0 & 16383] = 0.70710677f * fTemp136 + 0.70710677f * (fTemp135 - fTemp134);
			int iTemp137 = std::min<int>(8192, std::max<int>(0, int(fTemp130)));
			float fTemp138 = fVec39[(IOTA0 - iTemp137) & 16383];
			fVec40[0] = fTemp138;
			float fTemp139 = fTemp131 + (2.0f - fRec68[0]);
			fRec67[0] = fVec40[1] - fTemp139 * (fRec67[1] - fTemp138) / fTemp132;
			fRec65[0] = fRec67[0];
			fRec70[0] = 0.9999f * (fRec70[1] + float(iSlow66 * iTemp1)) + fSlow67;
			float fTemp140 = fRec70[0] + -1.49999f;
			float fTemp141 = std::floor(fTemp140);
			float fTemp142 = fRec70[0] - fTemp141;
			fVec41[IOTA0 & 16383] = 0.70710677f * fTemp136 + 0.70710677f * (fTemp134 - fTemp135);
			int iTemp143 = std::min<int>(8192, std::max<int>(0, int(fTemp140)));
			float fTemp144 = fVec41[(IOTA0 - iTemp143) & 16383];
			fVec42[0] = fTemp144;
			float fTemp145 = fTemp141 + (2.0f - fRec70[0]);
			fRec69[0] = fVec42[1] - fTemp145 * (fRec69[1] - fTemp144) / fTemp142;
			fRec66[0] = fRec69[0];
			float fTemp146 = 0.7602446f * fRec65[1] + 0.6496369f * fTemp129;
			fRec74[0] = 0.9999f * (fRec74[1] + float(iSlow68 * iTemp1)) + fSlow69;
			float fTemp147 = fRec74[0] + -1.49999f;
			float fTemp148 = std::floor(fTemp147);
			float fTemp149 = 0.7602446f * fRec66[1] + 0.6496369f * fTemp133;
			float fTemp150 = 0.7602446f * fTemp149;
			float fTemp151 = 0.6496369f * fRec72[1];
			float fTemp152 = 0.7602446f * fTemp146 - 0.6496369f * fRec71[1];
			fVec43[IOTA0 & 16383] = 0.70710677f * fTemp152 + 0.70710677f * (fTemp151 - fTemp150);
			float fTemp153 = fVec43[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp147)))) & 16383];
			fVec44[0] = fTemp153;
			fRec73[0] = fVec44[1] - (fTemp148 + (2.0f - fRec74[0])) * (fRec73[1] - fTemp153) / (fRec74[0] - fTemp148);
			fRec71[0] = fRec73[0];
			fRec76[0] = 0.9999f * (fRec76[1] + float(iSlow70 * iTemp1)) + fSlow71;
			float fTemp154 = fRec76[0] + -1.49999f;
			float fTemp155 = std::floor(fTemp154);
			float fTemp156 = fRec76[0] - fTemp155;
			fVec45[IOTA0 & 16383] = 0.70710677f * fTemp152 + 0.70710677f * (fTemp150 - fTemp151);
			int iTemp157 = std::min<int>(8192, std::max<int>(0, int(fTemp154)));
			float fTemp158 = fVec45[(IOTA0 - iTemp157) & 16383];
			fVec46[0] = fTemp158;
			float fTemp159 = fTemp155 + (2.0f - fRec76[0]);
			fRec75[0] = fVec46[1] - fTemp159 * (fRec75[1] - fTemp158) / fTemp156;
			fRec72[0] = fRec75[0];
			float fTemp160 = 0.7602446f * fRec71[1] + 0.6496369f * fTemp146;
			fVec47[IOTA0 & 16383] = fTemp160;
			float fTemp161 = fSlow49 * (fRec43[0] + 1.0f);
			float fTemp162 = fTemp161 + 3.500005f;
			int iTemp163 = int(fTemp162);
			int iTemp164 = std::max<int>(0, iTemp163 + 4);
			float fTemp165 = std::floor(fTemp162);
			float fTemp166 = fTemp161 + (2.0f - fTemp165);
			float fTemp167 = fTemp161 + (3.0f - fTemp165);
			float fTemp168 = fTemp161 + (4.0f - fTemp165);
			float fTemp169 = fTemp161 + (5.0f - fTemp165);
			float fTemp170 = fTemp169 * fTemp168;
			float fTemp171 = fTemp170 * fTemp167;
			float fTemp172 = fTemp171 * fTemp166;
			int iTemp173 = std::max<int>(0, iTemp163 + 3);
			int iTemp174 = std::max<int>(0, iTemp163 + 2);
			int iTemp175 = std::max<int>(0, iTemp163 + 1);
			int iTemp176 = std::max<int>(0, iTemp163);
			float fTemp177 = fTemp161 + (1.0f - fTemp165);
			fVec48[IOTA0 & 16383] = fTemp177 * (fTemp166 * (fTemp167 * (0.041666668f * fVec47[(IOTA0 - std::min<int>(8192, iTemp176)) & 16383] * fTemp168 - 0.16666667f * fTemp169 * fVec47[(IOTA0 - std::min<int>(8192, iTemp175)) & 16383]) + 0.25f * fTemp170 * fVec47[(IOTA0 - std::min<int>(8192, iTemp174)) & 16383]) - 0.16666667f * fTemp171 * fVec47[(IOTA0 - std::min<int>(8192, iTemp173)) & 16383]) + 0.041666668f * fTemp172 * fVec47[(IOTA0 - std::min<int>(8192, iTemp164)) & 16383];
			float fTemp178 = fVec48[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp2)))) & 16383];
			fVec49[0] = fTemp178;
			fRec9[0] = fVec49[1] - (fTemp3 + (2.0f - fRec10[0])) * (fRec9[1] - fTemp178) / (fRec10[0] - fTemp3);
			fRec8[0] = -(fSlow73 * (fSlow72 * fRec8[1] - (fRec9[0] + fRec9[1])));
			fRec7[0] = fRec8[0] - fSlow20 * (fSlow18 * fRec7[2] + fSlow13 * fRec7[1]);
			fRec6[0] = fSlow20 * (fRec7[2] + fRec7[0] + 2.0f * fRec7[1]) - fSlow17 * (fSlow15 * fRec6[2] + fSlow13 * fRec6[1]);
			float fTemp179 = fSlow17 * (fRec6[2] + fRec6[0] + 2.0f * fRec6[1]);
			fVec50[0] = fTemp179;
			fRec5[0] = -(fSlow75 * (fSlow74 * fRec5[1] - (fTemp179 + fVec50[1])));
			fRec4[0] = fRec5[0] - fSlow10 * (fSlow8 * fRec4[2] + fSlow4 * fRec4[1]);
			fRec3[0] = fSlow10 * (fRec4[2] + fRec4[0] + 2.0f * fRec4[1]) - fSlow7 * (fSlow6 * fRec3[2] + fSlow4 * fRec3[1]);
			fRec79[0] = -(fSlow75 * (fSlow74 * fRec79[1] - fSlow5 * (fTemp179 - fVec50[1])));
			fRec78[0] = fRec79[0] - fSlow10 * (fSlow8 * fRec78[2] + fSlow4 * fRec78[1]);
			fRec77[0] = fSlow77 * (fRec78[2] + (fRec78[0] - 2.0f * fRec78[1])) - fSlow7 * (fSlow6 * fRec77[2] + fSlow4 * fRec77[1]);
			float fTemp180 = fSlow4 * fRec80[1];
			fRec83[0] = -(fSlow73 * (fSlow72 * fRec83[1] - fSlow14 * (fRec9[0] - fRec9[1])));
			fRec82[0] = fRec83[0] - fSlow20 * (fSlow18 * fRec82[2] + fSlow13 * fRec82[1]);
			fRec81[0] = fSlow81 * (fRec82[2] + (fRec82[0] - 2.0f * fRec82[1])) - fSlow17 * (fSlow15 * fRec81[2] + fSlow13 * fRec81[1]);
			fRec80[0] = fSlow82 * (fRec81[2] + (fRec81[0] - 2.0f * fRec81[1])) - fSlow80 * (fSlow79 * fRec80[2] + fTemp180);
			float fTemp181 = fSlow84 * (fSlow83 * (fRec80[2] + fSlow80 * (fTemp180 + fSlow79 * fRec80[0])) + fSlow7 * (fSlow78 * (fRec77[2] + (fRec77[0] - 2.0f * fRec77[1])) + fSlow76 * (fRec3[2] + fRec3[0] + 2.0f * fRec3[1]))) + fTemp0;
			fVec51[IOTA0 & 1023] = fTemp181;
			fRec2[0] = fSlow85 * (fTemp177 * (fTemp166 * (fTemp167 * (0.041666668f * fTemp168 * fVec51[(IOTA0 - std::min<int>(512, iTemp176)) & 1023] - 0.16666667f * fTemp169 * fVec51[(IOTA0 - std::min<int>(512, iTemp175)) & 1023]) + 0.25f * fTemp170 * fVec51[(IOTA0 - std::min<int>(512, iTemp174)) & 1023]) - 0.16666667f * fTemp171 * fVec51[(IOTA0 - std::min<int>(512, iTemp173)) & 1023]) + 0.041666668f * fTemp172 * fVec51[(IOTA0 - std::min<int>(512, iTemp164)) & 1023]) + fSlow1 * fRec2[1];
			float fTemp182 = float(input1[i0]);
			fRec95[0] = 0.995f * (fRec95[1] + float(iSlow88 * iTemp1)) + fSlow89;
			float fTemp183 = fRec95[0] + -1.49999f;
			float fTemp184 = std::floor(fTemp183);
			float fTemp185 = 0.7602446f * fRec72[1] + 0.6496369f * fTemp149;
			fVec52[IOTA0 & 16383] = fTemp185;
			float fTemp186 = fSlow49 * (fRec43[0] + -1.0f);
			float fTemp187 = 3.500005f - fTemp186;
			int iTemp188 = int(fTemp187);
			float fTemp189 = fTemp186 + std::floor(fTemp187);
			float fTemp190 = 2.0f - fTemp189;
			float fTemp191 = 3.0f - fTemp189;
			float fTemp192 = 4.0f - fTemp189;
			float fTemp193 = 5.0f - fTemp189;
			float fTemp194 = fTemp193 * fTemp192;
			float fTemp195 = fTemp194 * fTemp191;
			fVec53[IOTA0 & 16383] = (1.0f - fTemp189) * (fTemp190 * (fTemp191 * (0.041666668f * fVec52[(IOTA0 - std::min<int>(8192, std::max<int>(0, iTemp188))) & 16383] * fTemp192 - 0.16666667f * fTemp193 * fVec52[(IOTA0 - std::min<int>(8192, std::max<int>(0, iTemp188 + 1))) & 16383]) + 0.25f * fTemp194 * fVec52[(IOTA0 - std::min<int>(8192, std::max<int>(0, iTemp188 + 2))) & 16383]) - 0.16666667f * fTemp195 * fVec52[(IOTA0 - std::min<int>(8192, std::max<int>(0, iTemp188 + 3))) & 16383]) + 0.041666668f * fTemp195 * fTemp190 * fVec52[(IOTA0 - std::min<int>(8192, std::max<int>(0, iTemp188 + 4))) & 16383];
			float fTemp196 = fVec53[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp183)))) & 16383];
			fVec54[0] = fTemp196;
			fRec94[0] = fVec54[1] - (fTemp184 + (2.0f - fRec95[0])) * (fRec94[1] - fTemp196) / (fRec95[0] - fTemp184);
			fRec93[0] = -(fSlow73 * (fSlow72 * fRec93[1] - (fRec94[0] + fRec94[1])));
			fRec92[0] = fRec93[0] - fSlow20 * (fSlow18 * fRec92[2] + fSlow13 * fRec92[1]);
			fRec91[0] = fSlow20 * (fRec92[2] + fRec92[0] + 2.0f * fRec92[1]) - fSlow17 * (fSlow15 * fRec91[2] + fSlow13 * fRec91[1]);
			float fTemp197 = fSlow17 * (fRec91[2] + fRec91[0] + 2.0f * fRec91[1]);
			fVec55[0] = fTemp197;
			fRec90[0] = -(fSlow75 * (fSlow74 * fRec90[1] - (fTemp197 + fVec55[1])));
			fRec89[0] = fRec90[0] - fSlow10 * (fSlow8 * fRec89[2] + fSlow4 * fRec89[1]);
			fRec88[0] = fSlow10 * (fRec89[2] + fRec89[0] + 2.0f * fRec89[1]) - fSlow7 * (fSlow6 * fRec88[2] + fSlow4 * fRec88[1]);
			fRec98[0] = -(fSlow75 * (fSlow74 * fRec98[1] - fSlow5 * (fTemp197 - fVec55[1])));
			fRec97[0] = fRec98[0] - fSlow10 * (fSlow8 * fRec97[2] + fSlow4 * fRec97[1]);
			fRec96[0] = fSlow77 * (fRec97[2] + (fRec97[0] - 2.0f * fRec97[1])) - fSlow7 * (fSlow6 * fRec96[2] + fSlow4 * fRec96[1]);
			float fTemp198 = fSlow4 * fRec99[1];
			fRec102[0] = -(fSlow73 * (fSlow72 * fRec102[1] - fSlow14 * (fRec94[0] - fRec94[1])));
			fRec101[0] = fRec102[0] - fSlow20 * (fSlow18 * fRec101[2] + fSlow13 * fRec101[1]);
			fRec100[0] = fSlow81 * (fRec101[2] + (fRec101[0] - 2.0f * fRec101[1])) - fSlow17 * (fSlow15 * fRec100[2] + fSlow13 * fRec100[1]);
			fRec99[0] = fSlow82 * (fRec100[2] + (fRec100[0] - 2.0f * fRec100[1])) - fSlow80 * (fSlow79 * fRec99[2] + fTemp198);
			float fTemp199 = fSlow84 * (fSlow83 * (fRec99[2] + fSlow80 * (fTemp198 + fSlow79 * fRec99[0])) + fSlow7 * (fSlow78 * (fRec96[2] + (fRec96[0] - 2.0f * fRec96[1])) + fSlow76 * (fRec88[2] + fRec88[0] + 2.0f * fRec88[1]))) + fTemp182;
			fVec56[IOTA0 & 1023] = fTemp199;
			fRec87[0] = fSlow85 * (fTemp76 * (fTemp65 * (fTemp66 * (0.041666668f * fTemp67 * fVec56[(IOTA0 - iTemp75) & 1023] - 0.16666667f * fTemp68 * fVec56[(IOTA0 - iTemp74) & 1023]) + 0.25f * fTemp69 * fVec56[(IOTA0 - iTemp73) & 1023]) - 0.16666667f * fTemp70 * fVec56[(IOTA0 - iTemp72) & 1023]) + 0.041666668f * fTemp71 * fVec56[(IOTA0 - iTemp63) & 1023]) + fSlow1 * fRec87[1];
			float fTemp200 = fSlow90 * fRec87[0];
			float fTemp201 = fSlow87 * fRec85[1];
			float fTemp202 = fSlow90 * fRec2[0] - fSlow87 * fRec84[1];
			fVec57[IOTA0 & 16383] = 0.70710677f * fTemp202 + 0.70710677f * (fTemp201 - fTemp200);
			float fTemp203 = fVec57[(IOTA0 - iTemp112) & 16383];
			fVec58[0] = fTemp203;
			fRec86[0] = fVec58[1] - fTemp114 * (fRec86[1] - fTemp203) / fTemp111;
			fRec84[0] = fRec86[0];
			fRec104[0] = 0.9999f * (fRec104[1] + float(iSlow91 * iTemp1)) + fSlow92;
			float fTemp204 = fRec104[0] + -1.49999f;
			float fTemp205 = std::floor(fTemp204);
			fVec59[IOTA0 & 16383] = 0.70710677f * fTemp202 + 0.70710677f * (fTemp200 - fTemp201);
			float fTemp206 = fVec59[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp204)))) & 16383];
			fVec60[0] = fTemp206;
			fRec103[0] = fVec60[1] - (fTemp205 + (2.0f - fRec104[0])) * (fRec103[1] - fTemp206) / (fRec104[0] - fTemp205);
			fRec85[0] = fRec103[0];
			float fTemp207 = fSlow90 * fRec84[1] + fSlow87 * fRec2[0];
			float fTemp208 = fSlow90 * fRec85[1] + fSlow87 * fRec87[0];
			float fTemp209 = fSlow90 * fTemp208;
			float fTemp210 = fSlow87 * fRec106[1];
			float fTemp211 = fSlow90 * fTemp207 - fSlow87 * fRec105[1];
			fVec61[IOTA0 & 16383] = 0.70710677f * fTemp211 + 0.70710677f * (fTemp210 - fTemp209);
			float fTemp212 = fVec61[(IOTA0 - iTemp137) & 16383];
			fVec62[0] = fTemp212;
			fRec107[0] = fVec62[1] - fTemp139 * (fRec107[1] - fTemp212) / fTemp132;
			fRec105[0] = fRec107[0];
			fVec63[IOTA0 & 16383] = 0.70710677f * fTemp211 + 0.70710677f * (fTemp209 - fTemp210);
			float fTemp213 = fVec63[(IOTA0 - iTemp126) & 16383];
			fVec64[0] = fTemp213;
			fRec108[0] = fVec64[1] - fTemp128 * (fRec108[1] - fTemp213) / fTemp125;
			fRec106[0] = fRec108[0];
			float fTemp214 = fSlow90 * fRec105[1] + fSlow87 * fTemp207;
			float fTemp215 = fSlow90 * fRec106[1] + fSlow87 * fTemp208;
			float fTemp216 = fSlow90 * fTemp215;
			float fTemp217 = fSlow87 * fRec110[1];
			float fTemp218 = fSlow90 * fTemp214 - fSlow87 * fRec109[1];
			fVec65[IOTA0 & 16383] = 0.70710677f * fTemp218 + 0.70710677f * (fTemp217 - fTemp216);
			float fTemp219 = fVec65[(IOTA0 - iTemp143) & 16383];
			fVec66[0] = fTemp219;
			fRec111[0] = fVec66[1] - fTemp145 * (fRec111[1] - fTemp219) / fTemp142;
			fRec109[0] = fRec111[0];
			fRec113[0] = 0.9999f * (fRec113[1] + float(iSlow93 * iTemp1)) + fSlow94;
			float fTemp220 = fRec113[0] + -1.49999f;
			float fTemp221 = std::floor(fTemp220);
			fVec67[IOTA0 & 16383] = 0.70710677f * fTemp218 + 0.70710677f * (fTemp216 - fTemp217);
			float fTemp222 = fVec67[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp220)))) & 16383];
			fVec68[0] = fTemp222;
			fRec112[0] = fVec68[1] - (fTemp221 + (2.0f - fRec113[0])) * (fRec112[1] - fTemp222) / (fRec113[0] - fTemp221);
			fRec110[0] = fRec112[0];
			float fTemp223 = fSlow90 * fRec109[1] + fSlow87 * fTemp214;
			fRec117[0] = 0.9999f * (fRec117[1] + float(iSlow95 * iTemp1)) + fSlow96;
			float fTemp224 = fRec117[0] + -1.49999f;
			float fTemp225 = std::floor(fTemp224);
			float fTemp226 = fSlow90 * fRec110[1] + fSlow87 * fTemp215;
			float fTemp227 = fSlow90 * fTemp226;
			float fTemp228 = fSlow87 * fRec115[1];
			float fTemp229 = fSlow90 * fTemp223 - fSlow87 * fRec114[1];
			fVec69[IOTA0 & 16383] = 0.70710677f * fTemp229 + 0.70710677f * (fTemp228 - fTemp227);
			float fTemp230 = fVec69[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp224)))) & 16383];
			fVec70[0] = fTemp230;
			fRec116[0] = fVec70[1] - (fTemp225 + (2.0f - fRec117[0])) * (fRec116[1] - fTemp230) / (fRec117[0] - fTemp225);
			fRec114[0] = fRec116[0];
			fVec71[IOTA0 & 16383] = 0.70710677f * fTemp229 + 0.70710677f * (fTemp227 - fTemp228);
			float fTemp231 = fVec71[(IOTA0 - iTemp157) & 16383];
			fVec72[0] = fTemp231;
			fRec118[0] = fVec72[1] - fTemp159 * (fRec118[1] - fTemp231) / fTemp156;
			fRec115[0] = fRec118[0];
			fRec0[0] = fSlow90 * fRec114[1] + fSlow87 * fTemp223;
			fRec1[0] = fSlow90 * fRec115[1] + fSlow87 * fTemp226;
			output0[i0] = FAUSTFLOAT(fSlow97 * fRec0[0] + fSlow0 * fTemp0);
			output1[i0] = FAUSTFLOAT(fSlow97 * fRec1[0] + fSlow0 * fTemp182);
			iVec0[1] = iVec0[0];
			fRec10[1] = fRec10[0];
			fRec12[1] = fRec12[0];
			fRec16[1] = fRec16[0];
			IOTA0 = IOTA0 + 1;
			fVec2[1] = fVec2[0];
			fRec15[1] = fRec15[0];
			fRec13[1] = fRec13[0];
			fRec18[1] = fRec18[0];
			fVec4[1] = fVec4[0];
			fRec17[1] = fRec17[0];
			fRec14[1] = fRec14[0];
			fRec22[1] = fRec22[0];
			fVec6[1] = fVec6[0];
			fRec21[1] = fRec21[0];
			fRec19[1] = fRec19[0];
			fRec24[1] = fRec24[0];
			fVec8[1] = fVec8[0];
			fRec23[1] = fRec23[0];
			fRec20[1] = fRec20[0];
			fRec28[1] = fRec28[0];
			fVec10[1] = fVec10[0];
			fRec27[1] = fRec27[0];
			fRec25[1] = fRec25[0];
			fRec30[1] = fRec30[0];
			fVec12[1] = fVec12[0];
			fRec29[1] = fRec29[0];
			fRec26[1] = fRec26[0];
			fRec34[1] = fRec34[0];
			fVec14[1] = fVec14[0];
			fRec33[1] = fRec33[0];
			fRec31[1] = fRec31[0];
			fRec36[1] = fRec36[0];
			fVec16[1] = fVec16[0];
			fRec35[1] = fRec35[0];
			fRec32[1] = fRec32[0];
			fRec40[1] = fRec40[0];
			fVec18[1] = fVec18[0];
			fRec39[1] = fRec39[0];
			fRec37[1] = fRec37[0];
			fRec42[1] = fRec42[0];
			fVec20[1] = fVec20[0];
			fRec41[1] = fRec41[0];
			fRec38[1] = fRec38[0];
			fRec43[1] = fRec43[0];
			fRec44[1] = fRec44[0];
			fVec23[1] = fVec23[0];
			fRec11[1] = fRec11[0];
			fRec48[1] = fRec48[0];
			fRec50[1] = fRec50[0];
			fVec26[1] = fVec26[0];
			fRec49[1] = fRec49[0];
			fVec28[1] = fVec28[0];
			fRec47[1] = fRec47[0];
			fRec45[1] = fRec45[0];
			fRec52[1] = fRec52[0];
			fVec30[1] = fVec30[0];
			fRec51[1] = fRec51[0];
			fRec46[1] = fRec46[0];
			fRec56[1] = fRec56[0];
			fVec32[1] = fVec32[0];
			fRec55[1] = fRec55[0];
			fRec53[1] = fRec53[0];
			fRec58[1] = fRec58[0];
			fVec34[1] = fVec34[0];
			fRec57[1] = fRec57[0];
			fRec54[1] = fRec54[0];
			fRec62[1] = fRec62[0];
			fVec36[1] = fVec36[0];
			fRec61[1] = fRec61[0];
			fRec59[1] = fRec59[0];
			fRec64[1] = fRec64[0];
			fVec38[1] = fVec38[0];
			fRec63[1] = fRec63[0];
			fRec60[1] = fRec60[0];
			fRec68[1] = fRec68[0];
			fVec40[1] = fVec40[0];
			fRec67[1] = fRec67[0];
			fRec65[1] = fRec65[0];
			fRec70[1] = fRec70[0];
			fVec42[1] = fVec42[0];
			fRec69[1] = fRec69[0];
			fRec66[1] = fRec66[0];
			fRec74[1] = fRec74[0];
			fVec44[1] = fVec44[0];
			fRec73[1] = fRec73[0];
			fRec71[1] = fRec71[0];
			fRec76[1] = fRec76[0];
			fVec46[1] = fVec46[0];
			fRec75[1] = fRec75[0];
			fRec72[1] = fRec72[0];
			fVec49[1] = fVec49[0];
			fRec9[1] = fRec9[0];
			fRec8[1] = fRec8[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fVec50[1] = fVec50[0];
			fRec5[1] = fRec5[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec79[1] = fRec79[0];
			fRec78[2] = fRec78[1];
			fRec78[1] = fRec78[0];
			fRec77[2] = fRec77[1];
			fRec77[1] = fRec77[0];
			fRec83[1] = fRec83[0];
			fRec82[2] = fRec82[1];
			fRec82[1] = fRec82[0];
			fRec81[2] = fRec81[1];
			fRec81[1] = fRec81[0];
			fRec80[2] = fRec80[1];
			fRec80[1] = fRec80[0];
			fRec2[1] = fRec2[0];
			fRec95[1] = fRec95[0];
			fVec54[1] = fVec54[0];
			fRec94[1] = fRec94[0];
			fRec93[1] = fRec93[0];
			fRec92[2] = fRec92[1];
			fRec92[1] = fRec92[0];
			fRec91[2] = fRec91[1];
			fRec91[1] = fRec91[0];
			fVec55[1] = fVec55[0];
			fRec90[1] = fRec90[0];
			fRec89[2] = fRec89[1];
			fRec89[1] = fRec89[0];
			fRec88[2] = fRec88[1];
			fRec88[1] = fRec88[0];
			fRec98[1] = fRec98[0];
			fRec97[2] = fRec97[1];
			fRec97[1] = fRec97[0];
			fRec96[2] = fRec96[1];
			fRec96[1] = fRec96[0];
			fRec102[1] = fRec102[0];
			fRec101[2] = fRec101[1];
			fRec101[1] = fRec101[0];
			fRec100[2] = fRec100[1];
			fRec100[1] = fRec100[0];
			fRec99[2] = fRec99[1];
			fRec99[1] = fRec99[0];
			fRec87[1] = fRec87[0];
			fVec58[1] = fVec58[0];
			fRec86[1] = fRec86[0];
			fRec84[1] = fRec84[0];
			fRec104[1] = fRec104[0];
			fVec60[1] = fVec60[0];
			fRec103[1] = fRec103[0];
			fRec85[1] = fRec85[0];
			fVec62[1] = fVec62[0];
			fRec107[1] = fRec107[0];
			fRec105[1] = fRec105[0];
			fVec64[1] = fVec64[0];
			fRec108[1] = fRec108[0];
			fRec106[1] = fRec106[0];
			fVec66[1] = fVec66[0];
			fRec111[1] = fRec111[0];
			fRec109[1] = fRec109[0];
			fRec113[1] = fRec113[0];
			fVec68[1] = fVec68[0];
			fRec112[1] = fRec112[0];
			fRec110[1] = fRec110[0];
			fRec117[1] = fRec117[0];
			fVec70[1] = fVec70[0];
			fRec116[1] = fRec116[0];
			fRec114[1] = fRec114[0];
			fVec72[1] = fVec72[0];
			fRec118[1] = fRec118[0];
			fRec115[1] = fRec115[0];
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
		}
	}

};
FAUSTPP_END_NAMESPACE


#if defined(__GNUC__)
#   pragma GCC diagnostic pop
#endif



//------------------------------------------------------------------------------
// End the Faust code section




DFJPverb::DFJPverb()
{

    mydsp *dsp = new mydsp;
    fDsp.reset(dsp);
    dsp->instanceResetUserInterface();

}

DFJPverb::~DFJPverb()
{
}

void DFJPverb::init(float sample_rate)
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.classInit(sample_rate);
    dsp.instanceConstants(sample_rate);
    clear();

}

void DFJPverb::clear() noexcept
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.instanceClear();

}

void DFJPverb::process(
    const float *in0,const float *in1,
    float *out0,float *out1,
    unsigned count) noexcept
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    float *inputs[] = {
        const_cast<float *>(in0),const_cast<float *>(in1),
    };
    float *outputs[] = {
        out0,out1,
    };
    dsp.compute(count, inputs, outputs);

}

const char *DFJPverb::parameter_label(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "Time (T60)";
    
    case 1:
        return "Size";
    
    case 2:
        return "Hi-Freq Damping";
    
    case 3:
        return "Early Reflections Shape";
    
    case 4:
        return "Low/Mid-Band Crossover Frequency";
    
    case 5:
        return "Mid/High-Band Crossover Frequency";
    
    case 6:
        return "Low-Band Multiplier";
    
    case 7:
        return "Mid-Band Multiplier";
    
    case 8:
        return "High-Band Multiplier";
    
    case 9:
        return "Modulation Depth";
    
    case 10:
        return "Modulation Frequency";
    
    case 11:
        return "Dry Gain";
    
    case 12:
        return "Wet Gain";
    
    default:
        return 0;
    }
}

const char *DFJPverb::parameter_short_label(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "";
    
    case 1:
        return "";
    
    case 2:
        return "";
    
    case 3:
        return "";
    
    case 4:
        return "";
    
    case 5:
        return "";
    
    case 6:
        return "";
    
    case 7:
        return "";
    
    case 8:
        return "";
    
    case 9:
        return "";
    
    case 10:
        return "";
    
    case 11:
        return "Dry";
    
    case 12:
        return "Wet";
    
    default:
        return 0;
    }
}

const char *DFJPverb::parameter_symbol(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "t60";
    
    case 1:
        return "size";
    
    case 2:
        return "damp";
    
    case 3:
        return "early_diff";
    
    case 4:
        return "low_cutoff";
    
    case 5:
        return "high_cutoff";
    
    case 6:
        return "low";
    
    case 7:
        return "mid";
    
    case 8:
        return "high";
    
    case 9:
        return "mod_depth";
    
    case 10:
        return "mod_freq";
    
    case 11:
        return "dry";
    
    case 12:
        return "wet";
    
    default:
        return 0;
    }
}

const char *DFJPverb::parameter_unit(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "";
    
    case 1:
        return "";
    
    case 2:
        return "";
    
    case 3:
        return "";
    
    case 4:
        return "Hz";
    
    case 5:
        return "Hz";
    
    case 6:
        return "";
    
    case 7:
        return "";
    
    case 8:
        return "";
    
    case 9:
        return "";
    
    case 10:
        return "Hz";
    
    case 11:
        return "dB";
    
    case 12:
        return "dB";
    
    default:
        return 0;
    }
}

const DFJPverb::ParameterRange *DFJPverb::parameter_range(unsigned index) noexcept
{
    switch (index) {
    
    case 0: {
        static const ParameterRange range = { 1.0, 0.1, 60.0 };
        return &range;
    }
    
    case 1: {
        static const ParameterRange range = { 1.0, 0.5, 5.0 };
        return &range;
    }
    
    case 2: {
        static const ParameterRange range = { 0.0, 0.0, 0.999 };
        return &range;
    }
    
    case 3: {
        static const ParameterRange range = { 0.70710677, 0.0, 0.99 };
        return &range;
    }
    
    case 4: {
        static const ParameterRange range = { 500.0, 100.0, 6000.0 };
        return &range;
    }
    
    case 5: {
        static const ParameterRange range = { 2000.0, 1000.0, 10000.0 };
        return &range;
    }
    
    case 6: {
        static const ParameterRange range = { 1.0, 0.0, 1.0 };
        return &range;
    }
    
    case 7: {
        static const ParameterRange range = { 1.0, 0.0, 1.0 };
        return &range;
    }
    
    case 8: {
        static const ParameterRange range = { 1.0, 0.0, 1.0 };
        return &range;
    }
    
    case 9: {
        static const ParameterRange range = { 0.1, 0.0, 1.0 };
        return &range;
    }
    
    case 10: {
        static const ParameterRange range = { 2.0, 0.0, 10.0 };
        return &range;
    }
    
    case 11: {
        static const ParameterRange range = { 0.0, -90.0, 10.0 };
        return &range;
    }
    
    case 12: {
        static const ParameterRange range = { -12.0, -90.0, 10.0 };
        return &range;
    }
    
    default:
        return 0;
    }
}

bool DFJPverb::parameter_is_trigger(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

bool DFJPverb::parameter_is_boolean(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

bool DFJPverb::parameter_is_integer(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

bool DFJPverb::parameter_is_logarithmic(unsigned index) noexcept
{
    switch (index) {
    
    case 4:
        return true;
    
    case 5:
        return true;
    
    default:
        return false;
    }
}

float DFJPverb::get_parameter(unsigned index) const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    switch (index) {
    
    case 0:
        return dsp.fHslider10;
    
    case 1:
        return dsp.fHslider4;
    
    case 2:
        return dsp.fHslider1;
    
    case 3:
        return dsp.fHslider11;
    
    case 4:
        return dsp.fHslider2;
    
    case 5:
        return dsp.fHslider3;
    
    case 6:
        return dsp.fHslider7;
    
    case 7:
        return dsp.fHslider8;
    
    case 8:
        return dsp.fHslider9;
    
    case 9:
        return dsp.fHslider6;
    
    case 10:
        return dsp.fHslider5;
    
    case 11:
        return dsp.fHslider0;
    
    case 12:
        return dsp.fHslider12;
    
    default:
        (void)dsp;
        return 0;
    }
}

void DFJPverb::set_parameter(unsigned index, float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    switch (index) {
    
    case 0:
        dsp.fHslider10 = value;
        break;
    
    case 1:
        dsp.fHslider4 = value;
        break;
    
    case 2:
        dsp.fHslider1 = value;
        break;
    
    case 3:
        dsp.fHslider11 = value;
        break;
    
    case 4:
        dsp.fHslider2 = value;
        break;
    
    case 5:
        dsp.fHslider3 = value;
        break;
    
    case 6:
        dsp.fHslider7 = value;
        break;
    
    case 7:
        dsp.fHslider8 = value;
        break;
    
    case 8:
        dsp.fHslider9 = value;
        break;
    
    case 9:
        dsp.fHslider6 = value;
        break;
    
    case 10:
        dsp.fHslider5 = value;
        break;
    
    case 11:
        dsp.fHslider0 = value;
        break;
    
    case 12:
        dsp.fHslider12 = value;
        break;
    
    default:
        (void)dsp;
        (void)value;
        break;
    }
}


float DFJPverb::get_t60() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider10;
}

float DFJPverb::get_size() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider4;
}

float DFJPverb::get_damp() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider1;
}

float DFJPverb::get_early_diff() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider11;
}

float DFJPverb::get_low_cutoff() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider2;
}

float DFJPverb::get_high_cutoff() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider3;
}

float DFJPverb::get_low() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider7;
}

float DFJPverb::get_mid() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider8;
}

float DFJPverb::get_high() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider9;
}

float DFJPverb::get_mod_depth() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider6;
}

float DFJPverb::get_mod_freq() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider5;
}

float DFJPverb::get_dry() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider0;
}

float DFJPverb::get_wet() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider12;
}


void DFJPverb::set_t60(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider10 = value;
}

void DFJPverb::set_size(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider4 = value;
}

void DFJPverb::set_damp(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider1 = value;
}

void DFJPverb::set_early_diff(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider11 = value;
}

void DFJPverb::set_low_cutoff(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider2 = value;
}

void DFJPverb::set_high_cutoff(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider3 = value;
}

void DFJPverb::set_low(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider7 = value;
}

void DFJPverb::set_mid(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider8 = value;
}

void DFJPverb::set_high(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider9 = value;
}

void DFJPverb::set_mod_depth(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider6 = value;
}

void DFJPverb::set_mod_freq(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider5 = value;
}

void DFJPverb::set_dry(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider0 = value;
}

void DFJPverb::set_wet(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider12 = value;
}



