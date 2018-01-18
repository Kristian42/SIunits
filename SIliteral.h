#ifndef LITERALS_H_INCLUDED
#define LITERALS_H_INCLUDED

#include "SIunits.h"
#include "SIalias.h"

namespace SIunits
{
    namespace literals
    {
        // Literals with long double argument
        constexpr Kilogram<float> operator"" _kgf(long double x) {return Kilogram<float>(x);}
        constexpr Meter<float> operator"" _mf(long double x) {return Meter<float>(x);}
        constexpr Second<float> operator"" _sf(long double x) {return Second<float>(x);}
        constexpr SquareMeter<float> operator""_m2f(long double x) {return SquareMeter<float>(x);}
        constexpr CubicMeter<float> operator"" _m3f(long double x) {return CubicMeter<float>(x);}
        constexpr Hertz<float> operator"" _Hzf(long double x) {return Hertz<float>(x);}
        constexpr Newton<float> operator"" _Nf(long double x) {return Newton<float>(x);}
        constexpr Joule<float> operator"" _Jf(long double x) {return Joule<float>(x);}
        constexpr Watt<float> operator"" _Wf(long double x) {return Watt<float>(x);}
        constexpr Pascal<float> operator"" _Paf(long double x) {return Pascal<float>(x);}

        constexpr Kilogram<double> operator"" _kg(long double x) {return Kilogram<double>(x);}
        constexpr Meter<double> operator"" _m(long double x) {return Meter<double>(x);}
        constexpr Second<double> operator"" _s(long double x) {return Second<double>(x);}
        constexpr SquareMeter<double> operator""_m2(long double x) {return SquareMeter<double>(x);}
        constexpr CubicMeter<double> operator"" _m3(long double x) {return CubicMeter<double>(x);}
        constexpr Hertz<double> operator"" _Hz(long double x) {return Hertz<double>(x);}
        constexpr Newton<double> operator"" _N(long double x) {return Newton<double>(x);}
        constexpr Joule<double> operator"" _J(long double x) {return Joule<double>(x);}
        constexpr Watt<double> operator"" _W(long double x) {return Watt<double>(x);}
        constexpr Pascal<double> operator"" _Pa(long double x) {return Pascal<double>(x);}

        constexpr Kilogram<long double> operator"" _kgl(long double x) {return Kilogram<long double>(x);}
        constexpr Meter<long double> operator"" _ml(long double x) {return Meter<long double>(x);}
        constexpr Second<long double> operator"" _sl(long double x) {return Second<long double>(x);}
        constexpr SquareMeter<long double> operator""_m2l(long double x) {return SquareMeter<long double>(x);}
        constexpr CubicMeter<long double> operator"" _m3l(long double x) {return CubicMeter<long double>(x);}
        constexpr Hertz<long double> operator"" _Hzl(long double x) {return Hertz<long double>(x);}
        constexpr Newton<long double> operator"" _Nl(long double x) {return Newton<long double>(x);}
        constexpr Joule<long double> operator"" _Jl(long double x) {return Joule<long double>(x);}
        constexpr Watt<long double> operator"" _Wl(long double x) {return Watt<long double>(x);}
        constexpr Pascal<long double> operator"" _Pal(long double x) {return Pascal<long double>(x);}

        // Literals with unsigned long long argument
        constexpr Kilogram<float> operator"" _kgf(unsigned long long x) {return Kilogram<float>(x);}
        constexpr Meter<float> operator"" _mf(unsigned long long x) {return Meter<float>(x);}
        constexpr Second<float> operator"" _sf(unsigned long long x) {return Second<float>(x);}
        constexpr SquareMeter<float> operator""_m2f(unsigned long long x) {return SquareMeter<float>(x);}
        constexpr CubicMeter<float> operator"" _m3f(unsigned long long x) {return CubicMeter<float>(x);}
        constexpr Hertz<float> operator"" _Hzf(unsigned long long x) {return Hertz<float>(x);}
        constexpr Newton<float> operator"" _Nf(unsigned long long x) {return Newton<float>(x);}
        constexpr Joule<float> operator"" _Jf(unsigned long long x) {return Joule<float>(x);}
        constexpr Watt<float> operator"" _Wf(unsigned long long x) {return Watt<float>(x);}
        constexpr Pascal<float> operator"" _Paf(unsigned long long x) {return Pascal<float>(x);}

        constexpr Kilogram<double> operator"" _kg(unsigned long long x) {return Kilogram<double>(x);}
        constexpr Meter<double> operator"" _m(unsigned long long x) {return Meter<double>(x);}
        constexpr Second<double> operator"" _s(unsigned long long x) {return Second<double>(x);}
        constexpr SquareMeter<double> operator""_m2(unsigned long long x) {return SquareMeter<double>(x);}
        constexpr CubicMeter<double> operator"" _m3(unsigned long long x) {return CubicMeter<double>(x);}
        constexpr Hertz<double> operator"" _Hz(unsigned long long x) {return Hertz<double>(x);}
        constexpr Newton<double> operator"" _N(unsigned long long x) {return Newton<double>(x);}
        constexpr Joule<double> operator"" _J(unsigned long long x) {return Joule<double>(x);}
        constexpr Watt<double> operator"" _W(unsigned long long x) {return Watt<double>(x);}
        constexpr Pascal<double> operator"" _Pa(unsigned long long x) {return Pascal<double>(x);}

        constexpr Kilogram<long double> operator"" _kgl(unsigned long long x) {return Kilogram<long double>(x);}
        constexpr Meter<long double> operator"" _ml(unsigned long long x) {return Meter<long double>(x);}
        constexpr Second<long double> operator"" _sl(unsigned long long x) {return Second<long double>(x);}
        constexpr SquareMeter<long double> operator""_m2l(unsigned long long x) {return SquareMeter<long double>(x);}
        constexpr CubicMeter<long double> operator"" _m3l(unsigned long long x) {return CubicMeter<long double>(x);}
        constexpr Hertz<long double> operator"" _Hzl(unsigned long long x) {return Hertz<long double>(x);}
        constexpr Newton<long double> operator"" _Nl(unsigned long long x) {return Newton<long double>(x);}
        constexpr Joule<long double> operator"" _Jl(unsigned long long x) {return Joule<long double>(x);}
        constexpr Watt<long double> operator"" _Wl(unsigned long long x) {return Watt<long double>(x);}
        constexpr Pascal<long double> operator"" _Pal(unsigned long long x) {return Pascal<long double>(x);}
    }
}



#endif // LITERALS_H_INCLUDED
