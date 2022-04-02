//거스름돈
#include <iostream>
using namespace std;

int main(void)
{
	int m, a = 0;
	int c[6] = { 500, 100, 50, 10, 5, 1 };
	int order = 0;

	cin >> m;   // 물건 가격 입력
	m = 1000 - m;   // 거스름돈

	while (m > 0)
	{
		a += (m / c[order]);   // 동전 갯수를 액수가 큰 동전부터 더함
		m %= c[order];   // 나머지 돈
		order++;
	}

	cout << a << endl;

	return 0;
}