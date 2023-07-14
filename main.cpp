#include <iostream>
#include "header/Sort.hpp"
#include <vector>
#include <ctime>
#include <cstring>

using namespace std;

int main()
{

    vector<int> a = Sort<int>::generateRandomA(20, 0, 4638);

    Sort<int>::show(a);

    Sort<int>::Selection(a);

    Sort<int>::show(a);

    return 0;
    
}
