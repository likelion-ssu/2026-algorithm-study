#include <iostream>
using namespace std;

int main()
{
  int T;
  cin >> T;

  for (int tc = 1; tc <= T; tc++)
  {

    int N;
    cin >> N;

    int price[1000000];

    // 가격 입력
    for (int i = 0; i < N; i++)
    {
      cin >> price[i];
    }

    long long profit = 0;
    int maxPrice = 0;

    // 뒤에서부터 탐색
    for (int i = N - 1; i >= 0; i--)
    {
      if (price[i] > maxPrice)
      {
        maxPrice = price[i];
      }
      else
      {
        profit += (maxPrice - price[i]);
      }
    }

    cout << "#" << tc << " " << profit << endl;
  }

  return 0;
}