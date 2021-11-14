#pragma once
#include <string>
#include <tuple>
#include <vector>
#include <list>
#include <type_traits>

template<class T>
struct is_string {
    static bool const value = false;
};

template<>
struct is_string<std::string> {
    static bool const value = true;
};

template<class T>
struct is_vector {
    static bool const value = false;
};

template<class T>
struct is_vector<std::vector<T>> {
    static bool const value = std::numeric_limits<T>::is_integer | is_string<T>::value;
};

template<class T>
struct is_list {
    static bool const value = false;
};

template<class T>
struct is_list<std::list<T>> {
    static bool const value = std::numeric_limits<T>::is_integer | is_string<T>::value;
};

template<typename T>
constexpr bool is_sametypes()
{
    return true;
}

template<typename T, typename T2, typename ...Args>
constexpr bool is_sametypes()
{
    return std::is_same<T, T2>::value && is_sametypes<T2, Args...>();
}

template<typename T>
struct is_tuple
{
    static bool const value = false;
};

template<typename ...Args>
struct is_tuple <std::tuple<Args...>>
{
    static bool const value = is_sametypes<Args...>();
};