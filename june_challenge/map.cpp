#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
 
const int ALPHABET_SIZE = 26;
 
// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
 
    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
    vector <int> index;
};
 
// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;
 
    pNode->isEndOfWord = false;
 
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
 
    return pNode;
}
 
// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *root, string key, int ind)
{
    struct TrieNode *pCrawl = root;
 
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
 		pCrawl->index.push_back(ind+1);
        pCrawl = pCrawl->children[index];
    }
 
    // mark last node as leaf
    pCrawl->isEndOfWord = true;
    
}
void disp(vector <int> index){
	//vector<int>::iterator it;
	for(int i=0; i<index.size(); i++)
		cout << index[i]<<" ";
	cout<<"\n";
}
// Returns true if key presents in trie, else
// false
bool look(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
 	cout<<key<<" : ";
 	
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;
 
        pCrawl = pCrawl->children[index];
    }
 
    return (pCrawl != NULL && pCrawl->isEndOfWord);
}
 

string search(struct TrieNode *root, string key, int R)
{	
	string prefix;
	vector<int>::iterator it;

    struct TrieNode *pCrawl = root;
 
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return prefix;
 
        pCrawl = pCrawl->children[index];
        prefix.push_back('a'+index);
       }

    return prefix;
}

string find(struct TrieNode *root, string key, int R){
	struct TrieNode *pCrawl = root;
	string prefix;
	int i;
	for(i=0; i<key.length(); i++){
		//cout<<key[i]<<" ";
		int index = key[i] - 'a';
		pCrawl = pCrawl->children[index];
		prefix.push_back('a'+index);
	}
	while((pCrawl->isEndOfWord) == false){
		for(i=0; i<26; i++){
			if(pCrawl->children[i] ){
				pCrawl = pCrawl->children[i];
				prefix.push_back('a'+i);
				break;
			}
		}
	}
	
	return prefix;
}
int main()
{
    
    int N,R,Q;
    cin>>N;
    string str[N], substr, prefix;

    
    
    for(int i=0; i<N; i++)
        cin>>str[i];

    cin>>Q;
    //find(root, "abcdex", 3);
    
    while(Q--){

    	struct TrieNode *root = getNode();
        cin>>R>>substr;
        for(int i=0; i<R; i++)
        	insert(root, str[i], i);
        //cout<<R<<"\n";
        prefix =search(root,substr,R);        
        //prefix = search(root, prefix,R)
        cout<<find(root, prefix, R)<<"\n";
    }
	
    return 0;
}