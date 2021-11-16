
#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <type_traits>
#include <string>
#include <tuple>
#include "MyTypeTraits.h"
#include <sstream>

const int ip_octets = 4;
const int bits_in_byte = 8;

/*!
    \brief Class for outputting ip addresses from different storage formats
*/
struct ip_printer
{

    ip_printer() = default;
    

    /*!
        Convert integral type view to string vie
        \param[in] ip_t Source integral value
    */
    template<typename T,
        typename Fake = typename std::enable_if<
        std::numeric_limits<typename 
            std::remove_const<typename 
                std::remove_reference<T>::type
                >::type>::is_integer>::type>
    std::string print(const T& ip_t)
    {
        int ip = static_cast<int>(ip_t);
        std::stringstream ss;
        for (int i = ip_octets - 1; i >=0; i--)
        {
            unsigned char b = ip >> (i * bits_in_byte);
            ss <<(int) b << ((i == 0) ? "" : ".");
        }
        return ss.str();
    }    
    
    /*!
        Realize print method for string
        \param[in] ip Source integral value
    */
    std::string print(const std::string& ip)
    {
        return ip;
    }
    
    /*!
        Realize print method for stl vectors and lists with integral or string values
        \param[ip] ip Source
    */
    template<typename T,
        typename Fake = typename std::enable_if<
                        is_vector<typename std::remove_const<typename std::remove_reference<T>::type>::type>::value |
                        is_list<typename std::remove_const<typename std::remove_reference<T>::type>::type>::value
    >::type>
    std::string print(const T& ip, bool container = true)
    {
        std::stringstream ss;
        int i = 0;
        for (auto it : ip)
        {
            ss << it << ((i == ip_octets-1) ? "" : ".");
            i++;
        }
        return ss.str();
    }

    /*!
       Realize print method for stl tuples with the same parameters
       \param[ip] ip Source
   */
    template<typename T,
        typename Fake = typename std::enable_if<
        is_tuple<typename std::remove_const<typename std::remove_reference<T>::type>::type>::value
    >::type>
    std::string print(const T& ip, int tuple = 1)
    {
        std::stringstream ss;
        ss << std::get<0>(ip) << "." << std::get<1>(ip) << "."<<
            std::get<2>(ip) << "." << std::get<3>(ip);
        return ss.str();
    }       
};