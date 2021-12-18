#pragma once
#include <iostream>
#include <ctime>
#include "stdlib.h"
#include "vals.hpp"

/*steps
    1 - reading and deciphering
    2 - reading 1st op
    3 - reading 2nd op
    4 - calc
    5 - writing to 2nd op
*/
/*operands
    0 - register
    1 - memory
*/
class Command
{
public:
    Command(int op_type);
    int readndeciphering();
    int read_1st_op();
    int read_2nd_op();
    int calc();
    int write();
    int sum_res();
    int next_step();

    int op1;
    int op2; 
    int step_num;
    int op_type;

};

int Command::next_step()
{
    int ans;
    switch (step_num)
    {
        case 1: ans = readndeciphering(); break;
        case 2: ans = read_1st_op(); break;
        case 3: ans = read_2nd_op(); break;
        case 4: ans = calc(); break;
        case 5: ans = write(); break;
    }

    this->step_num++;
    return ans;
}

Command::Command(int op_type)
{
    this->step_num = 1;
    this->op_type = op_type;
    int flag = rand()%101;
    flag <= v.P1 ? this->op1 = 0 : this->op1 = 1;
    flag = rand()%101;
    flag <= v.P1 ? this->op2 = 0 : this->op2 = 1;
}
int Command::readndeciphering()
{
    return 1;
}
int Command::read_1st_op()
{
    if(!op1)
        return 1;
    return v.N;
}
int Command::read_2nd_op()
{
    if(!op2)
        return 1;
    return v.N;
}
int Command::calc()
{
    switch (op_type)
    {
        case 1: return v.M1;break;
        case 2: return v.M2;break;
        case 3: return v.M3;break;

    }
}

int Command::write()
{
    if(!op2)
        return 1;
    return v.N;
}
int Command::sum_res()
{
    return readndeciphering() + read_1st_op() + read_2nd_op() + calc() + write();
}