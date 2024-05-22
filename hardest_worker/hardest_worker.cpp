class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        //initialize longest worker as the first entry id and the longest time worked as the first entry 
        //time as well
        int longest_worker = logs[0][0];
        int longest_time = logs[0][1];


        //for loop to loop through the vector to calculate time, time greater than previous time and
        //update the about variables
        for(int i = 1; i < size(logs); i++){
            int now = logs[i][1] - logs[i-1][1];
        

            if(now > longest_time){
                longest_worker = logs[i][0];
                longest_time = now;
            }else if(now == longest_time){
                longest_worker = min(logs[i][0] , longest_worker);
                longest_time = now;
            }
        }

        //return the longest worker id
        return longest_worker;
    }
};
