#include <math.h>

using namespace std;

int MissingNumber(int arr[], int size){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    for(int i = 0; i< size; i++){
      
      if(arr[abs(arr[i])]< 0) return abs(arr[i]);
      arr[abs(arr[i])]*=-1;
      //cout<<i<<endl;
      //0--3--2--7--4--
    }

}
