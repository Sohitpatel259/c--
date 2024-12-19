/* 
In the mysterious island named Reflectia, there's a grid made up of M rows and N columns. Some cells in this grid are empty, while others hold mirrors which are placed diagonally to the cells. These mirrors are the reason why the island is called Reflectia - they bounce light beams in the opposite direction when the light hits them. The mirrors are placed in two ways viz. slanted forward (/) or slanted backwards (\).

Rohit, a curious young explorer, decided to explore the Matrix with a flashlight in his hand as the island is very dark and is rumoured to be haunted. Once he entered, he aimed to find out the maximum number of cells the light could travel to, making a closed loop, within the grid when it is bounced on one of the mirrors in the grid. As it was too dark, he noted the structure of the grid and came out.

Given the structure of the grid that Rohit noted, find out what's the maximum number of cells the light could travel to, making a closed loop [a closed polygon shape], within the grid when it is bounced on one of the mirrors in the grid.

Constraints
3 < M, N < 50

Input
First line contains two integers separated by space, representing M and N.

Next M Lines contains N space separated characters viz. {'/', '\', '0'} representing the grid structure.

Output
Single integer representing the maximum number of cells that can be covered in the loop formed by the reflected light beam.

Time Limit (secs)
1

Examples
Example 1

Input

5 5

/ / 0 0 \

0 0 0 / 0

0 \ 0 0 /

\ / \ / 0

0 0 \ \ \

Output

10

Explanation

The below diagram depicts the input.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@bc57b40:image1.png

The mirror at indices [1,2], [1,5], [3,2] and [3,5] can form a loop covering 10 cells, which is the maximum possible.

Example 2

Input

6 6

0 0 0 0 / \

/ 0 / 0 / 0

0 \ 0 \ / 0

0 / \ \ / 0

0 / \ / 0 0

0 0 / \ 0 /

Output

0

Explanation

The below diagram depicts the input.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@bc57b40:image2.png

We cannot form any loop inside the given grid. Hence, print 0.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <tuple>

using namespace std;

// Directions for up, right, down, and left
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

// Function to simulate the light's movement
int findLoop(int M, int N, vector<vector<char>>& grid, int startX, int startY, int startDir) {
    vector<vector<vector<bool>>> visited(M, vector<vector<bool>>(N, vector<bool>(4, false)));  // Visited cells with direction
    
    int x = startX, y = startY, dir = startDir;
    int stepCount = 0;
    
    while (true) {
        if (x < 0 || y < 0 || x >= M || y >= N) {
            return 0;  // Out of bounds, no loop
        }
        if (visited[x][y][dir]) {
            return stepCount;  // Cycle found, return the size of the loop
        }
        
        visited[x][y][dir] = true;
        stepCount++;
        
        // Move according to the current direction and mirror
        if (grid[x][y] == '/') {
            // Reflect light based on the mirror '/'
            if (dir == 0) dir = 1;  // up -> right
            else if (dir == 1) dir = 0;  // right -> up
            else if (dir == 2) dir = 3;  // down -> left
            else if (dir == 3) dir = 2;  // left -> down
        } else if (grid[x][y] == '\\') {
            // Reflect light based on the mirror '\'
            if (dir == 0) dir = 3;  // up -> left
            else if (dir == 1) dir = 2;  // right -> down
            else if (dir == 2) dir = 1;  // down -> right
            else if (dir == 3) dir = 0;  // left -> up
        }
        
        // Move in the current direction
        x += dx[dir];
        y += dy[dir];
    }
}

int main() {
    int M, N;
    cin >> M >> N;
    
    vector<vector<char>> grid(M, vector<char>(N));
    
    // Read the grid
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    
    int maxLoopSize = 0;
    
    // Try starting from each possible cell in the grid
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] != '0') {  // Only start from mirror cells
                // Try all 4 possible initial directions: up (0), right (1), down (2), left (3)
                for (int dir = 0; dir < 4; dir++) {
                    int loopSize = findLoop(M, N, grid, i, j, dir);
                    maxLoopSize = max(maxLoopSize, loopSize);
                }
            }
        }
    }
    
    cout << maxLoopSize << endl;
    return 0;
}
