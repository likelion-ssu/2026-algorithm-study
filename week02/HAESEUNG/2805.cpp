#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    for(int i = 0; i < t; i++) {
        int farmSize;
        long long res = 0;

        cin >> farmSize;
        int middle = farmSize / 2;

        vector<vector<int>> board(farmSize, vector<int>(farmSize));

        for(int r = 0; r < farmSize; r++) {
            string s;
            cin >> s;

            for(int c = 0; c < farmSize; c++) {
                board[r][c] = (s[c] - '0');
            }
        }

        int row = 0;

        // 중앙까지
        for(int j = 0; j <= middle; j++) {
            for(int col = 0; col < farmSize; col++) {
                if(abs(col - middle) <= j) res += board[row][col];
            }
            row++;
        }

        // 중앙 다음줄부터
        for(int j = middle - 1; j >= 0; j--) {
            for(int col = 0; col < farmSize; col++) {
                if(abs(col - middle) <= j) res += board[row][col];
            }
            row++;
        }

        cout << "#" << i + 1 << " " << res << "\n";
    }

    return 0;
}