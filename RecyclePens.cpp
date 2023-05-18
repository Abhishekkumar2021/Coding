#include<bits/stdc++.h>
using namespace std;

int recyclePens(int n, int r, int k, int c ){
	// Write your code here.
    /**
     * n = total pens
     * r = total current rupees
     * k = reward on recycling a pen
     * c = cost of a refil
     * We want to maximize the number of pens we get as complete
    */

    int low = 1;
    int high = n;

    while(low<=high){
        int mid = (low + high)/2;
        int penLeft = n - mid;
        int currentRuppees = r + (mid*k) - (penLeft*c);
        if(currentRuppees == 0){
            return penLeft;
        }
        else if(currentRuppees > 0){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return n - low;
}