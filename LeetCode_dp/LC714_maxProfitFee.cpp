# include <iostream>
using namespace std;
#include <vector> 

int maxProfitFee(vector<int>& prices,int fee) {
    int len = prices.size();
    if (len==1) return 0;

    int hold = -prices[0];
    int wait = 0;
    int lasthold;
    
    for (int i = 1; i < len; i++){
        lasthold = hold;
        hold = max(hold, wait-prices[i]);
        wait = max(lasthold+prices[i]-fee,wait);
    }
    
    return wait;
}


int main(){
    int n = 6;
    int b[] = {1,3,2,8,4,9};
    vector<int> a(n);
    for (int i=0; i<n;i++){
        a[i] = b[i];
    }
    cout << maxProfitFee(a,2)<<endl;
}