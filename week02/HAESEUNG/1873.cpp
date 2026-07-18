#include <bits/stdc++.h>
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define GROUND '.'
#define BRICK '*'
#define WATER '-'
#define METAL '#'
using namespace std;

int h, w;

// {상, 하, 좌, 우}
int drow[4] = {-1, 1, 0, 0};
int dcol[4] = {0, 0, -1, 1};

// 탱크의 위치 정보
int tankRow;
int tankCol;
int dir;

// int isEnd = false;

vector<vector<char>> board(30, vector<char>(30));

void shoot() {
    int bombRow = tankRow + drow[dir];
    int bombCol = tankCol + dcol[dir];

    while(bombRow >= 0 && bombRow < h && bombCol >= 0 && bombCol < w) {
        // 벽돌 벽에 포탄이 부딪힌 경우
        if(board[bombRow][bombCol] == BRICK) {
            board[bombRow][bombCol] = GROUND;
            break;
        }

        // 메탈 벽에 포탄이 부딪힌 경우
        if(board[bombRow][bombCol] == METAL) {
            break;
        }

        // 포탄 이동
        bombRow += drow[dir];
        bombCol += dcol[dir];
    }
}

void move() {
    int tmpRow = tankRow + drow[dir];
    int tmpCol = tankCol + dcol[dir];

    // 맵 밖으로 나감
    if(tmpRow < 0 || tmpRow >= h || tmpCol < 0 || tmpCol >= w) {
        return;
    }

    // 앞이 물임
    if(board[tmpRow][tmpCol] == WATER) {
        return;
    }

    // 벽에 부딪힘
    if(board[tmpRow][tmpCol] == METAL || board[tmpRow][tmpCol] == BRICK) {
        // isEnd = true;
        return;
    }

    tankRow = tmpRow;
    tankCol = tmpCol;
}

void commandInterprete(char c) {
    // if(isEnd) return;

    switch(c) {
        case 'U':
            dir = UP;
            move();
            break;
        case 'D':
            dir = DOWN;
            move();
            break;
        case 'L':
            dir = LEFT;
            move();
            break;
        case 'R':
            dir = RIGHT;
            move();
            break;
        case 'S':
            shoot();
            break;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    for(int tc = 1; tc <= t; tc++) {
        cin >> h >> w;

        // 보드 입력 및 탱크 위치 확인
        for(int i = 0; i < h; i++) {
            string s;
            cin >> s;
            for(int j = 0; j < w; j++) {
                board[i][j] = s[j];

                switch(board[i][j]) {
                    case '^':
                        board[i][j] = GROUND;
                        tankRow = i;
                        tankCol = j;
                        dir = UP;
                        break;
                    case 'v':
                        board[i][j] = GROUND;
                        tankRow = i;
                        tankCol = j;
                        dir = DOWN;
                        break;
                    case '<':
                        board[i][j] = GROUND;
                        tankRow = i;
                        tankCol = j;
                        dir = LEFT;
                        break;
                    case '>':
                        board[i][j] = GROUND;
                        tankRow = i;
                        tankCol = j;
                        dir = RIGHT;
                        break;
                    default:
                        continue;
                }
            }
        }

        // isEnd = false;

        int n;
        cin >> n;

        string cmd;
        cin >> cmd;

        for(int index = 0; index < n; index++) {
            // if(isEnd) break;
            commandInterprete(cmd[index]);
        }

        cout << "#" << tc << " ";

        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(i == tankRow && j == tankCol) {
                    switch(dir) {
                        case UP:
                            cout << "^";
                            break;
                        case DOWN:
                            cout << "v";
                            break;
                        case LEFT:
                            cout << "<";
                            break;
                        case RIGHT:
                            cout << ">";
                            break;
                    }
                } else {
                    cout << board[i][j];
                }
            }
            cout << "\n";
        }
    }

    return 0;
}