#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
  int tt;
  cin >> tt;

  while (tt--) {
    int sl;
    cin >> sl;
    string str;
    cin >> str;

    int max = 0;
    for (int i = 0; i < sl; i++) {
      if (str[i] - 'a' + 1 > max) max = str[i] - 'a' + 1;
    }

    cout << max << '\n';
  }

  return 0;
}
