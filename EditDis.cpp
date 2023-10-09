#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
	string a, b;
	cin >> a >> b;
	int n = a.size(), m = b.size();
	vector<int> curr(m+1), prev(m+1);
	for(int i=0; i<=n; i++){
		for(int j=0; j<=m; j++){
			if(i==0) curr[j] = j;
			else if(j==0) curr[j] = i;
			else if(a[i-1] == b[j-1]) curr[j] = prev[j-1];
			else{
				curr[j] = 1 + min({prev[j], prev[j-1], curr[j-1]});
			}
		}
        prev = curr;
	}
	cout << curr[m] << "\n";
	return 0;
}