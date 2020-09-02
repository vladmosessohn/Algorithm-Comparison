#include "algo.h"
#include <algorithm>
using namespace std;

void sort(vector<int>& input, const bool reverse) {
	// comb sort
    int gap = input.size(); 
    bool swapped = true; 
    while (gap != 1 || swapped == true) { 
        gap = getNextGap(gap); 
        swapped = false; 
        int size = input.size();
        for (int i = 0; i < size-gap; i++) { 
            if (input[i] > input[i+gap]) { 
                swap(input[i], input[i+gap]); 
                swapped = true; 
            } 
        } 
    }
    if (reverse) {
		std::reverse(input.begin(), input.end());
	} 
} 

int getNextGap(int gap) { 
    gap = (gap*10)/13; 
    if (gap < 1) 
        return 1; 
    return gap; 
} 
