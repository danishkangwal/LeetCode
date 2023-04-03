class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(begin(people),end(people));
        int ans = 0,n = people.size();
        int l = 0,r = n-1;
        while(l<r){
            if(people[l]+people[r]<=limit){
                l++;r--;
            }else{
                r--;
            }
            ans++;
        }
        if(l==r)ans++;
        return ans;
    }
};