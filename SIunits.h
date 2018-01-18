#pragma once

#include "type_traits_extensions.h"

#include <complex>
#include <iostream>
#include <ratio>
#include <type_traits>
#include <utility>

namespace SIunits
{

    using ZERO = std::ratio<0>;
    using ONE  = std::ratio<1>;

    template <typename V, typename M, typename L, typename T> class Unit;
    template <typename V> class Unit<V, ZERO, ZERO, ZERO>;



    template <typename V, typename M, typename L, typename T>
    class Unit
    {
        static_assert(std::is_floating_point<V>::value || ext::is_one_of<V, std::complex<double>, std::complex<float>, std::complex<long double>>::value, "VALUE TYPE IS NOT A FLOATING POINT OR STD::COMPLEX TYPE.");

        public:
            using value_type = V;
            using kilogram_exponent = M;
            using meter_exponent = L;
            using second_exponent = T;

            Unit() = default;
            explicit constexpr Unit(V value) noexcept(std::is_nothrow_constructible<V, V>::value) : val{value}{}

            explicit constexpr operator V() const noexcept(noexcept(V())) {return val;}
            explicit constexpr operator V&() noexcept {return val;}

            template <typename U>
            explicit constexpr operator Unit<U, M, L, T>() const {return Unit<U, M, L, T>(val);}

            // Arithmetic operators
            constexpr Unit& operator+=(Unit rhs) {val += rhs.val; return *this;}
            constexpr Unit& operator-=(Unit rhs) {val -= rhs.val; return *this;}

            constexpr Unit& operator*=(V rhs);
            constexpr Unit& operator/=(V rhs);

            constexpr Unit operator+() {return *this;}
            constexpr Unit operator-() {return Unit(-val);}

            // Relational operators
            constexpr bool operator==(Unit rhs) {return val == rhs.val;}
            constexpr bool operator!=(Unit rhs) {return !(*this == rhs);}
            constexpr bool operator<(Unit rhs) {return val < rhs.val;}
            constexpr bool operator<=(Unit rhs) {return val <= rhs.val;}
            constexpr bool operator>(Unit rhs) {return val > rhs.val;}
            constexpr bool operator>=(Unit rhs) {return val >= rhs.val;}

            // Friend declarations
            friend std::ostream& operator<<(std::ostream& os, Unit rhs) {return os << rhs.val;}
            friend std::istream& operator>>(std::istream& is, Unit& rhs) {return is >> rhs.val;}

            template <typename V1, typename V2, typename M1, typename L1, typename T1>
            friend constexpr auto operator+(Unit<V1, M1, L1, T1> lhs, Unit<V2, M1, L1, T1> rhs);

            template <typename V1, typename V2, typename M1, typename L1, typename T1>
            friend constexpr auto operator-(Unit<V1, M1, L1, T1> lhs, Unit<V2, M1, L1, T1> rhs);

            template <typename V1, typename M1, typename L1, typename T1, typename V2, typename M2, typename L2, typename T2>
            friend constexpr auto operator*(Unit<V1, M1, L1, T1> lhs, Unit<V2, M2, L2, T2> rhs);

            template <typename V1, typename M1, typename L1, typename T1, typename U>
            friend constexpr auto operator*(Unit<V1, M1, L1, T1> lhs, U rhs);

            template <typename U, typename V1, typename M1, typename L1, typename T1>
            friend constexpr auto operator*(U lhs, Unit<V1, M1, L1, T1> rhs);

            template <typename V1, typename M1, typename L1, typename T1, typename V2, typename M2, typename L2, typename T2>
            friend constexpr auto operator/(Unit<V1, M1, L1, T1> lhs, Unit<V2, M2, L2, T2> rhs);

            template <typename V1, typename M1, typename L1, typename T1, typename U>
            friend constexpr auto operator/(Unit<V1, M1, L1, T1> lhs, U rhs);

            template <typename U, typename V1, typename M1, typename L1, typename T1>
            friend constexpr auto operator/(U lhs, Unit<V1, M1, L1, T1> rhs);

        private:
            V val;
    };


    template <typename V, typename M, typename L, typename T>
    constexpr Unit<V, M, L, T>& Unit<V, M, L, T>::operator*=(V rhs) {val *= rhs; return *this;}

    template <typename V, typename M, typename L, typename T>
    constexpr Unit<V, M, L, T>& Unit<V, M, L, T>::operator/=(V rhs) {val /= rhs; return *this;}

