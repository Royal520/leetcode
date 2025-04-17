#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        int cnt = 0;

        for(int i = 0; i < n - 1; i++){
            int x = row[i];   //某个人
            int y = x ^ 1;  //他的另一半

            if(row[i + 1] != y){  //情侣不挨着,就往后搜
                for(int k = i + 2; k < n; k++){
                    if(row[k] == y){
                        //找到了另一半,交换
                        int temp = row[i + 1];
                        row[i + 1] = row[k];
                        row[k] = temp;
                        cnt++;
                        break;   //找到就退回上一层循环，判断下一对是不是情侣坐一起
                    }
                }
            }
        }
        return cnt;
    }
    long long distributeCandies(int n, int limit) {
        if(n>limit*3)return 0;
        long long ans=0;
        int c=min(n,limit);
        int b= min(limit,n-c);
        int a= n-b-c;
        int dis=(b+c)/2-b;
        for (int i = 0; i <=dis ; ++i) {
            c-=i;
            b+=i;
            int k=(a+b)/2-a;
            int tempb=b;
            int tempa=a;
            for (int j = 0; j <=k; ++j) {
                b-=j;
                a+=j;
                ans+=set(a,b,c);
            }
            b=tempb;
            a=tempa;
        }

        return ans;
    }
    int set(int a,int b,int c){
        if(a==b&&b==c)return 1;
        else if(a==b||b==c) return 3;
        else return 6;
    }
};
//leetcode submit region end(Prohibit modification and deletion)




int main() {
    Solution solution = *new Solution();
    clock_t start, end;
    start = clock();
    cout <<solution.distributeCandies(3,3)<< endl;
    end = clock();
    cout << "spend " << double(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    return 0;
}