#include <iostream>
#include <vector>
#include <list>
#include <type_traits>
#include <string>
#include <tuple>
#include "MyTypeTraits.h"
#include <sstream>
struct ip_printer
{

    ip_printer() = default;
    
    template<typename T,
        typename Fake = typename std::enable_if<
        std::numeric_limits<typename 
            std::remove_const<typename 
                std::remove_reference<T>::type
                >::type>::is_integer>::type>
    std::string print(const T& ip)
    {
        std::stringstream ss;
        for (int i = 0; i < 4; i++)
        {
            unsigned char b = ip << (i * 8);
            ss <<(int) b << ((i == 3) ? "" : ".");
        }
        return ss.str();
    }    
  
    std::string print(const std::string& ip)
    {
        return ip;
    }
    
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
            ss << it << ((i == 3) ? "" : ".");
            i++;
        }
        return ss.str();
    }

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