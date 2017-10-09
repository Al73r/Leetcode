class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<=1) return 0;
        int n = height.size();
        int maxheight[n] = {0};
        int maxpos[n] = {0};
        int water[n] = {0};
        maxheight[n-1] = height[n-1];
        maxpos[n-1] = n-1;
        for(int i=n-2; i>=0; i--){
            if(height[i] >= maxheight[i+1]){
                maxheight[i] = height[i];
                maxpos[i] = i;
            }
            else{
                maxheight[i] = maxheight[i+1];
                maxpos[i] =maxpos[i+1];
            }
        }
        int i=0;
        while(i<n-1){
            if(height[i]>=maxheight[i+1]){
                water[i] = height[i];
                for(int j=i+1; j<=maxpos[i+1]; j++){
                    water[j] = maxheight[i+1];
                }
                i = maxpos[i+1];
            }
            else{
                int tmp = height[i];
                while(i<n && height[i]<=tmp){
                    water[i] = tmp;
                    i++;
                }
                water[i] = height[i];
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            ans += water[i] - height[i];
        }
        return ans;
    }
};