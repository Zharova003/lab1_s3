#ifndef LAB1_S3_MENU_H
#define LAB1_S3_MENU_H

int cmp_int(int a, int b){
    if(a>b)
        return 1;
    else return 0;
}

int ChooseSort(){
    int sort;
    cout << "What sort do you want to use?: \n"
         << "\t0: Exit\n"
         << "\t1: Bubble Sort\n"
         << "\t2: Bubble Shaker Sort\n"
         << "\t3: Insertion Sort\n"
         << "\t4: Selection Sort\n"
         << "\t5: Quick Sort\n"
         << "\t6: Compare all\n"
         << "Enter a number: ";
    cin >> sort;
    cout << endl;
    /*if (sort < 0 || sort > 5){
        throw invalid_argument("Incorrect number");
    }*/
    return sort;
}

void menu(){
    int len;
    cout << "\nEnter a dimension of sequence: ";
    cin >> len;
    cout << endl;
    if (len < 0) {
        throw "Incorrect number";
    }
    auto *seq1 = new ArraySequence<int>(len);
    auto *seq2 = new LinkedListSequence<int>();
    cout << "Enter elements of sequence: ";
    int element;
    for (int i = 0; i < len; i++) {
        cin >> element;
        seq1->Set(i, element);
        seq2->Append(element);
    }
    int s = 1;
    do {
        s = ChooseSort();
        switch (s) {
            case 0:
                break;
            case 1:{
                auto *newseq = ISorter<int>::BubbleSort(seq1, cmp_int);
                for (int i = 0; i < len; i++){
                    cout << newseq->Get(i) << " ";
                }
                cout << endl;
                cout << "AS  " << ISorter<int>::SortTime(1, seq1, cmp_int) << endl;
                cout << "LLS " << ISorter<int>::SortTime(1, seq2, cmp_int) << endl;
                break;
            }
            case 2:{
                auto *newseq = ISorter<int>::BubbleShakerSort(seq1, cmp_int);
                for (int i = 0; i < len; i++){
                    cout << newseq->Get(i) << " ";
                }
                cout << endl;
                cout << "AS  " << ISorter<int>::SortTime(2, seq1, cmp_int) << endl;
                cout << "LLS " << ISorter<int>::SortTime(2, seq2, cmp_int) << endl;
                break;
            }
            case 3:{
                auto *newseq = ISorter<int>::InsertionSort(seq1, cmp_int);
                for (int i = 0; i < len; i++){
                    cout << newseq->Get(i) << " ";
                }
                cout << endl;
                cout << "AS  " << ISorter<int>::SortTime(3, seq1, cmp_int) << endl;
                cout << "LLS " << ISorter<int>::SortTime(3, seq2, cmp_int) << endl;
                break;
            }
            case 4:{
                auto *newseq = ISorter<int>::SelectionSort(seq1, cmp_int);
                for (int i = 0; i < len; i++){
                    cout << newseq->Get(i) << " ";
                }
                cout << endl;
                cout << "AS  " << ISorter<int>::SortTime(4, seq1, cmp_int) << endl;
                cout << "LLS " << ISorter<int>::SortTime(4, seq2, cmp_int) << endl;
                break;
            }
            case 5:{
                auto *newseq = ISorter<int>::QuickSort(seq1, 0, len - 1, cmp_int);
                for (int i = 0; i < len; i++){
                    cout << newseq->Get(i) << " ";
                }
                cout << endl;
                cout << "AS  " << ISorter<int>::SortTime(5, seq1, cmp_int) << endl;
                cout << "LLS " << ISorter<int>::SortTime(5, seq2, cmp_int) << endl;
                break;
            }
            case 6: {
                auto *newseq = ISorter<int>::SelectionSort(seq1, cmp_int);
                for (int i = 0; i < len; i++){
                    cout << newseq->Get(i) << " ";
                }
                cout << endl;
                cout << "method   AS   LLS" << endl;
                cout << "Bubble   " <<  ISorter<int>::SortTime(1, seq1, cmp_int) << "   " << ISorter<int>::SortTime(1, seq2, cmp_int) << endl;
                cout << "Shaker   " <<  ISorter<int>::SortTime(2, seq1, cmp_int) << "   " << ISorter<int>::SortTime(2, seq2, cmp_int) << endl;
                cout << "Insert   " <<  ISorter<int>::SortTime(3, seq1, cmp_int) << "   " << ISorter<int>::SortTime(3, seq2, cmp_int) << endl;
                cout << "Select   " <<  ISorter<int>::SortTime(4, seq1, cmp_int) << "   " << ISorter<int>::SortTime(4, seq2, cmp_int) << endl;
                cout << "Quick    " <<  ISorter<int>::SortTime(5, seq1, cmp_int) << "   " << ISorter<int>::SortTime(5, seq2, cmp_int) << endl;
                break;
            }
        }
    } while (s);
}

#endif //LAB1_S3_MENU_H
