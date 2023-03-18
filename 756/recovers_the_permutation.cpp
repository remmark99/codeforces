// https://codeforces.com/problemset/problem/1611/C

#include <deque>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  int cases{};
  cin >> cases;

  while (cases--) {
    int length{};
    cin >> length;
    deque<int> arr(length);
    deque<int> result{};
    for (int i = 0; i < length; i++) cin >> arr.at(i);

    if (!(arr[0] == length || arr[length - 1] == length)) {
      cout << -1 << endl;
      continue;
    }

    for (int i = 0; i < length / 2; i++) {
      result.push_front(arr[i]);
      result.push_back(arr[length - i - 1]);
    }
    if (length % 2) result.push_front(arr[length / 2]);

    for (int temp : result) cout << temp << ' ';
    cout << endl;
  }

  return 0;
}
