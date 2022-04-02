// 2xn ≈∏¿œ∏µ2 (solved)
#include <iostream>
using namespace std;

int main(void)
{
	long long square[1001];
	int n;

	cin >> n;

	square[1] = 1;
	square[2] = 3;

	for (int i = 3; i < n + 1; i++)
		square[i] = (square[i - 1] + square[i - 2] * 2) % 10007;

	cout << square[n] << endl;

	return 0;
}