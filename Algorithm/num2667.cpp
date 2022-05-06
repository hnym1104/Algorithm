#include <vector>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> number;
vector<vector<bool>> visited;
vector<vector<int>> map;

/*
7
0110100
0110101
1110101
0000111
0100000
0111110
0111000

3
7
8
9
========
*/

bool effectivePos(int x, int y) {
	if (x < 0 || x >= map.size() || y < 0 || y >= map.size())
		return false;
	else
		return true;
}

int bfs(int x, int y) {   // x:행, y:열
	queue<pair<int, int>> q;
	pair<int, int> front;
	int count = 0;

	q.push(make_pair(x, y));   // 첫번째 pair push
	visited[x][y] = true;   // 첫번째 노드 방문

	while (!q.empty()) {
		front = q.front();
		int curX = front.first;   // 현재 노드의 x 좌표
		int curY = front.second;   //  현재 노드와 y 좌표
		if (effectivePos(curX - 1, curY) && map[curX - 1][curY] == 1 && !visited[curX - 1][curY]) {   // top이고 인접할 때
			q.push(make_pair(curX-1, curY));   // 노드 push
			visited[curX - 1][curY] = true;   // 방문
			map[curX - 1][curY] = -1;   // 새로운 map 시작점을 찾기 위해
		}
		if (effectivePos(curX, curY - 1) && map[curX][curY - 1] == 1 && !visited[curX][curY - 1]) {   // left이고 인접할 때
			q.push(make_pair(curX, curY-1));   // 노드 push
			visited[curX][curY - 1] = true;   // 방문
			map[curX][curY - 1] = -1;   // 새로운 map 시작점을 찾기 위해
		}
		if (effectivePos(curX, curY + 1) && map[curX][curY + 1] == 1 && !visited[curX][curY + 1]) {   // right이고 인접할 때
			q.push(make_pair(curX, curY+1));   // 노드 push
			visited[curX][curY+1] = true;   // 방문
			map[curX][curY + 1] = -1;   // 새로운 map 시작점을 찾기 위해
		}
		if (effectivePos(curX + 1, curY) && map[curX + 1][curY] == 1 && !visited[curX + 1][curY]) {   // bottom이고 인접할 때
			q.push(make_pair(curX+1, curY));   // 노드 push
			visited[curX+1][curY] = true;   // 방문
			map[curX + 1][curY] = -1;   // 새로운 map 시작점을 찾기 위해
		}
		q.pop();   // 가장 상위 노드 빼기
		count++;   // 인접한 노드 수 count
	}
	return count;
}

int main(void) {

	int size;
	
	cin >> size;
	map.assign(size, vector<int>(size, 0));   // map vector 초기화
	visited.assign(size, vector<bool>(size, false));

	for (int i = 0; i < size; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < size; j++) {
			map[i][j] = a[j] - '0';
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (map[i][j] == 1) {
				number.push_back(bfs(i, j));   // 한 구역 순회
			}
		}
	}
	
	cout << number.size() << endl;
	sort(number.begin(), number.end());   // 단지 수 오름차순 정렬
	for (int i = 0; i < number.size(); i++) {
		cout << number[i] << endl;
	}

	return 0;
}