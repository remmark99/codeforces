#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  int tt;

  cin >> tt;

outer:
  while (tt--) {
    int l;
    cin >> l;

    string s;
    cin >> s;

    int x = 0, y = 0;
    for (int i = 0; i < l; i++) {
      if (s[i] == 'U')
        y++;
      else if (s[i] == 'D')
        y--;
      else if (s[i] == 'L')
        x--;
      else
        x++;

      if (x == 1 && y == 1) {
        cout << "YES\n";
        goto outer;
      }
    }

    cout << "NO\n";
  }
  return 0;
}
