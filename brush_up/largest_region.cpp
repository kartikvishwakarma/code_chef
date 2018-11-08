#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
#define ROW 4
#define COL 5

using namespace std;

bool iSafe(int A[][COL], bool visited[][COL], int i, int j){
	return (i>=0 && i<ROW && j>=0 && j<COL && !visited[i][j] && A[i][j]);
}

bool finished(int A[][COL], int i, int j){
	if(A[i][j] && i==ROW)
		return true;
	return false;
}

int DFS(int A[][COL], bool visited[][COL], int row, int col, int &count){
	
	visited[row][col] = true;
	static int rowNbr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int colNbr[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for(int i=0; i<8;i++){
    	if(iSafe(A,visited, rowNbr[i]+row, colNbr[i]+col)){
    		count++;
    		DFS(A, visited, rowNbr[i]+row, colNbr[i]+col, count);
    	}
    }
}

int largestRegion(int A[][COL]){
	bool visited[ROW][COL];
	memset(visited, false, sizeof(visited));

	int count;
	int res=INT_MIN;

	for(int i=0; i<ROW; i++){
		for(int j=0; j<COL; j++){
			if(A[i][j] && !visited[i][j]){
				count = 1;
				//visited[i][j]=true;
				DFS(A,visited, i,j,count);
				res = max(res, count);
			}
		}
	}
	return res;
}


int main(int argc, char const *argv[])
{
	/* code */
	int A[][COL] = { {0, 0, 1, 1, 0},
                     {1, 0, 1, 1, 0},
                     {0, 1, 0, 0, 0},
                     {0, 0, 0, 0, 1}};
 	printf("%d\n",largestRegion(A));
	return 0;
}