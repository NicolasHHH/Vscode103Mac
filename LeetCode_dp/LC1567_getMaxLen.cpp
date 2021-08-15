#include <iostream>
using namespace std;
#include <vector>
int cas_zero(int depart, int arrive,vector<int>& nums){
        int len = nums.size();
        if  (len == 1 or len == 2){
            return 1;
        }
        int left = depart;
        int right = arrive;
        for(int i = depart ; i<=arrive; i++){
            if (nums[i]<0){
                left = i;
                break;
            }
        }
        for(int i = arrive ; i>=depart; i--){
            if (nums[i]<0){
                right = i;
                break;
            }
        }
        
        if (left -depart > arrive-right){
            return right - depart;
        }
        else return arrive - left;
    }


    int maxProduct(vector<int>& nums){
        int len = nums.size();
        if (len == 1 and nums[0]<=0)
        return 0;

        int maxlen = 0;
        int abs = 1;
        int depart = 0;
        int arrive = -1;
        int current = 0;

        for(int i = 0; i<len;i++){
            if ( nums[i] == 0 ){
                arrive = i-1;
                if (arrive >= depart ){
                    if (abs < 0){
                        maxlen = max(cas_zero(depart,arrive,nums),maxlen);
                    }
                    else{
                        maxlen = max(maxlen, arrive-depart);
                    }
                }
                abs = 0;
                current = 0;
                depart = i+1;
            }
            else{
                if (abs==0){
                    abs = nums[i];
                    current = 0;
                }
                else
                    abs *= nums[i]/std::abs(nums[i]);
                current += 1;
                if (abs>0){
                    maxlen = max(maxlen, current);
                }
            }
        }
        arrive = len-1;
        if (arrive >= depart){
            if (abs < 0){
                maxlen = max(cas_zero(depart,arrive,nums),maxlen);
            }
            else{
                maxlen = max(maxlen, arrive-depart);
            }
        }
        return maxlen;
    }

int main(){
    int n = 20;
    int b[] = {5,-20,-20,-39,-5,0,0,0,36,-32,0,-7,-10,-7,21,20,-12,-34,26,2};
    vector<int> a(n);
    for (int i=0; i<n;i++){
        a[i] = b[i];
    }
    int res = maxProduct(a);
    cout << endl;
    cout <<res;
}