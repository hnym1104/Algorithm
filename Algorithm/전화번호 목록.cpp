#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

bool solution()
{
    vector<string> phone_book = { "119", "97674223", "1195524421" };

    bool answer = true;
    map<int, string> M;

    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size(); i++) {
        M.insert({ i, phone_book[i] });   // Map¿¡ push
        for (int j = 0; j < i; j++) {
            if (phone_book[i].find(M.find(j)->second) == 0) {
                answer = true;
                return answer;
            }
        }
    }

    answer = false;
    return answer;
}

int main(void)
{
    bool answer = solution();
    if (answer == true)
        cout << "true";
    else
        cout << "false";

    return 0;
}