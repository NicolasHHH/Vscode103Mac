#include <iostream>
using namespace std;
#include <vector>
int cas_neg(int, int ,vector<int>& );

int maxProduct(vector<int>& nums){
    int len = nums.size();
    if (len == 1){
        return nums[0];
    }
    int pre = 1;
    int abs = 1;
    int maxRes = nums[0];
    int depart = 0;
    int arrive = -1;
    for(int i = 0; i<len;i++){
        if ( nums[i] == 0 ){
            pre = 0;
            arrive = i-1;
            cout <<"zero "<<depart<<" : "<<arrive<<endl;
            if (arrive >= depart && abs < 0){
                maxRes = max(cas_neg(depart,arrive,nums),maxRes);
            }
            abs = 0;
            depart = i+1;
        }
        else if (nums[i] > 0){
            if (abs == 0) abs = nums[i];
            else abs *= nums[i];

            if (pre>0){
                pre = pre * nums[i];
            }
            else {
                pre = nums[i];
            }
        }
        else{
            if (abs == 0) abs = nums[i];
            else abs *= nums[i];
            if (pre < 0){
                pre = pre * nums[i];
            }
            else {
                pre = nums[i];
            }
        }
        maxRes = max(maxRes,pre);
        if (abs>0) maxRes = max(maxRes,abs);
        cout << "abs "<< abs<<" pre "<<pre<<" max "<<maxRes<<endl;
        cout << "depart " << depart<<" arrive "<<arrive<<endl<<endl;
    }
    arrive = len-1;
    if (arrive >= depart && abs < 0){
        maxRes = max(cas_neg(depart,arrive,nums),maxRes);
    }
    return maxRes;
}

int cas_neg(int depart, int arrive,vector<int>& nums){
    cout << "cas_neg " << depart<<" : "<<arrive<<endl;
    if (arrive == depart) return nums[arrive];
    int middle = 1;
    int left=1;
    int leftpos;
    int right =1;
    int rightpos;
    for(int i = depart;i<=arrive;i ++){
        left *= nums[i];
        if (nums[i]<0){
            leftpos = i;
            break;
        }
    }
    for(int i = arrive ;i>=depart;i--){
        right *= nums[i];
        if (nums[i]<0){
            rightpos = i;
            break;
        }
    }
    cout << "left " << left<<" "<< leftpos<<" right "<<right<<" "<< rightpos<<endl;
    if (leftpos==rightpos){
        return max(left/nums[leftpos],right/nums[rightpos]);
    }
    else{
        for(int i = leftpos+1 ;i<rightpos;i++){
            middle *= nums[i];
        }
        cout << "middle " << middle<<" * "<<min(left,right)<<endl;
        return middle * min(left,right);
    }
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