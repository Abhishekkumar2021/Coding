#include<bits/stdc++.h>
using namespace std;

/*
Problem: Alien Dictionary
Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary.
Find the order of characters in the alien language.

Approach:
1. Create a graph with nodes as characters of the given words.
2. Find the topological sort of the graph.
3. Return the topological sort.

*/

vector<char> getAlienLanguage(string* dictionary, int n)
{
    // Write your code here.
    vector<char> ans;
    unordered_map<char, unordered_set<char>> graph;
    for(int i=0; i<n-1; i++){
        string word1 = dictionary[i];
        string word2 = dictionary[i+1];
        int j=0;
        while(j<word1.length() && j<word2.length()){
            if(word1[j] != word2[j]){
                graph[word1[j]].insert(word2[j]);
                break;
            }
            j++;
        }
    }

    unordered_map<char, int> indegree;
    for(auto it=graph.begin(); it!=graph.end(); it++){
        char node = it->first;
        indegree[node] = 0;
    }

    for(auto it=graph.begin(); it!=graph.end(); it++){
        char node = it->first;
        for(auto it2=graph[node].begin(); it2!=graph[node].end(); it2++){
            char nbr = *it2;
            indegree[nbr]++;
        }
    }

    queue<char> q;
    for(auto it=indegree.begin(); it!=indegree.end(); it++){
        char node = it->first;
        if(indegree[node] == 0){
            q.push(node);
        }
    }

    while(!q.empty()){
        char node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto it=graph[node].begin(); it!=graph[node].end(); it++){
            char nbr = *it;
            indegree[nbr]--;
            if(indegree[nbr] == 0){
                q.push(nbr);
            }
        }
    }

    return ans;

}

