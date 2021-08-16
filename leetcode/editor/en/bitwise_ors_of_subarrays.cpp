//We have an array arr of non-negative integers.
//
// For every (contiguous) subarray sub = [arr[i], arr[i + 1], ..., arr[j]] (with
// i <= j), we take the bitwise OR of all the elements in sub, obtaining a result
//arr[i] | arr[i + 1] | ... | arr[j].
//
// Return the number of possible results. Results that occur more than once are
//only counted once in the final answer
//
//
// Example 1:
//
//
//Input: arr = [0]
//Output: 1
//Explanation: There is only one possible result: 0.
//
//
// Example 2:
//
//
//Input: arr = [1,1,2]
//Output: 3
//Explanation: The possible subarrays are [1], [1], [2], [1, 1], [1, 2], [1, 1,
//2].
//These yield the results 1, 1, 2, 1, 3, 3.
//There are 3 unique values, so the answer is 3.
//
//
// Example 3:
//
//
//Input: arr = [1,2,4]
//Output: 6
//Explanation: The possible results are 1, 2, 3, 4, 6, and 7.
//
//
//
// Constraints:
//
//
// 1 <= nums.length <= 5 * 104
// 0 <= nums[i] <= 109
//
// Related Topics Array Dynamic Programming Bit Manipulation
// 👍 805 👎 157

#include <vector>
#include <cassert>
#include <set>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 private:
  static auto getContiguousSubarrays(vector<int> const &arr) {
    set<vector<int>> set;

    for (auto i = 0; i < arr.size(); i++) {
      vector<int> subset;
      subset.push_back(arr[i]);
      for (auto j = i + 1; j < arr.size(); j++) {
        auto const temp = subset;
        set.insert(temp);
        subset.push_back(arr[j]);
      }
      set.insert(subset);
    }

    return set;
  }
 public:

  static int subarrayBitwiseORs(vector<int> const &arr) {
    auto const combs = getContiguousSubarrays(arr);
    set<int> possible_ors;
    for (auto const &comb : combs) {
      int res = 0;
      for (auto const &el : comb) {
        res |= el;
      }
      possible_ors.insert(res);
    }
    return possible_ors.size();
  }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
  Solution solution;
  assert(solution.subarrayBitwiseORs({0}) == 1);
  assert(solution.subarrayBitwiseORs({1, 1, 2}) == 3);
  assert(solution.subarrayBitwiseORs({1, 2, 4}) == 6);
  assert(solution.subarrayBitwiseORs({6, 12, 7}) == 5);
}