#include <d:\Desktop\Document\Coding\C++\ProjectC\myDS\myVector.h>
#include <iostream>
#include <vector>

using namespace myDS;

int t1()
{
    std::vector<int> c;
    vector<int> a;
    auto x = a.begin();
    auto y = *x;
    vector<std::pair<int,int>> d;
    auto z = d.begin();
    auto zz = (*z).first;

    std::vector<std::pair<int,int>> cc;
    auto z2 = cc.begin();
    auto zz2 = z2->first;
    auto zzz2 = *z2;
    a.push_back(1);
    // auto x = c.begin();
    return 0;
};

vector<int> tc;
std::vector<int> comm;

void t2()
{
    //
    // vector<int> a;
    // a.push_back(1);
    // a.push_back(2);
    // std::cout << a[1] << " " << a.at(0) << "\n";
    char q;
    std::cin >> q;
    switch (q)
    {
    case 'p':
        {
            int c;
            std::cin >> c;
            tc.push_back(c);
            comm.push_back(c);
        }
        break;
    case 'a':
        {
            int n;
            std::cin >> n;
            for(int i = 0;i < n;i ++)
            {
                int t;
                std::cin >> t;
                tc.push_back(t);
                comm.push_back(t);
            }
        }
        break;
    case 'i':
        {
            int c;
            std::cin >> c;
            std::cout << "myDS: " << tc[c] << " " << tc.at(c) << "\n";
            std::cout << "STL:  "<< comm[c] << " " << comm.at(c) << "\n";
        }
        break;
    case 'r':
        {
            int c;
            std::cin >> c;
            tc.resize(c);
            comm.resize(c);
        }
        break;
    case 'w':
        {
            std::cout << "myDS + auto :";
            for(auto x:tc)
                std::cout << x <<" ";

            std::cout << "\nmyDS + for :";
            for(int i = 0;i < tc.size();i ++)
                std::cout << tc[i] << " ";

            std::cout << "\nSTL  + for :";
            for(int i = 0;i < comm.size();i ++)
                std::cout << comm[i] << " ";
        }
        break;
    case 's':
        {
            std::cout << "myDS:" << tc.size() << "\n";
            std::cout << "STL: " << comm.size() << "\n"; 
        }
        break;
    
    default:
        break;
    }
}

int main()
{
    while(1)
	    t2();
    //getchar();
    //getchar();
    return 0;
}
