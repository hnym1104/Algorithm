#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
	return  a + b > b + a;
}

bool dcompare(string a, string b) {
	return  a + b < b + a;
}

int main(void)
{
	vector<int> numbers = { 3, 30, 34, 5, 9 };
	string answer = "";
	vector<string> temp;

	for (int i = 0; i < numbers.size(); i++) {
		temp.push_back(to_string(numbers[i]));
	}

	sort(temp.begin(), temp.end(), compare);

	for (int i = 0; i < temp.size(); i++)
		answer += temp[i];

	if (temp[0] == "0")
		answer = "0";

	cout << "answer = " << answer << endl;

	return 0;
}