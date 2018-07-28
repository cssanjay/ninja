#include <iostream>

using namespace std;

int main() {
    /*  Read input as specified in the question.
     * Print output as specified in the question.
     */
  int n,a;
  cin >> n;
  for(int i=0; i<n;i++){
    for(int j=0; j<n+i;j++){
      while(j<=n-i-1) {cout<<""; j++;}
      cout<<i+j-1;
    }
  }
cout<<"sanjay";
cin>>a;
  return 0;  
}