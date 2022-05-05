#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

int solution(string s) {
	int answer = 0;
	vector<string> strNumber = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	string number = "0123456789";
	int i = 0;
	int j = 0;

	for (i = 0; i < s.length(); i++) {
		if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {   // 그냥 숫자
			continue;
		}
		else {
			for (j = 0; j < strNumber.size(); j++) {
				if (s.find(strNumber[j], i) != string::npos) {   // 현재 index부터 일치하는 문자를 찾으면
					s.replace(s.find(strNumber[j], i), strNumber[j].length(), to_string(number[j] - '0'));   // 문자로 대체
					continue;
				}
			}
		}
	}
	return stoi(s);
}

int main(void) {
	string s = "one4seveneight";
	cout << "answer1 : " << solution(s) << endl << endl;

	s = "23four5six7";
	cout << "answer2 : " << solution(s) << endl << endl;

	s = "2three45sixseven";
	cout << "answer3 : " << solution(s) << endl << endl;

	s = "123";
	cout << "answer4 : " << solution(s) << endl << endl;

	return 0;

}