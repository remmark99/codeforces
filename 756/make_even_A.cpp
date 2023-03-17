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
