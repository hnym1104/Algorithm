//미로탐색
#include <iostream>
#include <queue>
using namespace std;

bool cango(int n, int m, int x, int y, int(*maze)[101]);

class E   // 각 점의 정보 저장
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
	int moveX[4] = { 0, 0, -1, +1 };   // 왼쪽, 오른쪽, 위쪽, 아래 이동시 x좌표(열) 변화
	int moveY[4] = { -1, +1, 0, 0 };   // 왼쪽, 오른쪽, 위쪽, 아래 이동시 y좌표(행) 변화
	queue<E> MAZE;   // 미로 BFS 탐색 정보를 저장할 queue
	bool visited[101][101] = { false, };

	cin >> n >> m;

	// 미로 입력
	for (int i = 1; i <= n; i++)
	{
		cin >> input;
		for (int j = 1; j <= m; j++)
			maze[i][j] = (input[j - 1] - '0');
	}

	//(1, 1)에서 시작
	MAZE.push(E(1, 1, 1));   // push start edge
	visited[1][1] = true;
	while (!MAZE.empty())
	{
		currentX = MAZE.front().xpos;
		currentY = MAZE.front().ypos;   // 현재 좌표
		currentL = MAZE.front().length;   // 현재 거리

		MAZE.pop();

		for (int i = 0; i < 4; i++)   // 방문 여부, 미로 범위 내 존재 여부, 갈 수 있는 길인지 검사
		{
			if (currentX + moveX[i] == n && currentY + moveY[i] == m)
			{
				cout << currentL + 1 << endl;   // 목적지 도착까지 소요 경로 출력
				return 0;
			}
			if (!visited[currentX + moveX[i]][currentY + moveY[i]] && cango(n, m, currentX + moveX[i], currentY + moveY[i], maze))
			{
				visited[currentX + moveX[i]][currentY + moveY[i]] = true;
				MAZE.push(E(currentX + moveX[i], currentY + moveY[i], currentL + 1));   // 새로운 경로 queue에 push
			}
			else
				continue;
		}
	}

	return 0;
}

bool cango(int n, int m, int x, int y, int(*maze)[101])
{
	if ((x == 0) || (y == 0) || (x > n) || (y > m) || (maze[x][y] == 0))   // 미로 범위 내, 갈 수 있는 길인가
		return false;
	else
		return true;
}
