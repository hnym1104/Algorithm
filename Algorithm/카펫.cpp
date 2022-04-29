#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	int wide = 1;
	int length = 1;
	int total = 0;

	/*
	��ü = wide * length
	brown = (wide - 1 + length - 1) * 2 + 4
	yellow = ��ü - brown
	*/

	total = brown + yellow;   // ��ü Ÿ��

	for (wide = 1; wide < total; wide++) {
		if (total % wide != 0) {
			continue;
		}
		length = total / wide;   // ����, ���� Ȯ��
		if (brown == ((wide + length - 4) * 2) + 4 ) {
			answer.push_back(length);
			answer.push_back(wide);
			return answer;
		}
	}
}

int main(void) {
	vector<int> answer;

	int brown = 10;
	int yellow = 2;

	answer = solution(brown, yellow);
	cout << "answer1 : " << answer[0] << ",  " << answer[1] << endl;

	brown = 8; yellow = 1;
	answer = solution(brown, yellow);
	cout << "answer2 : " << answer[0] << ",  " << answer[1] << endl;

	brown = 24; yellow = 24;
	answer = solution(brown, yellow);
	cout << "answer3 : " << answer[0] << ",  " << answer[1] << endl;
}