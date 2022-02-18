class Node
{
public:
    int value, index, freq; 
    Node(int value = 0, int index = 0, int freq = 0){
        this -> value = value;
        this -> index = index;
        this -> freq = freq;
    }
};

class LFUCache
{
public:

    int capacity, position, currSize;
    vector<int> cache;
    Node *nodes;
    LFUCache(int capacity)
    {
        this -> capacity = capacity;
        this -> cache.resize(capacity, -1);
        nodes = new Node[capacity];
        this -> currSize = 0;
        this -> position = 0;
    }

    int get(int key)
    {
        position += 1;

        int value = -1;

        for(int i = 0; i < cache.size(); i++){

            if(key == cache[i]){

                value = nodes[i].value;
                nodes[i].freq += 1;
                nodes[i].index = position;
            }
        }
        return value;
        
    }

    void put(int key, int value)
    {
        position += 1;

        if(capacity == 0){
            return;
        }

        for(int i = 0; i < capacity; i++){
            if(cache[i] == key){

                nodes[i].index = position;
                nodes[i].freq += 1;
                nodes[i].value = value;
                return;
            }
        }
        if(currSize < capacity){

            cache[currSize] = key;
            nodes[currSize].value = value;
            nodes[currSize].freq = 1;
            nodes[currSize].index = position;
            currSize += 1;
        }

        else{

            int pos = 0;

            for(int j = 0; j < capacity; j++){

                if(nodes[j].freq < nodes[pos].freq){
                    pos = j;
                }

                else if(nodes[j].freq == nodes[pos].freq &&
                        nodes[j].index < nodes[pos].index){
                    pos = j;
                }
            }
            cache[pos] = key;
            nodes[pos].value = value;
            nodes[pos].freq = 1;
            nodes[pos].index = position;
        }

    }
};
