
#include <iostream>

#include <stdio.h>
#include <conio.h>
#include <map>
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
        cout << endl;
        for (j = 0; j < m; j++)
        {
            printf("%d\t", *((arr + j * n) + i));
        }
    }
    cout << endl;
};

void mapPrint(unordered_map<pair<int, int>, int, hash_pair> m)
{
    cout << "Contents of the unordered_map : \n";
    for (auto p : m)
        cout << "[" << (p.first).first << ", "
             << (p.first).second << "] ==> "
             << p.second << "\n";
};

void mapPrintSecond(map<int, pair<int, int>> m)
{
    cout << "Contents of the map : \n";
    for (auto p : m)
        cout << p.first << " ==> "
             << "[" << (p.second).first << ", "
             << (p.second).second << "]"
             << "\n";
};

void matrixFromMapPrint(unordered_map<pair<int, int>, int, hash_pair> map, const int n, const int m)
{

    int matrix[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            pair<int, int> p(i, j);
            matrix[i][j] = map[p];
        }
    }

    matrixPrint(&matrix[0][0], n, m);
};

int main()
{

    // number of rows
    const int n = 150;
    // number of columns
    const int m = 150;
    // area of matrix
    const int area = n * m;

    pair<int, int> playerLocation(4, 3);

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

    int step = 1;

    map<int, pair<int, int>> previousPoints;
    map<int, pair<int, int>> currentPoints;

    previousPoints[1] = playerLocation;
    pointMap[playerLocation] = -2;
    pair<int, int> block1(5, 7);
    pair<int, int> block2(5, 6);
    pair<int, int> block3(5, 5);
    pair<int, int> block4(6, 5);
    pointMap[block1] = -1;
    pointMap[block2] = -1;
    pointMap[block3] = -1;
    pointMap[block4] = -1;
    int compCounter = 0;


    while (!previousPoints.empty())
    {
        int currentPointIndex = 0;
        for (auto p : previousPoints)
        {
            compCounter++;
            pair<int, int> up((p.second.first + 1), p.second.second);
            pair<int, int> down((p.second.first - 1), p.second.second);
            pair<int, int> left(p.second.first, (p.second.second - 1));
            pair<int, int> right(p.second.first, (p.second.second + 1));
            if (pointMap.count(up) > 0 && pointMap[up] == 0)
            {
                pointMap[up] = step;
                currentPoints[currentPointIndex] = up;
                currentPointIndex++;
            }
            if (pointMap.count(down) > 0 && pointMap[down] == 0)
            {

                pointMap[down] = step;
                currentPoints[currentPointIndex] = down;
                currentPointIndex++;
            }
            if (pointMap.count(left) > 0 && pointMap[left] == 0)
            {
                pointMap[left] = step;
                currentPoints[currentPointIndex] = left;
                currentPointIndex++;
            }
            if (pointMap.count(right) > 0 && pointMap[right] == 0)
            {
                pointMap[right] = step;
                currentPoints[currentPointIndex] = right;
                currentPointIndex++;
            }
        }

        previousPoints = currentPoints;
        currentPoints.clear();
        step++;
    }
    cout << "Number of Comparisions: " << compCounter;
    matrixFromMapPrint(pointMap, n, m);

    return 0;
};