#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

class BuildingHeightsEasy{
public:
    vector<int> cnt ;
   int solve(vector<int> v, int x, int M){
    cnt.clear();
    int num = 0;
    int ans = 0;
    for(int i = 0; i < v.size(); i ++){
        if(x == v[i]) num ++;
    }
    if(num >= M) return 0;
    else {
        for(int i = 0; i < v.size(); i ++){
            if(v[i] < x) cnt.push_back(x-v[i]);
        }
        sort(cnt.begin(), cnt.end());
        for(int i = 0; i < M-num; i ++)
            ans += cnt[i];
        return ans;
    }
   }
   int minimum(int M, vector <int> heights){
        int minn = 0x3f3f3f3f;
        for(int i = 0; i < heights.size(); i ++){
            if(int ans = solve(heights, heights[i], M) < minn)
                minn = ans ;
        }
        return minn;
    }
};
int main(){
    vector<int> data;
    int M;
    while(scanf("%d", &M) != EOF){
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i ++){
            int x;
            scanf("%d", &x);
            data.push_back(x);
        }
        BuildingHeightsEasy solve;
         cout <<  solve.minimum(M, data);
    }
    return 0;
}
