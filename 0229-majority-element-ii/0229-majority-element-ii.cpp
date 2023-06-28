class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int ele1 = -1,ele2 = -1;
        int cnt1 = 0,cnt2 = 0;
        for(int i = 0;i < arr.size();i++){
            if(cnt1 ==0 and arr[i] != ele2){
                cnt1++;
                ele1 = arr[i];
            }
            else if(cnt2 == 0 and arr[i] != ele1){
                cnt2++;
                ele2 = arr[i];
            }
            else if(arr[i] == ele1)
                cnt1++;
            else if(arr[i] == ele2)
                cnt2++;
            else{
                cnt1--;cnt2--;
            }
        }
        vector<int> res;
        int c1 = 0,c2 = 0;
        for(auto i:arr){
            if(i == ele1)
                c1++;
            else if(i==ele2)
                c2++;
        }
        if(c1 > arr.size()/3)
            res.push_back(ele1);
        if(c2 > arr.size()/3)
            res.push_back(ele2);
        return res;
    }
};