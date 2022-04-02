#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int main(void)
{
    vector<vector<int>> edge = { {3, 6},{4, 3},{3, 2},{1, 3},{1, 2},{2, 4},{5, 2} };
    int n = 6;
    int answer = 0;
    vector<int> dis(n + 1, 0);   // �Ÿ��� ������ vector
    vector<int> visited(n + 1, -1);   // �湮 ���θ� ������ vector, �ʱⰪ -1(false)
    queue<int> q;
    vector<vector<int>> EDGE(n + 1);

    for (int i = 0; i < edge.size(); i++) {
        EDGE[edge[i][0]].push_back(edge[i][1]);
        EDGE[edge[i][1]].push_back(edge[i][0]);
    }

    q.push(1);
    dis[1] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        visited[node] = 1;   // �湮
        for (int i = 0; i < EDGE[node].size(); i++) {
            int neigh = EDGE[node][i];
            if (visited[neigh] == -1) {
                q.push(neigh);
                dis[neigh] = dis[node] + 1;
                visited[neigh] = 1;
            }
        }
    }

    int max = -10000;
    for (int i = 0; i < dis.size(); i++) {
        if (max < dis[i]) {
            max = dis[i];
            answer = 1;   // �ִ� ���� ���� ������ 1�� clear
        }
        else if (max == dis[i]) {
            answer++;   // ���� �ִ� ���� ��� anwer + 1
        }
    }


    return 0;
}