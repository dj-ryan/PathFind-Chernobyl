#include <iostream>

#include <stdio.h>
#include <conio.h>
#include <map>
#include <unordered_map>
#include <utility>
#include <chrono>

#include "PathFind_Chernobyl.hpp"

void matrixPrint(int *arr, int n, int m)
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

void mapPrint(std::unordered_map<std::pair<int, int>, int, hash_pair> m)
{
    std::cout << "Contents of the unordered_map : \n";
    for (auto p : m)
        std::cout << "[" << (p.first).first << ", "
                  << (p.first).second << "] ==> "
                  << p.second << "\n";
};

void mapPrintSecond(std::map<int, std::pair<int, int>> m)
{
    std::cout << "Contents of the map : \n";
    for (auto p : m)
        std::cout << p.first << " ==> "
                  << "[" << (p.second).first << ", "
                  << (p.second).second << "]"
                  << "\n";
};

void matrixFromMapPrint(std::unordered_map<std::pair<int, int>, int, hash_pair> map, const int n, const int m)
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

    matrixPrint(&matrix[0][0], n, m);
};
