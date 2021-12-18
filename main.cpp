#include "Command.hpp"
#include <vector>
#include <list>
#include <fstream>
#include <iterator>

int reg = 0;
int mem = 0;

Command& createCommand(int op);

int genOp();

int nextStep(std::list<Command>::iterator &it);

int main()
{
    srand(time(NULL));
    enter_data();

    std::list<Command>q;

    int ans = 0;
    int ticks = 0;
    int usual = 0;

    std::vector<std::pair<int, int>>res;
    std::vector<std::pair<int, int>>res2;

    while(ans < 1000)
    {
        int step = 0;
        reg = 0;
        mem = 0;
        int op = 1 + rand()%3;
        q.push_back(createCommand(genOp()));
        if(q.back().op_type == 3)
        {
            ticks += q.back().sum_res();
            ans++;
            q.pop_back();
        }
        for(auto j = q.begin(); j != q.end(); j++)
        {
            
            step = std::max(nextStep(j), step);
            auto z = j;
            if(j->step_num > 5)
            {
                z++;
                ans++;
                res2.push_back(std::make_pair(usual, ans));
                usual += j->sum_res();
                q.erase(j);

                j = z;
                j--;
            }
        }
        ticks += step;
        res.push_back(std::make_pair(ticks, ans));
    }

    std::ofstream fout;

    fout.open("logs.txt");
    double q1 = double(res.back().first)/double(res.back().second);
    fout << q1 << std::endl;
    
    for(int i = 0; i < res.size(); i++)
    {
        fout << res[i].first << " ";
    }

    fout << std::endl;
    for(int i = 0; i < res.size(); i++)
    {
        fout << res[i].second << " ";
    }
    fout << std::endl;
    for(int i = 0; i < res2.size(); i++)
    {
        fout << res2[i].first << " ";
    }

    fout << std::endl;
    for(int i = 0; i < res2.size(); i++)
    {
        fout << res2[i].second << " ";
    }

    fout.close();

}

Command& createCommand(int op)
{
    Command *c = new Command(op);
    return *c;
}

int genOp()
{
    int prob = rand()%101;
    if(prob <= v.P2)
    {
        return 1;
    }else{
        return 2 + rand()%2;
    }
}

int nextStep(std::list<Command>::iterator &it)
{
    int ans = 0;
    switch (it->step_num)
    {
    case 2:
        if(!it->op1)
        {
            if(!reg)
            {
                ans = it->next_step();
                reg++;
            }
        }else{
            if(mem < 2)
            {
                ans = it->next_step();
                mem++;
            }
        }
    break;

    case 3:
        if(!it->op2)
        {
            if(!reg)
            {
                ans = it->next_step();
                reg++;
            }
        }else{
            if(mem < 2)
            {
                ans = it->next_step();
                mem++;
            }
        }
    break;

    case 5:
        if(!it->op2)
        {
            if(!reg)
            {
                ans = it->next_step();
                reg++;
            }
        }else{
            if(mem < 2)
            {
                ans = it->next_step();
                mem++;
            }
        }
    break;

    default:
        ans = it->next_step();
    break;
    }
    return ans;
}