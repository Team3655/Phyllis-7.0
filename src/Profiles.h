///////////////////////////////////////////////////////////////////////////////
//
// Profiles.h
//
//  Created on: Feb 25, 2017
//      Author: Silas A.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef PROFILES_H
#define PROFILES_H

typedef int BOOL;

// Wrapper structure for profile
struct Profile
{
	BOOL turn;
	int size;
	const double (*profile)[3];
	bool split;

	Profile(BOOL turn, int size, const double (*profile)[3], bool split) :
		turn(turn), size(size), profile(profile), split(split) { }

	Profile() { }
};

// [position] [velocity] [duration(ms)]
// Profiles for driving to the peg

// A 45 degree Turn
const double Mp45Turn[][3] =
{
	{ 0, 0, 20 },
	{ 0.00021978021978022, 1.318681319, 20 },
	{ 0.000989010989010989, 3.296703297, 20 },
	{ 0.00252747252747253, 5.934065934, 20 },
	{ 0.00505494505494506, 9.230769231, 20 },
	{ 0.00879120879120879, 13.18681319, 20 },
	{ 0.013956043956044, 17.8021978, 20 },
	{ 0.0207692307692308, 23.07692308, 20 },
	{ 0.0294505494505495, 29.01098901, 20 },
	{ 0.0402197802197802, 35.6043956, 20 },
	{ 0.0532967032967033, 42.85714286, 20 },
	{ 0.0689010989010989, 50.76923077, 30 },
	{ 0.0872527472527472, 59.34065934, 20 },
	{ 0.108571428571429, 68.57142857, 20 },
	{ 0.132747252747253, 76.48351648, 20 },
	{ 0.159450549450549, 83.73626374, 20 },
	{ 0.188461538461538, 90.32967033, 20 },
	{ 0.21956043956044, 96.26373626, 20 },
	{ 0.252527472527472, 101.5384615, 20 },
	{ 0.287142857142857, 106.1538462, 20 },
	{ 0.323186813186813, 110.1098901, 20 },
	{ 0.36043956043956, 113.4065934, 20 },
	{ 0.398681318681319, 116.043956, 20 },
	{ 0.437692307692308, 118.021978, 20 },
	{ 0.477252747252747, 119.3406593, 20 },
	{ 0.517142857142857, 120, 20 },
	{ 0.557142857142857, 120, 20 },
	{ 0.597142857142857, 120, 20 },
	{ 0.637142857142857, 120, 20 },
	{ 0.677142857142857, 120, 20 },
	{ 0.717142857142857, 120, 20 },
	{ 0.757142857142857, 120, 20 },
	{ 0.797142857142857, 120, 20 },
	{ 0.837142857142857, 120, 20 },
	{ 0.877142857142857, 120, 20 },
	{ 0.917142857142857, 120, 20 },
	{ 0.957142857142857, 120, 20 },
	{ 0.997142857142857, 120, 20 },
	{ 1.03714285714286, 120, 20 },
	{ 1.07714285714286, 120, 20 },
	{ 1.11714285714286, 120, 20 },
	{ 1.15692307692308, 118.6813187, 20 },
	{ 1.19615384615385, 116.7032967, 20 },
	{ 1.23461538461538, 114.0659341, 20 },
	{ 1.27208791208791, 110.7692308, 20 },
	{ 1.30835164835165, 106.8131868, 20 },
	{ 1.34318681318681, 102.1978022, 20 },
	{ 1.37637362637363, 96.92307692, 20 },
	{ 1.40769230769231, 90.98901099, 20 },
	{ 1.43692307692308, 84.3956044, 20 },
	{ 1.46384615384615, 77.14285714, 20 },
	{ 1.48824175824176, 69.23076923, 20 },
	{ 1.50989010989011, 60.65934066, 20 },
	{ 1.52857142857143, 51.42857143, 20 },
	{ 1.5443956043956, 43.51648352, 20 },
	{ 1.55769230769231, 36.26373626, 20 },
	{ 1.56868131868132, 29.67032967, 20 },
	{ 1.57758241758242, 23.73626374, 20 },
	{ 1.58461538461538, 18.46153846, 20 },
	{ 1.59, 13.84615385, 20 },
	{ 1.59395604395604, 9.89010989, 20 },
	{ 1.5967032967033, 6.593406593, 20 },
	{ 1.59846153846154, 3.956043956, 20 },
	{ 1.59945054945055, 1.978021978, 20 },
	{ 1.59989010989011, 0.659340659, 20 },
	{ 1.6, 2.37905E-15, 20 },
	{ 1.6, 0, 20 }
};
const int Mp45TurnSize = 67;

