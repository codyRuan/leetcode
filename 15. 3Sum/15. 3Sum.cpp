# include <iostream>
# include <vector>
# include <map>
# include <set>
# include <algorithm>

using namespace std;
/**********
* 2022/1/24
* map solution O(n^2)
***********/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int, vector<vector<int>>> dict;
        set<vector<int>> tmp;
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                int sum = nums[i] + nums[j];
                vector<int> twosum;
                twosum.push_back(i);
                twosum.push_back(j);
                dict[sum].push_back(twosum);
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (dict.find(-nums.at(i)) != dict.end()){
                auto towsum = dict.find(-nums.at(i)) -> second;
                for (auto itr = towsum.begin(); itr != towsum.end(); itr++){
                    vector<int> datas = *itr;
                    vector<int> threesum;
                    if (find(datas.begin(), datas.end(), i) == datas.end()){
                        threesum.push_back(nums[datas[0]]);
                        threesum.push_back(nums[datas[1]]);
                        threesum.push_back(nums[i]);
                        sort(threesum.begin(), threesum.end());
                        tmp.insert(threesum);
                    }
                }
            }
        }
        for (auto itr = tmp.begin(); itr != tmp.end(); itr++){
            ans.push_back(*itr);
        }
        return ans;
    }
};


int main(){

    Solution s;
    vector<int> t = {-5,1,-10,2,-7,-13,-3,-8,2,-15,9,-3,-15,13,-6,-10,5,6,11,1,13,-12,14,6,11,4,13,-14,0,11,1,10,-11,6,-11,-10,8,2,-3,-13,-6,-9,-9,-6,11,-8,-9,1,13,9,9,3,13,0,-6,1,-10,-15,3,5,3,11,-8,0,2,-11,5,-13,6,9,-11,7,8,-13,8,4,-6,14,13,-15,1,7,-5,-1,-7,5,7,-2,-3,-13,10,7,13,9,-8,-8,13,12,-6,4,7,-10,-12,-8,-8,11,11,-6,3,9,-14,-11,2,-4,-5,10,8,-13,-7,12,-10,10};
    auto sol = s.threeSum(t);
    cout << sol.size() << endl;
    return 0;
}