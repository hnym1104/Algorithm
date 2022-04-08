#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    queue<int> truckOnBridge;   // 현재 다리위에 있는 트럭
    queue<int> waitTruck;

    int totalWeights = 0;   // 다리 위 트럭의 전체 무게
    int curTruck = 0;   // 이제 들어올 트럭의 무게

    for (int i = 0; i < truck_weights.size(); i++) {
        waitTruck.push(truck_weights[i]);
    }

    while (!waitTruck.empty()) {   // 다리 위 트럭이 모두 빠질 때 까지
        cout << "=====================" << endl;
        curTruck = waitTruck.front();
        cout << "현재 트럭 : " << curTruck << endl;
        if ((truckOnBridge.size() != bridge_length) || (truckOnBridge.back() == 0)) {   // 들어갈 자리 있을 때
            if (totalWeights + curTruck > weight) {   // 무게가 초과일 때
                cout << "무게 초과" << endl;
                truckOnBridge.push(0);   // 0이라는 것은 아무것도 올라가지 않았다는 것, 즉 빈공간!

            }
            else {   // 여기서만 새로운 트럭 들어갈 수 있음
                cout << "* 새로운 트럭 진입 *" << endl;
                waitTruck.pop();
                truckOnBridge.push(curTruck);   // 다리 위에 새로운 트럭
                totalWeights += curTruck;   // 다리 위 무게 증가
            }
        }
        // 무조건 빠져야함
        if (truckOnBridge.size() >= bridge_length) {   // 아직 큐가 다 채워지지않았을 경우를 제외하고
            totalWeights -= truckOnBridge.front();   // 다리 지탱 무게 감소
            truckOnBridge.pop();   // 트럭 빠져나옴    
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