#include<bits/stdc++.h>
using namespace std;

set<int> item;
vector< vector<int> > pairs;
int M[2007][2007];
bool visited[2007][2007];
//int ROW;//=2007;
//int COL;//=2007;
 
// A function to check if a given cell (row, col)
// can be included in DFS
int isSafe(int ROW, int COL, int row, int col, int p)
{
    // row number is in range, column number is in
    // range and value is 1 and not yet visited
    return (row >= 0) && (row < ROW) &&
           (col >= 0) && (col < COL) &&
           ((M[row][col]==pairs[p][0] || M[row][col]==pairs[p][1]) && !visited[row][col]);
}
 
// A utility function to do DFS for a 2D boolean
// matrix. It only considers the 8 neighbours as
// adjacent vertices	
void DFS(int ROW, int COL, int row, int col, int &count, int p)
{
    // These arrays are used to get row and column
    // numbers of 8 neighbours of a given cell
    //static int rowNbr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    //static int colNbr[] = {-1, 0, 1, -1, 1, -1, 0, 1};
 	static int rowNbr[] = {-1, 0, 0, 1};
 	static int colNbr[] = {0, -1, 1, 0};
    // Mark this cell as visited
    visited[row][col] = true;
 
    // Recur for all connected neighbours
    //for(int p = 0; p<pairs.size(); p++){
    for (int k = 0; k < 4; ++k)
    {
        if (isSafe(ROW, COL,row + rowNbr[k], col + colNbr[k], p))
        {
            // increment region length by one
            count++;
            DFS(ROW, COL, row + rowNbr[k], col + colNbr[k],count, p);
        }
    }
	//}
}
 
// The main function that returns largest  length region
// of a given boolean 2D matrix
int  largestRegion(int ROW, int COL)
{
    // Make a bool array to mark visited cells.
    // Initially all cells are unvisited
    
    for(int i=0; i<ROW;i++)
    	visited[i][COL] = {0};
 
    // Initialize result as 0 and travesle through the
    // all cells of given matrix
    int result;// = INT_MIN;
    int Max = 0;
    for(int p = 0; p<pairs.size(); p++){
     	result  = INT_MIN;
    for (int i = 0; i < ROW; ++i)
    {
        for (int j = 0; j < COL; ++j)
        {
            // If a cell with value 1 is not
            if ((M[i][j]==pairs[p][0] || M[i][j]==pairs[p][1])&& !visited[i][j])
            {
                // visited yet, then new region found
                int count = 1 ;
                DFS(ROW, COL, i, j, count,p);
 
                // maximum region
                result = max(result , count);
            }
         }
    }

    if (Max < result)
    	Max = result;
	}
	//result = INT_MIN;
    return Max ;
}
 
void combinationUtil(vector<int> arr, int n, int r, int index, int data[], int i)
{
    // Current cobination is ready, print it
    
    if (index == r)
    {
        vector<int> tmp;
        for (int j=0; j<r; j++)
            tmp.push_back(data[j]);
        pairs.push_back(tmp);
        return;
    }
 
    // When no more elements are there to put in data[]
    if (i >= n)
        return;
 
    // current is included, put next at next location
    data[index] = arr[i];
    combinationUtil(arr, n, r, index+1, data, i+1);
 
    // current is excluded, replace it with next (Note that
    // i+1 is passed, but index is not changed)
    combinationUtil(arr, n, r, index, data, i+1);
} 

void printCombination(vector<int> arr, int n, int r)
{
    // A temporary array to store all combination one by one
    int data[r];
 
    // Print all combination using temprary array 'data[]'
    combinationUtil(arr, n, r, 0, data, 0);
}

void disp(map<int, int> M){
	map<int, int>::iterator m;
	for(m = M.begin(); m != M.end(); m++)
		cout<<m->first<<" "<<m->second<<"\n";
	cout<<"\n";
}

void show(){
	for(int i=0; i<pairs.size(); i++)
		cout<<pairs[i][0]<<", "<<pairs[i][1]<<"\n";
}
// Driver program to test above function
int main()
{
	int ROW, COL;
	/*
	ROW = 4; COL = 5;
    M[ROW][COL] = { {0, 0, 1, 1, 0},
                     {1, 0, 1, 1, 0},
                     {0, 1, 0, 0, 0},
                     {0, 0, 0, 0, 1}};
 	*/
 	map<int, int> freq;
 	cin>>ROW>>COL;
 	for(int i=0;i<ROW; i++){
 		for(int j=0; j<COL; j++){
 			cin>>M[i][j];
 			//cout<<M[i][j]<<" ";
 			item.insert(M[i][j]);
 			freq[M[i][j]]++;
 		}
 	}
 	vector<int> num;
 	set<int>::iterator it;
 	map<int, int>::iterator itm;


 	//disp(freq);
 	int max = INT_MIN;
 	int min = INT_MAX;

 	for(itm = freq.begin(); itm != freq.end(); itm++){
 		if (freq[itm->first] > max){
 			max = freq[itm->first];
 		}
 		if(freq[itm->first] < min)
 			min = freq[itm->first];
 	}
 	//cout<<min<<" "<<max<<"\n";
 	
 	if (max == min){
 		vector<int> tmp;
 		itm = freq.begin();
 		tmp.push_back(itm->first);
 		itm++ ;
 		tmp.push_back(itm->first);
 		pairs.push_back(tmp);
 		//cout<<"if part\n";
 	}


 	else{
 		//cout<<"else  part\n";
	 	for(it = item.begin(); it != item.end(); it++){
	 		if (freq[*it] > 1)
	 			num.push_back(*it);
	 	}

	 	printCombination(num,num.size(),2);
   	}//show();
    cout << largestRegion(ROW, COL)<<"\n";
 	
    return 0;
}