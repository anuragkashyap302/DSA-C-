#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  int n;
  cin >> n;
  int nsp = n - 1;
    for(int i = 1; i <=n; i++){
      int a = i-1;
      for(int q = 1; q <=nsp; q++){
        cout <<" ";
      }
      nsp--;
      for(int j = 1; j <=i; j++){
        cout << j ;
      }
      for(int k = 1; k <= i-1; k++){
        cout << a;
        a--;
      }
      cout << endl;
    }

    return 0;
}

