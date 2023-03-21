#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
  int tt;
  cin >> tt;

  while (tt--) {
    int n;
    cin >> n;

    vector<int64_t> arr(n);

    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    int ncount = count_if(begin(arr), end(arr), [](int i) { return i < 0; });

    int64_t sum = accumulate(begin(arr), end(arr), (int64_t)0,
                             [](int64_t f, int64_t s) {
                               return abs(f) + abs(s);
                             });
    int64_t min = abs(*(min_element(
        begin(arr), end(arr), [](int f, int s) { return abs(f) < abs(s); })));

    if (!(ncount & 1)) {
      cout << sum << '\n';
    } else {
      cout << sum - 2 * min << '\n';
    }
  }

  return 0;
}
