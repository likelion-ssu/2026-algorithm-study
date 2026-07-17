#include <iostream>
#include <string>

using namespace std;

int main()
{
  int T;
  cin >> T;

  for (int tc = 1; tc <= T; tc++)
  {
    int H, W;
    cin >> H >> W;

    char map[20][20];

    // 전차의 현재 위치
    int r = 0;
    int c = 0;

    // 맵 입력
    for (int i = 0; i < H; i++)
    {
      for (int j = 0; j < W; j++)
      {
        cin >> map[i][j];

        // 전차 위치 찾기
        if (map[i][j] == '^' ||
            map[i][j] == 'v' ||
            map[i][j] == '<' ||
            map[i][j] == '>')
        {

          r = i;
          c = j;
        }
      }
    }

    int N;
    string cmd;

    cin >> N;
    cin >> cmd;

    for (int i = 0; i < N; i++)
    {

      // 위로 이동
      if (cmd[i] == 'U')
      {
        map[r][c] = '^';

        // 위로 이동할 때는 행이 -1, 열은 그대로
        int nr = r - 1;
        int nc = c;

        // 위쪽이 맵 안이고 평지이면 이동
        if (nr >= 0 && map[nr][nc] == '.')
        {
          map[r][c] = '.';

          r = nr;
          c = nc;

          map[r][c] = '^';
        }
      }

      // 아래로 이동
      else if (cmd[i] == 'D')
      {
        map[r][c] = 'v';

        int nr = r + 1;
        int nc = c;

        // 아래쪽이 맵 안이고 평지이면 이동(0~H-1까지)
        if (nr < H && map[nr][nc] == '.')
        {
          map[r][c] = '.';

          r = nr;
          c = nc;

          map[r][c] = 'v';
        }
      }

      // 왼쪽으로 이동
      else if (cmd[i] == 'L')
      {
        map[r][c] = '<';

        int nr = r;
        int nc = c - 1;

        // 왼쪽이 맵 안이고 평지이면 이동
        if (nc >= 0 && map[nr][nc] == '.')
        {
          map[r][c] = '.';

          r = nr;
          c = nc;

          map[r][c] = '<';
        }
      }

      // 오른쪽으로 이동
      else if (cmd[i] == 'R')
      {
        map[r][c] = '>';

        int nr = r;
        int nc = c + 1;

        // 오른쪽이 맵 안이고 평지이면 이동
        if (nc < W && map[nr][nc] == '.')
        {
          map[r][c] = '.';

          r = nr;
          c = nc;

          map[r][c] = '>';
        }
      }

      // 포탄 발사
      else if (cmd[i] == 'S')
      {

        // 기존 전차 위치는 변하지 않으므로 복사본을 통해 포탄위치 저장
        int br = r;
        int bc = c;

        while (true)
        {

          // 전차가 보는 방향으로 포탄 이동
          if (map[r][c] == '^')
          {
            br--;
          }
          else if (map[r][c] == 'v')
          {
            br++;
          }
          else if (map[r][c] == '<')
          {
            bc--;
          }
          else if (map[r][c] == '>')
          {
            bc++;
          }

          // 맵 밖으로 나가면 종료
          if (br < 0 || br >= H ||
              bc < 0 || bc >= W)
          {
            break;
          }

          // 벽돌 벽이면 부수고 종료
          if (map[br][bc] == '*')
          {
            map[br][bc] = '.';
            break;
          }

          // 강철 벽이면 그냥 종료
          if (map[br][bc] == '#')
          {
            break;
          }
        }
      }
    }

    cout << "#" << tc << " ";

    for (int i = 0; i < H; i++)
    {
      for (int j = 0; j < W; j++)
      {
        cout << map[i][j];
      }
      cout << '\n';
    }
  }

  return 0;
}