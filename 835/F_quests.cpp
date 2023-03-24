#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

int bin_search(vector<uint64_t> *sums, int n, uint64_t c, int d) {
  int min_found = -1;
  int a = 0, b = d;
  while (a <= b) {
    int k = (a + b) / 2;

    uint64_t full_cycles = (*sums)[min(k, n - 1)] * (d / (k + 1));
    uint64_t remainder =
        (d % (k + 1) - 1) >= 0 ? (*sums)[min(n - 1, (d % (k + 1) - 1))] : 0;
    if (full_cycles + remainder >= c) {
      min_found = k;
      a = k + 1;
    } else {
      b = k - 1;
    }
  }

  return min_found;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int tt;
  cin >> tt;

  while (tt--) {
    // TODO(Vi): c should be uint64_t
    uint64_t n, d;
    uint64_t c;
    cin >> n >> c >> d;

    vector<uint64_t> arr(n);

    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    sort(arr.rbegin(), arr.rend());

    vector<uint64_t> sums(n);
    uint64_t sum = 0;
    for (int i = 0; i < n; i++) {
      sum += arr[i];
      sums[i] = sum;
    }

    if (sums[0] * d < c) {
      cout << "Impossible" << endl;
      continue;
    }

    int min_found = bin_search(&sums, n, c, d);

    if (min_found == d)
      cout << "Infinity" << endl;
    else
      cout << min_found << endl;
  }

  return 0;
}
