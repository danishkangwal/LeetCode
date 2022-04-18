#include<bits/stdc++.h>
using namespace std;

int numIdenticalPairs(vector<int>& nums) {
	int pairs = 0;
    for(int i = 0;i < nums.size() - 1;i++){
        for(int j = i + 1;j < nums.size();j++){
            if(nums[i] == nums[j])pairs++;
        }
    }
    return pairs;
}

int main() {
	int n;
	cin >> n;
	vector<int> nums;
	for (int i = 0; i < n; ++i)
	{
		int a;cin>>a;
		nums.push_back(a);
	}
	cout << numIdenticalPairs(nums);

	return 0;
}