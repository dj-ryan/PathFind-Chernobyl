
#include <iostream>

#include <stdio.h>
#include <conio.h>
#include <map>
#include <unordered_map>
#include <utility>
#include <chrono>

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
    const int n = 20;
    // number of columns
    const int m = 20;
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

    // obstacle input
    // pair<int, int> block1(5, 7);
    // pair<int, int> block2(5, 6);
    // pair<int, int> block3(5, 5);
    // pair<int, int> block4(6, 5);
    // pair<int, int> block5(7, 5);
    // pair<int, int> block6(7, 6);
    // pointMap[block1] = -1;
    // pointMap[block2] = -1;
    // pointMap[block3] = -1;
    // pointMap[block4] = -1;
    // pointMap[block5] = -1;
    // pointMap[block6] = -1;

    // analysis variables
    int compCounter = 0;

    chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
    while (!previousPoints.empty())
    {
        int currentPointIndex = 0;
        for (auto p : previousPoints)
        {
            int p_first = p.second.first;
            int p_second = p.second.second;

            pair<int, int> up((p_first + 1), p_second);
            pair<int, int> down((p_first - 1), p_second);
            pair<int, int> left(p_first, (p_second - 1));
            pair<int, int> right(p_first, (p_second + 1));
            if (pointMap.count(up) > 0 && pointMap[up] == 0)
            {
                pointMap[up] = step;
                currentPoints[currentPointIndex] = up;
                currentPointIndex++;
                compCounter++;
            }
            if (pointMap.count(down) > 0 && pointMap[down] == 0)
            {

                pointMap[down] = step;
                currentPoints[currentPointIndex] = down;
                currentPointIndex++;
                compCounter++;
            }
            if (pointMap.count(left) > 0 && pointMap[left] == 0)
            {
                pointMap[left] = step;
                currentPoints[currentPointIndex] = left;
                currentPointIndex++;
                compCounter++;
            }
            if (pointMap.count(right) > 0 && pointMap[right] == 0)
            {
                pointMap[right] = step;
                currentPoints[currentPointIndex] = right;
                currentPointIndex++;
                compCounter++;
            }
        }
        previousPoints = currentPoints;
        currentPoints.clear();
        step++;
    }

    chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();

    chrono::duration<double, std::milli> time_span = t2 - t1;

    std::cout << "Duration:  " << time_span.count() << " milliseconds.";
    std::cout << std::endl;

    cout << "Number of Comparisions: " << compCounter;
    matrixFromMapPrint(pointMap, n, m);

    return 0;
};