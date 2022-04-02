//안전영역
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

bool cango(int x, int y, int n, int(*load)[101]);

class E
{
public :
	int xpos;
	int ypos;

	E(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
};

int main(void)
{
	int n;
	int p[101][101] = { 0, };
	int load[101][101] = { 0, };
	int max = -1000;
	int safe = 1;
	bool visited[101][101] = { false, };   //  방문여부 확인
	queue<E> short_path;
	int temp_count = 0;
	int mX[4] = { 0, 0, -1, +1 };   // 왼쪽, 오른쪽, 위쪽, 아래 이동시 x좌표(열) 변화
	int mY[4] = { -1, +1, 0, 0 };   // 왼쪽, 오른쪽, 위쪽, 아래 이동시 y좌표(행) 변화
	int T;


	cin >> n;
	getchar();   // 입력버퍼에 남아있는 개행문자 제거

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> T;
			p[i][j] = T;
			if (max < T)
				max = T;
		}
	}

	for (int i = 0; i <= max; i++)
	{
		temp_count = 0;   // 특정 강수량에서의 안전 구역의 개수
		for (int xx = 0; xx < 101; xx++)
		{
			for (int yy = 0; yy < 101; yy++)
				visited[xx][yy] = false;
		}   // 방문여부 다시 all false로 초기화
		for (int m = 0; m < n; m++)
		{
			for (int k = 0; k < n; k++)
			{
				if (p[m][k] <= i)
					load[m][k] = 0;   // 물에 잠겨서 갈 수 없는 곳
				else
					load[m][k] = 1;   // 물에 잠기지않아서 갈 수 있는 곳
			}
		}

		for (int m = 0; m < n; m++)
		{
			for (int k = 0; k < n; k++)
			{
				if (load[m][k] == 1 && !visited[m][k])   // 이동 가능한 곳이고 방문하지 않은 곳일 때
				{
					//safe  세기
					// 만약 기존 safe보다 크다면 safe 바꾸기(최대 안전구역)
					short_path.push(E(m, k));   // 첫 곳 queue에 push
					visited[m][k] = true;
					// BFS로 가능한 최단경로 찾기
					while (!short_path.empty())
					{
						int currentX = short_path.front().xpos;
						int currentY = short_path.front().ypos;
						short_path.pop();
						for (int q = 0; q < 4; q++)   // 현재 좌표에서 왼쪽, 오른쪽, 위쪽, 아래쪽 검사
						{
							// 방문 여부와 이동 가능한 길인지 판단
							if (!visited[currentX + mX[q]][currentY + mY[q]] && cango(currentX + mX[q], currentY + mY[q], n, load))
							{
								// 갈 수 있는 길일 때
								short_path.push(E(currentX + mX[q], currentY + mY[q]));   // 새로운 경로 queue에 push
								visited[currentX + mX[q]][currentY + mY[q]] = true;   // 방문
							}
							else
								continue;
						}
					}
					temp_count++;   // 최단경로 찾은 후 안전구역 개수 +1
				}
				else
					continue;
			}
		}
		if (safe <= temp_count)   // 특정 강수량에서의 안전구역의 개수가 가장 클 때 안전구역의 개수 바꾸기
			safe = temp_count;

	}

	cout << safe << endl;
	return 0;

}

bool cango(int x, int y, int n, int(*load)[101])
{
	if ((x < 0) || (y < 0) || (x > n-1) || (y > n-1) || (load[x][y] == 0))   // 미로 범위 내, 갈 수 있는 길인가
		return false;
	else
		return true;
}