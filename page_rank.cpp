//
// Created by Carlo on 2018-10-14.
//

#include "page_rank.hpp"
#include <ctgmath>
#include <iomanip>

using namespace std;

page_rank::page_rank(){}

page_rank::page_rank(string &file_name)
{
    std::ifstream file;
    file.open(file_name);
    double val;
    while(file >> val)
    {
        web.push_back(val);
        n++;
    }

    g = connectivity_matrix(&web[0], n);
    n = sqrt(n);
}

connectivity_matrix page_rank::get_web()
{
    return g;
}

void page_rank::set_importance()
{
    matrix *imp = new matrix(g);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            double val = 0;

            if(g.get_out_degree(i) > 0)
            {
                val = imp->get_value(j, i) / g.get_out_degree(i);
            }

           imp->set_value(j, i, val);
        }
    }

    S = *imp;
}

matrix page_rank::get_importance()
{
    return S;
}

void page_rank::make_stochastic()
{
    for(int i = 0; i < n; i++)
    {
        if(g.get_out_degree(i) == 0)
        {
            for(int j = 0; j < n; j++)
            {
                S.set_value(j, i, 1.0/n);
            }
        }
    }
}

void page_rank::set_Q()
{
    matrix *q = new matrix(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            q->set_value(i, j, 1.0/n);
        }
    }
    Q = *q;
}

matrix page_rank::get_Q()
{
    return Q;
}

void page_rank::set_transition_matrix()
{
    matrix *tmp = new matrix(S);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            double val = p * tmp->get_value(i, j) + (1 - p) * Q.get_value(i, j);
            tmp->set_value(i, j, val);
        }
    }

    M = *tmp;
}

matrix page_rank::get_transition_matrix()
{
    return M;
}

void page_rank::set_rank()
{
    matrix *r = new matrix(n, 1);
    for(int i = 0; i < n; i++)
    {
        r->set_value(i, 0, 1);
    }

    rank = *r;
}

matrix page_rank::get_rank()
{
    return rank;
}

void page_rank::markov()
{
    matrix *tmp = new matrix(rank);

    rank = M * rank;

    for(int i = 0; i < n; i++)
    {
        if(tmp->get_value(i, 0) != rank.get_value(i, 0))
        {
            markov();
        }
    }
}

void page_rank::final()
{
    double sum = 0;

    for(int i = 0; i < n; i++)
    {
        sum += rank.get_value(i, 0);
    }

    for(int i = 0; i < n; i++)
    {
        rank.set_value(i, 0, rank.get_value(i, 0)/sum);
    }
}

void page_rank::print()
{
    int character = 0;
    char ch = 'A';

    for(int i = 0; i < n; i++)
    {
        character = int(ch);

        cout << "Page " << ch << ": ";
        cout << fixed;
        cout << setprecision(2);
        cout << rank.get_value(i, 0) * 100 << "%" << endl;

        character++;
        ch = char(character);
    }
}