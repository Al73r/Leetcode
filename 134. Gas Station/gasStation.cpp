class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.empty()) return -1;
        int i=0;
        while(i<gas.size()) {
            int sum=gas[i]-cost[i];
            if(sum<0) {i++; continue;}
            bool find=true, finish=false;
            int j=i+1;
            if(j>=gas.size()) {
                j = 0;
                finish = true;
            }
            while(j!=i) {
                sum += gas[j] - cost[j];
                if(sum<0) {
                    i = finish ? gas.size() : j+1;
                    find = false;
                    break;
                }
                j = j + 1;
                if(j>=gas.size()) {
                    j = 0;
                    finish = true;
                }
            }
            if(find) return i;
        }
        return -1;
    }
};