// A 90 degree Turn
const double Mp90Turn[][3] =
{
	{ 0, 0, 20 },
	{ 0.000274725274725275, 1.648351648, 20 },
	{ 0.00123626373626374, 4.120879121, 20 },
	{ 0.00315934065934066, 7.417582418, 20 },
	{ 0.00631868131868132, 11.53846154, 20 },
	{ 0.010989010989011, 16.48351648, 20 },
	{ 0.0174450549450549, 22.25274725, 20 },
	{ 0.0259615384615385, 28.84615385, 20 },
	{ 0.0368131868131868, 36.26373626, 20 },
	{ 0.0502747252747253, 44.50549451, 20 },
	{ 0.0666208791208791, 53.57142857, 20 },
	{ 0.0861263736263736, 63.46153846, 20 },
	{ 0.109065934065934, 74.17582418, 20 },
	{ 0.135714285714286, 85.71428571, 20 },
	{ 0.165934065934066, 95.6043956, 20 },
	{ 0.199313186813187, 104.6703297, 20 },
	{ 0.235576923076923, 112.9120879, 20 },
	{ 0.274450549450549, 120.3296703, 20 },
	{ 0.315659340659341, 126.9230769, 20 },
	{ 0.358928571428571, 132.6923077, 20 },
	{ 0.403983516483516, 137.6373626, 20 },
	{ 0.450549450549451, 141.7582418, 20 },
	{ 0.498351648351648, 145.0549451, 20 },
	{ 0.547115384615385, 147.5274725, 20 },
	{ 0.596565934065934, 149.1758242, 20 },
	{ 0.646428571428572, 150, 20 },
	{ 0.696428571428572, 150, 20 },
	{ 0.746428571428572, 150, 20 },
	{ 0.796428571428572, 150, 20 },
	{ 0.846428571428572, 150, 20 },
	{ 0.896428571428572, 150, 20 },
	{ 0.946428571428572, 150, 20 },
	{ 0.996428571428572, 150, 20 },
	{ 1.04642857142857, 150, 20 },
	{ 1.09642857142857, 150, 20 },
	{ 1.14642857142857, 150, 20 },
	{ 1.19642857142857, 150, 20 },
	{ 1.24642857142857, 150, 20 },
	{ 1.29642857142857, 150, 20 },
	{ 1.34642857142857, 150, 20 },
	{ 1.39642857142857, 150, 20 },
	{ 1.44642857142857, 150, 20 },
	{ 1.49642857142857, 150, 20 },
	{ 1.54642857142857, 150, 20 },
	{ 1.59642857142857, 150, 20 },
	{ 1.64642857142857, 150, 20 },
	{ 1.69642857142857, 150, 20 },
	{ 1.74642857142857, 150, 20 },
	{ 1.79642857142857, 150, 20 },
	{ 1.84642857142857, 150, 20 },
	{ 1.89642857142857, 150, 20 },
	{ 1.94642857142857, 150, 20 },
	{ 1.99642857142857, 150, 20 },
	{ 2.04642857142857, 150, 20 },
	{ 2.09642857142857, 150, 20 },
	{ 2.14642857142857, 150, 20 },
	{ 2.19642857142857, 150, 20 },
	{ 2.24642857142857, 150, 20 },
	{ 2.29642857142857, 150, 20 },
	{ 2.34642857142857, 150, 20 },
	{ 2.39615384615385, 148.3516484, 20 },
	{ 2.44519230769231, 145.8791209, 20 },
	{ 2.49326923076923, 142.5824176, 20 },
	{ 2.54010989010989, 138.4615385, 20 },
	{ 2.58543956043956, 133.5164835, 20 },
	{ 2.62898351648352, 127.7472527, 20 },
	{ 2.67046703296703, 121.1538462, 20 },
	{ 2.70961538461538, 113.7362637, 20 },
	{ 2.74615384615385, 105.4945055, 20 },
	{ 2.77980769230769, 96.42857143, 20 },
	{ 2.8103021978022, 86.53846154, 20 },
	{ 2.83736263736264, 75.82417582, 20 },
	{ 2.86071428571429, 64.28571429, 20 },
	{ 2.88049450549451, 54.3956044, 20 },
	{ 2.89711538461538, 45.32967033, 20 },
	{ 2.91085164835165, 37.08791209, 20 },
	{ 2.92197802197802, 29.67032967, 20 },
	{ 2.93076923076923, 23.07692308, 20 },
	{ 2.9375, 17.30769231, 20 },
	{ 2.94244505494505, 12.36263736, 20 },
	{ 2.94587912087912, 8.241758242, 20 },
	{ 2.94807692307692, 4.945054945, 20 },
	{ 2.94931318681319, 2.472527473, 20 },
	{ 2.94986263736264, 0.824175824, 20 },
	{ 2.95, 2.97381E-15, 20 },
	{ 2.95, 0, 20 }
};
const int Mp90TurnSize = 86;

// A 180 Turn
const double Mp180Turn[][3] =
{
	{0,	0	,20},
	{0.00025,	1.5	,20},
	{0.001125,	3.75	,20},
	{0.002875,	6.75	,20},
	{0.00575,	10.5	,20},
	{0.01,	15	,20},
	{0.015875,	20.25	,20},
	{0.023625,	26.25	,20},
	{0.0335,	33	,20},
	{0.04575,	40.5	,20},
	{0.060625,	48.75	,20},
	{0.078375,	57.75	,30},
	{0.09925,	67.5	,20},
	{0.1235,	78	,20},
	{0.151375,	89.25	,20},
	{0.183125,	101.25	,20},
	{0.218625,	111.75	,20},
	{0.2575,	121.5	,20},
	{0.2995,	130.5	,20},
	{0.344375,	138.75	,20},
	{0.391875,	146.25	,20},
	{0.44175,	153	,20},
	{0.49375,	159	,20},
	{0.547625,	164.25	,20},
	{0.603125,	168.75	,20},
	{0.66,	172.5	,20},
	{0.718,	175.5	,20},
	{0.776875,	177.75	,20},
	{0.836375,	179.25	,20},
	{0.89625,	180	,20},
	{0.95625,	180	,20},
	{1.01625,	180	,20},
	{1.07625,	180	,20},
	{1.13625,	180	,20},
	{1.19625,	180	,20},
	{1.25625,	180	,20},
	{1.31625,	180	,20},
	{1.37625,	180	,20},
	{1.43625,	180	,20},
	{1.49625,	180	,20},
	{1.55625,	180	,20},
	{1.61625,	180	,20},
	{1.67625,	180	,20},
	{1.73625,	180	,20},
	{1.79625,	180	,20},
	{1.85625,	180	,20},
	{1.91625,	180	,20},
	{1.97625,	180	,20},
	{2.03625,	180	,20},
	{2.09625,	180	,20},
	{2.15625,	180	,20},
	{2.21625,	180	,20},
	{2.27625,	180	,20},
	{2.33625,	180	,20},
	{2.39625,	180	,20},
	{2.45625,	180	,20},
	{2.51625,	180	,20},
	{2.57625,	180	,20},
	{2.63625,	180	,20},
	{2.69625,	180	,20},
	{2.75625,	180	,20},
	{2.81625,	180	,20},
	{2.87625,	180	,20},
	{2.93625,	180	,20},
	{2.99625,	180	,20},
	{3.05625,	180	,20},
	{3.11625,	180	,20},
	{3.17625,	180	,20},
	{3.23625,	180	,20},
	{3.29625,	180	,20},
	{3.35625,	180	,20},
	{3.41625,	180	,20},
	{3.47625,	180	,20},
	{3.53625,	180	,20},
	{3.59625,	180	,20},
	{3.65625,	180	,20},
	{3.71625,	180	,20},
	{3.77625,	180	,20},
	{3.83625,	180	,20},
	{3.89625,	180	,20},
	{3.95625,	180	,20},
	{4.01625,	180	,20},
	{4.07625,	180	,20},
	{4.13625,	180	,20},
	{4.19625,	180	,20},
	{4.25625,	180	,20},
	{4.31625,	180	,20},
	{4.37625,	180	,20},
	{4.43625,	180	,20},
	{4.49625,	180	,20},
	{4.55625,	180	,20},
	{4.61625,	180	,20},
	{4.67625,	180	,20},
	{4.73625,	180	,20},
	{4.79625,	180	,20},
	{4.85625,	180	,20},
	{4.91625,	180	,20},
	{4.97625,	180	,20},
	{5.036,	178.5	,20},
	{5.095125,	176.25	,20},
	{5.153375,	173.25	,20},
	{5.2105,	169.5	,20},
	{5.26625,	165	,20},
	{5.320375,	159.75	,20},
	{5.372625,	153.75	,20},
	{5.42275,	147	,20},
	{5.4705,	139.5	,20},
	{5.515625,	131.25	,20},
	{5.557875,	122.25	,20},
	{5.597,	112.5	,20},
	{5.63275,	102	,20},
	{5.664875,	90.75	,20},
	{5.693125,	78.75	,20},
	{5.717625,	68.25	,20},
	{5.73875,	58.5	,20},
	{5.75674999999999,	49.5	,20},
	{5.771875,	41.25	,20},
	{5.784375,	33.75	,20},
	{5.7945,	27	,20},
	{5.8025,	21	,20},
	{5.808625,	15.75	,20},
	{5.813125,	11.25	,20},
	{5.81625,	7.5	,20},
	{5.81825,	4.5	,20},
	{5.819375,	2.25	,20},
	{5.819875,	0.75	,20},
	{5.81999999999999,	2.18575E-15	,20},
	{5.81999999999999,	0	,20}
};
const int Mp180TurnSize = 128;

