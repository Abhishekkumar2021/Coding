/*
Problem Statement
You are given two groups of points where the first group has 'N' points, the second group has 'M' points, and 'N' >= 'M'.
You are also given a "cost" matrix of 'N' * 'M' dimensions whose (i, j)th element denotes the cost of the connection between ith point of group 1 and jth point of group 2. The groups are connected if each point in both groups is connected to one or more points in the opposite group. In other words, each point in the first group must be connected to at least one point in the second group, and each point in the second group must be connected to at least one point in the first group.
Now you are supposed to find the minimum cost it takes to connect the two groups.

Constraints:
1 <= T <= 5
1 <= N <= 10
1 <= M <= 10
0 <= cost[i][j] <= 100
Time limit: 1 sec


Example:
Input:
1
3 2
1 2
2 3
4 1

Output:
4

Hints:
Hint 1: You can use the Hungarian algorithm to solve this problem.

Ques -  What is the Hungarian algorithm?
Ans -  The Hungarian algorithm is a combinatorial optimization algorithm that solves the assignment problem in polynomial time. It was developed by Harold Kuhn in 1955, and published in 1956. The algorithm provides an optimal solution to the assignment problem in the form of a minimum-weight matching in a bipartite graph. The algorithm has also been extended to the weighted matching problem, the maximum weight matching problem, and the weighted assignment problem.

Ques -  What is the assignment problem?
Ans -  The assignment problem is a combinatorial optimization problem in which objects are assigned to tasks. The goal is to minimize the total cost of completing all the tasks. The assignment problem is a special case of the transportation problem in which the number of supplies equals the number of demands.

Ques -  What is the transportation problem?
Ans -  The transportation problem is a special case of the assignment problem in which the number of supplies equals the number of demands. The transportation problem is a special case of the linear assignment problem in which the cost matrix is rectangular. The transportation problem is a special case of the minimum cost flow problem in which the supply and demand vectors are non-negative and the flow on each arc is non-negative.


Steps in Hungarian method for balanced assignment problem.
1. Row reduction
2. Column reduction
3. Count no of min lines to cover all the zeros
4. If the number of lines are not equals to N then continue otherwise we have reached the end.
5. Now, find the minimum of all the unselected cell and subtract that from the intersection all all unselected cell and keep all others cell the same 
6. Now repeat all the spets again.

*/
#include <bits/stdc++.h>
using namespace std;

void rowReduction(vector<vector<int>> &cost, int N, int M){
    for(int i = 0; i < N; i++){
        int min = INT_MAX;
        for(int j = 0; j < M; j++){
            if(cost[i][j] < min){
                min = cost[i][j];
            }
        }
        for(int j = 0; j < M; j++){
            cost[i][j] -= min;
        }
    }
}

void columnReduction(vector<vector<int>> &cost, int N, int M){
    for(int i = 0; i < M; i++){
        int min = INT_MAX;
        for(int j = 0; j < N; j++){
            if(cost[j][i] < min){
                min = cost[j][i];
            }
        }
        for(int j = 0; j < N; j++){
            cost[j][i] -= min;
        }
    }
}

int Hungarian(vector<vector<int>> &cost, int N, int M){
    // Step 1: Row reduction
    rowReduction(cost, N, M);
    // Step 2: Column reduction
    columnReduction(cost, N, M);
    // Step 3: Count no of min lines to cover all the zeros
    int count = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(cost[i][j] == 0){
                count++;
            }
        }
    }
    // Step 4: If the number of lines are not equals to N then continue otherwise we have reached the end.
    if(count != N){
        // Step 5: Now, find the minimum of all the unselected cell and subtract that from the intersection all all unselected cell and keep all others cell the same 
        int min = INT_MAX;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(cost[i][j] < min){
                    min = cost[i][j];
                }
            }
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(cost[i][j] != 0){
                    cost[i][j] -= min;
                }
            }
        }
        // Step 6: Now repeat all the spets again.
        return Hungarian(cost, N, M);
    }
    else{
        // Step 7: Now, find the sum of all the selected cell and return that.
        int sum = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(cost[i][j] == 0){
                    sum += cost[i][j];
                }
            }
        }
        return sum;
    }
}