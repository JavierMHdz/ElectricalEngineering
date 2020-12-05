#include <iostream>
using namespace std;

int main()
{
  int x=1;
  cout << "Enter an int: " << endl;
  cin >> x;

  while(cin.fail()){
   cout<<"Bad input"<<endl;
   cin.clear(); //clear the fail bit, forget that it fail
   cin.ignore(256,'\n');   //delete the data of cin
   cin>>x;
  }
  cout << "Good you entered: " << x << endl;
  return 0;
}
