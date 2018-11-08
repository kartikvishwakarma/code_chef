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
    int index;
    int length;
};
 
// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;
 
    pNode->isEndOfWord = false;
    pNode->index = -1;
    pNode->length = 0;
 
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
    int len = 0;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
 		//pCrawl->index.push_back(ind+1);
        pCrawl = pCrawl->children[index];
        len++;
    }
 
    // mark last node as leaf
    pCrawl->isEndOfWord = true;
    pCrawl->index = ind+1;
    pCrawl->length = len;
    
}
void disp(vector <int> index){
	//vector<int>::iterator it;
	for(int i=0; i<index.size(); i++)
		cout << index[i]<<" ";
	cout<<"\n";
}
// Returns true if key presents in trie, else
// false


string search(struct TrieNode *root, string key, int R)
{	
	string prefix;
	vector<int>::iterator it;

    struct TrieNode *pCrawl = root;
 
    for (int i = 0; i < key.length(); i++)
    {

        int index = key[i] - 'a';
        if ( (!pCrawl->children[index]) || (pCrawl->children[index]->index > R) ){// || pCrawl->isEndOfWord)
            cout<<pCrawl->length<<"\n";
            return prefix;
        }
        
        pCrawl = pCrawl->children[index];
        prefix.push_back('a'+index);
        /*
        if(pCrawl->length < prefix.length()){
            prefix.resize(prefix.length()-1);
            return prefix;
        }
        */
        
    }
    cout<<pCrawl->length<<"\n";
    return prefix;
}

bool isLeaf(struct TrieNode* node){
    for(int i=0; i<26; i++){
        if(node->children[i])
            return false;
    }
    return true;
}

string find(struct TrieNode *root, string key, int R){
	struct TrieNode *pCrawl = root;
	string prefix;
	vector<int>::iterator itr;
	int i;
	for(i=0; i<key.length(); i++){
		//cout<<key[i]<<" ";
		int index = key[i] - 'a';
		pCrawl = pCrawl->children[index];
		prefix.push_back('a'+index);
	}
	//cout<<prefix<<"\n";
    if(pCrawl->isEndOfWord ){
        if(pCrawl->index <= R)
            return prefix;
        else
            while(!isLeaf(pCrawl) && pCrawl->index > R){
                for(i=0; i<26; i++){
            

                if(pCrawl->children[i] ){//&& itr != pCrawl->index.end()){
                    pCrawl = pCrawl->children[i];
                    prefix.push_back('a'+i);
                    break;
                }
            }
        }

    }
    else{
    	while((pCrawl->isEndOfWord) == false && pCrawl->index <= R){
    		for(i=0; i<26; i++){

    			if(pCrawl->children[i] ){//&& itr != pCrawl->index.end()){
    				pCrawl = pCrawl->children[i];
    				prefix.push_back('a'+i);
    				break;
    			}
    		}
    	}
	}
	return prefix;
}
int main()
{
    
    int N,R,Q;
    cin>>N;
    string str, substr, prefix;

    struct TrieNode *root = getNode();

    
    for(int i=0; i<N; i++){
        cin>>str;
        insert(root, str, i);
        
    }

    cin>>Q;
    //find(root, "abcdex", 3);
    
    while(Q--){

        cin>>R>>substr;
        prefix =search(root,substr,R);  
        cout<<prefix<<"\n";      
        //cout<<find(root, prefix, R)<<"\n";
    }
	
    return 0;
}