const double MpPeg86[][3] =
{
	{ 0, 0, 30 },
	{ 0.000571428571428571, 2.285714286, 30 },
	{ 0.00257142857142857, 5.714285714, 30 },
	{ 0.00657142857142857, 10.28571429, 30 },
	{ 0.0131428571428571, 16, 30 },
	{ 0.0228571428571429, 22.85714286, 30 },
	{ 0.0362857142857143, 30.85714286, 30 },
	{ 0.054, 40, 30 },
	{ 0.0765714285714286, 50.28571429, 30 },
	{ 0.104571428571429, 61.71428571, 30 },
	{ 0.138571428571429, 74.28571429, 30 },
	{ 0.179142857142857, 88, 30 },
	{ 0.226857142857143, 102.8571429, 30 },
	{ 0.282285714285714, 118.8571429, 30 },
	{ 0.346, 136, 30 },
	{ 0.417714285714286, 150.8571429, 30 },
	{ 0.496571428571428, 164.5714286, 30 },
	{ 0.582, 177.1428571, 30 },
	{ 0.673428571428571, 188.5714286, 30 },
	{ 0.770285714285714, 198.8571429, 30 },
	{ 0.872, 208, 30 },
	{ 0.978, 216, 30 },
	{ 1.08771428571429, 222.8571429, 30 },
	{ 1.20057142857143, 228.5714286, 30 },
	{ 1.316, 233.1428571, 30 },
	{ 1.43342857142857, 236.5714286, 30 },
	{ 1.55228571428571, 238.8571429, 30 },
	{ 1.672, 240, 30 },
	{ 1.792, 240, 30 },
	{ 1.912, 240, 30 },
	{ 2.032, 240, 30 },
	{ 2.152, 240, 30 },
	{ 2.272, 240, 30 },
	{ 2.392, 240, 30 },
	{ 2.512, 240, 30 },
	{ 2.632, 240, 30 },
	{ 2.752, 240, 30 },
	{ 2.872, 240, 30 },
	{ 2.992, 240, 30 },
	{ 3.112, 240, 30 },
	{ 3.232, 240, 30 },
	{ 3.352, 240, 30 },
	{ 3.472, 240, 30 },
	{ 3.592, 240, 30 },
	{ 3.712, 240, 30 },
	{ 3.832, 240, 30 },
	{ 3.952, 240, 30 },
	{ 4.072, 240, 30 },
	{ 4.192, 240, 30 },
	{ 4.312, 240, 30 },
	{ 4.432, 240, 30 },
	{ 4.552, 240, 30 },
	{ 4.672, 240, 30 },
	{ 4.792, 240, 30 },
	{ 4.912, 240, 30 },
	{ 5.032, 240, 30 },
	{ 5.152, 240, 30 },
	{ 5.272, 240, 30 },
	{ 5.392, 240, 30 },
	{ 5.512, 240, 30 },
	{ 5.632, 240, 30 },
	{ 5.752, 240, 30 },
	{ 5.872, 240, 30 },
	{ 5.992, 240, 30 },
	{ 6.112, 240, 30 },
	{ 6.232, 240, 30 },
	{ 6.352, 240, 30 },
	{ 6.472, 240, 30 },
	{ 6.592, 240, 30 },
	{ 6.712, 240, 30 },
	{ 6.832, 240, 30 },
	{ 6.952, 240, 30 },
	{ 7.072, 240, 30 },
	{ 7.192, 240, 30 },
	{ 7.312, 240, 30 },
	{ 7.432, 240, 30 },
	{ 7.552, 240, 30 },
	{ 7.672, 240, 30 },
	{ 7.792, 240, 30 },
	{ 7.912, 240, 30 },
	{ 8.032, 240, 30 },
	{ 8.152, 240, 30 },
	{ 8.272, 240, 30 },
	{ 8.392, 240, 30 },
	{ 8.51142857142857, 237.7142857, 30 },
	{ 8.62942857142857, 234.2857143, 30 },
	{ 8.74542857142857, 229.7142857, 30 },
	{ 8.85885714285714, 224, 30 },
	{ 8.96914285714286, 217.1428571, 30 },
	{ 9.07571428571429, 209.1428571, 30 },
	{ 9.178, 200, 30 },
	{ 9.27542857142857, 189.7142857, 30 },
	{ 9.36742857142857, 178.2857143, 30 },
	{ 9.45342857142857, 165.7142857, 30 },
	{ 9.53285714285714, 152, 30 },
	{ 9.60514285714286, 137.1428571, 30 },
	{ 9.66971428571429, 121.1428571, 30 },
	{ 9.726, 104, 30 },
	{ 9.77428571428571, 89.14285714, 30 },
	{ 9.81542857142857, 75.42857143, 30 },
	{ 9.85, 62.85714286, 30 },
	{ 9.87857142857143, 51.42857143, 30 },
	{ 9.90171428571429, 41.14285714, 30 },
	{ 9.92, 32, 30 },
	{ 9.934, 24, 30 },
	{ 9.94428571428571, 17.14285714, 30 },
	{ 9.95142857142857, 11.42857143, 30 },
	{ 9.956, 6.857142857, 30 },
	{ 9.95857142857143, 3.428571429, 30 },
	{ 9.95971428571429, 1.142857143, 30 },
	{ 9.96, 5.32907E-15, 30 },
	{ 9.96, 0, 30 }
};
const int MpPeg86Size = 112;

