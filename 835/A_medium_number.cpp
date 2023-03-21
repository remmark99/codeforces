#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
  int tt;
  cin >> tt;

  while (tt--) {
    vector<int> arr(3);

    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr.begin(), arr.end());

    cout << arr[1] << '\n';
  }

  return 0;
}
