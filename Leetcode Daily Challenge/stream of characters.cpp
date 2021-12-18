class trie {
    public:
    trie* children[26];
    bool endsHere;
    trie() {
        for(int i=0; i<26; i++) children[i] = NULL;
        endsHere = false;
    }
    void add(string &word) {
        trie *temp = this;
        for(int i=0; i<word.length(); i++) {
            int pos = word[i]-'a';
            if(temp->children[pos]==NULL) {
                temp->children[pos] = new trie();
            }
            temp = temp->children[pos];
        }    
        temp->endsHere = true;
    }
};

class StreamChecker {
public:
    trie *head = new trie();
    queue<trie*> q;
    StreamChecker(vector<string>& words) {
        for(string &i: words) head->add(i);
    }
    
    bool query(char letter) {
        q.push(head);
        int size = q.size();
        int pos = letter-'a';
        bool flag = false;
        while(size--) {
            trie *temp = q.front();
            q.pop();
            if(temp->children[pos]) {
                temp = temp->children[pos];
                q.push(temp);
                flag |= temp->endsHere;
            }
        }
        return flag;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
