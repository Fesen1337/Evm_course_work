#pragma once
#include <iostream>

struct vals
{
    int M1;
    int M2;
    int M3;
    int N;
    int P1;
    int P2;
};

vals v;

void enter_data()
{
    std::cout << "Choose M1 value: \n 1) 1 \n 2) 2 \n 3) 3 \n";
    std::cin >> v.M1;
    switch (v.M1)
    {
        case 1: v.M1 = 1;break;
        case 2: v.M1 = 2;break;
        case 3: v.M1 = 3;break;
        default: v.M1 = 1;break;
    }

    std::cout << "Choose M2 value: \n 1) 4 \n 2) 8 \n 3) 16 \n";
    std::cin >> v.M2;
    switch (v.M2)
    {
        case 1: v.M2 = 4;break;
        case 2: v.M2 = 8;break;
        case 3: v.M2 = 16;break;
        default: v.M2 = 4;break;
    }

    v.M3 = 1;

    std::cout << "Choose N value: \n 1) 2 \n 2) 5 \n 3) 10 \n";
    std::cin >> v.N;
    switch (v.N)
    {
        case 1: v.N = 2;break;
        case 2: v.N = 5;break;
        case 3: v.N = 10;break;
        default: v.N = 2;break;
    }

    std::cout << "Choose P1 value: \n 1) 0.85 \n 2) 0.7 \n 3) 0.5 \n";
    std::cin >> v.P1;
    switch (v.P1)
    {
        case 1: v.P1 = 85;break;
        case 2: v.P1 = 70;break;
        case 3: v.P1 = 50;break;
        default: v.P1 = 85;break;
    }

    std::cout << "Choose P2 value: \n 1) 0.9 \n 2) 0.7 \n 3) 0.5 \n";
    std::cin >> v.P2;
    switch (v.P2)
    {
        case 1: v.P2 = 90;break;
        case 2: v.P2 = 70;break;
        case 3: v.P2 = 50;break;
        default: v.P2 = 90;break;
    }
}
