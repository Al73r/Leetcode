class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int Z[n*2+1]={0};
        char A[n*2+1];
        A[0] = '#';
        int t=1;
        for(int i=0; i<n; i++) {
            A[t++] = s[i];
            A[t++] = '#';
        }
        int center=0, right=0, ans=0;
        for(int i=0; i<n*2+1; i++) {
            if(i<right)
                Z[i] = min(right-i, Z[2*center-i]);
            while(A[i+Z[i]+1]==A[i-Z[i]-1])
                Z[i]++;
            if(i+Z[i]>right) {
                center = i;
                right = i+Z[i];
            }
            ans += (Z[i]+1)/2;
        }
        return ans;
    }
};