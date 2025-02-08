class NumberContainers {
    public:
        unordered_map<int,set<int>>m1;
        unordered_map<int,int>m2;

        NumberContainers() {}
        
        void change(int i, int n) {
            if(m2.find(i)!=m2.end()){
                int num = m2[i];
                m1[num].erase(i);
                if(m1[num].size()==0){
                    m1.erase(num);
                }
            }
            m1[n].insert(i);
            m2[i] = n;
        }
        
        int find(int n) {
            if(m1.find(n)!=m1.end()) return *m1[n].begin();
            return -1;
        }
};