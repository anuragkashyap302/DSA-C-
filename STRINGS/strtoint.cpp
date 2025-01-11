#include <bits/stdc++.h>
using namespace std;
int main() {
string s;
cin >> s;
int val = 0, pw = 1;
while (s.size()) {
val += pw * (s.back() - '0');
  cout << val <<endl;
s.pop_back();
pw *= 10;
}
cout << val;
}