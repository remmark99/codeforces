/*polycarp has an integer n

that doesn't contain the digit 0. He can do the following operation with his
number several (possibly zero) times:

    Reverse the prefix of length l

(in other words, l leftmost digits) of n. So, the leftmost digit is swapped
with the l-th digit from the left, the second digit from the left swapped
with (l−1)-th left, etc. For example, if n=123456789 and l=5, then the new
value of n will be 543216789

    .

Note that for different operations, the values of l
can be different. The number l can be equal to the length of the number n —
in this case, the whole number n

is reversed.

Polycarp loves even numbers. Therefore, he wants to make his number even. At
the same time, Polycarp is very impatient. He wants to do as few operations
as possible.

Help Polycarp. Determine the minimum number of operations he needs to perform
with the number n

to make it even or determine that this is impossible.

You need to answer t
independent test cases.*/

#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  int input_length{};
  string input_string{};

  getline(cin, input_string);
  input_length = stoi(input_string);

  for (int i = 0; i < input_length; i++) {
    getline(cin, input_string);
    int first_even_index{static_cast<int>(input_string.find_first_of("2468"))};
    int last_even_index{static_cast<int>(input_string.find_last_of("2468"))};

    if (last_even_index == input_string.length() - 1)
      cout << 0 << '\n';
    else if (first_even_index == 0)
      cout << 1 << '\n';
    else if (first_even_index == -1)
      cout << -1 << '\n';
    else
      cout << 2 << '\n';
  }

  return 0;
}

