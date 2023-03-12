// https://leetcode.com/problems/lru-cache/submissions/913705099/
class LRUCache {
public:

    class node {
        public:
        int key;
        int val;

        node *prev;
        node *next;

        // giving a constructor 
        node(int _key,int _val)
        {
            key =_key;
            val = _val;
        }
    };

    node *head= new node(-1,-1); // 
    node *tail = new node(-1,-1);

    // declaring a map 
    int cap; // capacity 
    unordered_map <int, node *> mpp;


    LRUCache(int capacity) {
        cap = capacity; 
        // iniitialisation of nodes
        head->next = tail;
        tail->prev = head; 
    }


    void addNode(node *newnode)
    {   
        node *temp = head->next; 
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;   
    }

    void deleteNode(node *delNode)
    {
        node *prevDel= delNode->prev;
        node *afterDel = delNode->next;
        // making connection 
        prevDel->next = afterDel;
        afterDel->prev = prevDel;  
    }
    
    int get(int key) {
        
        if(mpp.find(key) != mpp.end())
        {
            // if it is present 
            node *resNode = mpp[key];

            int res = resNode->val;
            mpp.erase(key);

            deleteNode(resNode); // remove the node and again attach in most recent 
            addNode(resNode);
            // updating into the map 
            mpp[key]  = head->next;
            return res;
        }
        // else 
        return -1;
    }

    
    void put(int key, int value) {

        // put measn addigg element if it not present
        if(mpp.find(key) != mpp.end())
        {
            node *existsNode = mpp[key];
            // remove from the map 
            mpp.erase(key);
            deleteNode(existsNode);
            // now add into most recent one 
        }

        if(mpp.size() == cap)
        {   // if it exceeds the capacity 
            mpp.erase(tail-> prev->key);
            deleteNode(tail->prev);
        }

        addNode(new node(key,value));
        // insergin into map too
        mpp[key] = head->next;
    }
};

 