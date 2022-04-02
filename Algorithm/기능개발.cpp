#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void)
{
    vector<int> progresses = { 93, 30, 55 };
    vector<int> speeds = { 1, 30, 5 };
    vector<int> answer;
    queue<int> q;
    int d;
    int pD;
    int count;

    for (int i = 0; i < progresses.size(); i++) {
        if (((100 - progresses[i]) % speeds[i]) == 0)
            d = (100 - progresses[i]) / speeds[i];
        else
            d = ((100 - progresses[i]) / speeds[i]) + 1;
        q.push(d);
    }

    while (!q.empty()) {
        count = 0;
        pD = q.front();
        cout << pD << endl;
        q.pop();
        count++;
        while (!(q.empty()) && q.front() <= pD) {
            q.pop();
            count++;
            if (q.empty())
                break;
        }
        answer.push_back(count);
        cout << "answer : " << count << endl;
    }

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << endl;

    return 0;
}
