import java.util.Scanner;
import java.io.FileInputStream;
import java.util.ArrayList;

class Solution {

    static int[] drow = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int[] dcol = {-1, 0, 1, -1, 1, -1, 0, 1};

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        for (int test_case = 1; test_case <= T; test_case++) {

            int N = sc.nextInt();
            int M = sc.nextInt();

            int[][] board = new int[N][N];

            int mid = N / 2;
            board[mid - 1][mid - 1] = 2;
            board[mid][mid] = 2;
            board[mid - 1][mid] = 1;
            board[mid][mid - 1] = 1;

            for (int i = 0; i < M; i++) {

                int x = sc.nextInt() - 1;
                int y = sc.nextInt() - 1;
                int color = sc.nextInt();

                board[y][x] = color;

                int enemy;
                if (color == 1) {
                    enemy = 2;
                } else {
                    enemy = 1;
                }

                for (int d = 0; d < 8; d++) {

                    int ny = y + dcol[d];
                    int nx = x + drow[d];

                    ArrayList<int[]> temp = new ArrayList<>();

                    while (0 <= ny && ny < N && 0 <= nx && nx < N) {

                        if (board[ny][nx] == 0) {
                            break;
                        }

                        if (board[ny][nx] == enemy) {
                            temp.add(new int[]{ny, nx});
                        }
                        else if (board[ny][nx] == color) {
                            for (int[] p : temp) {
                                board[p[0]][p[1]] = color;
                            }
                            break;
                        }
                        else {
                            break;
                        }

                        ny += dcol[d];
                        nx += drow[d];
                    }
                }
            }

            int black = 0;
            int white = 0;

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (board[i][j] == 1) {
                        black++;
                    }
                    else if (board[i][j] == 2) {
                        white++;
                    }
                }
            }

            System.out.println("#" + test_case + " " + black + " " + white);
        }

        sc.close();
    }
}