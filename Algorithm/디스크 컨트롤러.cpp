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

    sort(jobs.begin(), jobs.end());

    int i = 0;
    vector<int> cur_job;

    while (i != jobs.size()) {
        cout << "i : " << i << endl;
        cout << "priorFinTime : " << priorFinTime << endl;
        cur_job = jobs[i];   // ���� job
        cout << cur_job[0] << ", " << cur_job[1] << endl;
        if (priorFinTime <= cur_job[0]) {   // ���� ó������ �۾��� ���� ���
            priorFinTime = cur_job[0];   // ���� �ð��� ��û�� ���� �ð���
            answer += cur_job[1];   // �� �ҿ�ð�
            priorFinTime += cur_job[1];   // �۾��� ���� �� ���� �ð��� ó�� �ð��� ���� ��
            i++;
        }
        else {   // ���� ó������ �۾��� ���� ��� -> queue�� �־����
            cout << "���� ó������ �۾��� ����" << endl;
            while ((priorFinTime > jobs[i][0])) {   // ���� ���� ���� �۾� �� ���� ��� ��û queue�� �ֱ�
                cur_job = jobs[i];   // ���� job
                cout << cur_job[0] << ", " << cur_job[1] << endl;
                pq.push(cur_job);   // ó���ð� ������� queue�� ����
                i++;
                if (i == jobs.size()) {
                    break;
                }
            }
            cout << "queue�� ���� ������� ��û ó��" << endl;
            while (!pq.empty()) {   // queue�� ���� ��û ������� ó��
                cur_job = pq.top();
                cout << cur_job[0] << ", " << cur_job[1] << endl;
                answer += (priorFinTime - cur_job[0] + cur_job[1]);   // �� �ҿ�ð�
                priorFinTime += cur_job[1];   // ���� �۾��� ���� ���� �ð����� ó���ð��� ���ϸ� ���� �ð�
                pq.pop();
                cout << "priorFInTime : " << priorFinTime << endl;
            }
        }
    }

    return answer / jobs.size();
}

int main(void) {

    vector<vector<int>> jobs = { {0, 3}, {2, 6}, {1, 9} };

    vector<vector<int>> jobs2 = { {24, 10},{28, 39},{43, 20},{37, 5},{47, 22},{20, 47},
        {15, 34},{15, 2},{35, 43},{26, 1} };

    vector<vector<int>> jobs3 = { {0, 5}, {2, 10}, {10000, 2} };

    cout << "**************job***************" << endl;
    
    for (int i = 0; i < jobs.size(); i++) {   // ��û �ð��� a[0] ���� ����
        for (int j = 0; j < jobs[i].size(); j++) {
            cout << jobs[i][j] << " ";
        }
        cout << endl;
    }

    int answer = solution(jobs);

    cout << "answer : " << answer << endl;

    cout << "**************job2***************" << endl;
    for (int i = 0; i < jobs2.size(); i++) {   // ��û �ð��� a[0] ���� ����
        for (int j = 0; j < jobs2[i].size(); j++) {
            cout << jobs2[i][j] << " ";
        }
        cout << endl;
    }

    int answer2 = solution(jobs2);

    cout << "answer2 : " << answer2 << endl;

    int answer3 = solution(jobs3);

    cout << "answer3 : " << answer3 << endl;

    return 0;
}