// Time:  O(n)
// Space: O(1)
// 如果每个数字出现三次，则对应到每一位上，每一位上1出现的次数模3为0，如果使得每一位的1的个数满3的时候清0，则最终剩余的数即为所求。
//先更新two，否则就会多算一次
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0, xthree = 0;
        for(int i = 0; i < nums.size(); i++){
            two |= (one & nums[i]);
            one ^= nums[i];
            xthree = ~(one & two);
            one &= xthree;
            two &= xthree;
        }
        return one;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0;

        for (const auto& i : nums) {
            int new_one = (~i & one) | (i & ~one & ~two);
            int new_two = (~i & two) | (i & one);
            one = new_one, two = new_two;
        }

        return one;
    }
};
