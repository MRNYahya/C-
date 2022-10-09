#include<bits/stdc++.h>
using namespace std;
#define MAX 100

void sortStrings(char arr[][MAX], int n)
{
	char temp[MAX];
	printf("Data sebelum diurutkan: ");
	for (int i=0; i<n; i++)
		printf("\n%d. %s", i+1, arr[i]);

	//bubble sort
	for (int i=0; i<n-1; i++)
	{
		for (int j=0; j<n-1-i; j++)
		{
			if (strcmp(arr[j], arr[j+1]) > 0)
			{
				strcpy(temp, arr[j]);
				strcpy(arr[j], arr[j+1]);
				strcpy(arr[j+1], temp);
			}
		}
	}
}

int main()
{
	char arr[][MAX] = {"ayam","lontong","bebek","soto","bakso"};
	int n = sizeof(arr)/sizeof(arr[0]);

	sortStrings(arr, n);

	printf("\n\nData sesudah diurutkan: ");
	for (int i=0; i<n; i++)
		printf("\n%d. %s", i+1, arr[i]);
	return 0;
}

