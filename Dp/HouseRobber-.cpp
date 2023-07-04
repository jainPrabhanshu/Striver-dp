// mr  x  is  a  professional  robber  planning  to  rob  houses  along  a  street  each  house  has  a  certain  amount  of  money  hidden
// meanwhile  adjacent  houses  have  a  security  system  connected  and  it  will  automatically  contact  the  police  if  two  neighboring  houses  were  broken  into  the  same  night
// you  are  given  an  array  list  of  non  negative  integers  a  representing  the  amount  of  money  hidden  at  each  house  your  task  is  to  return  the  maximum  amount  of  money  mr  x  can  rob  tonight  without  alerting  the  police


int houseRobber(vector<int>&a) {
    // Write your code here.
    int n = a.size();
    if(n==1){
        return a[0];
    }
    int prev1 = max(a[0],a[1]);
    int prev2 = a[0];
    int current = 0;
    for(int i = 2;i<n;i++){
        current = max(prev1,prev2+a[i]);
        prev2 = prev1;
        prev1 = current;
    }
    return prev1;
}
