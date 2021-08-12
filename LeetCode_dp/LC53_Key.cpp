#include <iostream>
using namespace std;
#include <vector>

int maxSubArray(vector<int>& nums) {
    int pre = 0, maxAns = nums[0];
    for (int x : nums) {
        pre = max(pre + x, x);
        cout << pre << " "<< maxAns<<endl;
        maxAns = max(maxAns, pre);
    }
    return maxAns;
}
int main(){
    int n = 7;
    int b[] = {3,-2,-3,-3,1,3,0};
    vector<int> a(n);
    for (int i=0; i<n;i++){
        a[i] = b[i];
    }
    int res = maxSubArray(a);
    cout << endl;
    cout <<res;
}