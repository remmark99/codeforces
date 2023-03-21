#include <iostream>
#include <map>
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

    map<char, int> mp;
    int lkeys = 0, rkeys = 0;

    for (int i = 0; i < l; i++) {
      if (!mp[str[i]]) {
        mp[str[i]] = 1;
        rkeys++;
      } else {
        mp[str[i]]++;
      }
    }

    map<char, int> left;
    int max = 0;

    for (int i = 0; i < l; i++) {
      if (--mp[str[i]] == 0) rkeys--;
      if (!left[str[i]]) {
        lkeys++;
        left[str[i]] = 1;
      }

      if (lkeys + rkeys > max) max = lkeys + rkeys;
    }

    cout << max << '\n';
  }
  return 0;
}
