#include "PmergeMe.hpp"
#include <vector>
#include <deque>
#include <algorithm>  // For std::swap

MergeInsertSorter::MergeInsertSorter() { }
MergeInsertSorter::~MergeInsertSorter() { }

MergeInsertSorter::MergeInsertSorter(const MergeInsertSorter& other) {
	(void) other;
}

MergeInsertSorter& MergeInsertSorter::operator=(const MergeInsertSorter& other) {

	(void) other;
	return *this;
}
