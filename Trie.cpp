#include <bits/stdc++.h>
using namespace std;

// only lower case alphabets allowed
const int alpha_size = 26;

class TrieNode
{
    vector<TrieNode *> v;
    bool isEndofWord;

public:
    TrieNode();
    friend class Trie;
};

TrieNode ::TrieNode()
{
    v.resize(alpha_size, NULL);
    isEndofWord = false;
}


class Trie
{
    TrieNode *root;
    bool isLeaf(TrieNode *);
    void displayTrie(TrieNode *, string);
    bool searchTrie(string);
    bool deleteTrie(TrieNode *&, string, int);

public:
    Trie();
    bool Insert();
    void Search();
    void Display();
    void Delete();
};

Trie ::Trie()
{
    root = new TrieNode();
    for (int i = 0; i < alpha_size; i++)
        root->v[i] = NULL;
}

bool Trie ::isLeaf(TrieNode *node)
{

    for (int i = 0; i < alpha_size; i++)
    {
        if (node->v[i])
            return 0;
    }
    return 1;
}

bool Trie ::Insert()
{
    string s = "";
    cout<<"Enter the word to be inserted : \n";
    cin>>s;

    TrieNode *node = root;
    int l = s.length();
    for (int i = 0; i < l; i++)
    {
        if (node->v[s[i] - 'a'] == NULL)
        {
            TrieNode *newNode = new TrieNode();
            node->v[s[i] - 'a'] = newNode;
        }
        node = node->v[s[i] - 'a'];
    }
    // word already present
    if (node->isEndofWord)
        return false;
    node->isEndofWord = true;
    return true;
}

bool Trie ::searchTrie(string s)
{
    TrieNode *node = root;
    int l = s.length();
    int k = 0;
    while (k < l)
    {
        if (node->v[s[k] - 'a'] != NULL)
        {
            node = node->v[s[k] - 'a'];
        }
        else
        {
            return false;
        }
        k++;
    }
    // word is present
    if (node->isEndofWord)
        return true;
    return false;
}

void Trie ::Search()
{
    if (isLeaf(root))
    {
        cout << "The Trie is empty!\n";
        return;
    }

    string s = "";
    cout<<"Enter the word to be searched : \n";
    cin>>s;

    if (searchTrie(s))
    {
        cout << s << " -> Item Found!\n";
    }
    else
    {
        cout << s << " -> Not Found!\n";
    }
    return;
}

bool Trie ::deleteTrie(TrieNode *&node, string s, int ind)
{
    if (ind > s.length() || !node)
    {
        return false;
    }
    if (ind == s.length())
    {
        if (!node->isEndofWord)
            return false;
        node->isEndofWord = false;
        if (isLeaf(node))
        {
            node = NULL;
            delete node;
        }
        return true;
    }
    if (!node->v[s[ind] - 'a'])
    {
        return false;
    }
    bool ans = deleteTrie(node->v[s[ind] - 'a'], s, ind + 1);
    if (isLeaf(node))
    {
        node = NULL;
        delete node;
    }
    return ans;
}

void Trie ::Delete()
{
    if (isLeaf(root))
    {
        cout << "The Trie is empty!\n";
        return;
    }

    string s = "";
    cout<<"Enter the word to be deleted : \n";
    cin>>s;

    if (deleteTrie(root, s, 0))
    {
        cout << s << " -> Deletion Successful!\n";
    }
    else
    {
        cout << s << " -> Not Found!\n";
    }
    return;
}

void Trie ::displayTrie(TrieNode *node, string s)
{

    if (node->isEndofWord)
    {
        cout << s << endl;
    }

    for (int i = 0; i < alpha_size; i++)
    {
        if (node->v[i])
        {
            s += (i + 'a');
            displayTrie(node->v[i], s);
            s.pop_back();
        }
    }
}

void Trie ::Display()
{
    if (isLeaf(root))
    {
        cout << "The Trie is empty!\n";
        return;
    }
    displayTrie(root, "");
}

int main()
{
    Trie trie;
    // trie.Insert("nikita");
    // trie.Insert("nikki");
    // trie.Insert("niki");
    // trie.Insert("mok");
    // trie.Display();
    // trie.Search("mok");
    // trie.Search("nikki");
    // trie.Search("nik");
    // trie.Search("a");
    // trie.Search("nikit");
    // trie.Search("nikitamok");
    // trie.Delete("niki");
    // trie.Delete("nikit");
    // trie.Delete("nikki");
    // trie.Delete("nik");
    // trie.Display();

    int opt;
    cout << "***** TRIE DATA STRUCTURE MENU DRIVEN *****" << endl;
    cout << "0: Display Trie" << endl;
    cout << "1: Insert a word in Trie." << endl;
    cout << "2: Delete a word in Trie." << endl;
    cout << "3: Search for a word in Trie." << endl;
    cout << "-1: Quit" << endl;
    do
    {
        cout << "Enter your choice : ";
        cin >> opt;
        switch (opt)
        {
        case 0:
            trie.Display();
            break;
        case 1:
            trie.Insert();
            break;
        case 2:
            trie.Delete();
            break;
        case 3:
            trie.Search();
            break;      
        case -1:
            cout << "***** THANK YOU *****" << endl;
            break;
        default:
            cout << "Enter Valid Option!" << endl;
            break;
        }
    } while (opt != -1);
    
    return 0;
}