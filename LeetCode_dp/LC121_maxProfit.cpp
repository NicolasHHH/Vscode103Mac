
# include <iostream>
using namespace std;
#include <vector> 
int maxProfit(vector<int>& prices) {
    int len = prices.size();
    if (len==1) return 0;
    int min_depart = prices[0];
    int diff;
    int maxPrf = 0;
    for (int x:prices){
        if( x < min_depart){
            min_depart = x;
        }
        else{
            diff = x - min_depart;
            maxPrf = max(maxPrf,diff);
        }
    }
    return maxPrf;
}


int main(){
    int n = 8;
    int b[] = {2,1,2,6,1,8,10,10};
    vector<int> a(n);
    for (int i=0; i<n;i++){
        a[i] = b[i];
    }
    cout << maxProfit(a)<<endl;
}