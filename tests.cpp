#include <gtest/gtest.h>
#include "DynamicArray.h"
#include "LInkedList.h"
#include "ArraySequence.h"
#include "LinkedListSequence.h"
#include "ISorter.h"
#include <cmath>

int arr[] = {1, 4, 3, 2};
int *pointer = arr;

template <typename T>
int cmp(T a, T b){
    if(a>b)
        return 1;
    else return 0;
}

TEST(ArraySequence, Get) {
    auto *seq = new ArraySequence<int>(arr, 4);
    EXPECT_EQ(seq->Get(0), 1);
    EXPECT_THROW(seq->Get(-1), out_of_range);
}

TEST(ArraySequence, GetLength) {
    auto *seq = new ArraySequence<int>(arr, 4);
    EXPECT_EQ(seq->GetLength(), 4);
}

TEST(ArraySequence, Append) {
    auto *seq = new ArraySequence<int>(arr, 4);
    seq->Append(12);
    EXPECT_EQ(seq->Get(4), 12);
}

TEST(ArraySequence, Prepend) {
    auto *seq = new ArraySequence<int>(arr, 4);
    seq->Prepend(12);
    EXPECT_EQ(seq->Get(0), 12);
}

TEST(ListSequence, Get) {
    auto *seq = new LinkedListSequence<int>(pointer, 4);
    EXPECT_EQ(seq->Get(0), 1);
    EXPECT_THROW(seq->Get(-1), out_of_range);
}

TEST(ListSequence, GetSize) {
    auto *seq = new LinkedListSequence<int>(pointer, 4);
    EXPECT_EQ(seq->GetLength(), 4);
}

TEST(ListSequence, Append) {
    auto *seq = new LinkedListSequence<int>(pointer, 4);
    seq->Append(12);
    EXPECT_EQ(seq->Get(4), 12);
}

TEST(ListSequence, Prepend) {
    auto *seq = new LinkedListSequence<int>(pointer, 4);
    seq->Prepend(12);
    EXPECT_EQ(seq->Get(0), 12);
}

TEST(BubbleSort, ArraySequence){
    ArraySequence<int> array(arr, 4);
    //ArraySequence<int> *arrays = dynamic_cast<ArraySequence<int> *>(ISorter<int>::BubbleSort(&array, cmp));
    auto arrays = (ISorter<int>::BubbleSort(&array, cmp));
    EXPECT_EQ(arrays->Get(0), 1);
    EXPECT_EQ(arrays->Get(1), 2);
    EXPECT_EQ(arrays->Get(2), 3);
    EXPECT_EQ(arrays->Get(3), 4);
}

TEST(BubbleSort, LinkedListSequence){
    LinkedListSequence<int> array(arr, 4);
    auto arrays = ISorter<int>::BubbleSort(&array, cmp);
    EXPECT_EQ(arrays->Get(0), 1);
    EXPECT_EQ(arrays->Get(1), 2);
    EXPECT_EQ(arrays->Get(2), 3);
    EXPECT_EQ(arrays->Get(3), 4);
}

TEST(BubbleShakerSort, ArraySequence){
    ArraySequence<int> array(arr, 4);
    auto arrays = ISorter<int>::BubbleShakerSort(&array, cmp);
    EXPECT_EQ(arrays->Get(0), 1);
    EXPECT_EQ(arrays->Get(1), 2);
    EXPECT_EQ(arrays->Get(2), 3);
    EXPECT_EQ(arrays->Get(3), 4);
}

TEST(BubbleShakerSort, LinkedListSequence){
    LinkedListSequence<int> array(arr, 4);
    auto arrays = ISorter<int>::BubbleShakerSort(&array, cmp);
    EXPECT_EQ(arrays->Get(0), 1);
    EXPECT_EQ(arrays->Get(1), 2);
    EXPECT_EQ(arrays->Get(2), 3);
    EXPECT_EQ(arrays->Get(3), 4);
}

TEST(InsertionSort, ArraySequence){
    ArraySequence<int> array(arr, 4);
    auto arrays = ISorter<int>::InsertionSort(&array, cmp);
    EXPECT_EQ(arrays->Get(0), 1);
    EXPECT_EQ(arrays->Get(1), 2);
    EXPECT_EQ(arrays->Get(2), 3);
    EXPECT_EQ(arrays->Get(3), 4);
}

TEST(InsertionSort, LinkedListSequence){
    LinkedListSequence<int> array(arr, 4);
    auto arrays = ISorter<int>::InsertionSort(&array, cmp);
    EXPECT_EQ(arrays->Get(0), 1);
    EXPECT_EQ(arrays->Get(1), 2);
    EXPECT_EQ(arrays->Get(2), 3);
    EXPECT_EQ(arrays->Get(3), 4);
}

TEST(SelectionSort, ArraySequence){
    ArraySequence<int> array(arr, 4);
    auto arrays = ISorter<int>::SelectionSort(&array, cmp);
    EXPECT_EQ(arrays->Get(0), 1);
    EXPECT_EQ(arrays->Get(1), 2);
    EXPECT_EQ(arrays->Get(2), 3);
    EXPECT_EQ(arrays->Get(3), 4);
}

TEST(SelectionSort, LinkedListSequence){
    LinkedListSequence<int> array(arr, 4);
    auto arrays = ISorter<int>::SelectionSort(&array, cmp);
    EXPECT_EQ(arrays->Get(0), 1);
    EXPECT_EQ(arrays->Get(1), 2);
    EXPECT_EQ(arrays->Get(2), 3);
    EXPECT_EQ(arrays->Get(3), 4);
}

TEST(QuickSort, ArraySequence){
    ArraySequence<int> array(arr, 4);
    auto arrays = ISorter<int>::QuickSort(&array, 0, array.GetLength()-1, cmp);
    EXPECT_EQ(arrays->Get(0), 1);
    EXPECT_EQ(arrays->Get(1), 2);
    EXPECT_EQ(arrays->Get(2), 3);
    EXPECT_EQ(arrays->Get(3), 4);
}


