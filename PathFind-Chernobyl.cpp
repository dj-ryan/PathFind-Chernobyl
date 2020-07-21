
#include <iostream>

#include <stdio.h>
#include <conio.h>
#include <unordered_map>
#include <utility>

using namespace std;

struct hash_pair
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

void matrixPrint(int *arr, int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        std::cout << endl;
        for (j = 0; j < m; j++)
        {
            printf("%d ", *((arr + j * n) + i));
        }
    }
    std::cout << endl;
}

void mapPrint(unordered_map<pair<int, int>, int, hash_pair> m)
{
    cout << "Contents of the unordered_map : \n";
    for (auto p : m)
        cout << "[" << (p.first).first << ", "
             << (p.first).second << "] ==> "
             << p.second << "\n";
}

int main()
{

    // number of rows
    const int n = 10;
    // number of columns
    const int m = 10;
    // area of matrix
    const int area = n * m;

    pair<int,int> playerLocation(4,3);

    int matrix[n][m];
    unordered_map<pair<int, int>, int, hash_pair> pointMap;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = 0;
            pair<int, int> p(i, j);
            pointMap[p] = 0;
        }
    }

    matrixPrint(&matrix[0][0], n, m);

    mapPrint(pointMap);

    int step = 1;

    

    pair<int,int> up((playerLocation.first + 1),playerLocation.second);
    pair<int,int> down((playerLocation.first - 1),playerLocation.second);
    pair<int,int> left(playerLocation.first,(playerLocation.second - 1));
    pair<int,int> right(playerLocation.first,(playerLocation.second + 1));

    pointMap[up] = 1;
    pointMap[down] = 1;
    pointMap[left] = 1;
    pointMap[right] = 1;



    mapPrint(pointMap);


    return 0;
}