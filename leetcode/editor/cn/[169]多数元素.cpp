//给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。 
//
// 你可以假设数组是非空的，并且给定的数组总是存在多数元素。 
//
// 
//
// 示例 1: 
//
// 输入: [3,2,3]
//输出: 3 
//
// 示例 2: 
//
// 输入: [2,2,1,1,1,2,2]
//输出: 2
// 
// Related Topics 位运算 数组 分治算法 
// 👍 735 👎 0
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int element = -1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == element) count++;
            else{
                --count;
                if(count < 0){
                    element = nums[i];
                    count = 1;
                }
            }
        }
        return element;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
int result(){
    vector<int>nums = {3, 2, 3};
    Solution s;
    return s.majorityElement(nums);
}