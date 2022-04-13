#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct compare {
    bool operator()(vector<int> a, vector<int> b) {   // a�� �տ� ���¾�, b�� �ڿ� ���¾�
        return a[1] > b[1];

    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int priorFinTime = 0;   // �ٷ� ���� �۾��� ���� �ð�
    priority_queue<vector<int>, vector<vector<int>>, compare> pq;

    for (int i = 0; i < jobs.size(); i++) {
        pq.push(jobs[i]);
    }

    while (!pq.empty()) {
        vector<int> job = pq.top();
        answer += (priorFinTime - job[0]) + job[1];   // ���ð� + ����ð�
        priorFinTime += job[1];   // ������� �۾��� ���� �ð�
        pq.pop();
        //cout << endl << "priorFinTime : " << priorFinTime << endl;   // ���� �ð�
        //cout << endl << "answer : " << answer << endl;   // �� �ҿ�ð�
    }

    return answer / jobs.size();
 
}

int main(void) {

    vector<vector<int>> jobs = { {0, 3},{1, 9},{2, 6} };

    int answer = solution(jobs);

    cout << "answer : " << answer << endl;


    return 0;
}