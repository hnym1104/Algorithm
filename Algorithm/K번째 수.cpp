#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	vector<int> array = { 1, 5, 2, 6, 3, 7, 4 };
	vector<vector<int>> commands = { {2, 5, 3},{4, 4, 1},{1, 7, 3} };
	vector<int> answer;
	vector<int> temp;

	int i, j, k;

	for (int m = 0; m < commands.size(); m++) {
		i = commands[m][0]; j = commands[m][1]; k = commands[m][2];
		cout << "i : " << i << ", j : " << j << ", k : " << k << endl;
		temp.clear();
		temp.resize(j - i + 1);
		copy(array.begin() + i - 1, array.begin() + j, temp.begin());
		sort(temp.begin(), temp.end());
		for (int n = 0; n < temp.size(); n++)
			cout << temp[n] << " ";
		cout << endl << k << " : " << temp[k - 1] << endl;
		cout << endl;
	}

	return 0;

}