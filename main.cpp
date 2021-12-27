#include <iostream>
#include "gtest/gtest.h"
using namespace std;
#include "ISorter.h"
#include <fstream>
#include "menu.h"

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();

    menu();

//    int arr[5000];
//    for (int i = 0; i < 5000; i++) {
//        arr[i] = rand() % 1000;
//    }
//    ArraySequence<int> array(arr, 5000);
//    LinkedListSequence<int> list(arr, 5000);
//    ofstream fout(R"(D:\labs\lab1_s3\comp_sort.txt)", ios::app);
////    fout << "Работа с файлами в С++" << endl; // запись строки в файл
//    fout << 5000 << "   " << ISorter<int>::SortTime(5, &array, excmp) << "   " << ISorter<int>::SortTime(5, &list, excmp) << endl;
//    fout.close();
    return 0;
}
