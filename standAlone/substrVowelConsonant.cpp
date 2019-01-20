#include <iostream>
#include <string>
#include <climits>
using namespace std;


bool com(string f, string s){
#if 0	
	int i =0;
	while(i < f.length() && i < s.length() ){
		if(f[i] < s[i])
			return true;
		else if (f[i] > s[i])
				return false;
		++i;
	}
	return f.length() < s.length();
#else
	return lexicographical_compare(f.begin(), f.end(), s.begin(), s.end());
#endif
}

bool isVowel(char ch){
	if(ch == 'a' ||ch == 'e' ||ch == 'i' ||ch == 'o' ||ch == 'u')
		return true;
	else return false;
}
void outp(string s){
	int c = INT_MAX;
	// cout << s;
	string s2 = "", smaller = "z", larger = "";
	int i = 0;
	for( i = s.length()-1; i >=0; i--){
		if( !isVowel(s[i]) )
		{
			c = i;
			break;
		}
		// cout << "last consonant << " << c << endl;
	}

	// all vowel
	if(i == -1){
		cout << "All vowels";
		return;
	}

	for(int i = c; i>= 0; i--){
		s2 = s[i] + s2;

		if(!isVowel(s[i])){
			continue;
		}
		else{
//			smaller = com(s2, smaller) ? s2:smaller;
//			larger	= com(s2, larger) ? larger: s2;
//  	using in built comparison
			smaller = s2 < smaller ? s2:smaller;
			larger	= s2 < larger ? larger: s2;

			// cout << "smaller::"<< smaller << "  larger::"<< larger << endl;
		}
	}

	for(int i = 0; i < smaller.length(); i++){
		if(!isVowel(smaller[i])){
			c = i;
			break;
		}
	}
	smaller = smaller.substr(0,c+1);
	cout << "Result::"<<smaller << endl << larger;
}

int main(){

	// outp("abc");
	// outp("aab");
	// outp("absanjaysinghchauhon");
	// outp("aeababbb");

	
	// large string of size 10^5

	string s = "";
	//s.reserve(100000);
	 for(int i = 0; i < 100000; i++)
	 	s = s + "a";
	s += "b";
	outp(s);
	// char *str;
	
	// char buffer[100000] = {0};
	// cin.get(buffer, 99996);

	// string s = buffer;


	// s += s;
	// s += s;
	// s += "b";

	// cout << s << endl<< endl;
	// cout << s.length() << endl;
	// outp(s);

	// outp("aaaaa");
	return 0;
}