const double MpPeg92[][3] =
{
		{0,	0	,30},
		{0.000769230769230769,	3.076923077	,30},
		{0.00346153846153846,	7.692307692	,30},
		{0.00884615384615385,	13.84615385	,30},
		{0.0176923076923077,	21.53846154	,30},
		{0.0307692307692308,	30.76923077	,30},
		{0.0488461538461538,	41.53846154	,30},
		{0.0726923076923077,	53.84615385	,30},
		{0.103076923076923,	67.69230769	,30},
		{0.140769230769231,	83.07692308	,30},
		{0.186538461538462,	100	,30},
		{0.241153846153846,	118.4615385	,30},
		{0.305384615384615,	138.4615385	,30},
		{0.378846153846154,	155.3846154	,30},
		{0.460384615384615,	170.7692308	,30},
		{0.549230769230769,	184.6153846	,30},
		{0.644615384615385,	196.9230769	,30},
		{0.745769230769231,	207.6923077	,30},
		{0.851923076923077,	216.9230769	,30},
		{0.962307692307692,	224.6153846	,30},
		{1.07615384615385,	230.7692308	,30},
		{1.19269230769231,	235.3846154	,30},
		{1.31115384615385,	238.4615385	,30},
		{1.43076923076923,	240	,30},
		{1.55076923076923,	240	,30},
		{1.67076923076923,	240	,30},
		{1.79076923076923,	240	,30},
		{1.91076923076923,	240	,30},
		{2.03076923076923,	240	,30},
		{2.15076923076923,	240	,30},
		{2.27076923076923,	240	,30},
		{2.39076923076923,	240	,30},
		{2.51076923076923,	240	,30},
		{2.63076923076923,	240	,30},
		{2.75076923076923,	240	,30},
		{2.87076923076923,	240	,30},
		{2.99076923076923,	240	,30},
		{3.11076923076923,	240	,30},
		{3.23076923076923,	240	,30},
		{3.35076923076923,	240	,30},
		{3.47076923076923,	240	,30},
		{3.59076923076923,	240	,30},
		{3.71076923076923,	240	,30},
		{3.83076923076923,	240	,30},
		{3.95076923076923,	240	,30},
		{4.07076923076923,	240	,30},
		{4.19076923076923,	240	,30},
		{4.31076923076923,	240	,30},
		{4.43076923076923,	240	,30},
		{4.55076923076923,	240	,30},
		{4.67076923076923,	240	,30},
		{4.79076923076923,	240	,30},
		{4.91076923076923,	240	,30},
		{5.03076923076923,	240	,30},
		{5.15076923076923,	240	,30},
		{5.27076923076923,	240	,30},
		{5.39076923076923,	240	,30},
		{5.51076923076923,	240	,30},
		{5.63076923076923,	240	,30},
		{5.75076923076923,	240	,30},
		{5.87076923076923,	240	,30},
		{5.99076923076923,	240	,30},
		{6.11076923076923,	240	,30},
		{6.23076923076923,	240	,30},
		{6.35076923076923,	240	,30},
		{6.47076923076923,	240	,30},
		{6.59076923076923,	240	,30},
		{6.71076923076923,	240	,30},
		{6.83076923076923,	240	,30},
		{6.95076923076924,	240	,30},
		{7.07076923076924,	240	,30},
		{7.19076923076924,	240	,30},
		{7.31076923076924,	240	,30},
		{7.43076923076924,	240	,30},
		{7.55076923076924,	240	,30},
		{7.67076923076924,	240	,30},
		{7.79076923076924,	240	,30},
		{7.91076923076924,	240	,30},
		{8.03076923076924,	240	,30},
		{8.15076923076924,	240	,30},
		{8.27076923076923,	240	,30},
		{8.39076923076923,	240	,30},
		{8.51076923076923,	240	,30},
		{8.63076923076923,	240	,30},
		{8.75076923076923,	240	,30},
		{8.87076923076923,	240	,30},
		{8.99076923076923,	240	,30},
		{9.11076923076923,	240	,30},
		{9.23076923076923,	240	,30},
		{9.35076923076923,	240	,30},
		{9.47,	236.9230769	,30},
		{9.58730769230769,	232.3076923	,30},
		{9.70192307692307,	226.1538462	,30},
		{9.81307692307692,	218.4615385	,30},
		{9.92,	209.2307692	,30},
		{10.0219230769231,	198.4615385	,30},
		{10.1180769230769,	186.1538462	,30},
		{10.2076923076923,	172.3076923	,30},
		{10.29,	156.9230769	,30},
		{10.3642307692308,	140	,30},
		{10.4296153846154,	121.5384615	,30},
		{10.4853846153846,	101.5384615	,30},
		{10.5319230769231,	84.61538462	,30},
		{10.5703846153846,	69.23076923	,30},
		{10.6015384615385,	55.38461538	,30},
		{10.6261538461538,	43.07692308	,30},
		{10.645,	32.30769231	,30},
		{10.6588461538462,	23.07692308	,30},
		{10.6684615384615,	15.38461538	,30},
		{10.6746153846154,	9.230769231	,30},
		{10.6780769230769,	4.615384615	,30},
		{10.6796153846154,	1.538461538	,30},
		{10.68,	0	,30}
};
const int MpPeg92Size = 113;

