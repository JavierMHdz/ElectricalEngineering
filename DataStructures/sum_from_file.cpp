#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
  ifstream myf(argv[1]);
  ofstream myof(argv[2]);
  int x, y;
  
  if(myf.fail()){
   cout<<"Bad filename"<<endl;
   return 1;
  }
  
  myf>>x>>y;
  if(myf.fail()){
   cout<<"Bad integers"<<endl;
   myf.close();
   return 1;
  }
  
  myof << "X=" << x << " and Y=" << y << endl;
  myof<<"Sum="<<x+y<<endl;
  myf.close();
  myof.close();
  return 0;
}
