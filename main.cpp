#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class NQueenSolver {
public:
    explicit NQueenSolver(int n)
        : n_(n),
          placement_(n, 0),
          columns_(n, false),
          diag1_(2 * n - 1, false),
          diag2_(2 * n - 1, false) {}

    vector<vector<int>> solve() {
        backtrack(0);
        return solutions_;
    }

private:
    int n_;
    vector<int> placement_;
    vector<bool> columns_;
    vector<bool> diag1_;
    vector<bool> diag2_;
    vector<vector<int>> solutions_;

    void backtrack(int row) {
        if (row == n_) {
            solutions_.push_back(placement_);
            return;
        }

        for (int col = 0; col < n_; ++col) {
            int d1 = row - col + n_ - 1;
            int d2 = row + col;

            if (columns_[col] || diag1_[d1] || diag2_[d2]) {
                continue;
            }

            placement_[row] = col + 1;
            columns_[col] = true;
            diag1_[d1] = true;
            diag2_[d2] = true;

            backtrack(row + 1);

            columns_[col] = false;
            diag1_[d1] = false;
            diag2_[d2] = false;
        }
    }
};

void printSolutions(ofstream& output, const vector<vector<int>>& solutions) {
    output << '[';
    for (size_t i = 0; i < solutions.size(); ++i) {
        if (i > 0) {
            output << ", ";
        }

        output << '[';
        for (size_t j = 0; j < solutions[i].size(); ++j) {
            if (j > 0) {
                output << ", ";
            }
            output << solutions[i][j];
        }
        output << ']';
    }
    output << "]\n";
}

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt", ios::binary);

    int n = 0;
    if (!(input >> n) || n < 1) {
        output << "[]\n";
        return 0;
    }

    NQueenSolver solver(n);
    printSolutions(output, solver.solve());

    return 0;
}
