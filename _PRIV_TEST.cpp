#include <myVector.h>
#include <iostream>
#include <vector>

using namespace myDS;

int main()
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
    auto x = c.begin();
    return 0;
}