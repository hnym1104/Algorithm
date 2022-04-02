#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(void)
{
    vector<string> p(5);
    p[0] = "12";
    p[1] = "123";
    p[2] = "1235";
    p[3] = "567";
    p[4] = "88";

    sort(p.begin(), p.end());

    for (int i = 0; i < p.size(); i++)
        cout << p[i] << endl;

    return 0;
}
