/*我们可以将其拆分成 values[i]+i 和 values[j]−j 两部分，
这样对于统计景点 jj 答案的时候，由于 values[j]−j 是固定不变的，
因此最大化 values[i]+i+values[j]−j 的值其实就等价于求 [0,j−1] 中 values[i]+i 的最大值 mx，
景点 j 的答案即为 mx+values[j]−j */

# include <iostream>
using namespace std;
#include <vector> 

int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0, mx = values[0] + 0;
        for (int j = 1; j < values.size(); ++j) {
            ans = max(ans, mx + values[j] - j);
            // 边遍历边维护
            mx = max(mx, values[j] + j);
        }
        return ans;
}

int main(){
    int n = 15;
    int b[] = {402,224,922,720,323,714,129,303,556,532,925,824,466,169,725};
    vector<int> a(n);
    for (int i=0; i<n;i++){
        a[i] = b[i];
    }
    int res = maxScoreSightseeingPair(a);
    cout << endl;
    cout <<res;
}
