#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <iterator>

using namespace std;

void disp(set<int> Set){
	set<int>::iterator it;

	for(it = Set.begin(); it != Set.end(); it++)
		cout<<*it<<" ";
	cout<<"\n";
}

void disp_m(map<int, int>Map){
	map<int, int>::iterator it;
	for(it = Map.begin(); it != Map.end(); it++){
		cout<<it->first<<" - "<<it->second<<" | ";
	}
	cout<<"\n";
}

int max_of(map<int, int> Map){
	map<int, int>::iterator it;
	int max = 0;
	for(it = Map.begin(); it != Map.end(); it++){
		if (it->second > max)
			max = it->second;
	}
	return max;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main(int argc, char const *argv[])
{
	bool up, left, diag;
	int n,m;
	cin>>n>>m;
	int a[n][m];
	set<int> flowers;
	map<int,int> counter;

	set<int>::iterator its;
	vector<int>::iterator itv;
	map<int,int>::iterator itm;

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>a[i][j];
			flowers.insert(a[i][j]);
		}
	}

	for(its = flowers.begin(); its != flowers.end(); its++){
		counter[*its] = 0;
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if (!counter[a[i][j]])
				counter[a[i][j]]++;
			else {
				up = (i-1 >=0) && (a[i][j] == a[i-1][j]);
				left = (j-1 >=0) && (a[i][j] == a[i][j-1]);
				diag = (i-1 >=0) && (j-1 >=0) && (a[i][j] == a[i-1][j-1]);

				if(up || left || diag)
					counter[a[i][j]]++;
			}
		}
	}

	int max = 0;
	int min = 0;
	int max_key;
	int min_key;
	int second_max = 0;
	for(itm = counter.begin(); itm != counter.end(); itm++){
		if (max < itm->second){
			max = itm->second;
			max_key = itm->first;
		}
		if (min > itm->second){
			min = itm->second;
			min_key = itm->first;
		}

		//cout<<itm->first<<" : "<<itm->second<<"\n";
	}

	if (max == min){
		itm = counter.begin()
		int e1 = itm->first;
		itm = counter.begin()+1
		int e2 = itm->second;
	}

	if (max > (n*m)/2){
		cout<<max<<"\n";
		return 0;
	}
	else{
		heapSort(counter, counter.size())
	}
	/*
	for(itm = counter.begin(); itm != counter.end(); itm++){
		if (second_max < itm->second && itm->second < max)
			second_max = itm->second;
		//cout<<itm->first<<" : "<<itm->second<<"\n";
	}
	//cout<<max<<" : "<<second_max<<"\n";

	vector<int> max_flower, second_max_flower;

	for(itm = counter.begin(); itm != counter.end(); itm++){
		if (itm->second == max)
			max_flower.push_back(itm->first);
		if (itm->second == second_max)
			second_max_flower.push_back(itm->first);
	}
	

	max = 0;
	*/
	//counter.clear();
	for(itv = second_max_flower.begin(); itv != second_max_flower.end(); itv++){
		flowers.clear();
		flowers.insert(max_key);
		flowers.insert(*itv);
		//disp(flowers);
		counter.clear();
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				
				its = flowers.find(a[i][j]);
				if (its != flowers.end()){
					up = (i-1 >=0) && (flowers.find(a[i-1][j]) != flowers.end() );
					left = (j-1 >=0) && (flowers.find(a[i][j-1]) != flowers.end());
					diag = (i-1 >=0) && (j-1 >=0) && (flowers.find(a[i-1][j-1]) != flowers.end());

					if (up || left || diag){
						counter[max_key]++;
						counter[*itv]++;
					}
	
					
				}
				
			}

		}
		disp_m(counter);
		if (max < counter[max_key])
			max = counter[max_key];		

	}

	cout<<max<<"\n";
	//cout<<	max_of(counter)<<"\n";


	return 0;
} 