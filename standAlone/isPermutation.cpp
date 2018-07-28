// input1 - first input string
// input2 - second input string
#include <cstring>
bool isPermutation(char input1[], char input2[]) {
    // Write your code here
  int size1 = strlen(input1);
  int size2 = strlen(input2);
  int i = 0;
  
  if(size1!=size2) return false;
  
  char map_store[256] = {};
  
  for(i = 0; i < size1; i++)
    map_store[input1[i]]++;
  
  for(i = 0; i < size1; i++){
    if(--map_store[input2[i]] < 0) return false;
  }
  
  return true;
  
}
