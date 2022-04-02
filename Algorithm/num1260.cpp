//for�� ���� vertex ũ�⸸ŭ
//DFS�� BFS
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
	vector<vector <int>> graph(1001, vector<int>(1001, 0));   // ���� 1000, ���� 1000(�ִ� vertex)
	stack<int> D;
	queue<int> B;

	cin >> vertex >> edge >> start;

	for (int i = 0; i < edge; i++)
	{
		cin >> f >> t;   // ������ �� ���� �Է�
		graph[f][t] = 1;   // ������� 
		graph[t][f] = 1;
	}

	//dfs(stack ���)
	D.push(start);   // ���� vertex stack�� ����
	visited[start] = true;   // ���� ������ �湮�����Ƿ� true;
	cout << start << " ";

	while (!D.empty())
	{
		count = 0;
		int current = D.top();
		visited[current] = true;
		for (int i = 0; i < 1000; i++)
		{
			if (graph[current][i] == 1 && !visited[i])   // ����Ǿ������鼭 �湮�������� ���
			{
				D.push(i);
				cout << i << " ";
				visited[i] = true;
				count = 1;
				break;
			}
		}
		if (count == 0)   // �� �̻� �湮 ������ ���� ��尡 ���� ��
			D.pop();
	}

	cout << endl;
	visited.assign(1001, false);

	//bfs(queue ���)
	B.push(start);   // ���� vertex queue�� ����
	visited[start] = true;   // ���� ������ �湮�����Ƿ� true;
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

