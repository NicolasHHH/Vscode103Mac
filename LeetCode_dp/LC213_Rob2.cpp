#include <iostream>
using namespace std;
#include <vector>

// classic

int rob_aux(vector<int>& nums){
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

    int rob(vector<int>& nums){
        int len = nums.size();
        if (len == 1){
            return nums[0];
        }
        vector<int> a(len-1);
        vector<int> b(len-1);
        for (int i=0; i<len-1;i++){
            a[i] = nums[i];
        }
        for (int i=1; i<len;i++){
            b[i-1] = nums[i];
        }
        int res_a = rob_aux(a);
        int res_b = rob_aux(b);
        if (res_a > res_b) return res_a;
        else return res_b;
        
    }

int main(){
    int n = 8;
    int b[] = {2,1,2,6,1,8,10,10};
    vector<int> a(n);
    for (int i=0; i<n;i++){
        a[i] = b[i];
    }
    cout << rob(a)<<endl;
}