//
const double Mp28p5[][3] =
{
	{ 0, 0, 20 },
	{ 0.00021978021978022, 1.318681319, 20 },
	{ 0.000989010989010989, 3.296703297, 20 },
	{ 0.00252747252747253, 5.934065934, 20 },
	{ 0.00505494505494506, 9.230769231, 20 },
	{ 0.00879120879120879, 13.18681319, 20 },
	{ 0.013956043956044, 17.8021978, 20 },
	{ 0.0207692307692308, 23.07692308, 20 },
	{ 0.0294505494505495, 29.01098901, 20 },
	{ 0.0402197802197802, 35.6043956, 20 },
	{ 0.0532967032967033, 42.85714286, 20 },
	{ 0.0689010989010989, 50.76923077, 30 },
	{ 0.0872527472527472, 59.34065934, 20 },
	{ 0.108571428571429, 68.57142857, 20 },
	{ 0.132747252747253, 76.48351648, 20 },
	{ 0.159450549450549, 83.73626374, 20 },
	{ 0.188461538461538, 90.32967033, 20 },
	{ 0.21956043956044, 96.26373626, 20 },
	{ 0.252527472527472, 101.5384615, 20 },
	{ 0.287142857142857, 106.1538462, 20 },
	{ 0.323186813186813, 110.1098901, 20 },
	{ 0.36043956043956, 113.4065934, 20 },
	{ 0.398681318681319, 116.043956, 20 },
	{ 0.437692307692308, 118.021978, 20 },
	{ 0.477252747252747, 119.3406593, 20 },
	{ 0.517142857142857, 120, 20 },
	{ 0.557142857142857, 120, 20 },
	{ 0.597142857142857, 120, 20 },
	{ 0.637142857142857, 120, 20 },
	{ 0.677142857142857, 120, 20 },
	{ 0.717142857142857, 120, 20 },
	{ 0.757142857142857, 120, 20 },
	{ 0.797142857142857, 120, 20 },
	{ 0.837142857142857, 120, 20 },
	{ 0.877142857142857, 120, 20 },
	{ 0.917142857142857, 120, 20 },
	{ 0.957142857142857, 120, 20 },
	{ 0.997142857142857, 120, 20 },
	{ 1.03714285714286, 120, 20 },
	{ 1.07714285714286, 120, 20 },
	{ 1.11714285714286, 120, 20 },
	{ 1.15714285714286, 120, 20 },
	{ 1.19714285714286, 120, 20 },
	{ 1.23714285714286, 120, 20 },
	{ 1.27714285714286, 120, 20 },
	{ 1.31714285714286, 120, 20 },
	{ 1.35714285714286, 120, 20 },
	{ 1.39714285714286, 120, 20 },
	{ 1.43714285714286, 120, 20 },
	{ 1.47714285714286, 120, 20 },
	{ 1.51714285714286, 120, 20 },
	{ 1.55714285714286, 120, 20 },
	{ 1.59714285714286, 120, 20 },
	{ 1.63714285714286, 120, 20 },
	{ 1.67714285714286, 120, 20 },
	{ 1.71714285714286, 120, 20 },
	{ 1.75714285714286, 120, 20 },
	{ 1.79714285714286, 120, 20 },
	{ 1.83714285714286, 120, 20 },
	{ 1.87714285714286, 120, 20 },
	{ 1.91714285714286, 120, 20 },
	{ 1.95714285714286, 120, 20 },
	{ 1.99714285714286, 120, 20 },
	{ 2.03714285714286, 120, 20 },
	{ 2.07714285714286, 120, 20 },
	{ 2.11714285714286, 120, 20 },
	{ 2.15714285714286, 120, 20 },
	{ 2.19714285714286, 120, 20 },
	{ 2.23714285714286, 120, 20 },
	{ 2.27714285714286, 120, 20 },
	{ 2.31714285714286, 120, 20 },
	{ 2.35714285714286, 120, 20 },
	{ 2.39714285714286, 120, 20 },
	{ 2.43714285714286, 120, 20 },
	{ 2.47714285714286, 120, 20 },
	{ 2.51714285714286, 120, 20 },
	{ 2.55692307692308, 118.6813187, 20 },
	{ 2.59615384615385, 116.7032967, 20 },
	{ 2.63461538461539, 114.0659341, 20 },
	{ 2.67208791208791, 110.7692308, 20 },
	{ 2.70835164835165, 106.8131868, 20 },
	{ 2.74318681318681, 102.1978022, 20 },
	{ 2.77637362637363, 96.92307692, 20 },
	{ 2.80769230769231, 90.98901099, 20 },
	{ 2.83692307692308, 84.3956044, 20 },
	{ 2.86384615384616, 77.14285714, 20 },
	{ 2.88824175824176, 69.23076923, 20 },
	{ 2.90989010989011, 60.65934066, 20 },
	{ 2.92857142857143, 51.42857143, 20 },
	{ 2.94439560439561, 43.51648352, 20 },
	{ 2.95769230769231, 36.26373626, 20 },
	{ 2.96868131868132, 29.67032967, 20 },
	{ 2.97758241758242, 23.73626374, 20 },
	{ 2.98461538461539, 18.46153846, 20 },
	{ 2.99, 13.84615385, 20 },
	{ 2.99395604395605, 9.89010989, 20 },
	{ 2.9967032967033, 6.593406593, 20 },
	{ 2.99846153846154, 3.956043956, 20 },
	{ 2.99945054945055, 1.978021978, 20 },
	{ 2.99989010989011, 0.659340659, 20 },
	{ 3, 2.37905E-15, 20 },
	{ 3, 0, 20 }
};
const int Mp28p5Size = 102;

