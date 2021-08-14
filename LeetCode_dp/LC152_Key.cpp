#include <iostream>
using namespace std;
#include <vector>

int maxProduct(vector<int>& nums) {
    int maxF = nums[0], minF = nums[0], ans = nums[0];
    for(int i = 1; i <nums.size();i++){
        int ni = nums[i];
        int nm = maxF;
        maxF = max(minF*ni, max(maxF*ni,ni));
        minF = min(minF*ni, min(nm*ni,ni));
        ans = max(maxF,ans);
    }
    return ans;
}
int main(){
    int n = 3;
    int b[] = {-2,3,-4};
    vector<int> a(n);
    for (int i=0; i<n;i++){
        a[i] = b[i];
    }
    int res = maxProduct(a);
    cout << endl;
    cout <<res;
}