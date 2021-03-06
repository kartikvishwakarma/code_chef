    #include <iostream>
    #include <vector>
    #include <algorithm>
    using namespace std;
     
    const int ALPHABET_SIZE = 26;
     
    // trie node
    struct TrieNode
    {
        struct TrieNode *children[ALPHABET_SIZE];
     
        // isEndOfWord is true if the node represents
        // end of a word
        bool isEndOfWord;
        vector <int> index_list;
        int index;
    };
     
    // Returns new trie node (initialized to NULLs)
    struct TrieNode *getNode(void)
    {
        struct TrieNode *pNode =  new TrieNode;
     
        pNode->isEndOfWord = false;
        pNode->index = -1;
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
            pCrawl->index_list.push_back(ind+1);
        }
     
        // mark last node as leaf
        pCrawl->isEndOfWord = true;
        pCrawl->index = ind+1;
        
    }
    void disp(vector <int> index){
        //vector<int>::iterator it;
        for(int i=0; i<index.size(); i++)
            cout << index[i]<<" ";
        cout<<"\n";
    }
     
    bool inside(vector <int> index, int R){
        //cout<<index.size()<<"\n"
        int max=0;
        for(int i=0; i<index.size(); i++){
            if(index[i] <= R)
                return true;
        }
     
        return false;
    }
     
     
    void search(struct TrieNode *root, string key, int R)
    {   
        string prefix;
        vector<int>::iterator it;
        int index;
        struct TrieNode *pCrawl = root;
        
        for (int i = 0; i < key.length(); i++)
        {
     
            index = key[i] - 'a';
            if ( !pCrawl->children[index]){
                for(int i=0; i<26; i++){
                    if(pCrawl->children[i]){
                       // if( !(pCrawl->isEndOfWord) && pCrawl->index_list[pCrawl->index_list.size()-1] != i)
                            pCrawl = pCrawl->children[i];
                            prefix.push_back('a'+i);
                            break;
                        }
                    }
                }
            }    
                
                //return prefix;
            /*
            */
            pCrawl = pCrawl->children[index];
            prefix.push_back('a'+index);
            disp(pCrawl->index_list);
            /*
            if (!inside(pCrawl->index_list, R) ){
                prefix.resize(prefix.length()-1);
                return prefix;
            }
            */
           
        //cout<<(char)pCrawl->children[index]+'a'<<"\n";
        //return prefix;
        index = 0;


        while ( (pCrawl->isEndOfWord) && pCrawl->index_list[pCrawl->index_list.size()-1] != R){
            for(int i=0; i<26; i++){
                if(pCrawl->children[i]){
                   // if( !(pCrawl->isEndOfWord) && pCrawl->index_list[pCrawl->index_list.size()-1] != i)
                        pCrawl = pCrawl->children[i];
                        prefix.push_back('a'+i);
                        index = i;
                        break;
                }
            }
        }
        cout<<prefix<<endl;
    }
     
     
/*     
    string find(struct TrieNode *root, string key, int R){
        struct TrieNode *pCrawl = root;
        string prefix;
     
        int i, index;
        bool flag = true;
        //int last = key[key.length()] - 'a';
     
        for(i=0; i<key.length(); i++){
            //cout<<key[i]<<" ";
             index = key[i] - 'a';
            pCrawl = pCrawl->children[index];
            prefix.push_back('a'+index);
        }
        //bool flag = true;
        while(flag){
     
            if (pCrawl->isEndOfWord && pCrawl->index <= R)
                break;
            
     
            for(int i=0; i<26; i++){
                if (pCrawl->children[i] && inside(pCrawl->children[i]->index_list, R)){
                //    if (inside(pCrawl->children[i]->index_list, R)){   
                        prefix.push_back('a' + i);
                        pCrawl = pCrawl->children[i];
                        break;
                    }
                //}
            }
        
        }
     
        return prefix;
    }
     
*/
     
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
            search(root, substr, R);
            //prefix =search(root,substr,R);  
            //cout<<"prefix : "<<prefix<<"\n";      
           // cout<<find(root, prefix, R)<<"\n";
            //cout<<"match string : "<<find(root, prefix, R)<<"\n\n";
        }
        
        return 0;
    } 