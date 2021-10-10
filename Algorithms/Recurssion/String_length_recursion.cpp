// CPP program to calculate length of
// a string using recursion
#include <bits/stdc++.h>
using namespace std;

/* Function to calculate length */
int recLen(char* str)
{
	// if we reach at the end of the string
	if (*str == '\0')
		return 0;
	else
		return 1 + recLen(str + 1);
}

/* Driver program to test above function */
int main()
{
	char str[] = "GeeksforGeeks";
	cout << recLen(str);
	return 0;
}
