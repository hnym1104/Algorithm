//for문 수정 vertex 크기만큼
//DFS와 BFS
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main(void)
{
	int vertex, edge, start;
	int f, t, count = 0;
	vector<bool> visited(1001, false);
	vector<vector <int>> graph(1001, vector<int>(1001, 0));   // 가로 1000, 세로 1000(최대 vertex)
	stack<int> D;
	queue<int> B;

	cin >> vertex >> edge >> start;

	for (int i = 0; i < edge; i++)
	{
		cin >> f >> t;   // 연결할 두 정점 입력
		graph[f][t] = 1;   // 인접행렬 
		graph[t][f] = 1;
	}

	//dfs(stack 사용)
	D.push(start);   // 시작 vertex stack에 넣음
	visited[start] = true;   // 시작 정점은 방문했으므로 true;
	cout << start << " ";

	while (!D.empty())
	{
		count = 0;
		int current = D.top();
		visited[current] = true;
		for (int i = 0; i < 1000; i++)
		{
			if (graph[current][i] == 1 && !visited[i])   // 연결되어있으면서 방문하지않은 노드
			{
				D.push(i);
				cout << i << " ";
				visited[i] = true;
				count = 1;
				break;
			}
		}
		if (count == 0)   // 더 이상 방문 가능한 인접 노드가 없을 때
			D.pop();
	}

	cout << endl;
	visited.assign(1001, false);

	//bfs(queue 사용)
	B.push(start);   // 시작 vertex queue에 넣음
	visited[start] = true;   // 시작 정점은 방문했으므로 true;
	cout << start << " ";

	while (!B.empty())
	{
		int current = B.front();
		visited[current] = true;
		B.pop();
		for (int i = 0; i < 1000; i++)
		{
			if (graph[current][i] == 1 && !visited[i])
			{
				B.push(i);
				visited[i] = true;
				cout << i << " ";
			}
		}
	}

	return 0;
}

