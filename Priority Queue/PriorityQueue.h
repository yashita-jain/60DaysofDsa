#include <iostream>
#include <vector>
using namespace std;
class PriorityQueue
{
    vector<int> pq;

public:
    PriorityQueue()
    {
    }

    bool isEmpty()
    {
        return pq.size() == 0;
    }

    int getSize()
    {
        return pq.size();
    }

    int getMin()
    {
        if (isEmpty())
        {
            return 0;
        }
        else
        {
            return pq[0];
        }
    }

    void insert(int x)
    {
        pq.push_back(x);
        int childIndex = pq.size() - 1;
        int parentIndex = (childIndex - 1) / 2;

        while (childIndex > 0)
        {
            if (pq[parentIndex] > pq[childIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
            parentIndex = (childIndex - 1) / 2;
        }
    }

    int removeMin()
    {
        if (isEmpty())
        {
            return 0;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        int parentIndex = 0;
        int lci = 2 * parentIndex + 1;
        int rci = 2 * parentIndex + 2;
        while (lci < pq.size())
        {
            int minIndex = parentIndex;
            if (pq[minIndex] > pq[lci])
            {
                minIndex = lci;
            }
            if (rci < pq.size() && pq[rci] < pq[minIndex])
            {
                minIndex = rci;
            }
            if (minIndex == parentIndex)
            {
                break;
            }
            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = minIndex;
            lci = 2 * parentIndex + 1;
            rci = 2 * parentIndex + 2;
        }
        return ans;
    }
};