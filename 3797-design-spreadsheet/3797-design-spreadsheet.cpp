class Spreadsheet {
public:
    unordered_map<string,int> mp;
    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {
        mp[cell] = value;
    }
    
    void resetCell(string cell) {
        mp[cell] = 0;
    }
    
    int getValue(string formula) {
        int idx = formula.find('+');
        string left = formula.substr(1, idx - 1);
        string right = formula.substr(idx + 1);

        int valLeft = 
            isalpha(left[0]) 
            ? (mp.count(left) ? mp[left] : 0) 
            : stoi(left);

        int valRight = 
            isalpha(right[0]) 
            ? (mp.count(right) ? mp[right] : 0) 
            : stoi(right);

        return valLeft + valRight;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */