#include "SI.h"

#include <iostream>

using namespace SIunits;
using namespace SIunits::literals;

constexpr Newton<double> Gravity(Kilogram<double> mass1, Kilogram<double> mass2, Meter<double> distance)
{
    constexpr auto G = 6.67408e-11_N * 1._m * 1._m / (1._kg * 1._kg);

    return G * mass1 * mass2 / (distance * distance);
}

constexpr auto Acceleration(Newton<double> force, Kilogram<double> mass)
{
    return force / mass;
}


int main()
{
    const auto chicken_mass = 1.5_kg;
    const auto earth_mass = 5.972e24_kg;
    const auto earth_radius = 6371e3_m;

    const auto F_g = Gravity(chicken_mass, earth_mass, earth_radius);
    const auto A_g = Acceleration(F_g, chicken_mass);

    std::cout << "Gravitational force on chicken at earth surface: " << F_g << " N\n";
    std::cout << "Gravitational acceleration of chicken at earth surface: " << A_g << " m/s^2\n";

    return 0;
}
