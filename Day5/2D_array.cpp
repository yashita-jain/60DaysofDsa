#include <iostream>
using namespace std;
int main()
{
    int n = 3;
    int **p = new int *[n];
    cout << "Enter the  elements of row wise" << endl;
    for (int i = 0; i < n; i++)
    {
        p[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> p[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            cout << p[i][j];
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        delete[] p[i];
    }
    delete[] p;


//for n rows and ascending order type stair format
    int **p = new int *[n];
    for (int i = 0; i < n; i++)
    {
          p[i] = new int[i+1];
        for (int j = 1; j <= i + 1; j++)
        {
           cin >> p[i][j - 1];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= i + 1; j++)
        {

            cout << p[i][j - 1]<<" ";
        }
        cout<<endl;
    }
    for (int i = 0; i < n; i++)
    {
        delete[] p[i];
    }
    delete[] p;

    return 0;
}