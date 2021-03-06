
#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <string>
#include <vector>
#include <map>

using namespace std;
/*
* Name: 168. Excel Sheet Column Title
* Website: https://leetcode.com/problems/excel-sheet-column-title/description/
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    // Boyer-Moore Voting Algorithm
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;
        for (int v : nums)
        {
                if (count == 0)
                    candidate = v;
                count += (v == candidate ? 1 : -1);
        }
        return candidate;
    }
    int majorityElement_v1(vector<int>& nums) {
        int half =static_cast<int>(nums.size()/2);
        map<int, int> numberCountMap;
        int count = 0;
        for (auto &v : nums)
            numberCountMap[v]++;

        for (map<int, int>::const_iterator it = numberCountMap.begin();
            it != numberCountMap.end(); ++it)
        {
            if (it->second > half)
                return it->first;
            count += it->second;
            if (count > half)
                return 0;
        }
        return 0;   
    }
};

int main() 
{
    Solution s;

    std::cout << "method 1: \n";
    //std::cout <<  "function(): true <------> " << boolToString(s.function()) << "\n";

    std::cout << std::endl;
    return 0;
}