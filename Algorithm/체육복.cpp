#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(void)
{
    int n = 6;
    vector<int> lost = { 1, 2, 3, 4, 5, 6 };
    vector<int> reserve = { 1, 2, 3, 4, 5, 6 };
    int answer = 0;
    vector<int>::iterator can = reserve.begin();
    vector<int> temp;

    temp = lost;

    for (int i = 0; i < temp.size(); i++) {
        cout << "temp : " << temp[i] << endl;
        can = find(reserve.begin(), reserve.end(), temp[i]);
        if (can != reserve.end()) {   // 여분을 잃어버렸을 때
            cout << "reserve : " << *can << endl;
            lost.erase(find(lost.begin(), lost.end(), temp[i]));
            cout << "lost vector : ";
            for (int i = 0; i < lost.size(); i++)
                cout << lost[i] << " ";
            cout << endl;
            reserve.erase(can);
            cout << "reserve : ";
            for (int i = 0; i < reserve.size(); i++)
                cout << reserve[i] << " ";
            cout << endl;
        }
    }

    answer += (n - lost.size());   // 체육복 하나라도 있는 학생들
    cout << "first answer = " << answer << endl;

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    for (int i = 0; i < lost.size(); i++) {
        if (lost[i] == 1) {
            can = find(reserve.begin(), reserve.end(), 2);
            if (can != reserve.end()) {
                answer++;
                reserve.erase(can);
            }
        }
        else if (lost[i] == n) {
            can = find(reserve.begin(), reserve.end(), n - 1);
            if (can != reserve.end()) {
                answer++;
                reserve.erase(can);
            }
        }
        else {
            can = find(reserve.begin(), reserve.end(), lost[i] - 1);
            if (can != reserve.end()) {
                answer++;
                reserve.erase(can);
            }
            else {
                can = find(reserve.begin(), reserve.end(), lost[i] + 1);
                if (can != reserve.end()) {
                    answer++;
                    reserve.erase(can);
                }
            }
        }
    }
    cout << "answer = " << answer << endl;

    return 0;

}

