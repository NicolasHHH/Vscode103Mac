# include <iostream>
using namespace std;
#include <vector> 

int maxProfit2(vector<int>& prices) {
    int len = prices.size();
    if (len==1) return 0;

    int min_depart = prices[0];
    int maxDiff = 0;
    int last = prices[0];
    int maxPrf = 0;

    for (int x:prices){
        if( x < min_depart){
            min_depart = x;
        }
        else{
            maxDiff = max(maxDiff,x - min_depart);
        }
        if (x < last){
            maxPrf += maxDiff;
            min_depart = x;
            maxDiff = 0;
        }
        last = x;
        //cout << "maxDiff " << maxDiff<<" maxPrf "<<maxPrf<<endl;
    }
    maxPrf += maxDiff;
    return maxPrf;
}


int main(){
    int n = 5;
    int b[] = {7,6,4,3,1};
    vector<int> a(n);
    for (int i=0; i<n;i++){
        a[i] = b[i];
    }
    cout << maxProfit2(a)<<endl;
}