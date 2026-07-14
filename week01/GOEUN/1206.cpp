// C++ 풀이

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    for (int i = 1; i <= 10; i++){
        vector<int> V;
        int answer = 0;
        int N; // 건물의 개수 N (4 ≤ N ≤ 1000)
        cin >> N;
        for(int n = 0; n < N; n++){
            int height; // 건물의 높이, (0 ≤ 각 건물의 높이 ≤ 255)
            cin >> height;
            V.push_back(height);
        }
        for(int j = 0; j < V.size(); j++){
            if(V[j] == 0){ // 건물의 높이가 0일 경우 확인할 필요 없음(맨 왼쪽 두 칸과 맨 오른쪽 두 칸도 포함)
                continue;
            }
            // 좌우 2칸씩중에 가장 큰 건물의 높이 찾기
            int max_height = max({V[j-2], V[j-1], V[j+1], V[j+2]});
            if(V[j] - max_height > 0){
                answer += V[j] - max_height;
            }
        }
        printf("#%d %d\n", i, answer);
    }
}

