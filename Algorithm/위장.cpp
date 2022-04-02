#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> clothes) {

    int answer = 0;
    unordered_map<string, int> cMap;
    vector<int> num;
    vector<int> choiceVector;
    vector<int> tempVector;

    for (int i = 0; i < clothes.size(); i++) {
        if (cMap.find(clothes[i][1]) == cMap.end()) {
            cMap.insert({ clothes[i][1], 1 });
        }
        else {
            cMap[clothes[i][1]]++;
        }
    }

    answer = 1;

    unordered_map<string, int>::iterator iter;

    for (iter = cMap.begin(); iter != cMap.end(); iter++) {
        answer *= (iter->second + 1);
    }

    answer -= 1;

    /*unordered_map<string, int>::iterator iter;

    for (iter = cMap.begin(); iter != cMap.end(); iter++) {
        num.push_back(iter->second);   // °¡Áþ¼ö vector¿¡ push
        choiceVector.push_back(0);
    }

    sort(num.begin(), num.end());


    for (int i = 0; i < num.size(); i++) {
        choiceVector[i] = 1;

        tempVector.assign(choiceVector.begin(), choiceVector.end());
        sort(tempVector.begin(), tempVector.end());

        do {
            int tempNum = 1;
            for (int q = 0; q < tempVector.size(); q++) {
                if (tempVector[q] == 1) {
                    tempNum *= num[q];
                }
            }
            answer += tempNum;
        } while (next_permutation(tempVector.begin(), tempVector.end()));
    }
    */

    return answer;
}

int main(void) {

    vector<vector<string>> clothes = {
        {"yellowhat", "face"},{"bluesunglasses", "eyewear"},{"green_turban", "headgear"}
    };

    vector<vector<string>> clothes2 = {
        {"a", "a"},{"b", "b"},{"c", "c"}
    };

    int answer = solution(clothes);

    cout << "answer : " << answer << endl;

}