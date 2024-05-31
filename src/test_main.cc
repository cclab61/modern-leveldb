#include "co/co.h"
#include <iostream>
int main(int argc, char **argv)
{
    flag::parse(argc, argv);

    co::wait_group wg;
    wg.add(2);

    go([wg]()
       {
        std::cout << "hello world";
        wg.done(); });

    go([wg]()
       {
        std::cout << "hello again";
        wg.done(); });

    wg.wait();
    return 0;
}