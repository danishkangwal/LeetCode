class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](auto& box1, auto& box2) {
            return box1[1] > box2[1];
        });
        
        int totalUnits = 0;
        for(int box = 0;box < boxTypes.size();box++){
            int numBoxes = min(truckSize, boxTypes[box][0]);
            totalUnits += numBoxes * boxTypes[box][1];
            truckSize -= numBoxes;
        }
        return totalUnits;
    }
};