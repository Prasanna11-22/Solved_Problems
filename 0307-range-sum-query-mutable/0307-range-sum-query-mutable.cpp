class NumArray {
public:
int n;
vector<int> tree; 
    NumArray(vector<int>& nums) {
    n=nums.size();

    tree.resize(4*n);

    build(0,0,n-1,nums);   
    }

    void build(int node,int start,int end,vector<int> &nums)
    {
        if(start==end)
        {
            tree[node]=nums[start];
            return;
        }

        int m=(start+end)/2;
        build(2*node+1,start,m,nums);
        build(2*node+2,m+1,end,nums);

        tree[node]=tree[2*node+1]+tree[2*node+2];
    }

    void Update(int node,int start,int end,int ind,int val)
    {
        if(start==end)
        {
            tree[node]=val;
            return;
        }

        int mid = (start + end) / 2; 
 
        if (ind <= mid) 
            Update(2*node+1, start, mid, ind, val); 
  
        else 
            Update(2*node+2,mid+1, end, ind, val); 

        tree[node]=tree[2*node+1]+tree[2*node+2];
    }

    void update(int index, int val) 
    {
        Update(0,0,n-1,index,val);
    }
    
    int query(int ind,int st,int end,int left,int right)
    {
        if(right < st||end < left)
        {
            return 0;
        }
        else if (left <= st && end <= right)
        {
    return tree[ind];
    }

        int mid=(st+end)/2;

        int lsum=query(2*ind+1,st,mid,left,right);
        int rsum=query(2*ind+2,mid+1,end,left,right);
        
        return lsum+rsum;
    }
    

    int sumRange(int left, int right) 
    {
        return query(0,0,n-1,left,right);
    }



};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */