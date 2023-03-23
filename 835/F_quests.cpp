#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

int bin_search(vector<int> *sums, int n, int c, int d) {
  int min_found = -1;
  int a = 0, b = d;
  while (a <= b) {
    int k = (a + b) / 2;

    if ((*sums)[min(k, n - 1)] * (d / max(k, 1)) +
            (*sums)[min(n - 1, (d % max(1, k) - 1))] >=
        c) {
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
    int n, c, d;
    cin >> n >> c >> d;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    sort(arr.rbegin(), arr.rend());

    vector<int> sums(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += arr[i];
      sums[i] = sum;
    }

    if (sums[n - 1] * d < c) {
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
