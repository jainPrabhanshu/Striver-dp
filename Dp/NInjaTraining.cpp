// ninja is planing this n days long training schedule each day he can perform any one of these three activities running fighting practice or learning new moves each activity has some merit points on each day as ninja has to improve all his skills he can t do the same activity in two consecutive days can you help ninja find out the maximum merit points ninja can earn
// you are given a 2d array of size n 3 points with the points corresponding to each day and activity your task is to calculate the maximum number of merit points that ninja can earn

int ninja(int day,int last ,vector<vector<int>> &points,vector<vector<int>> &dp){
    if(day == 0){
        int maximum = 0;
        for(int i=0;i<3;i++){
            if(i!=last){
                maximum = max(maximum,points[0][i]);
            }
        }
        return maximum;
    }
    if(dp[day][last]!=-1){
        return dp[day][last];
    }
    int maximum = 0;
    for(int i =0;i<3;i++){
        if(i!=last){
            int temp = points[day][i] + ninja(day-1,i,points,dp) ;
            maximum = max(maximum,temp);
        }
    }
    return dp[day][last] = maximum;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(4,-1));
    return ninja(n-1,3,points,dp);
}