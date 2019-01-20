#include <iostream>
#include <map>
#include <string>
 
using namespace std;
 
int main()
{
	map<string, int> candidate;

	string name;

	int votes;

	cout<< "Enter the name and votes of the 5 candidates: " << endl;
 
	for (int i = 0; i < 5; i++)
	{
		  cin >> name >> votes;
		  candidate[name] = votes;
	}
 
	map<string, int>::const_iterator it = candidate.begin();
	map<string, int>::const_iterator end = candidate.end();

	// Variable to hold the sum of the votes
	int sumVotes = 0;

	// Variable to hold the highest, initialized to the first candidates vote total
	// Also a variable to hold the highest person's name.
	int highest = it->second;
	string highestName = it->first;

	while (it != end)
	{
		cout << it->first << " has "<< it->second << " votes\n";

		// Add their votes to a running total variable (called an accumulator)
		sumVotes += it->second;

		// If their vote count is higher than the currently recorded high
		// Record their vote count as the new highest and also record their
		// name while you are at it.
		if (it->second > highest) { 
			highest = it->second;
			highestName = it->first;
		}
		++it;
	}

	// Now we can print out the winner's name, their vote total out of the total casted
	cout << "Winner of the election is: " << highestName << " with " << highest  
		 << " votes out of the total " << sumVotes << " casted, congratulations!" << endl;
 
	system("pause");
	return 0;
 
}
