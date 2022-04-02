// 연속합 (unsolved)
#include <iostream>
using namespace std;

int sum[1000001];
int largest[1000001];

int main(void)
{
	int n;
	int MAX = -2001;
	int MAXIndex;
	int leftIndex = 1, rightIndex = 1;
	int MAXSUM = -2001;

	cin >> n;

	for (int i = 1; i < n + 1; i++)
	{
		cin >> sum[i];
		//cout << "i : " << i << " " << sum[i] << endl;
		if (MAX <= sum[i])
		{
			MAX = sum[i];
			MAXIndex = i;
		}
	}
	//cout << "max : " << MAX << " max index : " << MAXIndex << endl;

	largest[1] = MAX;   // 가장 큰 수부터 시작

	for (int i = 2; i < n + 1; i++)
	{
		if (largest[i - 1] + sum[MAXIndex - leftIndex] > largest[i] + sum[MAXIndex + rightIndex])   // 왼쪽으로 길이 늘리는 것이 더 클 때
		{
			largest[i] = largest[i - 1] + sum[MAXIndex - leftIndex];   // 왼쪽으로 늘리며 합치기
			if (MAXSUM < largest[i])
				MAXSUM = largest[i];
			//cout << "leftindex : " << leftIndex << endl;
			//cout << "왼쪽이 더 클 때 : " << largest[i] << endl;
			leftIndex++;
		}
		else if(largest[i - 1] + sum[MAXIndex - leftIndex] < largest[i] + sum[MAXIndex + rightIndex])   // 오른쪽으로 길이 늘리는 것이 더 클 때
		{
			largest[i] = largest[i - 1] + sum[MAXIndex + rightIndex];   // 왼쪽으로 늘리며 합치기
			if (MAXSUM < largest[i])
				MAXSUM = largest[i];
			//cout << "rightindex : " << rightIndex << endl;
			//cout << "오른쪽이 더 클 떄 : " << largest[i] << endl;
			rightIndex++;
		}
		else
		{
			cout << "같을 떄" << endl;
			largest[i] = largest[i - 1] + sum[MAXIndex - leftIndex];
			if (MAXSUM < largest[i])
				MAXSUM = largest[i];
			leftIndex++;
			rightIndex++;
		}
	}

	cout << MAXSUM << endl;

	return 0;

}