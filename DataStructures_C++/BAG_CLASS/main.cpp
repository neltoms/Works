//
// Created by faculty on 3/7/2017.
//

#include <iostream>
#include "bag.h"

int main()
{
    bag b1;
    bag b2;
    bag b3;

    b1 += b1;

    b1 += b2 += b3;

    bag b4 = b1;
    bag b5 = b1 + b2;
    b3 = b1 + b2;

    return 0;
}
