#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    queue<int> wait_truck;   // ����� Ʈ��
    queue<int> truck_on_bridge;   // �ٸ��� ������ Ʈ��
    int total_weights = 0;   // ���� �ٸ����� ����

    for (int i = 0; i < truck_weights.size(); i++) {
        wait_truck.push(truck_weights[i]);
    }

    while (!wait_truck.empty()) {
        cout << "========" << endl;
        answer++;
        cout << "truck on bridge size : " << truck_on_bridge.size() << endl;
        int cur_truck = wait_truck.front();   // ù��°�� ������� truck
        cout << "cur_truck : " << cur_truck << endl;
        // �տ� �� �ڸ��� �ִ���, ���Դ� ���� �ʴ��� Ȯ���ؾ���
        // 1. �տ� �� �ڸ��� �ִ���
        if (truck_on_bridge.size() >= bridge_length) {   // �� �ڸ��� ���� �� -> queue�� �������� 0�� �ƴҶ� (4, 0)
            cout << "�� �ڸ� ����" << endl;
            truck_on_bridge.push(0);   // 0�̶�� ���� �ش� ���ʿ� �� Ʈ���� ���ٴ°�            
        }
        else {   // �� �ڸ��� ���� ��
            if (total_weights + cur_truck <= weight) {   // ���ο� Ʈ���� ���� �� ���԰� ���� ���� ��
                cout << "OK!" << endl;
                truck_on_bridge.push(cur_truck);   // �ٸ��� Ʈ���� �ø�
                wait_truck.pop();   // ��⿭���� ����
                total_weights += cur_truck;   // �ٸ��� ���� ����
                cout << "current total weights after push : " << total_weights << endl;
            }
            else {   // �� ���԰� ���� ��
                cout << "�� ���԰� ����" << endl;
                truck_on_bridge.push(0);   // 0�̶�� ���� �ش� ���ʿ� �� Ʈ���� ���ٴ°�
            
            }          
        }
        // queue�� �ִ��� bridge length �Ѿ��� �� �ٸ����� �������� - ���� ���� ���????
        if (truck_on_bridge.size() == bridge_length && truck_on_bridge.front() != 0) {   // 7,0, 4
            total_weights -= truck_on_bridge.front();    // �ٸ��� ���� ����
            cout << "current total weights after pop truck : " << total_weights << endl;
            truck_on_bridge.pop();
        }
    }

    return answer;
}

int main(void) {

    int bridge_weight = 2;
    int weight = 10;
    vector<int> truck_weights = { 7, 4, 5, 6 };

    int answer = solution(bridge_weight, weight, truck_weights);

    cout << "answer : " << answer << endl;

    return 0;
}