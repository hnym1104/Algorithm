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
	char board[20][20] = { 1, };   // ����� ��� ������ �� �ִ� ��
	char alp[20];
	int mX[4] = { 0, 0, -1, +1 };   // ����, ������, ��, �Ʒ� ������ ���� x��ǥ ��ȭ(����)
	int mY[4] = { -1, +1, 0, 0 };   // ����, ������, ��, �Ʒ� ������ ���� y��ǥ ��ȭ(����)
	char path[20];   // �����±濡 ������ ���ĺ�
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

	//(0, 0)���� ����
	xpos = 0; ypos = 0;
	Q.push(P(xpos, ypos, 1));   // ���� ��ǥ push
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
			if (canGo(cX + mX[i], cY + mY[i], R, C) && !charFind(board[cX + mX[i]][cY + mY[i]], path))   // ���� ���ĺ��� ���� ���� ���� ���� ��
			{
				cout << "x : " << cX + mX[i] << " y : " << cY + mY[i] << " board : " << board[cX + mX[i]][cY + mY[i]] << endl;
				Q.push(P(cX + mX[i], cY + mY[i], cL + 1));   // queue�� push �� ��� update
				cout << "push!" << endl;
				path[store++] = board[cX + mX[i]][cY + mY[i]];
				count = true;
			}
		}
		if (!count)   // �� �̻� �̵� ������ ��ΰ� ���� ��
		{
			cout << "!!!!" << cL + 1 << endl;
			break;
		}
	}

	//���ߴ� ���� : �� �̻� ���� �� �ִ� ���� ���� ��

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