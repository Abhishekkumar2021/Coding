#include<bits/stdc++.h>
using namespace std;

double median(vector<int> a, vector<int> b)
{
    // Write your code here.
    int n = a.size();
    int m = b.size();
    if(n > m)
    {
        return median(b, a);
    }

    int s = 0;
    int e = n;
    while(s <= e)
    {
        int cut1 = (s+e)/2;
        int cut2 = (n+m+1)/2 - cut1;

        int l1 = cut1 == 0 ? INT_MIN : a[cut1-1];
        int l2 = cut2 == 0 ? INT_MIN : b[cut2-1];
        int r1 = cut1 == n ? INT_MAX : a[cut1];
        int r2 = cut2 == m ? INT_MAX : b[cut2];

        if(l1 <= r2 && l2 <= r1)
        {
            if((n+m)%2 == 0)
            {
                return (max(l1, l2) + min(r1, r2))/2.0;
            }
            else
            {
                return max(l1, l2);
            }
        }
        else if(l1 > r2)
        {
            e = cut1-1;
        }
        else
        {
            s = cut1+1;
        }
    }
    return 0.0;

}