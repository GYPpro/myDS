//#include <d:\Desktop\Document\Coding\C++\ProjectC\myDS\myVector.h>
#include "myVector.h"
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

class ssdftestcls{
public:
    vector<int> rtt = vector<int>();
    int a = 0;
    ssdftestcls* operator=(const ssdftestcls& mwr)
    {
        ssdftestcls* ctk = new ssdftestcls();
        ctk->a = mwr.a;
        // rtt = mwr.rtt;
        return ctk;
    }
    // std::vector<int> stlt;
};

void t2()
{
    //
    vector<int> a;
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
            std::cout << "myDS + auto:";
            for(auto x:tc)
                std::cout << x <<" ";

            std::cout << "\nmyDS + for :";
            for(int i = 0;i < tc.size();i ++)
                std::cout << tc[i] << " ";

            std::cout << "\nSTL  + for :";
            for(int i = 0;i < comm.size();i ++)
                std::cout << comm[i] << " ";
            std::cout << "\n";
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
    // ssdftestcls tcl;
    vector<ssdftestcls> arr(4);
    for(auto x = arr.begin();x != arr.end();x ++)
    {
        auto y = arr.end();
        std::cout << (*x).a << " ";
    }
    // arr[0].rtt = vector<int>(15);
}

class dtc{
public:
    ~dtc()
    {
        std::cout << "DTC";
    }
};

void t3()
{
    vector<dtc> arr(1);
    dtc * _begin = new dtc[20];
    dtc __tmp = dtc();
    delete &_begin[2];
    _begin[2] = __tmp;
}


// HACK:
void t4() //test case 4:template = calss(without operator= defined)
	  //FIXME:memary leak!
{
    // vector<vector<int>> arr(3);
    while(1){
	myDS::vector<dtc> arr(3);
    }
    // arr[0].resize(3);
    // for(auto &x:arr) x.resize(15);
}

int main()
{
    int i = 0;
    while(1){
        i ++;
        // std::cout << i << "\n";
	    t4();
    }
    //getchar();
    //getchar();
    return 0;
}
