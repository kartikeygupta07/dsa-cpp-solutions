class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        priority_queue<pair<int,int>> pq;

        for(int i = 0 ; i < boxTypes.size() ; i++){
            int numBoxes = boxTypes[i][0];
            int unitsPerBox = boxTypes[i][1];
            pq.push({unitsPerBox, numBoxes});
        }

        int totalUnits = 0;

        while(!pq.empty() && truckSize > 0){
            pair<int, int> top = pq.top();
            pq.pop() ;

            int unitsPerBox = top.first;
            int numBoxes = top.second;

            int boxesToTake = min(truckSize , numBoxes);
            totalUnits += boxesToTake * unitsPerBox ;
            truckSize -= boxesToTake ;
        }

        return totalUnits ;
    }
};