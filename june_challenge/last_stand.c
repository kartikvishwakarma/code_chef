#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//const int ALPHABET_SIZE = 26;
 
// trie node
struct TrieNode
{
    struct TrieNode *children[26];
 
    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
    int index_list[10];
    int index;
};
 
// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  (struct TrieNode*) malloc(sizeof(struct TrieNode));
 	//*(pNode->children) = (struct TrieNode*) malloc(sizeof(struct TrieNode)*26);
    pNode->isEndOfWord = false;
    pNode->index = -1;
    for (int i = 0; i < 26; i++)
        pNode->children[i] = NULL;
    
    return pNode;
}

void insert(struct TrieNode *root, char key[], int ind)
{
    struct TrieNode *pCrawl = root;
    int len = 0;
    int count = 0;
    //printf("%d\n", strlen(key)-1);
    
    for (int i = 0; i < strlen(key)-1; i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
 		//pCrawl->index.push_back(ind+1);
        pCrawl = pCrawl->children[index];
        pCrawl->index_list[count] = ind+1;
        count++;
    }
 
    // mark last node as leaf
    pCrawl->isEndOfWord = true;
    pCrawl->index = ind+1;
    
}



int main()
{
    
    int N,R,Q;
    char str[10], substr[10], prefix[10];

    struct TrieNode *root = getNode();
    scanf("%d\n", &N);
    
    for(int i=0; i<N; i++){
        fgets(str, 10, stdin);
        insert(root, str, i);
        //printf("%s   %d", str, strlen(str));
    }

    return 0;
}