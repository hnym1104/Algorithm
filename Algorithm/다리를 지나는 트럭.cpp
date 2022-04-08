#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    queue<int> truckOnBridge;   // ���� �ٸ����� �ִ� Ʈ��
    queue<int> waitTruck;

    int totalWeights = 0;   // �ٸ� �� Ʈ���� ��ü ����
    int curTruck = 0;   // ���� ���� Ʈ���� ����

    for (int i = 0; i < truck_weights.size(); i++) {
        waitTruck.push(truck_weights[i]);
    }

    while (!waitTruck.empty()) {   // �ٸ� �� Ʈ���� ��� ���� �� ����
        cout << "=====================" << endl;
        curTruck = waitTruck.front();
        cout << "���� Ʈ�� : " << curTruck << endl;
        if ((truckOnBridge.size() != bridge_length) || (truckOnBridge.back() == 0)) {   // �� �ڸ� ���� ��
            if (totalWeights + curTruck > weight) {   // ���԰� �ʰ��� ��
                cout << "���� �ʰ�" << endl;
                truckOnBridge.push(0);   // 0�̶�� ���� �ƹ��͵� �ö��� �ʾҴٴ� ��, �� �����!

            }
            else {   // ���⼭�� ���ο� Ʈ�� �� �� ����
                cout << "* ���ο� Ʈ�� ���� *" << endl;
                waitTruck.pop();
                truckOnBridge.push(curTruck);   // �ٸ� ���� ���ο� Ʈ��
                totalWeights += curTruck;   // �ٸ� �� ���� ����
            }
        }
        // ������ ��������
        if (truckOnBridge.size() >= bridge_length) {   // ���� ť�� �� ä�������ʾ��� ��츦 �����ϰ�
            totalWeights -= truckOnBridge.front();   // �ٸ� ���� ���� ����
            truckOnBridge.pop();   // Ʈ�� ��������    
        }
        answer++;
    }
        
    return bridge_length + answer;
}

int main(void) {

    int bridge_weight = 2;
    int weight = 10;
    vector<int> truck_weights = { 7, 4, 5, 6 };

    int answer = solution(bridge_weight, weight, truck_weights);

    cout << "answer1 : " << answer << endl;

    bridge_weight = 100;
    weight = 100;
    truck_weights = { 10 };

    answer = solution(bridge_weight, weight, truck_weights);

    cout << "answer2 : " << answer << endl;

    bridge_weight = 100;
    weight = 100;
    truck_weights = { 10,10,10,10,10,10,10,10,10,10 };

    answer = solution(bridge_weight, weight, truck_weights);

    cout << "answer3 : " << answer << endl;

    return 0;
}