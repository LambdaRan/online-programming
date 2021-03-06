
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

/*
* Name: 把数组排成最小的数
* Description: 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
* 例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
*
*/
class Solution {
public:
    string PrintMinNumber(vector<int>& numbers) {
        
        if (numbers.empty()) return string();
        if (numbers.size() == 1) return std::to_string(numbers[0]);

        std::sort(numbers.begin(), numbers.end(), [](int v1, int v2) -> bool{
            std::string str1 = std::to_string(v1);
            std::string str2 = std::to_string(v2);
            return std::string((str1+str2)) < std::string((str2+str1));
        });

        std::string result;
        // for_each(numbers.begin(), numbers.end(), [&result](int value){
        //     result += std::to_string(value);
        // });
        for(int value : numbers)
            result += std::to_string(value);
        return result;
    }
};

int main() 
{
    Solution s;

    vector<int> vec = {3, 32, 321};
    std::cout << "method 1: \n";
    std::cout << "321323 --> " << s.PrintMinNumber(vec);
    std::cout << std::endl;

    return 0;
}
