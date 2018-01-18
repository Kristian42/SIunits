#ifndef TYPE_TRAITS_EXTENSIONS_H_INCLUDED
#define TYPE_TRAITS_EXTENSIONS_H_INCLUDED

#include <ratio>
#include <type_traits>
#include <utility>

namespace ext
{

    template <typename T, typename... Args>
    struct is_one_of
    {
        static constexpr bool value = false;
    };

    template <typename T, typename S, typename... Rest>
    struct is_one_of<T, S, Rest...>
    {
        static constexpr bool value = std::is_same<T, S>::value || is_one_of<T, Rest...>::value;
    };

    template <typename... Args>
    using void_t = void;

    template <typename T, typename U = void>
    struct has_operator_plus
    {
        static constexpr bool value = false;
    };

    template <typename T>
    struct has_operator_plus<T, void_t<decltype(std::declval<T>() + std::declval<T>() )> >
    {
        static constexpr bool value = true;
    };


}



#endif // TYPE_TRAITS_EXTENSIONS_H_INCLUDED
