class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int> pq;
        for(auto& i:nums)
            pq.push(-1*i);
        vector<int> res;
        while(pq.size()){
            res.push_back(-1*pq.top());
            pq.pop();
        }
        return res;
    }
};