#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  for (int tc = 1; tc <= 10; tc++)
  {
    int N;
    cin >> N;

    int arr[1000];

    // 건물 높이 입력받기
    for (int i = 0; i < N; i++)
    {
      cin >> arr[i];
    }

    int result = 0;

    // 양쪽 2칸씩 비교해야 해서 2부터 N-3까지 확인
    for (int i = 2; i < N - 2; i++)
    {

      // 주변 건물 중 가장 높은 건물 찾기
      int maxheight = max(max(arr[i - 2], arr[i - 1]),
                          max(arr[i + 1], arr[i + 2]));
      int diff = arr[i] - maxheight;
      if (diff > 0)
      {
        result += diff;
      }
    }

    cout << "#" << tc << " " << result << endl;
  }

  return 0;
}