#ifndef LAB1_S3_ISORTER_H
#define LAB1_S3_ISORTER_H
#include "Sequence.h"
#include <ctime>
#include "ArraySequence.h"
#include "LinkedListSequence.h"
#include <cstdlib>
#include <chrono>

template<class T>
class ISorter {
public:
    static void Swapper(Sequence<T> *seq, int i, int j) {
        T temp = seq->Get(i);
        seq->Set(i, seq->Get(j));
        seq->Set(j, temp);
    }

    static Sequence<T>* BubbleSort(Sequence<T> *seq, int (*cmp)(T, T)) { //O(n^2)
        auto * newSeq = seq->Clone();
        for (int i = 0; i < newSeq->GetLength(); i++) {
            for (int j = 0; j < newSeq->GetLength() - i - 1; j++) {
                if (cmp((newSeq->Get(j)), (newSeq->Get(j + 1)))) {
                    Swapper(newSeq, j, j + 1);
                }
            }
        }
        return newSeq;
    }

    static Sequence<T>* BubbleShakerSort(Sequence<T> *seq, int(*cmp)(T, T)) { ////O(n^2)
        auto * newSeq = seq->Clone();
        int LeftSize = 1;
        int RightSize = newSeq->GetLength() - 1;
        while (LeftSize <= RightSize) {
            for (int i = LeftSize; i <= RightSize; i++) {
                if (cmp(newSeq->Get(i - 1), newSeq->Get(i))) {
                    Swapper(newSeq, i, i - 1);
                }
            }
            RightSize--;
            for (int i = RightSize; i >= LeftSize; i--) {
                if (cmp(newSeq->Get(i - 1), newSeq->Get(i))) {
                    Swapper(newSeq, i, i - 1);
                }
            }
            LeftSize++;
        }
        return newSeq;
    }

    static Sequence<T>* InsertionSort(Sequence<T> *seq, int (*cmp)(T, T)) { //O(n^2)
        auto *newSeq = seq->Clone();
        for (int i = 1; i < newSeq->GetLength(); i++) {
            for (int j = i; j > 0 && cmp(newSeq->Get(j - 1), newSeq->Get(j)); j--) {
                Swapper(newSeq, j, j - 1);
            }
        }
        return newSeq;
    }

    static Sequence<T>* SelectionSort(Sequence<T> *seq, int (*cmp)(T, T)) { //O(n^2)
        auto *newSeq = seq->Clone();
        T temp;
        for (int i = 0; i < newSeq->GetLength() - 1; i++) {
            int i_smallest = i;
            for (int j = i + 1; j < newSeq->GetLength(); j++) {
                if (cmp(newSeq->Get(i_smallest), newSeq->Get(j)))
                    i_smallest = j;
            }
            Swapper(newSeq, i, i_smallest);
        }
        return newSeq;
    }

    static Sequence<T>* QuickSort(Sequence<T>* seq, int first, int last, int (*cmp)(T, T)) { // O(nlogn)
        auto *newSeq = seq->Clone();
        if (newSeq->GetLength() == 0){
            return newSeq;
        }
        T mid;
        int i = first;
        int j = last;
        mid = newSeq->Get((i+j)/2);
        do {
            while(cmp(mid, newSeq->Get(i))) {
                i++;
            }
            while(cmp(newSeq->Get(j), mid)) {
                j--;
            }
            if (i <= j) {
                Swapper(newSeq, i, j);
                i++;
                j--;
            }
        } while (i < j);

        if(first < j) {
            QuickSort(newSeq, first, j, cmp);
        }
        if (i < last) {
            QuickSort(newSeq, i, last, cmp);
        }
        return newSeq;
    }

    static unsigned long long SortTime(int index, Sequence<T>* arr, int (*cmp) (T,T)){
        if(index == 1){
            auto start = std::chrono::high_resolution_clock::now();
            ISorter<T>:: BubbleSort(arr, cmp);
            auto finish = std::chrono::high_resolution_clock::now();
            auto result = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
            return result;// 1000000;
        }
        else if(index == 2){
            auto start = std::chrono::high_resolution_clock::now();
            ISorter<T>:: BubbleShakerSort(arr, cmp);
            auto finish = std::chrono::high_resolution_clock::now();
            auto result = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
            return result;// 1000000;
        }
        else if(index == 3){
            auto start = std::chrono::high_resolution_clock::now();
            ISorter<T>:: InsertionSort(arr, cmp);
            auto finish = std::chrono::high_resolution_clock::now();
            auto result = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
            return result ;// 1000000;
        }
        else if (index == 4){
            auto start = std::chrono::high_resolution_clock::now();
            ISorter<T>:: SelectionSort(arr, cmp);
            auto finish = std::chrono::high_resolution_clock::now();
            auto result = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
            return result ;// 1000000;
        }
        else if(index == 5) {
            auto start = std::chrono::high_resolution_clock::now();
            ISorter<T>::QuickSort(arr, 0, arr->GetLength() - 1, cmp);
            auto finish = std::chrono::high_resolution_clock::now();
            auto result = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
            return result ;// 1000000;
        }
    }

};



//template <typename T>

template <typename T>
int excmp(T a, T b){
    if(a>b)
        return 1;
    else return 0;
}

#endif //LAB1_S3_ISORTER_H
