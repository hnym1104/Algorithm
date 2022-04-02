//��������
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
	bool visited[101][101] = { false, };   //  �湮���� Ȯ��
	queue<E> short_path;
	int temp_count = 0;
	int mX[4] = { 0, 0, -1, +1 };   // ����, ������, ����, �Ʒ� �̵��� x��ǥ(��) ��ȭ
	int mY[4] = { -1, +1, 0, 0 };   // ����, ������, ����, �Ʒ� �̵��� y��ǥ(��) ��ȭ
	int T;


	cin >> n;
	getchar();   // �Է¹��ۿ� �����ִ� ���๮�� ����

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
		temp_count = 0;   // Ư�� ������������ ���� ������ ����
		for (int xx = 0; xx < 101; xx++)
		{
			for (int yy = 0; yy < 101; yy++)
				visited[xx][yy] = false;
		}   // �湮���� �ٽ� all false�� �ʱ�ȭ
		for (int m = 0; m < n; m++)
		{
			for (int k = 0; k < n; k++)
			{
				if (p[m][k] <= i)
					load[m][k] = 0;   // ���� ��ܼ� �� �� ���� ��
				else
					load[m][k] = 1;   // ���� ������ʾƼ� �� �� �ִ� ��
			}
		}

		for (int m = 0; m < n; m++)
		{
			for (int k = 0; k < n; k++)
			{
				if (load[m][k] == 1 && !visited[m][k])   // �̵� ������ ���̰� �湮���� ���� ���� ��
				{
					//safe  ����
					// ���� ���� safe���� ũ�ٸ� safe �ٲٱ�(�ִ� ��������)
					short_path.push(E(m, k));   // ù �� queue�� push
					visited[m][k] = true;
					// BFS�� ������ �ִܰ�� ã��
					while (!short_path.empty())
					{
						int currentX = short_path.front().xpos;
						int currentY = short_path.front().ypos;
						short_path.pop();
						for (int q = 0; q < 4; q++)   // ���� ��ǥ���� ����, ������, ����, �Ʒ��� �˻�
						{
							// �湮 ���ο� �̵� ������ ������ �Ǵ�
							if (!visited[currentX + mX[q]][currentY + mY[q]] && cango(currentX + mX[q], currentY + mY[q], n, load))
							{
								// �� �� �ִ� ���� ��
								short_path.push(E(currentX + mX[q], currentY + mY[q]));   // ���ο� ��� queue�� push
								visited[currentX + mX[q]][currentY + mY[q]] = true;   // �湮
							}
							else
								continue;
						}
					}
					temp_count++;   // �ִܰ�� ã�� �� �������� ���� +1
				}
				else
					continue;
			}
		}
		if (safe <= temp_count)   // Ư�� ������������ ���������� ������ ���� Ŭ �� ���������� ���� �ٲٱ�
			safe = temp_count;

	}

	cout << safe << endl;
	return 0;

}

bool cango(int x, int y, int n, int(*load)[101])
{
	if ((x < 0) || (y < 0) || (x > n-1) || (y > n-1) || (load[x][y] == 0))   // �̷� ���� ��, �� �� �ִ� ���ΰ�
		return false;
	else
		return true;
}