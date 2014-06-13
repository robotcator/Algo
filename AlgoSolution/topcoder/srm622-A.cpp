#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class CostOfDancing{
public:
    int minimum(int K, vector <int> danceCost){
        sort(danceCost.begin(), danceCost.end());
        int sum = 0;
        for(int i = 0; i < K; i ++){
            sum += danceCost[i];
        }
        return sum;
    }
};
int main(){
    return 0;
}
