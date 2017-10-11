class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        vector<int>::iterator A=nums1.begin();
        vector<int>::iterator B=nums2.begin();
        int k=m+n;
        if(k&0x01)
            return findKth(A, m, B, n, k/2+1);
        else
            return (findKth(A, m, B, n, k/2)+findKth(A, m, B, n, k/2+1))/2.0;
    }
private:
    static double findKth(const vector<int>::iterator & A, int m,
                          const vector<int>::iterator & B, int n, int k){
        if(m>n) return findKth(B, n, A, m, k);
        if(m==0)return B[k-1];
        if(k==1) return min(A[0], B[0]);
        
        int ia=min(m, k/2), ib=k-ia;
        if(A[ia-1]<B[ib-1])
            return findKth(A+ia, m-ia, B, n, k-ia);
        else if(A[ia-1]>B[ib-1])
            return findKth(A, m, B+ib, n-ib, k-ib);
        else
            return A[ia-1];
    }
};