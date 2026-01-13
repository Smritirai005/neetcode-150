class Solution {
public:
    int nextNum(int n) {
        int sum = 0;
        while (n > 0) {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        do {
            slow = nextNum(slow);
            fast = nextNum(fast);
            fast = nextNum(fast);
        } while (slow != fast);

        return slow == 1;
    }
};
