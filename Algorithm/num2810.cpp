//��Ȧ��
#include <iostream>
using namespace std;

int main(void)
{
	int seat;   // ��� ��
	char cup[50];
	int p = 1;   // �¼��� ���� ���ʿ��� ������ ���� ���� �� ����

	cin >> seat >> cup;

	for (int i = 0; i < seat && p < seat; i++)   // ������ �ִ� ������� �Էµ� ��� ���� ���� �� ����
	{
		p++;
		if (cup[i] == 'L')   // Ŀ�� �¼��� ��� �� �ڸ��� �ǳʶٰ� �˻�
			i++;
	}

	cout << p << endl;

	return 0;
}
