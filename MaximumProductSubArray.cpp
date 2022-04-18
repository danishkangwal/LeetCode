#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
    int res = *max_element(nums.begin(),nums.end());
    int currMax = 1,currMin = 1;
    for (int i = 0; i < nums.size(); ++i)
    {
        if(nums[i] == 0){
            currMax = 1;
            currMin = 1;
            continue;
        }
        int temp = currMax*nums[i];
        currMax = max(nums[i]*currMax,max(nums[i]*currMin,nums[i]));
        currMin = min(temp,min(nums[i]*currMin,nums[i]));
        res = max(res,currMax);
        
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    for(int i = 0;i < n; i++){
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }
    cout << maxProduct(nums);
}
