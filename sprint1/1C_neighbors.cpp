#include <iostream>
#include <vector>
#include <algorithm>
// #include <ranges>   

bool isValidPos(int i, int j, int n, int m);

int main()
{
    unsigned int n, m;
    
    std::cin >> n; // строки
    std::cin >> m; // столбцы
    
    // инициализация матрицы 0
    int** matrix = new int*[n]{};
    for (unsigned int i = 0; i < n; i++) {
        matrix[i] = new int[m]{};
    }
    
    // ввод данных
    for (unsigned int row = 0; row < n; row++) {
        for (unsigned int col = 0; col < m; col++) {
            std::cin >> matrix[row][col];
        }
    }
    
    unsigned int x, y;
    std::cin >> x >> y;
    std::vector<int> answ;
    
    if (isValidPos(x - 1, y, n, m))
        answ.push_back(matrix[x - 1][y]);

    if (isValidPos(x, y - 1, n, m))
        answ.push_back(matrix[x][y - 1]);

    if (isValidPos(x, y + 1, n, m))
        answ.push_back(matrix[x][y + 1]);

    if (isValidPos(x + 1, y, n, m))
        answ.push_back(matrix[x + 1][y]);
    
    // очистка выделенной памяти
    for (unsigned int i = 0; i < n; i++)
        delete[] matrix[i];
    delete[] matrix;
    
    std::sort(begin(answ), end(answ));
    
    for (int i = 0; i < answ.size(); i ++) 
        std::cout << answ[i] << ' ';
    
    return 0;
}

bool isValidPos(int i, int j, int n, int m) {
    if (i < 0 || j < 0 || i > n - 1 || j > m - 1)
        return 0;
    return 1;
}