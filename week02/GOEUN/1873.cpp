#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){

        int H, W; // 게임 맵의 높이 H, 너비가 W.  H, W (2 ≤ H, W ≤ 20)
        cin >> H >> W;
        char MAP[21][21]; // 게임 맵
        char state; // 전차 방향 저장(U, D, L, R) -> S를 위해 필요
        int x, y; // 전차 위치를 저장할 좌표

        for(int h = 0; h < H; h++){
            for(int w = 0; w < W; w++){
                cin >> MAP[h][w];
                if(MAP[h][w] == '^' || MAP[h][w] == 'v' || MAP[h][w] == '<' || MAP[h][w] == '>'){ // 전차 위치 찾기
                    x = h;
                    y = w;
                    if(MAP[h][w] == '^'){ // 전차 방향 
                        state = 'U';
                    }
                    else if(MAP[h][w] == 'v'){
                        state = 'D';
                    }
                    else if(MAP[h][w] == '<'){
                        state = 'L';
                    }
                    else if(MAP[h][w] == '>'){
                        state = 'R';
                    }
                }
            }
        }

        int N;
        cin >> N;
        char input[101]; // 사용자가 넣을 입력(SURSSSS...)
        cin >> input;

        for(int i = 0; i < N; i++){ 
            if(input[i] == 'U'){
                state = 'U';
                if((x - 1) >= 0 && MAP[x - 1][y] == '.'){ // 게임 맵 밖이 아니고, 한 칸 위의 칸이 평지라면 그 칸으로 이동
                    MAP[x][y] = '.'; // 전차 이동
                    MAP[x - 1][y] = '^'; // 전차 이동
                    x--;
                }
                else{ // 전차만 제자리에서 방향 이동
                    MAP[x][y] = '^';
                }
            }
            else if(input[i] == 'D'){
                state = 'D';
                if((x + 1) < H && MAP[x + 1][y] == '.'){ 
                    MAP[x][y] = '.';
                    MAP[x + 1][y] = 'v';
                    x++;
                }
                else{ 
                    MAP[x][y] = 'v';
                }
            }
            else if(input[i] == 'L'){
                state = 'L';
                if((y - 1) >= 0 && MAP[x][y - 1] == '.'){ 
                    MAP[x][y] = '.';
                    MAP[x][y - 1] = '<';
                    y--;
                }
                else{
                    MAP[x][y] = '<';
                }
            }
            else if(input[i] == 'R'){
                state = 'R';
                if((y + 1) < W && MAP[x][y + 1] == '.'){ 
                    MAP[x][y] = '.';
                    MAP[x][y + 1] = '>';
                    y++;
                }
                else{ 
                    MAP[x][y] = '>';
                }
            }
            else if(input[i] == 'S'){
                // 포탄은 벽돌로 만들어진 벽 또는 강철로 만들어진 벽에 충돌하거나 게임 맵 밖으로 나갈 때까지 직진한다.
                if(state == 'U'){
                    for(int g = x - 1; g >= 0; g--){ // 포탄이 이동하는 경로
                        if(MAP[g][y] == '*'){ // 벽돌로 만들어진 벽
                            MAP[g][y] = '.'; // 부딪힌 벽이 벽돌로 만들어진 벽이라면 이 벽은 파괴되어 칸은 평지가 되고, 포탄이 소멸함
                            break;
                        }
                        else if(MAP[g][y] == '#'){ // 강철로 만들어진 벽
                            break;
                            // 강철로 만들어진 벽에 포탄이 부딪히면 아무 일도 일어나지 않고, 포탄이 소멸함
                        }
                    }
                }
                else if(state == 'D'){
                    for(int g = x + 1; g < H; g++){ 
                        if(MAP[g][y] == '*'){ 
                            MAP[g][y] = '.'; 
                            break;
                        }
                        else if(MAP[g][y] == '#'){ 
                            break;
                        }
                    }
                }
                else if(state == 'L'){
                    for(int g = y - 1; g >= 0; g--){ 
                        if(MAP[x][g] == '*'){ 
                            MAP[x][g] = '.'; 
                            break;
                        }
                        else if(MAP[x][g] == '#'){ 
                            break;
                        }
                    }
                }
                else if(state == 'R'){
                    for(int g = y + 1; g < W; g++){ 
                        if(MAP[x][g] == '*'){ 
                            MAP[x][g] = '.'; 
                            break;
                        }
                        else if(MAP[x][g] == '#'){ 
                            break;
                        }
                    }
                }
            }
        }

        cout << '#' << t << ' ';
        for(int h = 0; h < H; h++){
            for(int w = 0; w < W; w++){
                cout << MAP[h][w];
            }
            cout << '\n';
        }
    }    

    return 0;
}