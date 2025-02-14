class ProductOfNumbers {
public:
    vector<int> prefixProduct;
    int lastZero;
    ProductOfNumbers() {
        prefixProduct.push_back(1);
        lastZero = -1;
    }
    void add(int num) {
        if (num == 0) {
            prefixProduct.clear();
            prefixProduct.push_back(1);
            lastZero = prefixProduct.size() - 1;
        } else {
            prefixProduct.push_back(num * prefixProduct.back());
        }
    }
    int getProduct(int k) {
        int n = prefixProduct.size();
        if (n - k - 1 < lastZero) return 0;
        return prefixProduct.back() / prefixProduct[n - k - 1];
    }
};