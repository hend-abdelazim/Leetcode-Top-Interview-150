class Solution {
public:
    bool knowBit(uint32_t n, uint32_t i) {
        return (n >> i) & 1;
    }
    int hammingWeight(uint32_t n) {
        int res = 0;
        for(int i = 0; i < 32; i++) {
            if(knowBit(n, i)) {
                res++;
            }
        }
        return res;
    }
};