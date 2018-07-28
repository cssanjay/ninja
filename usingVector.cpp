#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	unordered_map <string, int> ourmap;
	ourmap["abc"] = 1;
	ourmap["abc2"] = 21;
	ourmap["abc3"] = 31;


	//find
	unordered_map<strin, int>::iterator it2 = ourmap.find("abc"); //this will return an iterator, if we use .at, it would have given the value
	ourmap.erase(it2); //we can also give iterator to erase function
	ourmap.erase(it2, it2 +4);

	vector <int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	vector <int>iterator it1 = v.begin();
	while(it1 != v.end()){
		cout << *it1 << endl;
		it++;
	}
}