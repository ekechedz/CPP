#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <algorithm>  // For std::swap

class MergeInsertSorter {
public:
	MergeInsertSorter();
	~MergeInsertSorter();
	MergeInsertSorter(const MergeInsertSorter& other);
	MergeInsertSorter& operator=(const MergeInsertSorter& other);

	template <typename Container>
	void merge_insertion_sort(Container& container);

private:
	template <typename Container>
	void merge(Container& left, Container& right, Container& result);
};

template <typename Container>
void MergeInsertSorter::merge(Container& left, Container& right, Container& result) {
	size_t l = 0;
	size_t r = 0;
	while (l < left.size() && r < right.size())
	{
		if (left[l] < right[r])
			result.push_back(left[l++]);
		else
			result.push_back(right[r++]);
	}
	while (l < left.size())
		result.push_back(left[l++]);
	while (r < right.size())
		result.push_back(right[r++]);
}

template <typename Container>
void MergeInsertSorter::merge_insertion_sort(Container& container) {
	size_t n = container.size();

	if (n < 2)
		return;
	std::vector<Container> subarrays;
	for (size_t i = 0; i < n; i += 2)
	{
		Container subarray;
		subarray.push_back(container[i]);
		if (i + 1 < n)
			subarray.push_back(container[i + 1]);
		if (subarray.size() == 2 && subarray[0] > subarray[1])
			std::swap(subarray[0], subarray[1]);
		subarrays.push_back(subarray);
	}

	while (subarrays.size() > 1)
	{
		std::vector<Container> merged_subarrays;
		for (size_t i = 0; i < subarrays.size(); i += 2)
		{
			if (i + 1 < subarrays.size())
			{
				Container merged;
				merge(subarrays[i], subarrays[i + 1], merged);
				merged_subarrays.push_back(merged);
			}
			else
			{
				merged_subarrays.push_back(subarrays[i]);
			}
		}
		subarrays = merged_subarrays;
	}
	container = subarrays[0];
}

#endif
