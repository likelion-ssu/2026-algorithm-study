#include <bits/stdc++.h>
using namespace std;

void program(int index) {
    int day_amt;

    cin >> day_amt;

    vector<int> arr(day_amt);
    long long res = 0;

    for(int i = 0; i < day_amt; i++) {
        cin >> arr[i];
    }

    int max_price = arr[day_amt - 1];

    for(int i = day_amt - 2; i >= 0; i--) {
        if(arr[i] < max_price) {
            res += max_price - arr[i];
        } else {
            max_price = arr[i];
        }
    }

    cout << "#" << index << " " << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(int i = 1; i <= t; i++) {
        program(i);
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void program(int index) {
    int day_amt;

    cin >> day_amt;

    vector<int> arr(day_amt);
    long long res = 0;

    for(int i = 0; i < day_amt; i++) {
        cin >> arr[i];
    }

    int max_price = arr[day_amt - 1];

    for(int i = day_amt - 2; i >= 0; i--) {
        if(arr[i] < max_price) {
            res += max_price - arr[i];
        } else {
            max_price = arr[i];
        }
    }

    cout << "#" << index << " " << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(int i = 1; i <= t; i++) {
        program(i);
    }

    return 0;
}