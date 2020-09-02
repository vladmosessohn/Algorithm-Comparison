#include "algo.h"
#include <algorithm>
using namespace std;

void sort(std::vector<int>& input, const bool reverse) {
	// shell sort
	int i, j, gap;
    int size = input.size();
    for (gap = size / 2; gap > 0; gap = gap / 2) { 
        for (i = gap; i < size; ++i) {             
            for (j = i - gap; j >= 0 && input[j] > input[j + gap]; j = j -gap) {
                swap(input[j], input[j + gap]);
            }
        } 
    } 
    if (reverse) {
		std::reverse(input.begin(), input.end());
	} 
} 