//설탕배달
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
	for (int i = max; i >= 0; i--)   // 5키로 최댓값부터 검사
	{
		temp = sugar;   // sugar값 바뀌지않게
		bag = i;   // 봉지
		temp -= i * 5;   // 5키로로 나눌 수 있을만큼 담은 후 남은 양
		if (temp % 3 == 0)   // 5, 3으로 나누어질 수 있을 때
		{
			bag += (temp / 3);   // 남은 양을 3키로로 나누어 담음
			cout << bag << endl;
			return 0;
		}
	}

	cout << -1 << endl;   // 3과 5로 나누어질 수 없을 때
	return 0;
}