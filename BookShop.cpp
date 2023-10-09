#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n, maxPrice;
    cin >> n >> maxPrice;
    vector<int> price(n), page(n);
    for(int i=0; i<n; i++) cin >> price[i];
    for(int i=0; i<n; i++) cin >> page[i];
    vector<long long> prev(maxPrice+1, 0), curr(maxPrice+1, 0);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=maxPrice; j++){
            if(price[i-1] <= j){
                curr[j] = max(prev[j], page[i-1] + prev[j - price[i-1]]);
            }else{
                curr[j] = prev[j];
            }
        }
        prev = curr;
    }
    cout << curr[maxPrice] << "\n";
    return 0;
}
