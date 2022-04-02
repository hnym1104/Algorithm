#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool sosu(int n) {   // 소수 판별 함수
    if (n < 2)
        return false;
    int s = (int)sqrt(n);   // 루트 n
    for (int i = 2; i <= s; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main(void) {
    string numbers = "173";   // 1, 7, 17, 71
    int answer = 0;
    vector<int> ns;
    vector<int> N;

    for (int i = 0; i < numbers.size(); i++)
        ns.push_back(numbers[i] - '0');

    do {
        for (int i = 0; i <= ns.size(); i++) {
            int temp = 0;
            for (int j = 0; j < i; j++) {
                temp = (temp * 10) + ns[j];
                N.push_back(temp);
            }
        }
    } while (next_permutation(ns.begin(), ns.end()));

    sort(N.begin(), N.end());
    N.erase(unique(N.begin(), N.end()), N.end());

    for (int i = 0; i < N.size(); i++) {
        if (sosu(N[i]))
            answer++;
    }

    return 0;

}