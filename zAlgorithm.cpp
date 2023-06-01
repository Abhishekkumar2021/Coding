#include<bits/stdc++.h>
using namespace std;

int zAlgorithm(string s, string p, int n, int m)
{
    string str = p + "$" + s;
    int len = str.length();
    int z[len];
    memset(z, 0, sizeof(z));
    int l = 0, r = 0;
    for(int i = 1; i < len; i++)
    {
        if(i > r)
        {
            l = r = i;
            while(r < len && str[r - l] == str[r])
                r++;
            z[i] = r - l;
            r--;
        }
        else
        {
            int k = i - l;
            if(z[k] < r - i + 1)
                z[i] = z[k];
            else
            {
                l = i;
                while(r < len && str[r - l] == str[r])
                    r++;
                z[i] = r - l;
                r--;
            }
        }
    }
    for(int i = 0; i < len; i++)
    {
        if(z[i] == m)
            return i - m - 1;
    }
    return -1;
}
int main(){
    string s = "Geeks For Geeks";
    string p = "Geeks";
    int n = s.length();
    int m = p.length();
    int ans = zAlgorithm(s, p, n, m);
    cout << ans << endl;
    return 0;
}