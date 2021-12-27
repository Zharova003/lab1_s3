//
// Created by Александр on 07.05.2021.
//

#ifndef LAB2_1_DYNAMICARRAY_H
#define LAB2_1_DYNAMICARRAY_H
#include <cassert>
using namespace std;

template <class T>
class DynamicArray {
private:
    T* data;
    int lenght;
public:
// Конструкторы
    DynamicArray() {
        data = NULL;
        lenght = 0;
    }
    DynamicArray(int size) //	Создать массив заданной длины
    {
        if (size<0) {throw length_error("size must be >0");}
        data = new T[size];
        lenght = size;
    }

    DynamicArray(T* items, int count) //	Копировать элементы из переданного массива
    {
        if (count<0) {throw length_error("size must be >0");}
        data = new T[count];
        lenght = count;
        for (int i = 0; i < lenght ; i++)
        {
            data[i] = items[i];
        }
    }

    DynamicArray(DynamicArray<T>& dynamicArray) //	Копирующий конструктор
    {
        lenght = dynamicArray.lenght;
        data = new T[lenght];
        for (int i = 0; i < lenght; i++)
        {
            data[i] = dynamicArray.Get(i);
        }
    }

// Декомпозиция

    // Получить элемент по индексу.
    // Может выбрасывать исключения :	− IndexOutOfRange(если индекс отрицательный, больше
    // или равен числу элементов или указывает на не заданный элемент)
    T Get(int index)
    {
        if (lenght == 0) { throw out_of_range(": Index out of range! Dynamic Array is empty!"); }
        if (index >= lenght) { throw out_of_range(": Index out of range!"); }
        if (index < 0) { throw out_of_range(": Index must be > 0"); }
        return data[index];
    }
    int GetSize() //	Получить размер массива
    {
        return lenght;
    }

// Операции
    void Set(int index, T value) // Задать элемент по индексу. Может выбросить IndexOutOfRange
    {
        if (lenght == 0) { throw out_of_range(": Index out of range! Dynamic Array is empty!"); }
        if (index >= lenght) { throw out_of_range(": Index out of range!"); }
        if (index < 0) { throw out_of_range(": Index must be > 0"); }
        data[index] = value;
    }

    // Изменить размер массива.Если размер увеличивается, все элементы копируются в начало новой памяти.
    // Если уменьшается – элементы, которые не помещаются, отбрасываются.
    void Resize(int size)
    {
        if (size < 0) {
            throw length_error("Negative size!");
        }
        T* newData = new T[size];
        for (int i = 0; i < (this->lenght > size ? size : this->lenght); i++) {
            newData[i] = data[i];
        }
        delete[] data;
        this->data = newData;
        this->lenght = size;
    }

};


#endif //LAB2_1_DYNAMICARRAY_H
