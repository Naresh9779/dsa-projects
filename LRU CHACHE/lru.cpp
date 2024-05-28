#include <iostream>
#include<list>
#include<unordered_map>
using namespace std;

class Node{
    public:
    string key;
    int value;
    Node(string key, int value)
    {
        this->key = key;
        this->value = value;
    }
};

class LRUCACHE{
    public:
    list<Node>l;
    int maxSize;
    unordered_map<string,list<Node>::iterator>m;
    LRUCACHE(int maxSize)
    {
        this->maxSize = maxSize>1?maxSize:1;
    }

    void insert(string key , int value)
    {
        if(m.count(key)!=0)
        {
            auto it=m[key];
            it->value=value;
        }
        else{
            if(l.size()==maxSize)
            {
                auto last=l.back();
                m.erase(last.key);
                l.pop_back();
            }

            Node n(key,value);
            l.push_front(n);
            m[key]=l.begin();


        }

    }
    int* getValue(string key)
    {
        if(m.count(key)!=0)
        {
            auto it=m[key];
            int value=it->value;
          
            l.push_front(*it);
              l.erase(it);
            m[key]=l.begin();
            return &l.begin()->value;
        }
        return NULL;

    }
    string mostRecentKey()
    {
        return l.front().key;

    }
};

int main(){
    LRUCACHE lru(3);
    lru.insert("apple",10);
    lru.insert("banana",20);
    lru.insert("orange",30);
    cout<<"Most Recent Key : "<<lru.mostRecentKey()<<endl;
    lru.insert("apple",40);
    cout<<"Most Recent Key : "<<lru.mostRecentKey()<<endl;
   auto *it= lru.getValue("apple");
    if(it!=NULL)
    {
        cout<<"Price Of Apple : "<<*it<<endl;
    }

    lru.insert("Strawberry",300);
   
    cout<<"Most Recent Key : "<<lru.mostRecentKey()<<endl;
    
    
    if(lru.getValue("banana")==NULL)
    {
        cout<<"banana Not Found"<<endl;
    }
    

}