#include<bits/stdc++.h>
using namespace std;

set<int> item;
vector< vector<int> > pairs;
int M[2007][2007];
bool visited[2007][2007];

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

void show(){
    for(int i=0; i<pairs.size(); i++)
        cout<<pairs[i][0]<<", "<<pairs[i][1]<<"\n";
}

struct Node{
    int x,y;
    int freq;
};

vector<Node> node;

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

    bool left, right, up, down;

    for(int i=0;i<ROW; i++){
        for(int j=0; j<COL; j++){
            left = j-1>=0;
            right = j+1 >COL;
            up = i-1>=0;
            down = i+1>ROW;

            if (!left && down && right && !up){
                if (ispair())

            }
            else if (left && down && right && !up){

            }
            else if (!left && down && right && up){

            }
            else if (left && down && right && up){

            }
            else if (left && down && !right && !up){

            }
            else if (left && down && !right && up){

            }
            else if (!left && !down && right && up){

            }
            else if (left && !down && !right && up){

            } 


        }
    }
    
 	vector<int> num;
 	set<int>::iterator it;

 	//disp(freq);
 	for(it = item.begin(); it != item.end(); it++){
 			num.push_back(*it);
 	}

 	printCombination(num,num.size(),2);
   	show();
    //cout << largestRegion(ROW, COL)<<"\n";
 	
    return 0;
}