#include <iostream>
#include <queue>
using namespace std;

bool charFind(char C, char* Path);
bool canGo(int R, int C, int x, int y);

class P
{
public:
	int xpos;
	int ypos;
	int len;

	P(int x, int y, int l)
	{
		xpos = x;
		ypos = y;
		len = l;
	}
};

int main(void)
{
	int R, C;
	char board[20][20] = { 1, };   // 현재는 모두 지나갈 수 있는 길
	char alp[20];
	int mX[4] = { 0, 0, -1, +1 };   // 왼쪽, 오른쪽, 위, 아래 움직일 때의 x좌표 변화(가로)
	int mY[4] = { -1, +1, 0, 0 };   // 왼쪽, 오른쪽, 위, 아래 움직일 때의 y좌표 변화(세로)
	char path[20];   // 지나온길에 쓰여진 알파벳
	bool count = false;
	int xpos, ypos;
	int store = 0;
	queue<P> Q;

	cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		cin >> alp;
		for (int j = 0; j < C; j++)
			board[i][j] = alp[j];
	}

	//(0, 0)에서 시작
	xpos = 0; ypos = 0;
	Q.push(P(xpos, ypos, 1));   // 시작 좌표 push
	path[store++] = board[xpos][ypos];

	while (!Q.empty())
	{
		count = false;
		int cX = Q.front().xpos;
		int cY = Q.front().ypos;
		int cL = Q.front().len;
		Q.pop();
		cout << "current : " << cX << " ," << cY << endl;
		for (int i = 0; i < 4; i++)
		{
			cout << i << endl;
			cout << "x : " << cX + mX[i] << " y : " << cY + mY[i] << " board : " << board[cX + mX[i]][cY + mY[i]] << endl;
			if (canGo(cX + mX[i], cY + mY[i], R, C) && !charFind(board[cX + mX[i]][cY + mY[i]], path))   // 같은 알파벳이 없고 범위 내에 있을 때
			{
				cout << "x : " << cX + mX[i] << " y : " << cY + mY[i] << " board : " << board[cX + mX[i]][cY + mY[i]] << endl;
				Q.push(P(cX + mX[i], cY + mY[i], cL + 1));   // queue에 push 후 경로 update
				cout << "push!" << endl;
				path[store++] = board[cX + mX[i]][cY + mY[i]];
				count = true;
			}
		}
		if (!count)   // 더 이상 이동 가능한 경로가 없을 때
		{
			cout << "!!!!" << cL + 1 << endl;
			break;
		}
	}

	//멈추는 조건 : 더 이상 지날 수 있는 길이 없을 때

	return 0;

}

bool charFind(char C, char* Path)
{
	for (int i = 0; i < 20; i++)
	{
		if (Path[i] == C)
			return true;
	}
	return false;
}

bool canGo(int R, int C, int x, int y)
{
	if (x < 0 || y < 0 || x >= R || y >= C)
		return false;
	return true;
}