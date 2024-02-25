#include <iostream>
using namespace std;

template <typename V>
class MapNode {
    public : 
        string key; // not making the key to template as for every key we would have to write the hashcode. so just writing the code for only string key
        V value;
        MapNode<V>* next;
    public :
        MapNode (string key, V value) {
            this->key = key;
            this->value = value;
            next = NULL;
        }         
        // friend class HashMap<V>;   // some error coming see it later.
        ~MapNode () {   
            delete next;
        }
};

template <typename V>
class HashMap {
    private :
        int count;
        int bucketCapacity;
        double loadFactor;
        MapNode<V>** bucket; 
    public : 
        HashMap() {
            count = 0;
            bucketCapacity = 5;
            loadFactor = 0.0;
            bucket = new MapNode<V>* [bucketCapacity];
            for (int i = 0; i < bucketCapacity; i++) {   // try by removing these runing or not.
                bucket[i] = NULL;
            }
        }
    private :
        // "abc" = a * p^2 + b * p^1 + c * p^0  
        int HashFun (string key) {
            int baseP = 1;   // cofficient 
            int bucketIndex = 0;
            for (int i = 0; i < key.size(); i++) {
                bucketIndex = bucketIndex + key[i] * baseP;
                baseP *= 37;
                baseP % bucketCapacity;
                bucketIndex = bucketIndex % bucketCapacity;
            }
            return bucketIndex % bucketCapacity;
        }

        void ReHashing () {
            MapNode<V>** temp = bucket;
            bucket = new MapNode<V>* [2*bucketCapacity];
            for (int i = 0; i < 2*bucketCapacity; i++) {
                bucket[i] = NULL;
            }
            int oldCapacity = bucketCapacity;
            bucketCapacity *= 2;
            count = 0;
            for (int i = 0; i < oldCapacity; i++) {
                MapNode<V>* head = temp[i];
                while (head != NULL)
                {
                    insert (head->key, head->value);
                    head = head->next;
                }
                
            }
            for (int i = 0; i < oldCapacity; i++) {
                delete temp[i];
            }
            delete [] temp;
        }
    public :
        void insert (string key, V value) {
            MapNode<V>* head = new MapNode<V>(key, value);
            int index = HashFun(key);
            cout << "index of " << key << " : " << index << endl;
            if (bucket[index] == NULL) {
                bucket[index] = head; 
            } else {
                MapNode<V>* temp = bucket[index]; 
                while (temp->next != NULL)
                {
                    if (temp->key == key) {
                        temp->value = value;
                        return;
                    }
                    temp = temp->next;
                }
                if (temp->key == key) {
                    temp->value = value;
                    return;
                }
                    temp->next = head;
            }
            count++;
            loadFactor = (1.0 * count) / bucketCapacity;    // to check
            if (loadFactor >= 0.7) {
                ReHashing ();
            }
        }
        V remove (string key) {
            int index = HashFun (key);
            MapNode<V>* temp = bucket[index];
            MapNode<V>* prev = bucket[index];
            while (temp != NULL) {
                if (temp->key == key) {
                    prev->next = temp->next;
                    V deletedValue = temp->value;
                    delete temp; // check it
                    count--;
                    return deletedValue;
                }
                prev = temp;
                temp = temp->next;
            } 
            cout << "invalid key\n";
            return 0;
        }
        V getValue (string key) {
            int index = HashFun (key);
            MapNode<V>* temp = bucket[index];
            while (temp != NULL) {
                if (temp->key == key) {
                    return temp->value;
                }
                temp = temp->next;
            }
            cout << "Enter valid key. Key not present\n";
            return 0;
        }
        int size () {
            return count;
        }
        // check it
        double loadFactor () {
            return loadFactor;
        }
        ~HashMap () {
            for (int i = 0; i < bucketCapacity; i++) {
                delete bucket[i];
            }
            delete [] bucket;
        }
};

int main () {
    HashMap<int> map;
    cout << "size : " << map.size() << endl;
    map.insert("abc", 1);
    map.insert("abc1", 2);
    map.insert("abc2", 3);
    map.insert("abc3", 4);
    map.insert("abc4", 5);
    map.insert("abc5", 6);
    map.insert("abc6", 7);
    map.insert("abc7", 8);
    cout << "size : " << map.size() << endl;
    map.insert("abc", 6);
    cout << "size : " << map.size() << endl;
    cout << map.getValue("abc") << endl;
    cout << map.getValue("abc1") << endl;
    cout << map.getValue("abc2") << endl;
    cout << map.getValue("abc3") << endl;
    cout << map.remove ("abc2") << endl;
    cout << map.getValue("abc2") << endl;
    cout << map.remove("def") << endl;
    cout << map.getValue("abc7") << endl;

    // Check by input of other method.
    
    return 0;
}