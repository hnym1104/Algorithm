//�������
#include <iostream>
using namespace std;

int main(void)
{
	int sugar, temp;
	int bag = 0;
	int max = 0;

	cin >> sugar;
	if (sugar < 3 || sugar > 5000)
		return -1;

	max = sugar / 5;
	for (int i = max; i >= 0; i--)   // 5Ű�� �ִ񰪺��� �˻�
	{
		temp = sugar;   // sugar�� �ٲ����ʰ�
		bag = i;   // ����
		temp -= i * 5;   // 5Ű�η� ���� �� ������ŭ ���� �� ���� ��
		if (temp % 3 == 0)   // 5, 3���� �������� �� ���� ��
		{
			bag += (temp / 3);   // ���� ���� 3Ű�η� ������ ����
			cout << bag << endl;
			return 0;
		}
	}

	cout << -1 << endl;   // 3�� 5�� �������� �� ���� ��
	return 0;
}