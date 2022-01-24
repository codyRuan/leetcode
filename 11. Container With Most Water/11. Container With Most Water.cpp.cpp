class Solution {
public:
    int maxArea(vector<int>& height) {
        int head = 0, tail = height.size()-1;
        int maxA = -1;
        while(head != tail){
            maxA = max(maxA, min(height[head],height[tail])*(tail-head));
            if (height[head] < height[tail]) head ++;
            else tail --;
        }
        return maxA;
    }
};