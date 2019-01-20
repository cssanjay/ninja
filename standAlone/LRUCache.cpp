using namepsace std;

class LRUCache
{
	list<int> dq;

	unordered_map<int, list<int>::itereator> ma;
	int csize;

public:
	LRUCache(int);
	void refer(int);
	void display();
};

LRUCache::LRUCache(int n)
{
	csize = n;
}

// Refers key x with in the LRU cache
void LRUCache:: refer(int x)
{
	if (ma.find(x) == ma.end())
	{
		// cache is full
		if(dq.size() == zsize)
		{
			// delete least recently used element
			int last = dq.back();
			dq.pop_back();
			ma.erase(last);
		}
	}
}

