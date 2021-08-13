#include <iostream>
#include <type_traits> 
#include <utility>     
#include <cstddef> 


constexpr std::size_t COLUMN_SIZE{4};
constexpr std::size_t ROW_SIZE{4};

template <typename T>
void insertionSort(T matrix[][COLUMN_SIZE], const std::size_t &ROW_SIZE)
{
     
    static_assert(
        std::is_integral<T>() || std::is_floating_point<T>(),
        "Type for array must be bool,"
        "a char type, a short type, a long type, "
        "or a long long type or Type must be float, double, or long double");

   
    for (std::size_t row{}; row < ROW_SIZE; ++row)
    {
        for (std::size_t column{}; column < COLUMN_SIZE - 1; ++column)
        {
            T currentMin = std::move(matrix[row][column]);
            std::size_t currentMinIndex = std::move(column);

            for (std::size_t j{column + 1}; j < COLUMN_SIZE; ++j)
            {
                if (currentMin > matrix[row][j])
                {
                    currentMin = std::move(matrix[row][j]);
                    currentMinIndex = std::move(j);
                }
            }
            if (currentMinIndex != column)
            {
                matrix[row][currentMinIndex] = std::move(matrix[row][column]);
                matrix[row][column] = std::move(currentMin);
            }
        }
    }
}


template <typename T>
inline void printArray(const T matrix[][COLUMN_SIZE], const std::size_t &ROW_SIZE)
{
    static_assert(
        std::is_integral<T>() || std::is_floating_point<T>(),
        "Type for array must be bool,"
        "a char type, a short type, a long type, "
        "or a long long type or Type must be float, double, or long double");
    for (std::size_t i{}; i < ROW_SIZE; ++i)
    {
        for (std::size_t j{}; j < COLUMN_SIZE; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
int main()
{
    std::size_t matrix[][COLUMN_SIZE] = {{5, 32, 1, 6}, {3, 41, 2, 7}, {3, 6, 1, 7}, {2, 31, 5, 6}};
    insertionSort(matrix, ROW_SIZE);
    printArray(matrix, ROW_SIZE);
}
