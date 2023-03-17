// https://codeforces.com/contest/1611/problem/B?locale=ru

#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  int inputs_amount{};
  int progs{}, maths{};

  cin >> inputs_amount;

  while (inputs_amount--) {
    cin >> progs >> maths;
    int maxx = max(progs, maths);
    int min = (maxx == progs) ? maths : progs;
    int big_teams = (maxx - min) / 2;

    if (big_teams > min)
      cout << min << endl;
    else
      cout << big_teams + (min - big_teams) / 2 << endl;
  }

  return 0;
}
