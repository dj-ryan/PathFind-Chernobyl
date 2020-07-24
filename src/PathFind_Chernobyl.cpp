#include <iostream>

#include <stdio.h>
#include <map>
#include <unordered_map>

#include "PathFind_Chernobyl.hpp"

void printMatrix(int *arr, int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        std::cout << std::endl;
        for (j = 0; j < m; j++)
        {
            printf("%d\t", *((arr + j * n) + i));
        }
    }
    std::cout << std::endl;
};

void printPairValueMap(std::unordered_map<std::pair<int, int>, int, hash_pair> m)
{
    std::cout << "Contents of the unordered_map : \n";
    for (auto p : m)
        std::cout << "[" << (p.first).first << ", "
                  << (p.first).second << "] ==> "
                  << p.second << "\n";
};

void printValuePairMap(std::map<int, std::pair<int, int>> m)
{
    std::cout << "Contents of the map : \n";
    for (auto p : m)
        std::cout << p.first << " ==> "
                  << "[" << (p.second).first << ", "
                  << (p.second).second << "]"
                  << "\n";
};

void printMatrixFromMap(std::unordered_map<std::pair<int, int>, int, hash_pair> map, const int n, const int m)
{

    int matrix[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::pair<int, int> p(i, j);
            matrix[i][j] = map[p];
        }
    }

    printMatrix(&matrix[0][0], n, m);
};

std::unordered_map<std::pair<int, int>, int, hash_pair> calcPlaceBlock(std::unordered_map<std::pair<int, int>, int, hash_pair> pointMap, std::pair<int, int> blockArray[], int size)
{
    for (int i = 0; i < size; i++)
    {
        pointMap[blockArray[i]] = -1;
    }
    return pointMap;
};

std::unordered_map<std::pair<int, int>, int, hash_pair> calcHeatMap(std::unordered_map<std::pair<int, int>, int, hash_pair> pointMap, std::pair<int, int> origin)
{

    int step = 1;

    std::map<int, std::pair<int, int>> previousPoints;
    std::map<int, std::pair<int, int>> currentPoints;

    previousPoints[0] = origin;
    pointMap[origin] = -2;

    while (!previousPoints.empty())
    {
        int currentPointIndex = 0;
        for (auto p : previousPoints)
        {
            int p_first = p.second.first;
            int p_second = p.second.second;

            std::pair<int, int> up((p_first + 1), p_second);
            std::pair<int, int> down((p_first - 1), p_second);
            std::pair<int, int> left(p_first, (p_second - 1));
            std::pair<int, int> right(p_first, (p_second + 1));
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

    return pointMap;
};
