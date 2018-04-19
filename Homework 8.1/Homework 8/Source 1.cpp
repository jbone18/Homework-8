/**
*	Recursive Binary Search
*	Reading: section 7.3
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

//Template function for performing the recursive binary search
template <typename T>
int binary_search(const vector<T> &items, int first, int last, T target) 
{
	// All options have been checked
	if (first >last)
	{
		//Ask about base case for unsuccessful searches!
		return -1;
	}
	else 
	{
		int middle = (first + last) / 2;
		if (target > items[middle])
		{
			return binary_search(items, middle + 1, last, target);
		}
		else if (target < items[middle])
		{
			return binary_search(items, first, middle - 1, target);
		}
		else
		{
			return middle;
		}
	}
}

/**
*	Template function for invoking the recursive binary search function.
*	This is the function a user calls.
*/
template <typename T>
int binary_search(const vector<T> &items, T target) 
{
	return binary_search(items, 0, items.size() - 1, target);
}

int main()
{
	// TEST 
	vector<int> haystack;

	srand(1);
	for (int i = 0; i < 1000000; ++i) // initialize the vector with random values
		haystack.push_back(rand());

	sort(haystack.begin(), haystack.end()); // sort the contents of the vector

	bool retryflag = true;
	do 
	{
		int needle;
		cout << "Enter a number to search for [-1 to exit]: ";
		cin >> needle; // get the value to search for in the vector
		if (needle == -1) 
		{
			retryflag = false; // time to exit 
		}
		else 
		{
			int idx = binary_search(haystack, needle); // search for the needle in the haystack
			if (idx != -1) // found the index where the needle is located in the haystack
				cout << needle << " found at index " << idx << endl;
			else
				cout << needle << " is not in haystack\n";
		}
	} while (retryflag);

}