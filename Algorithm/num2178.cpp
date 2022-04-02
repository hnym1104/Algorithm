//�̷�Ž��
#include <iostream>
#include <queue>
using namespace std;

bool cango(int n, int m, int x, int y, int(*maze)[101]);

class E   // �� ���� ���� ����
{
public :
	int xpos, ypos;
	int length;

	E(int x, int y, int l)
	{
		xpos = x;
		ypos = y;
		length = l;
	}
};

int main(void)
{
	int n, m, currentX, currentY, currentL;
	int maze[101][101] = { 0, };
	char input[101];
	int moveX[4] = { 0, 0, -1, +1 };   // ����, ������, ����, �Ʒ� �̵��� x��ǥ(��) ��ȭ
	int moveY[4] = { -1, +1, 0, 0 };   // ����, ������, ����, �Ʒ� �̵��� y��ǥ(��) ��ȭ
	queue<E> MAZE;   // �̷� BFS Ž�� ������ ������ queue
	bool visited[101][101] = { false, };

	cin >> n >> m;

	// �̷� �Է�
	for (int i = 1; i <= n; i++)
	{
		cin >> input;
		for (int j = 1; j <= m; j++)
			maze[i][j] = (input[j - 1] - '0');
	}

	//(1, 1)���� ����
	MAZE.push(E(1, 1, 1));   // push start edge
	visited[1][1] = true;
	while (!MAZE.empty())
	{
		currentX = MAZE.front().xpos;
		currentY = MAZE.front().ypos;   // ���� ��ǥ
		currentL = MAZE.front().length;   // ���� �Ÿ�

		MAZE.pop();

		for (int i = 0; i < 4; i++)   // �湮 ����, �̷� ���� �� ���� ����, �� �� �ִ� ������ �˻�
		{
			if (currentX + moveX[i] == n && currentY + moveY[i] == m)
			{
				cout << currentL + 1 << endl;   // ������ �������� �ҿ� ��� ���
				return 0;
			}
			if (!visited[currentX + moveX[i]][currentY + moveY[i]] && cango(n, m, currentX + moveX[i], currentY + moveY[i], maze))
			{
				visited[currentX + moveX[i]][currentY + moveY[i]] = true;
				MAZE.push(E(currentX + moveX[i], currentY + moveY[i], currentL + 1));   // ���ο� ��� queue�� push
			}
			else
				continue;
		}
	}

	return 0;
}

bool cango(int n, int m, int x, int y, int(*maze)[101])
{
	if ((x == 0) || (y == 0) || (x > n) || (y > m) || (maze[x][y] == 0))   // �̷� ���� ��, �� �� �ִ� ���ΰ�
		return false;
	else
		return true;
}