const double Mp35p125[][3] =
{
	{ 0, 0, 20 },
	{ 0.000208333333333333, 1.25, 20 },
	{ 0.0009375, 3.125, 20 },
	{ 0.00239583333333333, 5.625, 20 },
	{ 0.00479166666666667, 8.75, 20 },
	{ 0.00833333333333333, 12.5, 20 },
	{ 0.0132291666666667, 16.875, 20 },
	{ 0.0196875, 21.875, 20 },
	{ 0.0279166666666667, 27.5, 20 },
	{ 0.038125, 33.75, 20 },
	{ 0.0505208333333333, 40.625, 20 },
	{ 0.0653125, 48.125, 20 },
	{ 0.0827083333333333, 56.25, 20 },
	{ 0.102916666666667, 65, 20 },
	{ 0.126145833333333, 74.375, 20 },
	{ 0.152604166666667, 84.375, 20 },
	{ 0.1821875, 93.125, 20 },
	{ 0.214583333333333, 101.25, 20 },
	{ 0.249583333333333, 108.75, 20 },
	{ 0.286979166666667, 115.625, 20 },
	{ 0.3265625, 121.875, 20 },
	{ 0.368125, 127.5, 20 },
	{ 0.411458333333333, 132.5, 20 },
	{ 0.456354166666667, 136.875, 20 },
	{ 0.502604166666667, 140.625, 20 },
	{ 0.55, 143.75, 20 },
	{ 0.598333333333333, 146.25, 20 },
	{ 0.647395833333333, 148.125, 20 },
	{ 0.696979166666667, 149.375, 20 },
	{ 0.746875, 150, 20 },
	{ 0.796875, 150, 20 },
	{ 0.846875, 150, 20 },
	{ 0.896875, 150, 20 },
	{ 0.946875, 150, 20 },
	{ 0.996875, 150, 20 },
	{ 1.046875, 150, 20 },
	{ 1.096875, 150, 20 },
	{ 1.146875, 150, 20 },
	{ 1.196875, 150, 20 },
	{ 1.246875, 150, 20 },
	{ 1.296875, 150, 20 },
	{ 1.346875, 150, 20 },
	{ 1.396875, 150, 20 },
	{ 1.446875, 150, 20 },
	{ 1.496875, 150, 20 },
	{ 1.546875, 150, 20 },
	{ 1.596875, 150, 20 },
	{ 1.646875, 150, 20 },
	{ 1.696875, 150, 20 },
	{ 1.746875, 150, 20 },
	{ 1.796875, 150, 20 },
	{ 1.846875, 150, 20 },
	{ 1.896875, 150, 20 },
	{ 1.946875, 150, 20 },
	{ 1.996875, 150, 20 },
	{ 2.046875, 150, 20 },
	{ 2.096875, 150, 20 },
	{ 2.146875, 150, 20 },
	{ 2.196875, 150, 20 },
	{ 2.246875, 150, 20 },
	{ 2.296875, 150, 20 },
	{ 2.346875, 150, 20 },
	{ 2.396875, 150, 20 },
	{ 2.446875, 150, 20 },
	{ 2.496875, 150, 20 },
	{ 2.546875, 150, 20 },
	{ 2.596875, 150, 20 },
	{ 2.646875, 150, 20 },
	{ 2.696875, 150, 20 },
	{ 2.746875, 150, 20 },
	{ 2.796875, 150, 20 },
	{ 2.846875, 150, 20 },
	{ 2.896875, 150, 20 },
	{ 2.946875, 150, 20 },
	{ 2.996875, 150, 20 },
	{ 3.046875, 150, 20 },
	{ 3.096875, 150, 20 },
	{ 3.146875, 150, 20 },
	{ 3.196875, 150, 20 },
	{ 3.246875, 150, 20 },
	{ 3.296875, 150, 20 },
	{ 3.346875, 150, 20 },
	{ 3.39666666666666, 148.75, 20 },
	{ 3.4459375, 146.875, 20 },
	{ 3.49447916666666, 144.375, 20 },
	{ 3.54208333333333, 141.25, 20 },
	{ 3.58854166666666, 137.5, 20 },
	{ 3.63364583333333, 133.125, 20 },
	{ 3.6771875, 128.125, 20 },
	{ 3.71895833333333, 122.5, 20 },
	{ 3.75875, 116.25, 20 },
	{ 3.79635416666666, 109.375, 20 },
	{ 3.8315625, 101.875, 20 },
	{ 3.86416666666666, 93.75, 20 },
	{ 3.89395833333333, 85, 20 },
	{ 3.92072916666666, 75.625, 20 },
	{ 3.94427083333333, 65.625, 20 },
	{ 3.9646875, 56.875, 20 },
	{ 3.98229166666666, 48.75, 20 },
	{ 3.99729166666666, 41.25, 20 },
	{ 4.00989583333333, 34.375, 20 },
	{ 4.0203125, 28.125, 20 },
	{ 4.02875, 22.5, 20 },
	{ 4.03541666666666, 17.5, 20 },
	{ 4.04052083333333, 13.125, 20 },
	{ 4.04427083333333, 9.375, 20 },
	{ 4.046875, 6.25, 20 },
	{ 4.04854166666666, 3.75, 20 },
	{ 4.04947916666666, 1.875, 20 },
	{ 4.04989583333333, 0.625, 20 },
	{ 4.05, 1.82146E-15, 20 },
	{ 4.05, 0, 20 }
};
const int Mp35p125Size = 112;

