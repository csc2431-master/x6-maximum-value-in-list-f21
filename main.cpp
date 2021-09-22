#include <assert.h>
#include <iostream>
using std::cout;
using std::endl;

#include "FixedArrayList.h"

int FindMaximum(const FixedArrayList<int>& L, unsigned N);

int main() {
	FixedArrayList<int> L(5);
    int max;

	// Load list with numbers
	L.Insert(0,47);
	L.Insert(1,2);
	L.Insert(2,39);
	L.Insert(3, 54);
	L.Insert(4, 10);

	// Find the maximum in the list recursively
	cout << "List: " << L << endl;
	max = FindMaximum(L, L.Size());
	cout << "Maximum of entire list = " << max << endl;
    return 0;
}

int FindMaximum(const FixedArrayList<int>& L, unsigned N) {
	int last;

	assert(0 < N && N <= L.Size());

    cout << "Calling FindMaximum with N = " << N <<  endl;
	// Get last element in list
	L.Get(N-1, last);
	if (1 == N) {
		return last;
	}
	else {
		int maxOfSublist;

		maxOfSublist = FindMaximum(L, N - 1);
		cout << "Maximum of sublist of " << N-1 << " elements = " << maxOfSublist << endl;
		if (last > maxOfSublist) {
		    return last;
		}
		else {
		    return maxOfSublist;
		}
	}
}
