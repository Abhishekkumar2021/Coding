#include<bits/stdc++.h>
using namespace std;

// This is for ordered_set
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Ordered Set : Policy based data structure
    ordered_set<int> s;

    // All set functions are already present + 2 extra functions are there
    s.insert(1);
    s.insert(10);
    s.insert(20);
    s.insert(3);
    s.insert(12);
    s.insert(50);
    
    auto elementAt4thPosition = s.find_by_order(4);
    cout << *elementAt4thPosition << "\n";

    int idxOf13 = s.order_of_key(13);
    cout << idxOf13 << "\n";
    
    return 0;
}
