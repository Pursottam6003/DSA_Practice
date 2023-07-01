// https://leetcode.com/problems/lru-cache/description/
class LRUCache {
public:

    class DoublyLL
    {
        // create a contructor 
        public:
        int key;
        int val;
        DoublyLL *prev;
        DoublyLL *next;
        DoublyLL(int _key,int _val)
        {   // assign key value pair into it 
            key = _key;
            val = _val;
        }
    };
    
    // creating head and tail variable
    DoublyLL *head = new DoublyLL(-1,-1);
    DoublyLL *tail = new DoublyLL(-1,-1);

    int maxiSize;
    unordered_map <int,DoublyLL*> mpp;


    LRUCache(int capacity) {
        maxiSize = capacity;
        // initialised 
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(DoublyLL *newNode)
    {
        DoublyLL *temp = head->next; // ahead of head 
        newNode->next  = temp;
        newNode->prev = head;

        head->next = newNode;
        temp->prev = newNode;

    }

    void deleteNode(DoublyLL *delNode)
    {
        DoublyLL *prevDel = delNode->prev;
        DoublyLL *afterDel = delNode->next;

        prevDel->next = afterDel;
        afterDel->prev = prevDel;

        //delete delNode;

    }
    int get(int key) {
        
        // find the key 

        if(mpp.find(key) != mpp.end())
        {
            // if its find
            // even thought it is get operation but this also used operation 

            DoublyLL* resNode  = mpp[key];

            int res= resNode->val;
            mpp.erase(key);

            // delete the res node right ?
            deleteNode(resNode);

            addNode(resNode);

            // iupdate in map 
            mpp[key] = head->next;

            return res;
        }

        return -1;

    }
    
    void put(int key, int value) {
        // first find the element if it is already present 

        if(mpp.find(key) != mpp.end())
        {
            // get the resultent key node

            DoublyLL *existsNode = mpp[key];
            // remove from the map 
            mpp.erase(key);
            deleteNode(existsNode);
            // now add into most recent one 
        }

        if(mpp.size() == maxiSize)
        {   // if it exceeds the capacity 
            mpp.erase(tail-> prev->key);
            deleteNode(tail->prev);
        }

        addNode(new DoublyLL(key,value));
        // insergin into map too
        mpp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */