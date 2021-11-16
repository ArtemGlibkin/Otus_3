#pragma once
#include <string>
#include <tuple>
#include <vector>
#include <list>
#include <limits>
#include <type_traits>

/*!
    \brief Class for checking template on std::string
*/
template<class T>
struct is_string {
    static bool const value = false;
};

template<>
struct is_string<std::string> {
    static bool const value = true;
};


/*!
    \brief Class for checking template on std::vector with integer parameters as long, short, char and etc
*/
template<class T>
struct is_vector {
    static bool const value = false;
};

template<class T>
struct is_vector<std::vector<T>> {
    static bool const value = std::numeric_limits<T>::is_integer | is_string<T>::value;
};


/*!
    \brief Class for checking template on std::list with integer parameters as long, short, char and etc
*/
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

/*!
    \brief Function for checking variadic template on same arguments
*/

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

/*!
    \brief Class for checking template on std::tuple with same parameters
*/
template<typename ...Args>
struct is_tuple <std::tuple<Args...>>
{
    static bool const value = is_sametypes<Args...>();
};