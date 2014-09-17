# CS141 Extra Crediti Project Documentation

## Algorithm Design

In the first stage, the algorithm uses dynamic programming to find the size of the largest square in the m by n circuit board B. We define T(i, j) to be the size of the square who's bottom right corner is the point (i, j), where i is the row and j is the column. We can see a clear recursive definition of T(i,j): if the square above, to the left, and diagonally up and left of it are filled, then the square at that point is of size one plus the smallest of those 3. The recurrence relation for the algorithm is as follows:

* T(i,j) = 0						if B[i,j] = 0
* T(i,j) = 1						if i or j = 0 and B[i,j] = 1
* T(i,j) = 1 + min(T(i-1,j-1), T(i, j-1), T(i-1,j))	otherwise

In the second stage, in order to maximize the size of the largest square not overlapping the largest, we must evaluate each instance of the largest size square and select the largest among squares that do not overlap it. 


The time taken for the first stage is O(mn), because we must compute a value for each cell in the dynamic programming table. In the second stage we do an O(mn) scan of the table for each instance of the largest square. This dominates the cost of the initial dynamic programming procedure. So, for a board with K instances of the largest square, the overall complexity is O(Kmn). 

Space complexity is O(mn), since both the initial board and the dynamic programming table are stored in an m by n vector<vector<int>> 


## Implementation

In order to store the table, I implemented a basic matrix class called Board, which encapsulates a vector of int vectors, and provides an interface to access individual cells and print cell contents. I originally used a vector of bool vectors, because the STL optimizes these containers for speed, but eventually opted for an implementation with int so that I could do the dynamic programming procedure in place, without having to compute results in a new vector of vectors that might be 1000 by 1000. 

While the dynamic programming is running, I keep a variable that stores the value of the largest square encounterd so far. With that result handy, I do a scan of the table just calculated and record the coordinates of every square with that value. From here, the procedure diverges into three cases.

1. if there is only one instance of the largest square, I simply find an instance of the second largest square that does not overlap it, and return that result. 

2. if there is more than one instance of the largest square, and two of those intances do not overlap, then both the largest and the second largest have the same size and that result is returned. 

3. if there is more than one instance of the largest square, and all of them happen to overlap, then I do a scan of the dynamic programming table for each, and store the largest non-overlapping square seen so far


In the code, the three cases are handled in the same nested for loop, which terminates early if the second largest value ever equals the maximum value. 
