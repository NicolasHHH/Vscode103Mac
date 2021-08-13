#include <iostream>
using namespace std;
#include <vector>

//time out
int maxSubarraySumCircular(vector<int>& nums) {
    int N = nums.size();
    int ans = nums[0], cur = nums[0];
    for (int i = 1; i < N; ++i) {
        cur = nums[i] + max(cur, 0);
        ans = max(ans, cur);
    }

        // ans is the answer for 1-interval subarrays.
        // Now, let's consider all 2-interval subarrays.
        // For each i, we want to know
        // the maximum of sum(A[j:]) with j >= i+2

        // rightsums[i] = A[i] + A[i+1] + ... + A[N-1]
    int rightsums[N];
    rightsums[N-1] = nums[N-1];
    for (int i = N-2; i >= 0; --i)
        rightsums[i] = rightsums[i+1] + nums[i];

        // maxright[i] = max_{j >= i} rightsums[j]
    int maxright[N];
    maxright[N-1] = nums[N-1];
    for (int i = N-2; i >= 0; --i)
        maxright[i] = max(maxright[i+1], rightsums[i]);

    int leftsum = 0;
    for (int i = 0; i < N-2; ++i) {
        leftsum += nums[i];
        ans = max(ans, leftsum + maxright[i+2]);
    }

    return ans;
}
int main(){
    int n = 5;
    int b[] = {1,1,-3,4,5};
    vector<int> a(n);
    for (int i=0; i<n;i++){
        a[i] = b[i];
    }
    int res = maxSubarraySumCircular(a);
    cout << endl;
    cout <<res;
}