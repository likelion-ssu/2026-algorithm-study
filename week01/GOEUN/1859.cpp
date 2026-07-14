#include <iostream>
#include <deque>

using namespace std;

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        deque<int> dq;
        long long total_price = 0;
        int max_price = 0;
        int N;
        cin >> N;
        for(int n = 0; n < N; n++){
            int P;
            cin >> P;
            dq.push_front(P);
        }
        while(!dq.empty()){
            int price = dq.front();
            if(price >= max_price){
                max_price = price;
            }
            else{
                total_price += (max_price - price);
            }
            dq.pop_front();
        }
        printf("#%d %lld\n", t, total_price);
    }
}