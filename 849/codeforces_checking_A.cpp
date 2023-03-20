#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  int tt;

  cin >> tt;

  while (tt--) {
    char ch;

    cin >> ch;
    const string cf = "codeforces";

    if (any_of(cf.begin(), cf.end(), [ch](char c) { return c == ch; }))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