    template <typename V, typename U, typename M, typename L, typename T>
    constexpr auto operator+(Unit<V, M, L, T> lhs, Unit<U, M, L, T> rhs)
    {
        return Unit<decltype(std::declval<V>() + std::declval<U>()), M, L, T>(lhs.val + rhs.val);
    }

    template <typename V, typename U, typename M, typename L, typename T>
    constexpr auto operator-(Unit<V, M, L, T> lhs, Unit<U, M, L, T> rhs)
    {
        return Unit<decltype(std::declval<V>() - std::declval<U>()), M, L, T>(lhs.val - rhs.val);
    }

    template <typename V, typename M1, typename L1, typename T1, typename U, typename M2, typename L2, typename T2>
    constexpr auto operator*(Unit<V, M1, L1, T1> lhs, Unit<U, M2, L2, T2> rhs)
    {
        return Unit<decltype(std::declval<V>() * std::declval<U>()), std::ratio_add<M1,M2>, std::ratio_add<L1,L2>, std::ratio_add<T1,T2>>(lhs.val * rhs.val);
    }

    template <typename V, typename M, typename L, typename T, typename U>
    constexpr auto operator*(Unit<V, M, L, T> lhs, U rhs)
    {
        return Unit<decltype(std::declval<V>() * std::declval<U>()), M, L, T>(lhs.val * rhs);
    }

    template <typename V, typename U, typename M, typename L, typename T>
    constexpr auto operator*(V lhs, Unit<U, M, L, T> rhs)
    {
        return Unit<decltype(std::declval<V>() * std::declval<U>()), M, L, T>(lhs * rhs.val);
    }

    template <typename V1, typename M1, typename L1, typename T1, typename V2, typename M2, typename L2, typename T2>
    constexpr auto operator/(Unit<V1, M1, L1, T1> lhs, Unit<V2, M2, L2, T2> rhs)
    {
        return Unit<decltype(std::declval<V1>() / std::declval<V2>()), std::ratio_subtract<M1,M2>, std::ratio_subtract<L1,L2>, std::ratio_subtract<T1,T2>>(lhs.val / rhs.val);
    }

    template <typename V, typename M, typename L, typename T, typename U>
    constexpr auto operator/(Unit<V, M, L, T> lhs, U rhs)
    {
        return Unit<decltype(std::declval<V>() / std::declval<U>()), M, L, T>(lhs.val / rhs);
    }

    template <typename U, typename V, typename M, typename L, typename T>
    constexpr auto operator/(U lhs, Unit<V, M, L, T> rhs)
    {
        return Unit<decltype(std::declval<U>() / std::declval<V>()), M, L, T>(lhs / rhs.val);
    }


    // SPECIALIZATIONS FOR SCALAR
    template <typename V>
    class Unit<V, ZERO, ZERO, ZERO>
    {
        static_assert(std::is_floating_point<V>::value || ext::is_one_of<V, std::complex<double>, std::complex<float>, std::complex<long double>>::value, "VALUE TYPE IS NOT A FLOATING POINT OR STD::COMPLEX TYPE.");

        public:
            using value_type = V;
            using kilogram_exponent = ZERO;
            using meter_exponent = ZERO;
            using second_exponent = ZERO;

            Unit() = default;
            constexpr Unit(V value) noexcept(std::is_nothrow_constructible<V, V>::value) : val{value}{}

            constexpr operator V() const noexcept(noexcept(V())) {return val;}
            constexpr operator V&() noexcept {return val;}

            template <typename U>
            explicit constexpr operator Unit<U, ZERO, ZERO, ZERO>() const {return Unit<U, ZERO, ZERO, ZERO>(val);}

            // Arithmetic operators
            constexpr Unit& operator+=(Unit rhs) {val += rhs.val; return *this;}
            constexpr Unit& operator-=(Unit rhs) {val -= rhs.val; return *this;}

            constexpr Unit& operator*=(V rhs);
            constexpr Unit& operator/=(V rhs);

            // Relational operators
            constexpr bool operator==(Unit rhs) {return val == rhs.val;}
            constexpr bool operator!=(Unit rhs) {return !(*this == rhs);}
            constexpr bool operator<(Unit rhs) {return val < rhs.val;}
            constexpr bool operator<=(Unit rhs) {return val <= rhs.val;}
            constexpr bool operator>(Unit rhs) {return val > rhs.val;}
            constexpr bool operator>=(Unit rhs) {return val >= rhs.val;}

