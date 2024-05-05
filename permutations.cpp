#include <iostream>
#include <algorithm>
using namespace std;
int main () {
    int noOfDigits;
    cin >> noOfDigits;
  int myints[noOfDigits];
  for(int i = 0; i<noOfDigits; i++)
  {
      cin >> myints[i];
  }

  sort (myints,myints+3);
  do {
        for(int i = 0; i<noOfDigits;i++)
        {
            cout << myints[i];
        }
        cout << endl;
  } while ( next_permutation(myints,myints+noOfDigits) );
  return 0;
}

