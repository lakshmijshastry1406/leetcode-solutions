#include <bits/stdc++.h>
using namespace std;

int bad = 4;

bool isBadVersion(int version) {
    return version >= bad;
}

int firstBadVersion(int n) {
    int low = 1, high = n;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (isBadVersion(mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    int n;
    cin >> n;
    cout << firstBadVersion(n);
    return 0;
}