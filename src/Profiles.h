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
		turn(turn), size(size), profile(profile), split(split) {    }

	Profile() {  }
  };

// [position] [velocity] [duration(ms)]
// Profiles for driving to the peg

// A 45 degree Turn
const double Mp45Turn[][3] =
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
	{ 1.89615384615385, 148.3516484, 20 },
	{ 1.94519230769231, 145.8791209, 20 },
	{ 1.99326923076923, 142.5824176, 20 },
	{ 2.04010989010989, 138.4615385, 20 },
	{ 2.08543956043956, 133.5164835, 20 },
	{ 2.12898351648352, 127.7472527, 20 },
	{ 2.17046703296703, 121.1538462, 20 },
	{ 2.20961538461539, 113.7362637, 20 },
	{ 2.24615384615385, 105.4945055, 20 },
	{ 2.27980769230769, 96.42857143, 20 },
	{ 2.3103021978022, 86.53846154, 20 },
	{ 2.33736263736264, 75.82417582, 20 },
	{ 2.36071428571429, 64.28571429, 20 },
	{ 2.38049450549451, 54.3956044, 20 },
	{ 2.39711538461539, 45.32967033, 20 },
	{ 2.41085164835165, 37.08791209, 20 },
	{ 2.42197802197802, 29.67032967, 20 },
	{ 2.43076923076923, 23.07692308, 20 },
	{ 2.4375, 17.30769231, 20 },
	{ 2.44244505494506, 12.36263736, 20 },
	{ 2.44587912087912, 8.241758242, 20 },
	{ 2.44807692307692, 4.945054945, 20 },
	{ 2.44931318681319, 2.472527473, 20 },
	{ 2.44986263736264, 0.824175824, 20 },
	{ 2.45, 2.97381E-15, 20 },
	{ 2.45, 0, 20 }
 };
const int Mp45TurnSize = 76;

