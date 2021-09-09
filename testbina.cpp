#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{

    vector<int> vect1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    vector<int>::iterator low, up;
    low = lower_bound(vect1.begin(), vect1.end(), 8);
    up = upper_bound(vect1.begin(), vect1.end(), 8);

    cout << (low - vect1.begin()) << endl;
    ;
    cout << (up - vect1.begin());
}