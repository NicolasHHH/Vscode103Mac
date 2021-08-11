#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int> &nums) {
    int size = nums.size();
    int first = nums[0], second = max(nums[0], nums[1]);
    for (int i = 2; i < size; i++) {
        int temp = second;
        second = max(first + nums[i], second);
        first = temp;
    }
    return second;
}


int deleteAndEarn(vector<int> &nums) {
    int maxVal = 0;
    for (int val : nums) {
        maxVal = max(maxVal, val);
    }
    vector<int> sum(maxVal + 1);
    for (int val : nums) {
        sum[val] += val;
    }
    return rob(sum);
}


int main(){
    int n = 7;
    int b[] = {1,2,2,3,5,4,4};
    vector<int> a;
    for (int i = 0; i<n; i++){
        a[i] = b[i];
    }
    cout << deleteAndEarn(a) << endl;
}