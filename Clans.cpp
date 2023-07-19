#include<bits/stdc++.h>
using namespace std;

vector<int> primes(int n){
    vector<int> ans;
    vector<bool> prime(n+1, true);
    prime[0] = false;
    prime[1] = false;
    int limit = sqrt(n);
    for(int i=2; i<=n; i++){
        if(prime[i]){
            ans.push_back(i);
            if(i>limit) continue;
            for(int j=i*i; j<=n; j += i) prime[j] = false; 
        }
    }

    return ans;
}

int beauty(vector<int> &arr){
    // Sieve of Eratosthenes
    int n = arr.size();
    int maxi = *max_element(arr.begin(), arr.end());
    vector<int> res = primes(maxi);

    int ans = 1;
    int mod = 1e9 + 7;
    unordered_map<string, int> mp;
    for(int i=0; i<n; i++){
        string s = "";
        for(int j=0; j<res.size(); j++){
            if(arr[i]%res[j] == 0){
                s += to_string(res[j]) + " ";
            }
        }
        mp[s]++;
    }

    for(auto it: mp){
        ans = (ans * (it.second))%mod;
    } 

    return ans;
}

int main(){
    vector<int> arr = {1, 2, 3, 4};
    cout << beauty(arr) << endl;
}