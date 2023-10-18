#include<bits/stdc++.h>
using namespace std;
 
long long pow10(int n){
    long long ans = 1;
    for(int i=1; i<=n; i++) ans *= 10;
    return ans;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long k;
        cin >> k;
        int n = 1;
        long long curr = 9;
		while (k > n * curr) {
			k -= n * curr;
            curr *= 10;
			n++;
		}
		// The exact number the kth digit is in
		long long num = (k - 1) / n + pow10(n - 1);
		// The location in num of the kth digit
		int loc = (int)((k - 1) % n);
		// Determine answer by converting num to string and indexing at loc
		cout << to_string(num)[loc] << endl;
    }
    return 0;
}