// 100 Inches
const double Mp100[][3] =
{
	{ 0, 0, 30 },
	{ 0.000571428571428571, 2.285714286, 30 },
	{ 0.00257142857142857, 5.714285714, 30 },
	{ 0.00657142857142857, 10.28571429, 30 },
	{ 0.0131428571428571, 16, 30 },
	{ 0.0228571428571429, 22.85714286, 30 },
	{ 0.0362857142857143, 30.85714286, 30 },
	{ 0.054, 40, 30 },
	{ 0.0765714285714286, 50.28571429, 30 },
	{ 0.104571428571429, 61.71428571, 30 },
	{ 0.138571428571429, 74.28571429, 30 },
	{ 0.179142857142857, 88, 30 },
	{ 0.226857142857143, 102.8571429, 30 },
	{ 0.282285714285714, 118.8571429, 30 },
	{ 0.346, 136, 30 },
	{ 0.417714285714286, 150.8571429, 30 },
	{ 0.496571428571428, 164.5714286, 30 },
	{ 0.582, 177.1428571, 30 },
	{ 0.673428571428571, 188.5714286, 30 },
	{ 0.770285714285714, 198.8571429, 30 },
	{ 0.872, 208, 30 },
	{ 0.978, 216, 30 },
	{ 1.08771428571429, 222.8571429, 30 },
	{ 1.20057142857143, 228.5714286, 30 },
	{ 1.316, 233.1428571, 30 },
	{ 1.43342857142857, 236.5714286, 30 },
	{ 1.55228571428571, 238.8571429, 30 },
	{ 1.672, 240, 30 },
	{ 1.792, 240, 30 },
	{ 1.912, 240, 30 },
	{ 2.032, 240, 30 },
	{ 2.152, 240, 30 },
	{ 2.272, 240, 30 },
	{ 2.392, 240, 30 },
	{ 2.512, 240, 30 },
	{ 2.632, 240, 30 },
	{ 2.752, 240, 30 },
	{ 2.872, 240, 30 },
	{ 2.992, 240, 30 },
	{ 3.112, 240, 30 },
	{ 3.232, 240, 30 },
	{ 3.352, 240, 30 },
	{ 3.472, 240, 30 },
	{ 3.592, 240, 30 },
	{ 3.712, 240, 30 },
	{ 3.832, 240, 30 },
	{ 3.952, 240, 30 },
	{ 4.072, 240, 30 },
	{ 4.192, 240, 30 },
	{ 4.312, 240, 30 },
	{ 4.432, 240, 30 },
	{ 4.552, 240, 30 },
	{ 4.672, 240, 30 },
	{ 4.792, 240, 30 },
	{ 4.912, 240, 30 },
	{ 5.032, 240, 30 },
	{ 5.152, 240, 30 },
	{ 5.272, 240, 30 },
	{ 5.392, 240, 30 },
	{ 5.512, 240, 30 },
	{ 5.632, 240, 30 },
	{ 5.752, 240, 30 },
	{ 5.872, 240, 30 },
	{ 5.992, 240, 30 },
	{ 6.112, 240, 30 },
	{ 6.232, 240, 30 },
	{ 6.352, 240, 30 },
	{ 6.472, 240, 30 },
	{ 6.592, 240, 30 },
	{ 6.712, 240, 30 },
	{ 6.832, 240, 30 },
	{ 6.952, 240, 30 },
	{ 7.072, 240, 30 },
	{ 7.192, 240, 30 },
	{ 7.312, 240, 30 },
	{ 7.432, 240, 30 },
	{ 7.552, 240, 30 },
	{ 7.672, 240, 30 },
	{ 7.792, 240, 30 },
	{ 7.912, 240, 30 },
	{ 8.032, 240, 30 },
	{ 8.152, 240, 30 },
	{ 8.272, 240, 30 },
	{ 8.392, 240, 30 },
	{ 8.512, 240, 30 },
	{ 8.632, 240, 30 },
	{ 8.752, 240, 30 },
	{ 8.872, 240, 30 },
	{ 8.992, 240, 30 },
	{ 9.112, 240, 30 },
	{ 9.232, 240, 30 },
	{ 9.35199999999999, 240, 30 },
	{ 9.47199999999999, 240, 30 },
	{ 9.59199999999999, 240, 30 },
	{ 9.71199999999999, 240, 30 },
	{ 9.83199999999999, 240, 30 },
	{ 9.95199999999999, 240, 30 },
	{ 10.0714285714286, 237.7142857, 30 },
	{ 10.1894285714286, 234.2857143, 30 },
	{ 10.3054285714286, 229.7142857, 30 },
	{ 10.4188571428571, 224, 30 },
	{ 10.5291428571428, 217.1428571, 30 },
	{ 10.6357142857143, 209.1428571, 30 },
	{ 10.738, 200, 30 },
	{ 10.8354285714286, 189.7142857, 30 },
	{ 10.9274285714286, 178.2857143, 30 },
	{ 11.0134285714286, 165.7142857, 30 },
	{ 11.0928571428571, 152, 30 },
	{ 11.1651428571428, 137.1428571, 30 },
	{ 11.2297142857143, 121.1428571, 30 },
	{ 11.286, 104, 30 },
	{ 11.3342857142857, 89.14285714, 30 },
	{ 11.3754285714286, 75.42857143, 30 },
	{ 11.41, 62.85714286, 30 },
	{ 11.4385714285714, 51.42857143, 30 },
	{ 11.4617142857143, 41.14285714, 30 },
	{ 11.48, 32, 30 },
	{ 11.494, 24, 30 },
	{ 11.5042857142857, 17.14285714, 30 },
	{ 11.5114285714286, 11.42857143, 30 },
	{ 11.516, 6.857142857, 30 },
	{ 11.5185714285714, 3.428571429, 30 },
	{ 11.5197142857143, 1.142857143, 30 },
	{ 11.52, 5.32907E-15, 30 },
	{ 11.52, 0, 30 }
};
const int Mp100Size = 125;

