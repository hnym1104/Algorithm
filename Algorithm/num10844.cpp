// 쉬운 계단수 (solved)
#include <iostream>
using namespace std;

int main(void)
{
	int stairs[101];
	int n;
	int result;

	stairs[1] = 9;
	stairs[2] = 17;

	cin >> n;

	if (n < 3)
		result = stairs[n];
	else
	{
		for (int i = 3; i < n + 1; i++)
			stairs[i] = ((stairs[i - 1] - 1) * 2) + 1;
	}

	cout << stairs[n] % (1000000000) << endl;

	return 0;
}