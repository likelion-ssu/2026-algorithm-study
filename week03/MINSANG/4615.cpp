#include <iostream>
#include <vector>

using namespace std;

int dr[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dc[8] = {0, 0, -1, 1, -1, 1, -1, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; ++tc) {
        int N, M;
        cin >> N >> M;

        vector<vector<int>> board(N, vector<int>(N, 0));

        int mid = N / 2;
        board[mid - 1][mid - 1] = 2;
        board[mid][mid] = 2;
        board[mid - 1][mid] = 1;
        board[mid][mid - 1] = 1;

        for (int i = 0; i < M; ++i) {
            int x, y, color;
            cin >> x >> y >> color;

            int r = y - 1;
            int c = x - 1;
            board[r][c] = color;

            for (int d = 0; d < 8; ++d) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                vector<pair<int, int>> flip_candidates;

                while (nr >= 0 && nr < N && nc >= 0 && nc < N) {
                    if (board[nr][nc] == 0) {
                        break;
                    } 
                    else if (board[nr][nc] != color) {
                        flip_candidates.push_back({nr, nc});
                    } 
                    else if (board[nr][nc] == color) {
                        for (auto pos : flip_candidates) {
                            board[pos.first][pos.second] = color;
                        }
                        break;
                    }

                    nr += dr[d];
                    nc += dc[d];
                }
            }
        }

        int black_cnt = 0;
        int white_cnt = 0;

        for (int row = 0; row < N; ++row) {
            for (int col = 0; col < N; ++col) {
                if (board[row][col] == 1) {
                    black_cnt++;
                } else if (board[row][col] == 2) {
                    white_cnt++;
                }
            }
        }

        cout << "#" << tc << " " << black_cnt << " " << white_cnt << "\n";
    }

    return 0;
}