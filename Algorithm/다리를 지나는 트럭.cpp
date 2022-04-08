#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    queue<int> wait_truck;   // 대기중 트럭
    queue<int> truck_on_bridge;   // 다리를 지나는 트럭
    int total_weights = 0;   // 현재 다리위의 무게

    for (int i = 0; i < truck_weights.size(); i++) {
        wait_truck.push(truck_weights[i]);
    }

    while (!wait_truck.empty()) {
        cout << "========" << endl;
        answer++;
        cout << "truck on bridge size : " << truck_on_bridge.size() << endl;
        int cur_truck = wait_truck.front();   // 첫번째로 대기중인 truck
        cout << "cur_truck : " << cur_truck << endl;
        // 앞에 들어갈 자리가 있는지, 무게는 넘지 않는지 확인해야함
        // 1. 앞에 들어갈 자리가 있는지
        if (truck_on_bridge.size() >= bridge_length) {   // 들어갈 자리가 없을 때 -> queue의 마지막이 0이 아닐때 (4, 0)
            cout << "들어갈 자리 없음" << endl;
            truck_on_bridge.push(0);   // 0이라는 것은 해당 차례에 들어간 트럭이 없다는것            
        }
        else {   // 들어갈 자리가 있을 때
            if (total_weights + cur_truck <= weight) {   // 새로운 트럭이 들어가도 총 무게가 넘지 않을 때
                cout << "OK!" << endl;
                truck_on_bridge.push(cur_truck);   // 다리로 트럭을 올림
                wait_truck.pop();   // 대기열에서 빠짐
                total_weights += cur_truck;   // 다리위 현재 무게
                cout << "current total weights after push : " << total_weights << endl;
            }
            else {   // 총 무게가 넘을 때
                cout << "총 무게가 넘음" << endl;
                truck_on_bridge.push(0);   // 0이라는 것은 해당 차례에 들어간 트럭이 없다는것
            
            }          
        }
        // queue에 있는지 bridge length 넘었을 때 다리에서 빠져야함 - 조건 설정 어떻게????
        if (truck_on_bridge.size() == bridge_length && truck_on_bridge.front() != 0) {   // 7,0, 4
            total_weights -= truck_on_bridge.front();    // 다리위 무게 빠짐
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