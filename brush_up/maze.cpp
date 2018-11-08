#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
#define ROW 4
#define COL 5
#define Sx 0
#define Sy 0

#define Ex 3
#define Ey 4
using namespace std;

bool isSafe(int A[][COL], bool visited[][COL], int row, int col){
	return (row>=0 && row<ROW 
		&& col>=0 && col<COL 
		&& A[row][col] 
		&& !visited[row][col]);
}

bool isFinished(int A[][COL], int i, int j){
	if(A[i][j] && i==ROW)
		return true;
	return false;
}


void DFS(int A[][COL], bool visited[][COL], int row, int col, int &count){
	visited[row][col] = true;

	static int rowNbr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int colNbr[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for(int k = 0; k<8; k++){
    	if (row+rowNbr[k] == Ex && col+colNbr[k] == Ey && A[Ex][Ey])
    		printf("yes\n");
    		//return true;

    	if(isSafe(A, visited, row+rowNbr[k], col+colNbr[k])){
    		count++;
    		DFS(A, visited, row+rowNbr[k], col+colNbr[k], count);

    	}
    }
}

void  largestRegion(int A[][COL]){
	bool visited[ROW][COL];
	memset(visited, false, sizeof(visited));
	int count;
	int ans = INT_MIN;

	DFS(A, visited, Sx, Sy, count);
	
	ans = max(ans, count);
			
}

int main(int argc, char const *argv[])
{
	int A[][COL] = { {0, 0, 1, 1, 0},
                     {1, 0, 1, 1, 0},
                     {0, 1, 0, 0, 0},
                     {0 ,0, 0, 0, 1}};

 	
 	largestRegion(A);
 	//printf("%d\n", ans);
	return 0;
}