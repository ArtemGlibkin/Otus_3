
#include "IPPrint.h"
int main()
{
    ip_printer v;
    int integer = -1;
    short sh = 0;
    char c = 0;
    long d = 0;
    std::cout << v.print(integer) << std::endl;
    std::cout << v.print(sh) << std::endl;
    std::cout << v.print(c) << std::endl;
    std::cout << v.print(d) << std::endl;

    std::vector<int> vec = { 255, 0, 0, 1 };
    std::list<int> list = { 255, 0, 0, 1 };
    std::vector<std::string> vec2 = { "255", "0", "0", "2" };

    std::cout << v.print(vec) << std::endl;
    std::cout << v.print(vec2) << std::endl;
    std::cout << v.print(list) << std::endl;
    std::tuple<int, int, int, int> tuple = std::make_tuple(255, 255, 255, 3);
    std::cout << v.print(tuple) << std::endl;
    return 0;
}