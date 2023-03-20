// https://codeforces.com/contest/1611/problem/D?locale=en

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  int cases{};
  cin >> cases;

  while (cases--) {
    int l{};
    cin >> l;

    vector<int> tree(l);
    vector<int> perm(l);

    for (int i = 0; i < l; i++) cin >> tree[i];

    for (int i = 0; i < l; i++) cin >> perm[i];

    vector<int> res(l);
    vector<int> total(l);

    for (int i = 0; i < l; i++) {
      total[i] = -1;
    }

    int max = -1;

    int no = 0;
    for (int i = 0; i < l; i++) {
      if (tree[perm[i] - 1] == perm[i]) {
        res[perm[i] - 1] = 0;
        total[perm[i] - 1] = 0;
        max++;
        continue;
      }
      if (total[tree[perm[i] - 1] - 1] != -1) {
        res[perm[i] - 1] = max - total[tree[perm[i] - 1] - 1] + 1;
        total[perm[i] - 1] = ++max;
      } else {
        cout << -1 << '\n';
        no++;
        break;
      }
    }

    if (no) continue;
    for (size_t i = 0; i < l; i++) {
      cout << res[i] << ' ';
    }

    cout << '\n';
  }

  return 0;
}
