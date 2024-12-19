/*Leo is trying to move his sofa to different place in his house. The issue is that the house is filled with lot of household items already.

His home will be divided into cells of M rows and N columns like a matrix. The matrix is used to represent the house and the things in it. The current placement of sofa will be represented as "s" and place where the sofa is required will be represented as "S". "H" represents the presence of household items while "0" indicates empty spaces where the Sofa can be moved. The sofa will always occupy two cells and can either move vertically or horizontally. The sofa can be rotated, but the rotation can only occur within a 2*2 area of free cells that includes the sofa. The destination to where the sofa needs to be moved will always be free of household items.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@25f9407e:image1.png

Since sofa is heavy object, it must only be moved and not lifted. Help Leo to find the minimum possible steps required to move the sofa to the required place without altering the positions of other household items. Moving the sofa one cell as well as rotating the sofa are considered as one step.

Constraints
4 < M, N < 25

Input
First line contains two space separated integers representing M, N.

Next M lines contain N space separated characters being either "s", "S", "H" or "0" representing the house's matrix.

Output
Print a single integer representing minimum number of steps required to move the sofa to the required place. Print "Impossible" if it is impossible to move the sofa to the required place.

Time Limit (secs)
1

Examples
Example 1

Input

5 5
s s 0 0 0
0 H 0 0 H
0 H 0 H H
0 H 0 0 H
0 0 0 S S

Output

8

Explanation

The diagram shown in the description depicts the input given

Below diagrams show the movement of sofa to the required place.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@25f9407e:image2.png

After two moves, the sofa occupies a 2x2 area of free cells, allowing it to be rotated. Following this process, the sofa has been moved to its destination in 8 steps, which represents the minimum required.

Example 2

Input

5 5
s s 0 H 0
0 H 0 0 H
0 H 0 H H
0 H 0 0 H
0 0 0 S S

Output

Impossible

Explanation

As you can see it impossible to move the sofa to the required place without rotating and there is not enough place to rotate the sofa, hence print "Impossible".*/

#include <iostream>
#include <vector>
#include <tuple>
#include <set>
#include <algorithm>

using namespace std;

const int dx[] = {0, 1, 0, -1};  // Directions: right, down, left, up
const int dy[] = {1, 0, -1, 0};

// Custom comparator for pairs
struct ComparePairs {
    bool operator()(const tuple<int, int, int, int>& a, const tuple<int, int, int, int>& b) const {
        // Compare first pair element
        if (get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
        if (get<1>(a) != get<1>(b)) return get<1>(a) < get<1>(b);
        // Compare second pair element
        if (get<2>(a) != get<2>(b)) return get<2>(a) < get<2>(b);
        return get<3>(a) < get<3>(b);  // Compare fourth element
    }
};

// Check if a position is valid and within bounds
bool isFree(int x, int y, int M, int N, const vector<vector<char>>& grid) {
    return x >= 0 && y >= 0 && x < M && y < N && (grid[x][y] == '0' || grid[x][y] == 'S');
}

// Function to try moving the sofa in different directions
bool moveSofa(int M, int N, vector<vector<char>>& grid, int x1, int y1, int x2, int y2, int targetX1, int targetY1, int targetX2, int targetY2, set<tuple<int, int, int, int>, ComparePairs>& visited, int steps) {
    if ((x1 == targetX1 && y1 == targetY1 && x2 == targetX2 && y2 == targetY2) || (x1 == targetX2 && y1 == targetY2 && x2 == targetX1 && y2 == targetY1)) {
        return true;  // If the sofa reaches the target position
    }
    
    visited.insert({x1, y1, x2, y2});
    
    // Try moving in all 4 directions
    for (int i = 0; i < 4; i++) {
        int nx1 = x1 + dx[i], ny1 = y1 + dy[i];
        int nx2 = x2 + dx[i], ny2 = y2 + dy[i];
        if (isFree(nx1, ny1, M, N, grid) && isFree(nx2, ny2, M, N, grid) && visited.find({nx1, ny1, nx2, ny2}) == visited.end()) {
            if (moveSofa(M, N, grid, nx1, ny1, nx2, ny2, targetX1, targetY1, targetX2, targetY2, visited, steps + 1)) {
                return true;
            }
        }
    }

    // Try rotating the sofa (only in free space)
    if (x1 == x2) {  // Horizontal to Vertical
        if (isFree(x1 - 1, y1, M, N, grid) && isFree(x1 - 1, y2, M, N, grid) && isFree(x1 + 1, y1, M, N, grid) && isFree(x1 + 1, y2, M, N, grid)) {
            if (moveSofa(M, N, grid, x1, y1, x1 - 1, y1, targetX1, targetY1, targetX2, targetY2, visited, steps + 1)) {
                return true;
            }
        }
    } else {  // Vertical to Horizontal
        if (isFree(x1, y1 + 1, M, N, grid) && isFree(x2, y2 + 1, M, N, grid)) {
            if (moveSofa(M, N, grid, x1, y1, x1, y1 + 1, targetX1, targetY1, targetX2, targetY2, visited, steps + 1)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int M, N;
    cin >> M >> N;
    vector<vector<char>> grid(M, vector<char>(N));
    pair<int, int> start1, start2, target1, target2;

    // Read the grid and find positions of 's' and 'S'
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 's') {
                if (start1.first == 0 && start1.second == 0) start1 = {i, j};
                else start2 = {i, j};
            } else if (grid[i][j] == 'S') {
                if (target1.first == 0 && target1.second == 0) target1 = {i, j};
                else target2 = {i, j};
            }
        }
    }

    // Set to track visited states to prevent cycles
    set<tuple<int, int, int, int>, ComparePairs> visited;

    // Try to find the minimum steps to move the sofa
    bool result = moveSofa(M, N, grid, start1.first, start1.second, start2.first, start2.second, target1.first, target1.second, target2.first, target2.second, visited, 0);

    // Output the result
    if (result) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}
