class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();

        vector<int> parents;
        vector<int> ranks;

        for(int i=0;i<n+1;i++)
        {
            parents.push_back(i);
            ranks.push_back(1);
        }

        vector<int>result;

        for(int i=0;i<n;i++)
        {
            int n1=edges[i][0];
            int n2=edges[i][1];
            if(!doUnion(parents,ranks,n1,n2))
            {
                result={n1,n2};
                break;
            }
        }

        return result;
    }
private:
    int doFind(vector<int>& parent,int n)
    {
        int p=parent[n];
        while(p!=parent[p])
        {
            parent[p]=parent[parent[p]];
            p=parent[p];
        }

        return p;
    }
    bool doUnion(vector<int>& parents,vector<int>& ranks,int n1,int n2)
    {
        int p1=doFind(parents,n1);
        int p2=doFind(parents,n2);
        if(p1==p2)
        {
            return false;
        }

        if(ranks[p1]>ranks[p2])
        {
            parents[p2]=p1;
            ranks[p1]+=ranks[p2];
        }
        else{
            parents[p1]=p2;
            ranks[p2]+=ranks[p1];
        }

        return true;
    }
};