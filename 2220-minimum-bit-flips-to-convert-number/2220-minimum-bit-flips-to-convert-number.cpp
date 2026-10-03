class Solution {
public:
    int minBitFlips(int start, int goal) {
        int no = start ^ goal;
        int count = 0;
        while (no > 0) {
            no = no & (no - 1);
            count++;
        }
        return count;
    }
};
// How it works:
// If no = 12 (1100 in binary):
// 1100 & 1011 -> 1000 (count = 1)
// 1000 & 0111 -> 0000 (count = 2)