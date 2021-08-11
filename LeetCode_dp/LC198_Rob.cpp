#include <iostream>
using namespace std;
#include <vector>

int rob(vector<int>& nums){
    int len = nums.size();
    if (len == 1){
        return nums[0];
    }
    if (len == 2){
        if (nums[0]>nums[1]){
            return nums[0] ;
        }
        else return nums[1];
    }

    if (len == 3){
        if (nums[0] + nums[2]>nums[1]){
            return nums[0] + nums[2] ;
        }
        else return nums[1];
    }
    nums[2] += nums[0];

    for (int i = 3; i < len;i++){
        if (nums[i-2]>nums[i-3]){
            nums[i] += nums[i-2] ;
        }
        else{
            nums[i] += nums[i-3] ;
        }
    }
    
    if (nums[len-1]>nums[len-2]){
        return nums[len-1];
    }
    else return nums[len-2];
}

int main(){
    int n = 5;
    int b[] = {2,7,9,3,1};
    vector<int> a(n);
    for (int i=0; i<n;i++){
        a[i] = b[i];
    }
    cout << rob(a)<<endl;
}