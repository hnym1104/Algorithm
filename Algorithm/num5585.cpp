//�Ž�����
#include <iostream>
using namespace std;

int main(void)
{
	int m, a = 0;
	int c[6] = { 500, 100, 50, 10, 5, 1 };
	int order = 0;

	cin >> m;   // ���� ���� �Է�
	m = 1000 - m;   // �Ž�����

	while (m > 0)
	{
		a += (m / c[order]);   // ���� ������ �׼��� ū �������� ����
		m %= c[order];   // ������ ��
		order++;
	}

	cout << a << endl;

	return 0;
}