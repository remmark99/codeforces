#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  int tt;

  cin >> tt;

  while (tt--) {
    int l;
    cin >> l;

    string str;
    cin >> str;

    int res = l;
    for (int i = 0; i < l / 2; i++) {
      if (str[i] != str[l - i - 1]) {
        res -= 2;
      } else {
        break;
      }
    }

    cout << res << '\n';
  }
  return 0;
}
