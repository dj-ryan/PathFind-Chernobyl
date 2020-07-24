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

void printMatrix(int *arr, int n, int m);

void printPairValueMap(std::unordered_map<std::pair<int, int>, int, hash_pair> m);

void printValuePairMap(std::map<int, std::pair<int, int>> m);

void printMatrixFromMap(std::unordered_map<std::pair<int, int>, int, hash_pair> map, const int n, const int m);

std::unordered_map<std::pair<int, int>, int, hash_pair> calcPlaceBlock(std::unordered_map<std::pair<int, int>, int, hash_pair> pointMap, std::pair<int, int> blockArray[]);

std::unordered_map<std::pair<int, int>, int, hash_pair> calcHeatMap(std::unordered_map<std::pair<int, int>, int, hash_pair> pointMap, std::pair<int, int> origin);