// A 90 degree Turn
const double Mp90Turn[][3] =
{
	{ 0, 0, 20 },
	{ 0.00032967032967033, 1.978021978, 20 },
	{ 0.00148351648351648, 4.945054945, 20 },
	{ 0.00379120879120879, 8.901098901, 20 },
	{ 0.00758241758241758, 13.84615385, 20 },
	{ 0.0131868131868132, 19.78021978, 20 },
	{ 0.0209340659340659, 26.7032967, 20 },
	{ 0.0311538461538462, 34.61538462, 20 },
	{ 0.0441758241758242, 43.51648352, 20 },
	{ 0.0603296703296703, 53.40659341, 20 },
	{ 0.079945054945055, 64.28571429, 20 },
	{ 0.103351648351648, 76.15384615, 20 },
	{ 0.130879120879121, 89.01098901, 20 },
	{ 0.162857142857143, 102.8571429, 20 },
	{ 0.199120879120879, 114.7252747, 20 },
	{ 0.239175824175824, 125.6043956, 20 },
	{ 0.282692307692308, 135.4945055, 20 },
	{ 0.329340659340659, 144.3956044, 20 },
	{ 0.378791208791209, 152.3076923, 20 },
	{ 0.430714285714286, 159.2307692, 20 },
	{ 0.48478021978022, 165.1648352, 20 },
	{ 0.540659340659341, 170.1098901, 20 },
	{ 0.598021978021978, 174.0659341, 20 },
	{ 0.656538461538462, 177.032967, 20 },
	{ 0.715879120879121, 179.010989, 20 },
	{ 0.775714285714286, 180, 20 },
	{ 0.835714285714286, 180, 20 },
	{ 0.895714285714286, 180, 20 },
	{ 0.955714285714286, 180, 20 },
	{ 1.01571428571429, 180, 20 },
	{ 1.07571428571429, 180, 20 },
	{ 1.13571428571429, 180, 20 },
	{ 1.19571428571429, 180, 20 },
	{ 1.25571428571429, 180, 20 },
	{ 1.31571428571429, 180, 20 },
	{ 1.37571428571429, 180, 20 },
	{ 1.43571428571429, 180, 20 },
	{ 1.49571428571429, 180, 20 },
	{ 1.55571428571429, 180, 20 },
	{ 1.61571428571429, 180, 20 },
	{ 1.67571428571429, 180, 20 },
	{ 1.73571428571429, 180, 20 },
	{ 1.79571428571429, 180, 20 },
	{ 1.85571428571429, 180, 20 },
	{ 1.91571428571429, 180, 20 },
	{ 1.97571428571429, 180, 20 },
	{ 2.03571428571429, 180, 20 },
	{ 2.09571428571429, 180, 20 },
	{ 2.15571428571429, 180, 20 },
	{ 2.21571428571429, 180, 20 },
	{ 2.27571428571429, 180, 20 },
	{ 2.33571428571429, 180, 20 },
	{ 2.39571428571429, 180, 20 },
	{ 2.45571428571429, 180, 20 },
	{ 2.51571428571429, 180, 20 },
	{ 2.57571428571429, 180, 20 },
	{ 2.63571428571429, 180, 20 },
	{ 2.69571428571429, 180, 20 },
	{ 2.75571428571429, 180, 20 },
	{ 2.81571428571429, 180, 20 },
	{ 2.87571428571429, 180, 20 },
	{ 2.93571428571429, 180, 20 },
	{ 2.99571428571429, 180, 20 },
	{ 3.05571428571429, 180, 20 },
	{ 3.11571428571429, 180, 20 },
	{ 3.17571428571429, 180, 20 },
	{ 3.23571428571429, 180, 20 },
	{ 3.29571428571429, 180, 20 },
	{ 3.35571428571429, 180, 20 },
	{ 3.41571428571429, 180, 20 },
	{ 3.47571428571429, 180, 20 },
	{ 3.53571428571429, 180, 20 },
	{ 3.59571428571429, 180, 20 },
	{ 3.65571428571429, 180, 20 },
	{ 3.71571428571429, 180, 20 },
	{ 3.77571428571429, 180, 20 },
	{ 3.83571428571429, 180, 20 },
	{ 3.89571428571429, 180, 20 },
	{ 3.95571428571429, 180, 20 },
	{ 4.01571428571429, 180, 20 },
	{ 4.07571428571429, 180, 20 },
	{ 4.13571428571429, 180, 20 },
	{ 4.19571428571429, 180, 20 },
	{ 4.25538461538462, 178.021978, 20 },
	{ 4.31423076923077, 175.0549451, 20 },
	{ 4.37192307692308, 171.0989011, 20 },
	{ 4.42813186813187, 166.1538462, 20 },
	{ 4.48252747252747, 160.2197802, 20 },
	{ 4.53478021978022, 153.2967033, 20 },
	{ 4.58456043956044, 145.3846154, 20 },
	{ 4.63153846153846, 136.4835165, 20 },
	{ 4.67538461538462, 126.5934066, 20 },
	{ 4.71576923076923, 115.7142857, 20 },
	{ 4.75236263736264, 103.8461538, 20 },
	{ 4.78483516483517, 90.98901099, 20 },
	{ 4.81285714285714, 77.14285714, 20 },
	{ 4.83659340659341, 65.27472527, 20 },
	{ 4.85653846153846, 54.3956044, 20 },
	{ 4.87302197802198, 44.50549451, 20 },
	{ 4.88637362637363, 35.6043956, 20 },
	{ 4.89692307692308, 27.69230769, 20 },
	{ 4.905, 20.76923077, 20 },
	{ 4.91093406593407, 14.83516484, 20 },
	{ 4.91505494505495, 9.89010989, 20 },
	{ 4.91769230769231, 5.934065934, 20 },
	{ 4.91917582417583, 2.967032967, 20 },
	{ 4.91983516483517, 0.989010989, 20 },
	{ 4.92, 3.56857E-15, 20 },
	{ 4.92, 0, 20 }
 };
const int Mp90TurnSize = 109;

#endif // PROFILES_H