const double Mp81p5[][3] =
{
		{0,	0	,25},
		{0.00037593984962406,	1.804511278	,25},
		{0.00169172932330827,	4.511278195	,25},
		{0.00432330827067669,	8.120300752	,25},
		{0.00864661654135338,	12.63157895	,25},
		{0.0150375939849624,	18.04511278	,25},
		{0.0238721804511278,	24.36090226	,25},
		{0.0355263157894737,	31.57894737	,25},
		{0.0503759398496241,	39.69924812	,25},
		{0.068796992481203,	48.72180451	,25},
		{0.0911654135338346,	58.64661654	,25},
		{0.117857142857143,	69.47368421	,30},
		{0.149248120300752,	81.20300752	,25},
		{0.185714285714286,	93.83458647	,25},
		{0.227631578947368,	107.3684211	,25},
		{0.275,	120	,25},
		{0.327631578947368,	132.6315789	,25},
		{0.385526315789474,	145.2631579	,25},
		{0.448684210526316,	157.8947368	,25},
		{0.516917293233083,	169.6240602	,25},
		{0.58984962406015,	180.4511278	,25},
		{0.667105263157895,	190.3759398	,25},
		{0.748308270676691,	199.3984962	,25},
		{0.833082706766917,	207.518797	,25},
		{0.921052631578947,	214.7368421	,25},
		{1.01184210526316,	221.0526316	,25},
		{1.10507518796992,	226.4661654	,25},
		{1.20037593984962,	230.9774436	,25},
		{1.29736842105263,	234.5864662	,25},
		{1.39567669172932,	237.2932331	,25},
		{1.49492481203008,	239.0977444	,25},
		{1.59473684210526,	240	,25},
		{1.69473684210526,	240	,25},
		{1.79473684210526,	240	,25},
		{1.89473684210526,	240	,25},
		{1.99473684210526,	240	,25},
		{2.09473684210526,	240	,25},
		{2.19473684210526,	240	,25},
		{2.29473684210526,	240	,25},
		{2.39473684210526,	240	,25},
		{2.49473684210526,	240	,25},
		{2.59473684210526,	240	,25},
		{2.69473684210526,	240	,25},
		{2.79473684210526,	240	,25},
		{2.89473684210526,	240	,25},
		{2.99473684210526,	240	,25},
		{3.09473684210526,	240	,25},
		{3.19473684210526,	240	,25},
		{3.29473684210526,	240	,25},
		{3.39473684210526,	240	,25},
		{3.49473684210526,	240	,25},
		{3.59473684210526,	240	,25},
		{3.69473684210526,	240	,25},
		{3.79473684210526,	240	,25},
		{3.89473684210527,	240	,25},
		{3.99473684210527,	240	,25},
		{4.09473684210526,	240	,25},
		{4.19473684210526,	240	,25},
		{4.29473684210526,	240	,25},
		{4.39473684210526,	240	,25},
		{4.49473684210526,	240	,25},
		{4.59473684210526,	240	,25},
		{4.69473684210526,	240	,25},
		{4.79473684210526,	240	,25},
		{4.89473684210526,	240	,25},
		{4.99473684210526,	240	,25},
		{5.09473684210526,	240	,25},
		{5.19473684210526,	240	,25},
		{5.29473684210526,	240	,25},
		{5.39473684210526,	240	,25},
		{5.49473684210526,	240	,25},
		{5.59473684210526,	240	,25},
		{5.69473684210526,	240	,25},
		{5.79473684210526,	240	,25},
		{5.89473684210526,	240	,25},
		{5.99473684210526,	240	,25},
		{6.09473684210526,	240	,25},
		{6.19473684210526,	240	,25},
		{6.29473684210526,	240	,25},
		{6.39473684210526,	240	,25},
		{6.49473684210526,	240	,25},
		{6.59473684210526,	240	,25},
		{6.69473684210526,	240	,25},
		{6.79473684210526,	240	,25},
		{6.89473684210525,	240	,25},
		{6.99473684210525,	240	,25},
		{7.09473684210525,	240	,25},
		{7.19473684210525,	240	,25},
		{7.29473684210525,	240	,25},
		{7.39473684210525,	240	,25},
		{7.49473684210525,	240	,25},
		{7.59473684210525,	240	,25},
		{7.69473684210525,	240	,25},
		{7.79473684210525,	240	,25},
		{7.89473684210525,	240	,25},
		{7.99436090225563,	238.1954887	,25},
		{8.09304511278194,	235.4887218	,25},
		{8.19041353383457,	231.8796992	,25},
		{8.2860902255639,	227.3684211	,25},
		{8.37969924812029,	221.9548872	,25},
		{8.47086466165412,	215.6390977	,25},
		{8.55921052631578,	208.4210526	,25},
		{8.64436090225563,	200.3007519	,25},
		{8.72593984962405,	191.2781955	,25},
		{8.80357142857142,	181.3533835	,25},
		{8.87687969924811,	170.5263158	,25},
		{8.9454887218045,	158.7969925	,25},
		{9.00902255639097,	146.1654135	,25},
		{9.06710526315788,	132.6315789	,25},
		{9.11973684210525,	120	,25},
		{9.16710526315788,	107.3684211	,25},
		{9.20921052631578,	94.73684211	,25},
		{9.24605263157894,	82.10526316	,25},
		{9.27781954887217,	70.37593985	,25},
		{9.3048872180451,	59.54887218	,25},
		{9.32763157894736,	49.62406015	,25},
		{9.34642857142856,	40.60150376	,25},
		{9.36165413533834,	32.48120301	,25},
		{9.37368421052631,	25.26315789	,25},
		{9.3828947368421,	18.94736842	,25},
		{9.38966165413533,	13.53383459	,25},
		{9.39436090225563,	9.022556391	,25},
		{9.39736842105262,	5.413533835	,25},
		{9.39906015037593,	2.706766917	,25},
		{9.39981203007518,	0.902255639	,25},
		{9.39999999999999,	4.20716E-15	,25},
		{9.39999999999999,	0	,25}
};
const int Mp81p5Size = 127;

#endif // PROFILES_H
