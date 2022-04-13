#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct compare {
    bool operator()(vector<int> a, vector<int> b) {   // a가 앞에 오는애, b가 뒤에 오는애
        return a[1] > b[1];

    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int priorFinTime = 0;   // 바로 직전 작업이 끝난 시간
    priority_queue<vector<int>, vector<vector<int>>, compare> pq;

    for (int i = 0; i < jobs.size(); i++) {
        pq.push(jobs[i]);
    }

    while (!pq.empty()) {
        vector<int> job = pq.top();
        answer += (priorFinTime - job[0]) + job[1];   // 대기시간 + 실행시간
        priorFinTime += job[1];   // 현재까지 작업이 끝난 시간
        pq.pop();
        //cout << endl << "priorFinTime : " << priorFinTime << endl;   // 현재 시간
        //cout << endl << "answer : " << answer << endl;   // 총 소요시간
    }

    return answer / jobs.size();
 
}

int main(void) {

    vector<vector<int>> jobs = { {0, 3},{1, 9},{2, 6} };

    int answer = solution(jobs);

    cout << "answer : " << answer << endl;


    return 0;
}