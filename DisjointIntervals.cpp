#include <bits/stdc++.h> 
using namespace std;

class DisjointIntervals 
{
    public:
    vector<vector<int>> intervals;
    DisjointIntervals()
    {
    	// Intialise your data structure here.
    }
    
    void addInteger(int val) 
    {
        // Add new integer to the data structure.
        if (intervals.empty())
        {
            intervals.push_back({val, val});
            return;
        }
        int n = intervals.size();
        if (val < intervals[0][0] - 1)
        {
            intervals.insert(intervals.begin(), {val, val});
            return;
        }
        if (val > intervals[n - 1][1] + 1)
        {
            intervals.push_back({val, val});
            return;
        }
        if(val == intervals[0][0] - 1)
        {
            intervals[0][0] = val;
            return;
        }
        if(val == intervals[n - 1][1] + 1)
        {
            intervals[n - 1][1] = val;
            return;
        }

        int  idx = 0;
        for (int i = 0; i < n; i++)
        {
            if (val >= intervals[i][0] && val <= intervals[i][1])
                return;
            if (val > intervals[i][1] && val < intervals[i + 1][0])
            {
                idx = i + 1;
                break;
            }
        }

        if (val == intervals[idx][0] - 1)
        {
            intervals[idx][0] = val;
            if (idx > 0 && intervals[idx - 1][1] + 1 == val)
            {
                intervals[idx - 1][1] = intervals[idx][1];
                intervals.erase(intervals.begin() + idx);
            }
            return;
        }

        if (val == intervals[idx - 1][1] + 1)
        {
            intervals[idx - 1][1] = val;
            if (idx < n && intervals[idx][0] - 1 == val)
            {
                intervals[idx][0] = intervals[idx - 1][0];
                intervals.erase(intervals.begin() + idx - 1);
            }
            return;
        }

        intervals.insert(intervals.begin() + idx, {val, val});
        return;
    
    }

    vector<vector<int>> getDisjointIntervals() 
    {
        // Return the disjoint intervals.
        return intervals;
    }
};

/*
   Your class's object will be instantiated and called as such:
   DisjointIntervals* obj = new DisjointIntervals();
   obj->addInteger(val);
   vector<vector<int>> arr = obj->getDisjointIntervals();
*/