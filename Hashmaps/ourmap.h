#include <iostream>
#include <string>

template <typename V>
class MapNode
{
public:
    string key;
    V value;
    MapNode *next;

    MapNode(string key, V value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~MapNode()
    {
        delete next;
    }
};

template <typename V>
class ourmap
{
    MapNode<V> **buckets;
    int size;
    int numBuckets;
    int count=0;

public:
    ourmap()
    {
        size = 0;
        numBuckets = 5;
        buckets = new MapNode<V> *[numBuckets];
        for (int i = 0; i < numBuckets; i++)
        {
            buckets[i] = NULL;
        }
    }
    ~ourmap()
    {
        for (int i = 0; i < numBuckets; i++)
        {
            delete buckets[i];
        }

        delete[] buckets;
    }

    int size()
    {
        return count;
    }

private:
    int getBucketIndex(string key)
    {
        int hashCode;
        int currentCoeff = 1;
        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashCode += key[i] * currentCoeff;
            hashCode = hashCode % numBuckets;
            currentCoeff *= 37;
            currentCoeff = currentCoeff % numBuckets;
        }

        return hashcode % numBuckets;
    }

void rehash(){
    MapNode<V>** temp=buckets;
    buckets=new MapNode<V>*[2*numBuckets];
    for (int i = 0; i < 2*numBuckets; i++)
    {buckets[i]=NULL;
    }
    int oldBumBuckets=numBuckets;
    numBuckets2*numBuckets;
    count=0;loadfactor;}
    for(int i=0;i<oldBumBuckets;i++){
        MapNode<V> head=temp[i];
        while (head!=NULL){}
        {string key=head->key;
        V value=head->value;
        insert(key,value);
        head=head->next;
        }
        
    }

    for (int i = 0; i < oldBumBuckets; i++)
    { MapNode<V> head=temp[i];
    delete head;
    }
    delete []temp;
    
}

public:
double getLoadFactor(){
    return (1.0*count)/numBuckets;}

    void insert(string key, V value)
    {
        int bucketIndex = getBucketIndex( key);
        MapNode<V> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                head->val = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        MapNode<V> *node = new MapNode<V>(key, value);
        node->next = head;
        buckets[bucketIndex] = node;
        count++;
        double loadfactor=(1.0*count)/numBuckets;
        if(loadfactor>0.7){
        rehash();
                }
    }

    V getValue(string key)
    {
       int bucketIndex = getBucketIndex(key); 
           MapNode<V> *head = buckets[bucketIndex];

      while (head!=NULL)
      {if(head->key==key){
return head->val;
      }
      head=head->next;
      }

      return 0;
       
    }

    void remove(string key)
    {
        int bucketIndex = getBucketIndex( key);
        MapNode<V> *head = buckets[bucketIndex];
        MapNode<V> *previous = NULL;
        while (head != NULL)
        {
            if (head->key == key)
            {
                if (prev == NULL)
                {
                    buckets[bucketIndex] = head->next;
                }
                else
                {
                    prev->next = head->next;
                }
                V value = head->value;
                head->next = NULL;
                delete head;
                count--;
                return value;
            }
            prev = head;
            head = head->next;
        }

        return 0;
    }
};