class Solution {
public:
#define f first
#define s second

    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int maxi=0,n=img1.size();
        map<pair<int,int>,int> mp;
        
        vector<pair<int,int>> p1;
        vector<pair<int,int>> p2;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(img1[i][j]==1)
                {
                    p1.push_back({i,j});
                }
                if(img2[i][j]==1)
                {
                    p2.push_back({i,j});
                }
            }
        }

        for(auto q : p1)
        {
            for(auto r : p2)
            {
                int rd=q.f-r.f;
                int cd=q.s-r.s;

                mp[{rd,cd}]++;
                int res=mp[{rd,cd}];
                maxi=max(maxi,res);
            }
        }
        return maxi;

    }
};