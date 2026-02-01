#include <bits/stdc++.h>
using namespace std;

int ternarySearch(vector<int>& a) {
    int l = 0, r = a.size() - 1;

    while (r - l > 2) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        if (a[m1] < a[m2])
            l = m1;
        else
            r = m2;
    }

    // Linear search for remaining elements
    int idx = l;
    for (int i = l; i <= r; i++) {
        if (a[i] > a[idx])
            idx = i;
    }
    return idx;
}

int main() {
    vector<int> a = {1, 3, 7, 12, 9, 5, 2};
    int idx = ternarySearch(a);
    cout << "Maximum element = " << a[idx]
         << " at index " << idx << endl;
}
