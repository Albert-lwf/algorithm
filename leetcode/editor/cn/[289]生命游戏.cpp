//根据 百度百科 ，生命游戏，简称为生命，是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机。 
//
// 给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞都具有一个初始状态：1 即为活细胞（live），或 0 即为死细胞（dea
//d）。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律： 
//
// 
// 如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡； 
// 如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活； 
// 如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡； 
// 如果死细胞周围正好有三个活细胞，则该位置死细胞复活； 
// 
//
// 根据当前状态，写一个函数来计算面板上所有细胞的下一个（一次更新后的）状态。下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生
//和死亡是同时发生的。 
//
// 
//
// 示例： 
//
// 输入： 
//[
//  [0,1,0],
//  [0,0,1],
//  [1,1,1],
//  [0,0,0]
//]
//输出：
//[
//  [0,0,0],
//  [1,0,1],
//  [0,1,1],
//  [0,1,0]
//] 
//
// 
//
// 进阶： 
//
// 
// 你可以使用原地算法解决本题吗？请注意，面板上所有格子需要同时被更新：你不能先更新某些格子，然后使用它们的更新后的值再更新其他格子。 
// 本题中，我们使用二维数组来表示面板。原则上，面板是无限的，但当活细胞侵占了面板边界时会造成问题。你将如何解决这些问题？ 
// 
// Related Topics 数组 
// 👍 260 👎 0
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/*
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int neighbors[3] = {0,1,-1};
        int rows = board.size();
        int cols = board[0].size();

        vector<vector<int>>copyBoard(rows, vector<int>(cols, 0));
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                copyBoard[i][j] = board[i][j];
            }
        }

        for(int row=0; row<rows; row++){
            for(int col=0; col<cols; col++){
                int liveNeighbors = 0;

                for(int i=0; i<3; i++){
                    for(int j=0; j<3; j++){

                        if (!(neighbors[i] == 0 && neighbors[j] == 0)){
                            int r = (row + neighbors[i]);
                            int c = (col + neighbors[j]);

                            // 查看相邻的细胞是否是活细胞
                            if ((r < rows && r >= 0) && (c < cols && c >= 0) && (copyBoard[r][c] == 1)){
                                liveNeighbors += 1;
                            }
                        }
                    }
                }
                // 规则 1 或规则 3
                if ((copyBoard[row][col] == 1) && (liveNeighbors < 2 || liveNeighbors > 3)){
                    board[row][col] = 0;
                }
                // 规则 4
                if (copyBoard[row][col] == 0 && liveNeighbors == 3){
                    board[row][col] = 1;
                }
            }
        }
    }
};
*/

// 根据数组的细胞状态计算新一轮的细胞状态，这里会用到能同时代表过去状态和现在状态的复合状态
/*
 * 规则1   1 => -1
 * 规则2   1 => 1
 * 规则3   1 => -1
 * 规则4   0 => 2
 * */
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int neighbors[3] = {0,1,-1};
        int rows = board.size();
        int cols = board[0].size();

        for(int row=0; row<rows; row++){
            for(int col=0; col<cols; col++){
                int liveNeighbors = 0;

                for(int i=0; i<3; i++){
                    for(int j=0; j<3; j++){

                        if (!(neighbors[i] == 0 && neighbors[j] == 0)){
                            int r = (row + neighbors[i]);
                            int c = (col + neighbors[j]);

                            // 查看相邻的细胞是否是活细胞
                            if ((r < rows && r >= 0) && (c < cols && c >= 0) && (abs(board[r][c]) == 1)){
                                liveNeighbors += 1;
                            }
                        }
                    }
                }
                // 规则 1 或规则 3
                if ((board[row][col] == 1) && (liveNeighbors < 2 || liveNeighbors > 3)){
                    // -1 代表这个细胞过去是活的现在死了
                    board[row][col] = -1;
                }
                // 规则 4
                if (board[row][col] == 0 && liveNeighbors == 3){
                    // 2 代表这个细胞过去是死的现在活了
                    board[row][col] = 2;
                }
            }
        }

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (board[row][col] > 0) board[row][col] = 1;
                else board[row][col] = 0;
            }
        }
    }
};

//leetcode submit region end(Prohibit modification and deletion)
vector<vector<int>>result(){
    vector<vector<int> > board({
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 0}
    });
    Solution s;
    s.gameOfLife(board);
    return board;
}