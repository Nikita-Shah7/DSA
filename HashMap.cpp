// key --> hashcode --> index --> value
// Alex --> 10 --> 0 --> 100
// Bob --> 11 --> 1 --> 101
// Nik --> 12 --> 2 --> 102
// Mok --> 13 --> 3 --> 103,104
// Keni --> 13 --> 3 --> 103,104
// Rit --> 24 --> 4 --> 105,106
// Ach --> 34 --> 4 --> 105,106

// diff keys may map to same values but same keys cannot map to diff values

// https://www.bing.com/videos/riverview/relatedvideo?
// &q=hash+table+data+structure+c%2b%2b&&mid=075BB96B596F89BA7799075BB96B596F89BA7799&&FORM=VRDGAR

// here, we make a hash table with 
// hash function takes string(key) as input and gives the length of string + 100 as output(hashcode)
// index value = output%numOfBuckets
// value can be any integer

#include<bits/stdc++.h>
using namespace std;

class Pair
{
    string key;
    int value;
    public:
        friend class hashTable;
};

class hashTable
{
    int numOfBuckets;
    vector<list<Pair>>table;
    bool isEmpty();
    int hashFunc(string);
    public:
        hashTable(int);
        void Insert();
        void Search();
        void Display();
        void Delete();
};

hashTable :: hashTable(int n)
{
    numOfBuckets = n;
    table.resize(numOfBuckets);
}

bool hashTable :: isEmpty()
{
    for(int i=0;i<numOfBuckets;i++)
    {
        list<Pair>&row = table[i];
        if(!row.empty()) return 0;
    }
    return 1;
}

int hashTable :: hashFunc(string s)
{
    return (s.length() + 100) % numOfBuckets ;
}

void hashTable :: Insert()
{
    Pair p;
    cout<<"Enter the data to be inserted : \n";
    cout<<"Key : ";
    cin>>p.key;
    cout<<"Value : ";
    cin>>p.value;
    list<Pair>&row = table[hashFunc(p.key)];
    for(auto& obj : row)   
    {
        if(obj.key==p.key)
        {
            cout<<"Key is already present!\n";
            return;
        }
    }
    table[hashFunc(p.key)].push_back(p);
}

void hashTable :: Search()
{
    string s;
    cout<<"Enter the key : ";
    cin>>s;

    if(isEmpty())
    {
        cout<<"The Hash Table is Empty!\n";
        return ;
    }

    list<Pair>&row = table[hashFunc(s)];
    if(row.empty())
    {
        cout<<"No relevant data found!\n";
        return;
    }    
    
    for(auto& obj : row)   
    {
        if(obj.key==s)
        {
            cout<<"Data found.\n";
            cout<<obj.key<<"->"<<obj.value<<endl;
            return;
        }        
    }
    cout<<"No relevant data found!\n";
}

void hashTable :: Display()
{
    if(isEmpty())
    {
        cout<<"The Hash Table is Empty!\n";
        return ;
    }

    cout<<"Index\t  Key-Value Pairs";
    for(int i=0;i<numOfBuckets;i++)
    {
        cout<<endl;
        cout<<"  "<<i<<" --->  ";
        list<Pair>&row = table[i];
        for(auto& obj : row)   cout<<obj.key<<"->"<<obj.value<<" ; ";
    }
    cout<<endl;
}

void hashTable :: Delete()
{
    string s;
    cout<<"Enter the key : ";
    cin>>s;

    if(isEmpty())
    {
        cout<<"The Hash Table is Empty!\n";
        return ;
    }

    list<Pair>&row = table[hashFunc(s)];
    if(row.empty())
    {
        cout<<"Key not found!\n";
        return;
    }    
    
    for(auto it = row.begin() ; it != row.end() ; it++)
    {
        if(it->key == s)  
        {
            row.erase(it);
            return;
        }
    }
    cout<<"Key not found!\n";
    return;
}

int main(void)
{
    hashTable ht(7);
    int opt;
    cout << "***** HASH TABLE DATA STRUCTURE MENU DRIVEN *****" << endl;
    cout << "0: Display Hash Table" << endl;
    // cout << "1: Create Hash Table." << endl;
    cout << "2: Insert a key-value pair in Hash Table." << endl;
    cout << "3: Delete a key-value pair in Hash Table." << endl;
    cout << "4: Search for a key-value pair in Hash Table." << endl;
    cout << "-1: Quit" << endl;
    do
    {
        cout << "Enter your choice : ";
        cin >> opt;
        switch (opt)
        {
        case 0:
            ht.Display();
            break;
        // case 1:
            // ht.Create();
            // break;
        case 2:
            ht.Insert();
            break;
        case 3:
            ht.Delete();
            break;
        case 4:
            ht.Search();
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