            // Friend declarations
            friend std::ostream& operator<<(std::ostream& os, Unit rhs) {return os << rhs.val;}
            friend std::istream& operator>>(std::istream& is, Unit& rhs) {return is >> rhs.val;}

            template <typename U, typename W>
            friend constexpr auto operator+(Unit<U, ZERO, ZERO, ZERO> lhs, Unit<W, ZERO, ZERO, ZERO> rhs);

            template <typename U, typename W>
            friend constexpr auto operator-(Unit<U, ZERO, ZERO, ZERO> lhs, Unit<W, ZERO, ZERO, ZERO> rhs);

            template <typename U, typename W>
            friend constexpr auto operator*(Unit<U, ZERO, ZERO, ZERO> lhs, Unit<W, ZERO, ZERO, ZERO> rhs);

            template <typename U, typename W>
            friend constexpr auto operator*(Unit<U, ZERO, ZERO, ZERO> lhs, W rhs);

            template <typename U, typename W>
            friend constexpr auto operator*(U lhs, Unit<W, ZERO, ZERO, ZERO> rhs);

            template <typename V1, typename V2>
            friend constexpr auto operator/(Unit<V1, ZERO, ZERO, ZERO> lhs, Unit<V2, ZERO, ZERO, ZERO> rhs);

            template <typename V1, typename U>
            friend constexpr auto operator/(Unit<V1, ZERO, ZERO, ZERO> lhs, U rhs);

            template <typename U, typename V1>
            friend constexpr auto operator/(U lhs, Unit<V1, ZERO, ZERO, ZERO> rhs);



        private:
            V val;
    };



    template <typename V>
    constexpr Unit<V, ZERO, ZERO, ZERO>& Unit<V, ZERO, ZERO, ZERO>::operator*=(V rhs) {val *= rhs; return *this;}

    template <typename V>
    constexpr Unit<V, ZERO, ZERO, ZERO>& Unit<V, ZERO, ZERO, ZERO>::operator/=(V rhs) {val /= rhs; return *this;}

    template <typename V, typename U>
    constexpr auto operator+(Unit<V, ZERO, ZERO, ZERO> lhs, Unit<U, ZERO, ZERO, ZERO> rhs)
    {
        return Unit<decltype(std::declval<V>() + std::declval<U>()), ZERO, ZERO, ZERO>(lhs.val + rhs.val);
    }

    template <typename V, typename U>
    constexpr auto operator-(Unit<V, ZERO, ZERO, ZERO> lhs, Unit<U, ZERO, ZERO, ZERO> rhs)
    {
        return Unit<decltype(std::declval<V>() - std::declval<U>()), ZERO, ZERO, ZERO>(lhs.val - rhs.val);
    }

    template <typename V, typename U>
    constexpr auto operator*(Unit<V, ZERO, ZERO, ZERO> lhs, Unit<U, ZERO, ZERO, ZERO> rhs)
    {
        return Unit<decltype(std::declval<V>() * std::declval<U>()), ZERO, ZERO, ZERO>(lhs.val * rhs.val);
    }

    template <typename V, typename U>
    constexpr auto operator*(Unit<V, ZERO, ZERO, ZERO> lhs, U rhs)
    {
        return Unit<decltype(std::declval<V>() * std::declval<U>()), ZERO, ZERO, ZERO>(lhs.val * rhs);
    }

    template <typename V, typename U>
    constexpr auto operator*(V lhs, Unit<U, ZERO, ZERO, ZERO> rhs)
    {
        return Unit<decltype(std::declval<V>() * std::declval<U>()), ZERO, ZERO, ZERO>(lhs * rhs.val);
    }

    template <typename V, typename U>
    constexpr auto operator/(Unit<V, ZERO, ZERO, ZERO> lhs, Unit<U, ZERO, ZERO, ZERO> rhs)
    {
        return Unit<decltype(std::declval<V>() / std::declval<U>()), ZERO, ZERO, ZERO>(lhs.val / rhs.val);
    }

    template <typename V, typename U>
    constexpr auto operator/(Unit<V, ZERO, ZERO, ZERO> lhs, U rhs)
    {
        return Unit<decltype(std::declval<V>() / std::declval<U>()), ZERO, ZERO, ZERO>(lhs.val / rhs);
    }

    template <typename V, typename U>
    constexpr auto operator/(V lhs, Unit<U, ZERO, ZERO, ZERO> rhs)
    {
        return Unit<decltype(std::declval<V>() / std::declval<U>()), ZERO, ZERO, ZERO>(lhs / rhs.val);
    }



}
