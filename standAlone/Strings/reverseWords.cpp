#include <cstring>
#include <iostream>
using namespace std;


void reverseEachWord(char input[]) {
    // Write your code here
  cout << input;

    int i = 0, start = 0, end = 0;
    char temp;
    while(input[i] != '\0'){
      cout <<i << endl;
      while(input[i]!=' ') {i++; cout <<endl<<"::" <<i;} cout <<"I AM HERE";
      COUT << "ASDASD";
    }
}

int main(){
  char input[] = "Welcome to Coding Ninjas";
  reverseEachWord(input);
  cout << input;
}