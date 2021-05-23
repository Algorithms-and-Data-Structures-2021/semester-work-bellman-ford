#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

// подключаем вашу структуру данных
#include "algorithm.hpp"


using namespace std;
using namespace itis;

// абсолютный путь до набора данных и папки проекта
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};
static constexpr auto kProjectPath = string_view{PROJECT_SOURCE_DIR};

int main() {
    string path = "C:\\Users\\username\\acd_projects\\semester-work-bellman-ford\\dataset\\";
    const string test_data_name = "data";
    path += test_data_name;

    long int count_top[] = {10, 50, 100, 500, 1000};
    const int SETS_NUMBER = 5;
    const int FILE_NUMBER = 10;
    for (int set_n = 0; set_n < SETS_NUMBER; set_n++) {
      cout << "---------SET NUMBER " << set_n + 1<< "---------" << endl;

      long double middle_time = 0;
      for (int file_n = 1; file_n <= FILE_NUMBER; file_n++) {
        string file_path = path + "\\" + to_string(count_top[set_n]) + "\\" + to_string(file_n) + ".txt";
        ifstream file(file_path);

        int n = 0;
        int** matrix = create_graph(file, n);

        bool has_negative_cycle = false;
        const auto time_point_before = chrono::steady_clock::now();  // запоминаем время начала операции
        int* array_top = algorithm(matrix, n, has_negative_cycle);
        const auto time_point_after = chrono::steady_clock::now();  // запоминаем время конца операции
        // измеряем разницу по времени
        const auto time_diff = time_point_after - time_point_before;
        // переводим время в наносекунды
        const long double time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();

        cout << "Time taken: " << time_elapsed_ns / 1000000 << '\n';
        //cout << (has_negative_cycle ? "Graph has negative cycle" : "Graph hasn't negative cycle") << endl;
        middle_time += time_elapsed_ns / 1000000;

        delete_matrix(matrix, n);
        delete[] array_top;
        file.close();
      }
        middle_time /= 10;
        cout << "Middle time = " << middle_time << endl;
        cout << "--------------------------------" << endl;
    }
}
