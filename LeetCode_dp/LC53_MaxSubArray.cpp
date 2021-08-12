#include <iostream>
using namespace std;
#include <vector>

int maxSubArray(vector<int>& nums) {
    int len = nums.size();
    if (len == 1)
    return nums[0];

    int left = 0;
    int right = 0;
    int sum = nums[0];
    for (int i =1; i<len; i++){
        int temp = 0;
        for (int j = left; j<=i;j++){
            temp+=nums[j];
        }
        if (temp >= sum){
            right = i;
            if (temp <= nums[i]) {
                left = i;
                sum = nums[i];
            }
            else {
                sum = temp;
            }
        }
        else
        {
            if (nums[i] >= sum){
                left = right = i;
                sum = nums[i];
            }
            else if ( temp >=0 && temp - nums[i]<0){
                    left = i;
                }
        }
        if (temp<0) {
            left = i;
        }
        
        cout << "sum: "<<sum << " left: "<<left<<" temp: "<<temp<<endl;
    }
    return sum;
}

int main(){
    int n = 15;
    int b[] = {-1,6,7,-7,-2,-6,-1,3,4,2,6,-3,-8,-1,7};
    vector<int> a(n);
    for (int i=0; i<n;i++){
        a[i] = b[i];
    }
    int res = maxSubArray(a);
    cout << endl;
    cout <<res;
}