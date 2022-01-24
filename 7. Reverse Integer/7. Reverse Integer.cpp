class Solution {
public:
    int reverse(int x) {
        vector<int> tmp;
        int rev = 0;
        if (x > 0){
            while (x != 0){
                tmp.push_back(x % 10);
                x /= 10;
            }
            for (auto it = tmp.begin(); it < tmp.end(); it++){
                if (rev > (pow(2,31) - 1)/10) return 0;
                rev *= 10;
                rev += *it;
            }
            return rev;
        }
        else {
            x = abs(x);
            if (x < 0) return 0;
            cout << x << endl;
            while (x != 0){
                tmp.push_back(x % 10);
                x /= 10;
            }
            for (auto it = tmp.begin(); it < tmp.end(); it++){
                if (rev > (pow(2,31)/10)) return 0;
                rev *= 10;
                rev += *it;
            }
            rev = -rev;
            return rev;

        }
        return rev;
    }
};