#include <bits/stdc++.h>
using namespace std;
double dist(vector<int>x,vector<int>y)
{
    double dx=(double)(x[0]-x[1]);
    double dy=(double)(y[0]-y[1]);
    return sqrt(dx*dx+dy*dy);
}
bool check(int mid,vector<vector<int> > &A,int B)
{
    int n=A.size();
    for(int i=0;i<n-1;i++)
    {
        vector<int>temp(2,-1);
        int res=1;
        for(int j=i+1;j<n;j++)
        {
            if(temp[0]==-1)
            {
                if(dist(A[i],A[j])<=2*mid)
                {
                    res++;
                    temp=A[j];
                }
            }
            else
            {
                double d1,d2;
                d1=dist(A[i],A[j]);
                d2=dist(temp,A[j]);
                if(max(d1,d2)<=2*mid)
                    res++;
            }
        }
        if(res>=B)
            return true;
    }
    return false;
}
int solve(vector<vector<int> > &A, int B) {
    sort(A.begin(),A.end());
    int n=A.size();
    int l=0;
    int r=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            r=max(r,(int)ceil(dist(A[i],A[j])));
        }
    }
    int res=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid,A,B))
        {
            res=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    return res;
}
