// 1로 만들기 (solved)
#include <iostream>
using namespace std;

int oper[1000001] = { 0, };

int main(void)
{
	int n;

	cin >> n;

	oper[1] = 0;

	for (int i = 2; i < n + 1; i++)
	{
		oper[i] = oper[i - 1] + 1;
		if (i % 2 == 0)
			oper[i] = min(oper[i], oper[i / 2] + 1);
		if (i % 3 == 0)
			oper[i] = min(oper[i], oper[i / 3] + 1);
	}

	cout << oper[n] << endl;

	return 0;
}