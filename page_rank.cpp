//
// Created by Carlo on 2018-10-14.
//

#include "page_rank.hpp"
#include <ctgmath>
#include <iomanip>

using namespace std;

page_rank::page_rank(string &file_name)
{
    ifstream file(file_name);
    string line;
    int mat_size = 0;
    while(getline(file, line))
    {
        istringstream iss(line);
        double val;
        while(iss >> val)
        {
            web.push_back(val);
            mat_size++;
        }
        n++;
    }

    g = connectivity_matrix(&web[0], mat_size);

    set_importance();

    make_stochastic();

    set_Q();

    set_transition_matrix();

    set_rank();

    markov();

    final();
}

void page_rank::set_importance()
{
    S = g;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            double val = 0;

            if(g.get_out_degree(i) > 0)
            {
                val = S.get_value(j, i) / g.get_out_degree(i);
            }

           S.set_value(j, i, val);
        }
    }
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
    Q = n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            Q.set_value(i, j, 1.0/n);
        }
    }
}

void page_rank::set_transition_matrix()
{
    M = S;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            double val = p * M.get_value(i, j) + (1 - p) * Q.get_value(i, j);
            M.set_value(i, j, val);
        }
    }
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