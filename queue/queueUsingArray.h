#include <iostream>
using namespace std;


template <typename T>
class queueUsingArray
{
    T* data;
    int nextIndex;
    int firstIndex;
    int capacity;
    int size;

public:
    queueUsingArray()
    {
        data = new T[5];
        nextIndex = 0;
        firstIndex = -1;
        capacity=5;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(int element)
    {
        if (size == capacity)
        {
            T* newData=new T[capacity*2];
            int j=0;
            for (int i = firstIndex; i < capacity; i++)
            {newData[j]=data[i];
                        j++;
            }
             for (int i = 0; i < firstIndex; i++)
            {newData[j]=data[i];
             j++;
            }
        delete[]data;
        data=newData;
        firstIndex=-1;
        nextIndex=0;
        capacity=capacity*2;
        }
        data[nextIndex] = element;
        nextIndex = (1 + nextIndex) % capacity;
        size++;
        if (firstIndex == -1)
        {
            firstIndex = 0;
        }
    }

    T dequeue()
    {

        if (isEmpty())
        {
            cout << "Queue is Empty." << endl;
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        return ans;
    }

    T top()
    {

        if (isEmpty())
        {
            cout << "Queue is Empty." << endl;
            return 0;
        }
        return data[firstIndex];
    }
};