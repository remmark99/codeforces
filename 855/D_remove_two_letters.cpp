#include <bits/stdc++.h>

#include <algorithm>
#include <cctype>
#include <cstdint>

using namespace std;

void solve(const vector<uint64_t> &powers) {
  int n;
  cin >> n;

  string str;
  cin >> str;

  map<uint64_t, int> mp;
  int dunno = 1e9 + 9;

  uint64_t right_hash = 0;
  uint64_t left_hash = 0;
  uint64_t p_pow = 0;
  for (const char &ch : str) {
    right_hash += (ch - 'a' + 1) * powers[p_pow++];
    right_hash %= dunno;
  }

  right_hash -= (str[0] - 'a' + 1 + (str[1] - 'a' + 1) * 31);
  right_hash %= dunno;

  int res = 0;
  for (int i = 0; i < n - 1; i++) {
    uint64_t new_hash = (left_hash + right_hash) % dunno;

    if (!mp[new_hash]) {
      mp[new_hash] = 1;
      res++;
    }

    left_hash += (str[i] - 'a' + 1) * powers[i + 2];
    left_hash %= dunno;

    if (right_hash) {
      right_hash -= (str[i + 2] - 'a' + 1) * powers[i + 2];
      right_hash = ((right_hash % dunno) + dunno) % dunno;
    }
  }

  cout << res << '\n';
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int tt;
  cin >> tt;

  vector<uint64_t> powers(2e5);
  powers[0] = 1;

  for (int i = 1; i < 2e5; i++) {
    powers[i] = (powers[i - 1] * 31) % static_cast<uint64_t>(1e9 + 9);
  }

  while (tt--) {
    solve(powers);
  }

  return 0;
}
