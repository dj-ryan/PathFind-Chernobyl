#include <map>
#include <unordered_map>


struct hash_pair
{
    template <class T1, class T2>
    size_t operator()(const std::pair<T1, T2> &p) const
    {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

void matrixPrint(int *arr, int n, int m);

void mapPrint(std::unordered_map<std::pair<int, int>, int, hash_pair> m);

void mapPrintSecond(std::map<int, std::pair<int, int>> m);

void matrixFromMapPrint(std::unordered_map<std::pair<int, int>, int, hash_pair> map, const int n, const int m);