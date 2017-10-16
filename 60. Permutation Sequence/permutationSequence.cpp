class Solution {
public:
    string getPermutation(int n, int k) {
        int tmp[n+1], flag[n+1];
        tmp[0] = 1; flag[0] = false;
        for(int i=1; i<n+1; i++){
            tmp[i] = tmp[i-1] * i;
            flag[i] = false;
        }
        string ans;
        for(int i=n; i>=1; i--){
            int m, j, t;
            m = k / tmp[i-1] + (k%tmp[i-1]==0 ? 0 : 1);
            k %= tmp[i-1];
            k = k==0 ? tmp[i-1] : k;
            for(j=1, t=0; j<n+1; j++){
                if(flag[j]) continue;
                t++;
                if(t==m){
                    flag[j] = true;
                    break;
                }
            }
            ans += j + '0';
        }
        return ans;
    }
};