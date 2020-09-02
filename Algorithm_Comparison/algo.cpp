#include "algo.h"
#include <algorithm>
using namespace std;


int getMax(vector<int>& input, int n) { 
    int mx = input[0]; 
    for (int i = 1; i < n; i++) 
        if (input[i] > mx) 
            mx = input[i]; 
    return mx; 
}

void countSort(vector<int>& input, int exp) { 
	    int n = input.size();
    int output[n];

    int i, count[10] = {0}; 
    for (i = 0; i < n; i++) {
        count[ (input[i]/exp)%10 ]++; 
    }
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1]; 
    }
    for (i = n - 1; i >= 0; i--) { 
        output[count[ (input[i]/exp)%10 ] - 1] = input[i]; 
        count[ (input[i]/exp)%10 ]--; 
    } 
    for (i = 0; i < n; i++) {
        input[i] = output[i]; 
    }
} 

void sort(vector<int>& input, const bool reverse) { 
	// radix sort
    int m = getMax(input, input.size()); 
    for (int exp = 1; m/exp > 0; exp *= 10) {
        countSort(input, exp); 
    }
    if (reverse) {
		std::reverse(input.begin(), input.end());
	} 
}






