/** PathFind_Chernobyl.cpp
 * 
 * Main file of Chernobyl path find package
 * 
 * Author: David Ryan
 * Contact: davidryn6@gmial.com
 * 
 * Last modified: 7/23/2020
 * 
 */

#include <iostream>
#include <stdio.h>
#include <map>
#include <unordered_map>
#include <chrono>

#include "PathFind_Chernobyl.hpp"

using namespace std;

int main()
{

    // number of rows
    const int n = 10;
    // number of columns
    const int m = 10;

    pair<int, int> playerLocation(4, 3);

    unordered_map<pair<int, int>, int, hash_pair> pointMap;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            pair<int, int> p(i, j);
            pointMap[p] = 0;
        }
    }

    chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();

    pointMap = calcHeatMap(pointMap, playerLocation);

    chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> time_span = t2 - t1;

    printMatrixFromMap(pointMap, n, m);

    cout << "Duration:  " << time_span.count() << " milliseconds.";
    cout << endl;

    return 0;
};