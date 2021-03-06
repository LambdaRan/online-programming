
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <utility>

#include <cctype>

using namespace std;
/*
* Name: 463. Island Perimeter
* WebSite: https://leetcode.com/problems/island-perimeter/
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        std::sort(heaters.begin(), heaters.end());
        int radius = 0;
        int res = 0;
        for (int house : houses) {
            auto lbv = std::lower_bound(heaters.begin(), heaters.end(), house);
            
            radius = (lbv != heaters.end() ? *lbv-house : std::numeric_limits<int>::max());
            if (lbv != heaters.begin()) {
                radius = min(radius, house-*(--lbv));
            }
            res = max(res, radius);
        }
        return res;
    }
};

int main() 
{
    Solution s;

    std::cout << "method 1: \n";

    std::cout << std::endl;
    return 0;
}