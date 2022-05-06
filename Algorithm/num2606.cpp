#include<vector>
#include<iostream>
using namespace std;

/*
7
6
1 2
2 3
1 5
5 2
5 6
4 7

4
*/

vector<vector<int>> network;
vector<bool> visited;

int dfs(int x, int count) {
	visited[x] = true;
	for (int i = 0; i < network[x].size(); i++) {
		if (network[x][i] == 1 && !visited[i]) {   // 인접한 노드이고 아직 방문하지 않았다면
			count = dfs(i, ++count);
			visited[i] = true;
		}
	}
	return count;
}

int main(void) {
	int comNumber;
	int pairNumber;
	int start, end;
	int count = 0;

	cin >> comNumber >> pairNumber;
	network.assign(comNumber+1, vector<int>(comNumber+1, 0));
	visited.assign(comNumber+1, false);

	for (int i = 0; i < pairNumber; i++) {   // 그래프 초기화
		cin >> start >> end;
		network[start][end] = 1;
		network[end][start] = 1;
	}

	cout << dfs(1, 0) << endl;

	return 0;
	
}