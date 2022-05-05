#include <vector>
#include <queue>
#include <iostream>
using namespace std;

/*
4 5 1
1 2
1 3
1 4
2 4
3 4

1 2 4 3
1 2 3 4
==========
5 5 3
5 4
5 2
1 2
3 4
3 1

3 1 2 5 4
3 1 4 2 5
==========
1000 1 1000
999 1000

1000 999
1000 999
*/

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int x) {
	visited[x] = true;
	cout << x << " ";
	for (int i = 0; i < graph[x].size(); i++) {
		if (graph[x][i] == 1) {
			if (!visited[i])
				dfs(i);
		}
	}
}

void bfs(int x) {
	queue<int> q;
	visited[x] = true;
	q.push(x);   // 초기 원소
	while (!q.empty()) {
		x = q.front();
		cout << q.front() << " ";
		for (int i = 0; i < graph[x].size(); i++) {
			if (graph[x][i] == 1) {
				if (!visited[i]) {
					q.push(i);   // 인접한 노드 push
					visited[i] = true;
				}
			}
		}
		q.pop();
	}
}

int main(void)
{
	int vertex, edge, start;
	int p1, p2;
	cin >> vertex >> edge >> start;

	graph.assign(1001, vector<int>(1001, 0));
	visited.assign(1001, false);
	
	for (int i = 0; i < edge; i++) {   // 그래프 초기화
		cin >> p1 >> p2;
		graph[p1][p2] = 1;
		graph[p2][p1] = 1;
	}

	/*for (int i = 0; i < graph.size(); i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}*/

	dfs(start);   // vertex 0부터 탐색 시작
	visited.assign(1001, false);   // bfs 위해 visited 초기화
	cout << endl;
	bfs(start);
	return 0;
}

