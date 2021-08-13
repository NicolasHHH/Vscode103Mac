#include <iostream>
using namespace std;
#include <vector>

//time out
int maxSubarraySumCircular(vector<int>& nums) {
    int maxRes =nums[0];
    int len = nums.size();
    if (len ==1 )
    return maxRes;
    for (int i= 0; i <len;i++){
        int pre = 0, maxAns = nums[i];
        for (int j = 0;j<len ;j++) {
            pre = max(pre + nums[(i+j)%len], nums[(i+j)%len]);
            //cout << pre << " "<< maxAns<<endl;
            maxAns = max(maxAns, pre);
        }
        maxRes = max(maxRes,maxAns);

    }
    return maxRes;
}
int main(){
    int n = 3;
    int b[] = {5,-3,5};
    vector<int> a(n);
    for (int i=0; i<n;i++){
        a[i] = b[i];
    }
    int res = maxSubarraySumCircular(a);
    cout << endl;
    cout <<res;
}