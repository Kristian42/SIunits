#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include "SIunits.h"

#include <cmath>
#include <ratio>

namespace SIunits
{
    template <typename V, typename M, typename L, typename T>
    constexpr auto sqrt(Unit<V, M, L, T> x)
    {
        return Unit<V, std::ratio_divide<M,std::ratio<2>>, std::ratio_divide<L,std::ratio<2>>, std::ratio_divide<T,std::ratio<2>>>(std::sqrt(V(x)));
    }

    template <typename V, typename M, typename L, typename T>
    constexpr auto cbrt(Unit<V, M, L, T> x)
    {
        return Unit<V, std::ratio_divide<M,std::ratio<3>>, std::ratio_divide<L,std::ratio<3>>, std::ratio_divide<T,std::ratio<3>>>(std::cbrt(V(x)));
    }

    template <typename V, typename M, typename L, typename T>
    constexpr auto hypot(Unit<V, M, L, T> x, Unit<V, M, L, T> y)
    {
        return Unit<V, M, L, T>(std::hypot(V(x), V(y)));
    }


    template <int num, int den = 1, typename V, typename M, typename L, typename T>
    constexpr auto pow(Unit<V, M, L, T> x)
    {
        return Unit<V, std::ratio_multiply<M,std::ratio<num,den>>, std::ratio_multiply<L,std::ratio<num,den>>, std::ratio_multiply<T,std::ratio<num,den>>>(std::pow(V(x), V(num)/den));
    }
}




#endif // FUNCTIONS_H_INCLUDED
