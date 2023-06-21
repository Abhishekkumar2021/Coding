#include<bits/stdc++.h>
using namespace std;

int minDropping(int eggs, int floors){
    if(floors <= 1 || eggs == 1) return floors;
    
    int mini = INT_MAX;
    for(int f = 1; f<=floors; f++){
        int breaked = minDropping(eggs - 1, f - 1);
        int unbreaked = minDropping(eggs, floors - f);

        // Max is for the worst case
        int temp = 1 + max(breaked, unbreaked);

        // Min for minimum out of all worst cases
        mini = min(mini, temp);
    }
    return mini;
}