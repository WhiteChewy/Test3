#include <iostream>
#include <vector>
#define SIZE 20

using namespace std;

typedef vector<int> Array;

Array sortQuick(Array array) {

	if (array.size() <= 1) {
		return array;
	}
	else {
		srand((unsigned)array.size());
		int q = array[rand() % array.size()];

		Array L;
		Array M;
		Array R;

		for (auto& elem : array) {
			if (elem < q)
				L.push_back(elem);
			else if (elem > q)
				R.push_back(elem);
			else
				M.push_back(elem);
		}

		Array resultL = sortByQuick(L);
		Array resultR = sortByQuick(R);

		resultL.reserve(M.size() + resultR.size());
		resultL.insert(resultL.end(), M.begin(), M.end());
		resultL.insert(resultL.end(), resultR.begin(), resultR.end());

		return resultL;
	}
}

void _heapify(Array& array, int end, int i) {
	int l = 2 * i + 1;
	int r = 2 * (i + 1);
	int max = i;

	if (l < end && array[i] < array[l])
		max = l;
	if (r < end && array[max] < array[r])
		max = r;
	if (max != i) {
		swap(array[i], array[max]);
		_heapify(array, end, max);
	}
}


Array sortHeap(Array array) {

	int end = (int) array.size();
	int start = end / 2 - 1;

	for (auto i = start; i >= 0; --i) {
		_heapify(array, end, i);
	}

	for (auto i = end - 1; i > 0; --i) {
		std::swap(array[i], array[0]);
		_heapify(array, i, 0);
	}
	return array;
}