#include <iostream>
using namespace std;
#include <vector>


int maxProfit(vector<int>& prices) {
    int len = prices.size();
    if (len==1) return 0;
    int hold = -prices[0];
    int cool = 0;
    int wait = 0;
    int lasthold = 0;

    for (int i = 1; i < len ; i++){
        int current = prices[i];
        lasthold = hold;
        hold = max(hold,wait-current);
        wait = max(cool,wait);
        cool = lasthold + current;
    }
    return max(cool,wait);
}


int main(){
    int n = 5;
    int b[] = {1,3,2,4,7};
    vector<int> a(n);
    for (int i=0; i<n;i++){
        a[i] = b[i];
    }
    cout << maxProfit(a)<<endl;
}