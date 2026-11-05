class Solution {
public:
int lb (vector<int>& arr1,int num)
{
    return lower_bound(arr1.begin(),arr1.end(),num)-arr1.begin();
}
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int cnt=0,n1=arr1.size(),n2=arr2.size();
        for(int i=0;i<n1;i++)
        {
            int num=arr1[i];
            int res=lb(arr2,num);
            bool chk = true;
 
            if((res < n2 && abs(arr2[res] - num) <= d) || (res > 0 && abs(arr2[res - 1] - num) <= d))
            {
                chk = false;
            }
            
            if(chk) 
            {
                cnt++;
            }
        }
        return cnt;
    }
};