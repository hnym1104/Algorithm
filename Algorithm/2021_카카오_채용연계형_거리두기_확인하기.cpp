#include <vector>
#include <string>
#include <iostream>
#include <queue>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };   // top, right, bottom, left(�ð����)
int dy[4] = { 0, 1, 0, -1 };   // top, right, bottom, left(�ð����)
bool check;
void dfs(vector<string>& perClass, int x, int y, int X, int Y, int distance) {   // X, Y�� ���� Ž�� ���� ��ǥ
	if (distance == 2)   // �Ÿ��α⸦ ��Ű�� ����
		return;
	for (int i = 0; i < 4; i++) {
		int cx = x + dx[i];   // x��ǥ �̵�
		int cy = y + dy[i];   // y��ǥ �̵�
		if (cx >= 0 && cx < 5 && cy >= 0 && cy < 5 && perClass[cx][cy] != 'X') {
			if (X == cx && Y == cy)
				continue;
			if (perClass[cx][cy] == 'P') {
				check = false;
				return;
			}
			dfs(perClass, cx, cy, X, Y, distance + 1);   // �ٽ� ���� �ڸ� Ž��
		}
	}
}

int main(void) {
	vector<int> answer;
	vector<vector<string>> places = {
		{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
		{"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
		{"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
		{"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
		{"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}
	};
	int x = 0, y = 0, i = 0;
	
	for (auto perClass : places) {
		bool flag = true;
		for (x = 0; x < 5; x++) {
			for (y = 0; y < 5; y++) {
				if (perClass[x][y] == 'P') {   // ����� �ִ� �ڸ��� ��� �Ÿ� 2 �̳��� �����ڰ� �ִ��� Ȯ��
					check = true; 
					dfs(perClass, x, y, x, y, 0); 
					if (!check)
						flag = false;
				}
			}
		}
		if (!flag)   // �Ÿ��α⸦ ��Ű�� �ʰ� ����
			answer.push_back(0);
		else   // �Ÿ��α⸦ ��Ű�� ����
			answer.push_back(1);
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}

	return 0;
}