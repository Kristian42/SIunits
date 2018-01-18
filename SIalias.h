#ifndef UNITS_H_INCLUDED
#define UNITS_H_INCLUDED

#include "SIunits.h"

#include <ratio>

namespace SIunits
{
    template <typename V> using Scalar      = Unit<V, std::ratio<0>, std::ratio<0>, std::ratio<0>>;
    template <typename V> using Kilogram    = Unit<V, std::ratio<1>, std::ratio<0>, std::ratio<0>>;
    template <typename V> using Meter       = Unit<V, std::ratio<0>, std::ratio<1>, std::ratio<0>>;
    template <typename V> using Second      = Unit<V, std::ratio<0>, std::ratio<0>, std::ratio<1>>;

    template <typename V> using SquareMeter = Unit<V, std::ratio<0>, std::ratio<2>, std::ratio<0>>;
    template <typename V> using CubicMeter  = Unit<V, std::ratio<0>, std::ratio<3>, std::ratio<0>>;

    template <typename V> using Hertz       = Unit<V, std::ratio<0>, std::ratio<0>, std::ratio<-1>>;
    template <typename V> using Newton      = Unit<V, std::ratio<1>, std::ratio<1>, std::ratio<-2>>;
    template <typename V> using Joule       = Unit<V, std::ratio<1>, std::ratio<2>, std::ratio<-2>>;
    template <typename V> using Watt        = Unit<V, std::ratio<1>, std::ratio<2>, std::ratio<-3>>;
    template <typename V> using Pascal      = Unit<V, std::ratio<1>, std::ratio<-1>, std::ratio<-2>>;
}



#endif // UNITS_H_INCLUDED
