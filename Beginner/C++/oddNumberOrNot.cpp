#include <iostream>
using namespace std;

int main() {
  int n;

  cout << "Enter an integer: ";
  cin >> n;

  if ( n % 2 != 0)
    cout << n << " is odd.";
  else
    cout << n << " is even.";

  return 0;
}
