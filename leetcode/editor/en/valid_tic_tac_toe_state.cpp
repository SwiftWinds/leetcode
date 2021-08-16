//Given a Tic-Tac-Toe board as a string array board, return true if and only if 
//it is possible to reach this board position during the course of a valid tic-tac
//-toe game. 
//
// The board is a 3 x 3 array that consists of characters ' ', 'X', and 'O'. The
// ' ' character represents an empty square. 
//
// Here are the rules of Tic-Tac-Toe: 
//
// 
// Players take turns placing characters into empty squares ' '. 
// The first player always places 'X' characters, while the second player always
// places 'O' characters. 
// 'X' and 'O' characters are always placed into empty squares, never filled one
//s. 
// The game ends when there are three of the same (non-empty) character filling 
//any row, column, or diagonal. 
// The game also ends if all squares are non-empty. 
// No more moves can be played if the game is over. 
// 
//
// 
// Example 1: 
//
// 
//Input: board = ["O  ","   ","   "]
//Output: false
//Explanation: The first player always plays "X".
// 
//
// Example 2: 
//
// 
//Input: board = ["XOX"," X ","   "]
//Output: false
//Explanation: Players take turns making moves.
// 
//
// Example 3: 
//
// 
//Input: board = ["XXX","   ","OOO"]
//Output: false
// 
//
// Example 4: 
//
// 
//Input: board = ["XOX","O O","XOX"]
//Output: true
// 
//
// 
// Constraints: 
//
// 
// board.length == 3 
// board[i].length == 3 
// board[i][j] is either 'X', 'O', or ' '. 
// 
// Related Topics Array String 
// 👍 308 👎 835

#include <cassert>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  bool validTicTacToe(vector<string> &board) {
    auto num_x = 0;
    auto num_o = 0;
    for (auto const &row : board) {
      num_x += count(row.begin(), row.end(), 'X');
      num_o += count(row.begin(), row.end(), 'O');
    }
    if (num_x < num_o || num_o + 1 < num_x) {
      return false;
    }
    auto const &check_if_won = [&](char player) {
      for (auto const &row : board) {
        if (row == string(3, player)) {
          return true;
        }
      }
      for (auto col = 0; col < board[0].size(); col++) {
        auto found = true;
        for (auto const &row : board) {
          if (row[col] != player) {
            found = false;
            break;
          }
        }
        if (found) {
          return true;
        }
      }
      auto found = true;
      for (auto i = 0; i < board.size(); i++) {
        if (board[i][i] != player) {
          found = false;
          break;
        }
      }
      if (found) {
        return true;
      }
      found = true;
      for (auto i = 0; i < board.size(); i++) {
        if (board[i][2 - i] != player) {
          found = false;
          break;
        }
      }
      if (found) {
        return true;
      }
      return false;
    };
    auto const x_wins = check_if_won('X');
    if (x_wins) {
      return num_x == num_o + 1;
    }
    auto const o_wins = check_if_won('O');
    if (o_wins) {
      return num_o == num_x;
    }
    return true;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
  Solution solution;
  vector<string> board{"O  ", "   ", "   "};
  assert(!solution.validTicTacToe(board));
  board = {"XOX", " X ", "   "};
  assert(!solution.validTicTacToe(board));
  board = {"XXX", "   ", "OOO"};
  assert(!solution.validTicTacToe(board));
  board = {"XOX", "O O", "XOX"};
  assert(solution.validTicTacToe(board));
  board = {"XO ", "XO ", "XO "};
  assert(!solution.validTicTacToe(board));
  return 0;
}
