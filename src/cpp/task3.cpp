#include <iostream>
#include <queue>

using namespace std;

bool canTransform(int a, int b) {
  queue<int> q;
  q.push(a);

  while (!q.empty()) {
    int currentNumber = q.front();
    q.pop();

    if (currentNumber == b) {
      return true;
    }
    int newNumber1 = 10 * currentNumber + 1;
    if (newNumber1 <= b) {
      q.push(newNumber1);
    }
    int newNumber2 = 2 * currentNumber;
    if (newNumber2 <= b) {
      q.push(newNumber2);
    }
  }

  return false;
}

int main() {
  int a, b;
  cin >> a >> b;

  if (canTransform(a, b)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
