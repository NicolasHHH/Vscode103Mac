#include <iostream>
using namespace std;
#include <vector>

int jump(vector<int>& nums){
    int len = nums.size();
    int pas[len] ;
    if (len == 1){
        return 0;
    }
    if (len == 2){
        return 1;
    }
    for (int k = 0; k< len;k++){
        pas[k]=0;
    }
    for (int i=0; i<len-1;i++){
        int loin = i + nums[i];
        if (loin >= len-1){
            return pas[i] + 1;
        }
        else{
            for(int j =i+1 ; j<= loin; j++){
                if ( pas[j] == 0){
                    pas[j] = pas[i]+1;
                }
                else pas[j] = min(pas[i]+1,pas[j]);
            }
        }
        for (int k = 0; k< loin+1;k++){
            cout<< pas[k] <<" ";
        }
        cout << endl;
    }
    return pas[len-1];
}


int main(){
    int n = 5;
    int b[] = {2,3,2,2,1};
    vector<int> a(n);
    for (int i=0; i<n;i++){
        a[i] = b[i];
    }
    cout << jump(a)<<endl;
}