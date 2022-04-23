#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
	int answer = 0;

	sort(citations.begin(), citations.end(), greater<>());   // 내림차순 정렬

	cout << "citations" << endl;
	for (int i = 0; i < citations.size(); i++) {
		cout << citations[i] << " ";
	}
	cout << endl;
	
	int i = 0;

	while (i < citations.size()) {
		if (i >= citations[i]) {   // i는 index, citations[i]는 index의 값
			if (i == citations[i - 1]) {
				return citations[i - 1];
			}
			else {
				return i;
			}
		}
		i++;
	}
}

int main(void) {

	vector<int> citations = { 3 ,0, 6, 1, 5 };
	int answer = 0;

	answer = solution(citations);

	cout << "answer1 : " << answer << endl;

	citations = { 8, 4, 1 };

	answer = solution(citations);

	cout << "answer2 : " << answer << endl;

	citations = { 4 ,0, 6, 1, 5 };

	answer = solution(citations);

	cout << "answer3 : " << answer << endl;

	citations = { 16 ,8, 6, 1, 5 };

	answer = solution(citations);

	cout << "answer4 : " << answer << endl;

	return 0;
}