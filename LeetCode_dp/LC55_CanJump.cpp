#include <iostream>
using namespace std;
#include <vector>

// greedy: noter la position la plus lointaine qu'on pourrait atteindre
// dp 
bool canjump(vector<int>& nums){
    int energie = nums[0];
    int len = nums.size();
    if (len == 1 ){
        return true;
    }
    if (energie == 0){
            return false;
        }
    for (int i = 1; i<len-1 ; i++){
        energie = max(nums[i],energie - 1);
        if (energie == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int n = 8;
    int b[] = {2,1,2,6,1,8,10,10};
    vector<int> a(n);
    for (int i=0; i<n;i++){
        a[i] = b[i];
    }
    cout << canjump(a)<<endl;
}