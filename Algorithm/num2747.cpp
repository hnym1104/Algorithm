//피보나치 수 (solved)
#include <iostream>
using namespace std;

int fibo(int n)
{
	int fi[46];
	fi[0] = 0;
	fi[1] = 1;

	if (n < 2)
		return fi[n];
	else
	{
		for (int i = 2; i < n+1; i++)
			fi[i] = fi[i - 1] + fi[i - 2];
		return fi[n];
	}

}

int main(void)
{
	int fi[46];
	int n;

	cin >> n;
	cout << fibo(n) << endl;
}