/*
Give few arrays
1. mass[] - mass of each asteroid
2. speed[] - speed of each asteroid
3. direction[] - direction of each asteroid

All the asteroids are in a straight line and moving in the given direction at the given speed.
When two asteroids collide, they both explode and the new asteroid is same as the one with greater mass.
The task is to find the final configuration of the asteroids after all the collisions.

Input Format
First line contains an integer N, the number of asteroids.
Next line contains N space separated integers, the mass of each asteroid.
Next line contains N space separated integers, the speed of each asteroid.
Next line contains N space separated integers, the direction of each asteroid.

Output Format
Print the indexes of all the asteroids that remains after all the collisions.

Constraints
1 <= N <= 10^5
1 <= mass[i] <= 10^9
1 <= speed[i] <= 10^9
direction[i] = 1 or -1

Sample Input
5
2 3 5 1 7
4 2 5 3 2
1 -1 -1 1 1

Sample Output
2 4
*/

#include<bits/stdc++.h>
using namespace std;

class Asteroid{
    public:
    int mass;
    int speed;
    int direction;
    Asteroid(int mass, int speed, int direction){
        this->mass = mass;
        this->speed = speed;
        this->direction = direction;
    }
};

class TestcaseGenerator{
    public:
    vector<Asteroid> generateTestcase(int n){
        vector<Asteroid> asteroids;
        for(int i=0;i<n;i++){
            int mass = rand()%100 + 1;
            int speed = rand()%100 + 1;
            int direction = rand()%2;
            if(direction == 0){
                direction = -1;
            }
            asteroids.push_back(Asteroid(mass,speed,direction));
        }
        return asteroids;
    }
};

class Solution{
    public:
    vector<int> getFinalConfiguration(vector<int> mass, vector<int> speed, vector<int> direction, int n){
        stack<int> st;  // stack contains index of all the asteroids
        for(int i=0; i<n; i++){
            int curr = i;
            bool flag = true;
            while(!st.empty()){
                int prev = st.top();
                if(direction[prev] == -1 && direction[curr] == 1){
                    // They are moving away from each other so no collision
                    break;
                }
                if(direction[prev] == -1 && direction[curr] == -1){
                    // They are moving in the same direction so there may be a collision, depend on speed
                    if(speed[prev] >= speed[curr]){
                        // No collision
                        break;
                    }
                    else{
                        // Collision will be based on the mass
                        if(mass[prev] > mass[curr]){
                            flag = false;
                            break;
                        }
                        else{
                            st.pop();
                        }
                    }
                }
                else if(direction[prev] == 1 && direction[curr] == 1){
                    // They are moving in the same direction so there may be a collision, depend on speed
                    if(speed[prev] <= speed[curr]){
                        // No collision
                        break;
                    }
                    else{
                        // Collision will be based on the mass
                        if(mass[prev] > mass[curr]){
                            flag = false;
                            break;
                        }
                        else{
                            st.pop();
                        }
                    }
                }
                else{
                    // They are moving towards each other so there will be a collision
                    if(mass[prev] > mass[curr]){
                        flag = false;
                        break;
                    }
                    else{
                        st.pop();
                    }
                }
            }
            if(flag){
                st.push(curr);
            }
        }
        
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main(){
    ofstream fout("testcase.txt");

    TestcaseGenerator tc;
    for(int t=1; t<=10; t++){
        fout << "Testcase " << t << endl;
        fout << "Input" << endl;
        int n = rand()%10 + 1;
        vector<Asteroid> asteroids = tc.generateTestcase(n);
        fout<<n<<endl;
        for(int i=0; i<n; i++){
            fout<<asteroids[i].mass<<" ";
        }
        fout<<endl;
        for(int i=0; i<n; i++){
            fout<<asteroids[i].speed<<" ";
        }
        fout<<endl;
        for(int i=0; i<n; i++){
            fout<<asteroids[i].direction<<" ";
        }
        fout<<endl;

        fout << "Output" << endl;
        vector<int> mass;
        vector<int> speed;
        vector<int> direction;
        for(int i=0; i<n; i++){
            mass.push_back(asteroids[i].mass);
            speed.push_back(asteroids[i].speed);
            direction.push_back(asteroids[i].direction);
        }
        Solution sol;
        vector<int> ans = sol.getFinalConfiguration(mass,speed,direction,n);
        for(int i=0; i<ans.size(); i++){
            fout<<ans[i]<<" ";
        }
        fout<<endl;
        fout<<endl;
    }
    fout.close();
}