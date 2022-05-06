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

int bfs(int x, int y) {   // x:��, y:��
	queue<pair<int, int>> q;
	pair<int, int> front;
	int count = 0;

	q.push(make_pair(x, y));   // ù��° pair push
	visited[x][y] = true;   // ù��° ��� �湮

	while (!q.empty()) {
		front = q.front();
		int curX = front.first;   // ���� ����� x ��ǥ
		int curY = front.second;   //  ���� ���� y ��ǥ
		if (effectivePos(curX - 1, curY) && map[curX - 1][curY] == 1 && !visited[curX - 1][curY]) {   // top�̰� ������ ��
			q.push(make_pair(curX-1, curY));   // ��� push
			visited[curX - 1][curY] = true;   // �湮
			map[curX - 1][curY] = -1;   // ���ο� map �������� ã�� ����
		}
		if (effectivePos(curX, curY - 1) && map[curX][curY - 1] == 1 && !visited[curX][curY - 1]) {   // left�̰� ������ ��
			q.push(make_pair(curX, curY-1));   // ��� push
			visited[curX][curY - 1] = true;   // �湮
			map[curX][curY - 1] = -1;   // ���ο� map �������� ã�� ����
		}
		if (effectivePos(curX, curY + 1) && map[curX][curY + 1] == 1 && !visited[curX][curY + 1]) {   // right�̰� ������ ��
			q.push(make_pair(curX, curY+1));   // ��� push
			visited[curX][curY+1] = true;   // �湮
			map[curX][curY + 1] = -1;   // ���ο� map �������� ã�� ����
		}
		if (effectivePos(curX + 1, curY) && map[curX + 1][curY] == 1 && !visited[curX + 1][curY]) {   // bottom�̰� ������ ��
			q.push(make_pair(curX+1, curY));   // ��� push
			visited[curX+1][curY] = true;   // �湮
			map[curX + 1][curY] = -1;   // ���ο� map �������� ã�� ����
		}
		q.pop();   // ���� ���� ��� ����
		count++;   // ������ ��� �� count
	}
	return count;
}

int main(void) {

	int size;
	
	cin >> size;
	map.assign(size, vector<int>(size, 0));   // map vector �ʱ�ȭ
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
				number.push_back(bfs(i, j));   // �� ���� ��ȸ
			}
		}
	}
	
	cout << number.size() << endl;
	sort(number.begin(), number.end());   // ���� �� �������� ����
	for (int i = 0; i < number.size(); i++) {
		cout << number[i] << endl;
	}

	return 0;
}