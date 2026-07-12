#include <bits/stdc++.h>
using namespace std;

void program(int index) {
    int building_amt;
    cin >> building_amt;

    vector <int> arr(building_amt);
    int res = 0;

    for(int i = 0; i < building_amt; i++) {
        cin >> arr[i];
    }


    for(int i = 2; i < building_amt - 2; i++) {
        int cur_height = arr[i];

        int left_max = max(arr[i - 1], arr[i - 2]);
        int right_max = max(arr[i + 1], arr[i + 2]);

        int tmp = cur_height - max(left_max, right_max);

        if(tmp < 0) {
            tmp = 0;
        }
       
        int a;
        int b;
        bool res;

        if(a < b) {
            res = true;
        }
        else {
            res = false;
        }

        res = a < b ? true : false;


        tmp = tmp > 0 ? tmp : 0;

        res += tmp;
    }
    cout << "#" << index << " " << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 1; i <= 10; i++) {
        program(i);
    }

    return 0;
}