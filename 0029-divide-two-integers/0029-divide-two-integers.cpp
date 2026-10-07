class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle edge case for 32-bit signed integer overflow limits
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determine the sign of the final result
        bool isNegative = (dividend < 0) ^ (divisor < 0);

        // Convert to long long and take absolute values safely
        long long dd = abs((long long)dividend);
        long long ds = abs((long long)divisor);

        long long quotient = 0;

        // Core division loop using bit shifting (chunking)
        while (dd >= ds) {
            long long temp_ds = ds;
            long long multiple = 1;

            // Double the divisor and the multiple as long as it fits into the remaining dividend
            while (dd >= (temp_ds << 1)) {
                temp_ds = temp_ds << 1;
                multiple = multiple << 1;
            }

            // Subtract the largest chunk we found and add its multiple to the quotient
            dd -= temp_ds;
            quotient += multiple;
        }

        // Apply the correct sign
        if (isNegative) {
            quotient = -quotient;
        }

        // Final boundary check (just in case)
        if (quotient > INT_MAX) return INT_MAX;
        if (quotient < INT_MIN) return INT_MIN;

        return quotient;
    }
};