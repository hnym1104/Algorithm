// ÀÌÄ£¼ö (unsolved)
#include <iostream>
using namespace std;

int main(void)
{
	long long binary[91];
	int n;

	cin >> n;

	binary[1] = 1;
	binary[2] = 1;

	for (int i = 3; i < n + 1; i++)
		binary[i] = binary[i - 2] + binary[i - 1];

	cout << binary[n] << endl;

	return 0;
}