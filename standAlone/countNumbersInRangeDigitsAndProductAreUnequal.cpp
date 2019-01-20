using namespace std;

bool checkIfUnequal(int n, int q)
{
	string s1 = to_string(n);
	int a[26] = {0};

	for(int i = 0; i < s1.size(); i++)
		a[s1[i]-'0']++;

	int prod = n * q;

	string s2 = to_string(prod);

	for(int i = 0; i < s2.size(); i++)
		if(a[s2[i] - '0'])
			return false;

	return true;
}

int countInRange(int l, int r, int q)
{
	int count = 0;
	for(int i = l; i <= r; i++)
	{
		if(checkIfUnequal(i, q))
			count++;
	}

	return count;
}