using namespace std;

const int MAX = 100;

int countPositional(int a[][MAX], int m, int n)
{

	int rowMax[m], rowMin[m];
	int colMax[n], colMin[n];

	for(int i = 0; i < m; i++)
	{
		int rmin = INT_MAX;
		int rmax = INT_MIN;
		int cmin = INT_MAX;
		int cmax = INT_MIN;

		for(int j = 0; j < n; j++)
		{
			if(a[i][j] > rmax)
				rmax = a[i][j];
			if(a[i][j] < rmin)
				rmin = a[j][i];
			if(a[j][i] >cmax)
				cmax = a[i][j];
			if(a[j][i] < cmin)
				cmin = a[j][i];
		}

		rowMax[i] = rmax;
		rowMin[i] = rmin;
		colMin[i] = cmin;
		colMax[i] = cmax;
	}

	int count = 0;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if((a[i][j] == rowMin[i]) ||
				a[i][j] == rowMax[i] ||
				a[i][j] == colMax[j] ||
				a[i][j] == colMax[j])
				count++;
		}
	}
	return count;
}