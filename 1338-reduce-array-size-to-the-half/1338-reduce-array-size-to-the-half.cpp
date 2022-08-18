class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> m;
        for(auto &i:arr)
            m[i]++;
        vector<int> freq;
        for(auto it=m.begin();it!=m.end();it++){
            freq.push_back(it->second);
        }
        sort(freq.rbegin(),freq.rend());
        int n=arr.size(),count = 0,rem = n,index = 0;
        while(rem>n/2){
            rem -= freq[index++];
            count++;
        }
        return count;
    }
};