#include <iostream>
#include <deque>

using namespace std;

struct Node {
    int row, col, dist;
};

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        int N;
        cin >> N;
        char MAP[101][101]; 

        int row;
        int col;
        int dist;

        for(int r = 0; r < N; r++){
            for(int c = 0; c < N; c++){
                cin >> MAP[r][c];
                if(MAP[r][c] == '2'){
                    row = r;
                    col = c;
                }
            }
        }

        int drow[4] = {-1, 1, 0, 0};
        int dcol[4] = {0, 0, -1, 1};

        int answer = 0;
        bool found = false;


        deque<Node> queue;
        queue.push_back({row, col, 0});
        bool visited[101][101] = {};
        visited[row][col] = true;

        while(!queue.empty()){ 
            Node cur = queue.front();
            queue.pop_front();
            row = cur.row;
            col = cur.col;
            dist = cur.dist;

            for(int i = 0; i < 4; i++){
                int new_row = row + drow[i];
                int new_col = col + dcol[i];
                if((new_row >= 0 && new_row < N && new_col >= 0 && new_col < N) // 미로 범위 내에 있는지
                    && (MAP[new_row][new_col] != '1') // 벽이 아닌지
                    && (visited[new_row][new_col] == false)){ // 방문하지 않은 곳인지
                    if(MAP[new_row][new_col] == '3'){ // 해당 칸이 도착점
                        answer = dist;
                        found = true;
                        break;
                    }
                    else{ // 해당 칸이 도착점이 아님(0일 경우) -> 이동
                        visited[new_row][new_col] = true;
                        queue.push_back({new_row, new_col, dist + 1});
                    }
                }
                
            }

            if(found == true){
                break;
            }

        }

        printf("#%d %d\n", t, answer);

    }

    return 0;
}