//컵홀더
#include <iostream>
using namespace std;

int main(void)
{
	int seat;   // 사람 수
	char cup[50];
	int p = 1;   // 좌석의 가장 왼쪽에는 무조건 컵을 넣을 수 있음

	cin >> seat >> cup;

	for (int i = 0; i < seat && p < seat; i++)   // 가능한 최대 사람수는 입력된 사람 수를 넘을 수 없음
	{
		p++;
		if (cup[i] == 'L')   // 커플 좌석일 경우 한 자리를 건너뛰고 검사
			i++;
	}

	cout << p << endl;

	return 0;
}
