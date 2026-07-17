import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        for (int test_case = 1; test_case <= T; test_case++) {

            int H = sc.nextInt();
            int W = sc.nextInt();

            char[][] game = new char[H][W];

            int r = 0, c = 0;

            for (int i = 0; i < H; i++) {
                String row = sc.next();
                for (int j = 0; j < W; j++) {
                    game[i][j] = row.charAt(j);
                    if (game[i][j] == '^' ||
                        game[i][j] == 'v' ||
                        game[i][j] == '<' ||
                        game[i][j] == '>') {
                        r = i;
                        c = j;
                    }
                }
            }

            int N = sc.nextInt();
            String orders = sc.next();

            for (int i = 0; i < N; i++) {
                char order = orders.charAt(i);
                if (order == 'U') {
                    game[r][c] = '^';
                    if (r > 0 && game[r - 1][c] == '.') {
                        game[r][c] = '.';
                        r--;
                        game[r][c] = '^';
                    }
                } else if (order == 'D') {
                    game[r][c] = 'v';
                    if (r < H - 1 && game[r + 1][c] == '.') {
                        game[r][c] = '.';
                        r++;
                        game[r][c] = 'v';
                    }
                } else if (order == 'L') {
                    game[r][c] = '<';
                    if (c > 0 && game[r][c - 1] == '.') {
                        game[r][c] = '.';
                        c--;
                        game[r][c] = '<';
                    }
                } else if (order == 'R') {
                    game[r][c] = '>';
                    if (c < W - 1 && game[r][c + 1] == '.') {
                        game[r][c] = '.';
                        c++;
                        game[r][c] = '>';
                    }

                } else if (order == 'S') {

                    if (game[r][c] == '^') {
                        int nr = r - 1;
                        while (nr >= 0) {
                            if (game[nr][c] == '#')
                                break;
                            if (game[nr][c] == '*') {
                                game[nr][c] = '.';
                                break;
                            }
                            nr--;
                        }
                    }
                    else if (game[r][c] == 'v') {
                        int nr = r + 1;
                        while (nr < H) {
                            if (game[nr][c] == '#')
                                break;
                            if (game[nr][c] == '*') {
                                game[nr][c] = '.';
                                break;
                            }
                            nr++;
                        }
                    }
                    
                    else if (game[r][c] == '<') {
                        int nc = c - 1;
                        while (nc >= 0) {
                            if (game[r][nc] == '#')
                                break;
                            if (game[r][nc] == '*') {
                                game[r][nc] = '.';
                                break;
                            }
                            nc--;
                        }
                    }
                    else if (game[r][c] == '>') {
                        int nc = c + 1;
                        while (nc < W) {
                            if (game[r][nc] == '#')
                                break;
                            if (game[r][nc] == '*') {
                                game[r][nc] = '.';
                                break;
                            }
                            nc++;
                        }
                    }
                }
            }

            System.out.println("#" + test_case);

            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    System.out.print(game[i][j]);
                }
                System.out.println();
            }
        }
    }
}