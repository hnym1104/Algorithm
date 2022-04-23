#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct compare {
    bool operator()(vector<int> a, vector<int> b) {   // a�� �տ� ���¾�, b�� �ڿ� ���¾�
        return a[1] > b[1];   // �� �ҿ�ð� ª�� ������� ����
    }
};

int solution(vector<vector<int>> jobs) {
    /*
    1. ��û �ð� ��� ���� ���� ���� �۾��� ���� ���
        : ���� ������� ó��
    2. ���� �۾� ���� �� ��û�� ���� ���
        : ����ð��� ª�� ����� ó��
    */
    int answer = 0;
    int priorFinTime = 0;   // �ٷ� ���� �۾��� ���� �ð�
    priority_queue<vector<int>, vector<vector<int>>, compare> pq;

    sort(jobs.begin(), jobs.end());   // jobs ����, ��û ���� �ð� ��, ��û ���� �ð��� ���ٸ� �ҿ�ð� ��

    cout << "********** job **********" << endl;

    for (int i = 0; i < jobs.size(); i++) {
        cout << jobs[i][0] << ", " << jobs[i][1] << endl;
    }

    int i = 0;
    vector<int> cur_job;   // ���� ����� �۾�

    while (i < jobs.size() || !pq.empty()) {
        if (i < jobs.size() && priorFinTime >= jobs[i][0]) {   // ���� �ð����� ���� �ð��� ���� �۾��� ���� ���
            pq.push(jobs[i]);   // �ҿ�ð������� push
            i++;
            continue;
        }
        if (!pq.empty()) {   // ť�� �����ʾҴٸ�
            cur_job = pq.top();
            priorFinTime += cur_job[1];
            answer += priorFinTime - cur_job[0];
            pq.pop();
        }
        else
            priorFinTime = jobs[i][0];
    }
    
    return answer / jobs.size();
}

int main(void) {

    vector<vector<int>> jobs = { {0, 3}, {2, 6}, {1, 9} };

    vector<vector<int>> jobs2 = { {24, 10},{28, 39},{43, 20},{37, 5},{47, 22},{20, 47},
        {15, 34},{15, 2},{35, 43},{26, 1} };

    vector<vector<int>> jobs3 = { {0, 5}, {2, 10}, {10000, 2} };

    vector<vector<int>> jobs4 = { {0, 3}, {4, 1} };

    int answer = solution(jobs);

    cout << "answer : " << answer << endl;

    int answer2 = solution(jobs2);

    cout << "answer2 : " << answer2 << endl;

    int answer3 = solution(jobs3);

    cout << "answer3 : " << answer3 << endl;

    int answer4 = solution(jobs4);

    cout << "answer4 : " << answer4 << endl;

    jobs = { {0, 3},{0, 2},{1, 9},{2, 6} };   // 8

    cout << "answer5 : " << solution(jobs) << endl;

    jobs = { {0, 9}, {0, 4}, {0, 5}, {0, 7}, {0, 3} };   // 13

    cout << "answer6 : " << solution(jobs) << endl;

    jobs = { {0, 3}, {4, 6} };   // 4

    cout << "answer7 : " << solution(jobs) << endl;

    jobs = { {0, 3}, {4, 4}, {5, 3}, {4, 1} };    // 3

    cout << "answer8 : " << solution(jobs) << endl;

    jobs = { {0, 3}, {1, 9}, {500, 6} };   // 6

    cout << "answer10 : " << solution(jobs) << endl;

    jobs = { {1, 9}, {1, 4}, {1, 5}, {1, 7}, {1, 3} };   // 13

    cout << "answer11 : " << solution(jobs) << endl;

    jobs = { {0, 5}, {1, 4}, {6, 1}, {7, 1} };

    cout << "answer12 : " << solution(jobs) << endl;   // 5

    return 0;
}