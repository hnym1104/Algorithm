#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int dfs(int index, vector<int> numbers, int sum, int target) {
    cout << "current sum = " << sum << endl << endl;
    if (index >= numbers.size()) {
        if (sum == target) {
            cout << "sum = " << sum << endl;
            return 1;
        }
        else
            return 0;
    }

    cout << "numbers[" << index << "] = " << numbers[index] << endl;

    int tmpSum1 = sum + numbers[index];
    int tmpSum2 = sum - numbers[index];

    int tmpAnswer = 0;
    tmpAnswer += dfs(index + 1, numbers, tmpSum1, target);
    tmpAnswer += dfs(index + 1, numbers, tmpSum2, target);

    return tmpAnswer;
}

int main(void)
{
    vector<int> numbers = { 1, 1, 1, 1, 1 };
    int target = 3;

    int answer = 0;

    answer += dfs(1, numbers, numbers[0], target);
    answer += dfs(1, numbers, -numbers[0], target);

    cout << "answer = " << answer << endl;

    return 0;
}