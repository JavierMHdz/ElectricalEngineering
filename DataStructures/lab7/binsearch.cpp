#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void sort(int *, int);
int binsearch(int, int *, int, int);

int main(int argc, char *argv[]){
  if(argc < 3){
    cout << "Provide a filename of the data to be searched and the target value" << endl;
    return 1;
  }
  ifstream datfile(argv[1], ios::in);
  if(! datfile.good() ){
    cout << "Unable to open file: " << argv[1] << endl;
    return 1;
  }

  int count = 0;
  // Count how many integers are in the file
  while(datfile.good()){
    int temp;
    datfile >> temp;
    if(datfile.good()){
      count++;
    }
  }
  // When we reach the end of the file, the EOF flag is set
  // To be able to read through the file again we need to clear that flag
  datfile.clear();
  //  We also need to set our internal position in the file back to 0
  datfile.seekg(0,ios::beg);

  // Now allocate an array to store the file data and read in the data
  int *data = new int[count];
  for(int i=0; i < count; i++){
    datfile >> data[i];
  }

  datfile.close();

  cout << "Read " << count << " integers from the data file.\n" << endl;

  // Uncomment the line below if you expect unsorted data
  sort(data, count);


  // Get the target value
  int target = atoi(argv[2]);

  // Call binary search
  int retval = binsearch(target,data,0,count);

  // Interpret and print the results
  if(retval == -1){
    cout << target << " does not appear in the data." << endl;
  }
  else {
    cout << target << " appears at index " << retval << " in the data." << endl;
  }

  // Deallocate the data array
  delete [] data;
  return 0;
}

// sorts the integer values in the 'data' array of size 'len'
void sort(int *data, int len)
{
   //Bubble Sort Algorithm
   int swap;
   for(int i = len-2; 0 <= i; i--){
      for (int j = 0; j <= i; j++){
         if(data[j] > data[j+1]){
            swap = data[j];
            data[j] = data[j+1];
            data[j+1] = swap;
         }
      } 
   }
}

// Returns the index in the data array where target is located
//  or -1 if the target value is not in the list
int binsearch(int target, int *data, int start, int end)
{
   //Binary Search 
   int i;
   //base case when the number is not found in the list
   if (start ==  end){
      return -1;
   }
   else{
      i = (start+end)/2;
      //base case when the number is found in the list
      if(target == data[i]){
         return i;
      }
      //if target is smaller, then set end equal to i
      //and use the binsearch function again
      else if(target < data[i]){
         end = i;
         binsearch(target, data, start, end);
      }
      //if target is greater, then set start equal to i+1
      //and use the binsearch function again
      else{
         start = i+1;
         binsearch(target, data, start, end);
      }
   }
}
