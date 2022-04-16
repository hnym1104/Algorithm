#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct compare {
    bool operator()(vector<int> a, vector<int> b) {   // a가 앞에 오는애, b가 뒤에 오는애
        return a[1] > b[1];   // 총 소요시간 짧은 순서대로 놓기
    }
};

int solution(vector<vector<int>> jobs) {
    /*
    1. 요청 시간 당시 현재 실행 중인 작업이 없을 경우
        : 들어온 순서대로 처리
    2. 현재 작업 실행 중 요청이 들어온 경우
        : 실행시간이 짧은 순대로 처리
    */
    int answer = 0;
    int priorFinTime = 0;   // 바로 직전 작업이 끝난 시간
    priority_queue<vector<int>, vector<vector<int>>, compare> pq;

    sort(jobs.begin(), jobs.end());

    int i = 0;
    vector<int> cur_job;

    while (i != jobs.size()) {
        cout << "i : " << i << endl;
        cout << "priorFinTime : " << priorFinTime << endl;
        cur_job = jobs[i];   // 현재 job
        cout << cur_job[0] << ", " << cur_job[1] << endl;
        if (priorFinTime <= cur_job[0]) {   // 현재 처리중인 작업이 없는 경우
            priorFinTime = cur_job[0];   // 현재 시간은 요청이 들어온 시간임
            answer += cur_job[1];   // 총 소요시간
            priorFinTime += cur_job[1];   // 작업이 끝난 후 현재 시간은 처리 시간을 더한 것
            i++;
        }
        else {   // 현재 처리중인 작업이 있을 경우 -> queue에 넣어야함
            cout << "현재 처리중인 작업이 있음" << endl;
            while ((priorFinTime > jobs[i][0])) {   // 현재 실행 중인 작업 중 들어온 모든 요청 queue에 넣기
                cur_job = jobs[i];   // 현재 job
                cout << cur_job[0] << ", " << cur_job[1] << endl;
                pq.push(cur_job);   // 처리시간 순서대로 queue에 넣음
                i++;
                if (i == jobs.size()) {
                    break;
                }
            }
            cout << "queue에 들어온 순서대로 요청 처리" << endl;
            while (!pq.empty()) {   // queue에 들어온 요청 순서대로 처리
                cur_job = pq.top();
                cout << cur_job[0] << ", " << cur_job[1] << endl;
                answer += (priorFinTime - cur_job[0] + cur_job[1]);   // 총 소요시간
                priorFinTime += cur_job[1];   // 이전 작업이 끝난 현재 시간에서 처리시간을 더하면 현재 시간
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
    
    for (int i = 0; i < jobs.size(); i++) {   // 요청 시간순 a[0] 으로 정렬
        for (int j = 0; j < jobs[i].size(); j++) {
            cout << jobs[i][j] << " ";
        }
        cout << endl;
    }

    int answer = solution(jobs);

    cout << "answer : " << answer << endl;

    cout << "**************job2***************" << endl;
    for (int i = 0; i < jobs2.size(); i++) {   // 요청 시간순 a[0] 으로 정렬
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