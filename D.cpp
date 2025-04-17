#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

class Piece {
public:
    char type;
    Piece(char c) {
        this->type = c;
    }
};

class Hexapawn {
private:
    vector<vector<Piece>> board;
    vector<vector<int>> wDirs = {{-1, 0}, {-1, -1}, {-1, 1}};
    vector<vector<int>> bDirs = {{1, 0}, {1, -1}, {1, 1}};

public:
    Hexapawn(int n) : board(3, vector<Piece>(n, Piece('.'))) {
        for (int j = 0; j < board[0].size(); j++) {
            board[0][j].type = 'B';
            board[2][j].type = 'W';
        }
    }

    void printBoard() {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                cout << board[i][j].type << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    char changeTurn(char turn) {
        return (turn == 'B') ? 'W' : 'B';
    }

    bool outOfBounds(int x, int y) {
        return (x < 0 || x >= board.size() || y < 0 || y >= board[0].size());
    }

    vector<pair<int, int>> findMoves(Piece piece, int i, int j) {
        vector<pair<int, int>> moves;
        if (piece.type == 'W') {
            for (int k = 0; k < wDirs.size(); k++) {
                int x = i + wDirs[k][0];
                int y = j + wDirs[k][1];
                if (outOfBounds(x, y)) continue;

                if (k == 0 && board[x][y].type == '.') moves.push_back({x, y});
                else if (k > 0 && board[x][y].type == 'B') moves.push_back({x, y});
            }
        } else if (piece.type == 'B') {
            for (int k = 0; k < bDirs.size(); k++) {
                int x = i + bDirs[k][0];
                int y = j + bDirs[k][1];
                if (outOfBounds(x, y)) continue;

                if (k == 0 && board[x][y].type == '.') moves.push_back({x, y});
                else if (k > 0 && board[x][y].type == 'W') moves.push_back({x, y});
            }
        }
        return moves;
    }

    int calcEval(char turn) {
        // Check win by reaching end row
        for (int j = 0; j < board[0].size(); j++) {
            if (board[0][j].type == 'W') return 1;
            if (board[2][j].type == 'B') return -1;
        }

        // Check if current player has any moves
        bool hasMoves = false;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j].type == turn && !findMoves(board[i][j], i, j).empty()) {
                    hasMoves = true;
                    break;
                }
            }
        }

        if (!hasMoves) {
            return (turn == 'W') ? -1 : 1;
        }

        return 0;
    }

    int minimax(char turn, int alpha, int beta) {
        int result = calcEval(turn);
        if (result != 0) return result;

        if (turn == 'W') {
            int maxEval = INT_MIN;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < board[0].size(); j++) {
                    if (board[i][j].type != 'W') continue;

                    auto moves = findMoves(board[i][j], i, j);
                    for (auto [x, y] : moves) {
                        char captured = board[x][y].type;

                        board[i][j].type = '.';
                        board[x][y].type = 'W';

                        int val = minimax('B', alpha, beta);
                        maxEval = max(maxEval, val);
                        alpha = max(alpha, val);

                        board[i][j].type = 'W';
                        board[x][y].type = captured;

                        if (beta <= alpha) return maxEval;
                    }
                }
            }
            return maxEval;
        } else {
            int minEval = INT_MAX;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < board[0].size(); j++) {
                    if (board[i][j].type != 'B') continue;

                    auto moves = findMoves(board[i][j], i, j);
                    for (auto [x, y] : moves) {
                        char captured = board[x][y].type;

                        board[i][j].type = '.';
                        board[x][y].type = 'B';

                        int val = minimax('W', alpha, beta);
                        minEval = min(minEval, val);
                        beta = min(beta, val);

                        board[i][j].type = 'B';
                        board[x][y].type = captured;

                        if (beta <= alpha) return minEval;
                    }
                }
            }
            return minEval;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    Hexapawn obj(n);
    auto curr = chrono::high_resolution_clock::now();

    int result = obj.minimax('W', INT_MIN, INT_MAX);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> time = end - curr;

    cout << "time taken: " << time.count() << " seconds" endl;
    cout << (result == 1 ? "White" : "Black") << endl;

    return 0;
}
