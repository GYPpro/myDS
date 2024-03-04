#include <myVector.h>
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
    auto x = c.begin();
    return 0;
};

void t2()
{
    //
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    cout << a[1] << " " << a.at(0) << "\n";
}

int main()
{
    
	t2();
    //getchar();
    //getchar();
    return 0;
}
