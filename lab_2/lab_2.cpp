
#include <iostream>
using namespace std;
const static int block_size = 100;
struct block_struct {
    int k;
    char c;
};
struct list {
    block_struct* block= NULL;
    bool occupied = false; // занят ли блок
};

short add(list*&s, short&size) {
    for (short i = 0; i < size; i++) {
        if (s[i].occupied == false) {
            s[i].block = new block_struct[block_size];// выделение памяти под блок int
            s[i].occupied = true;
            return i;
        }
    }
    list* h = s;
    s = new list[size * 2];
    for (int i = 0; i < size; i++) {
        s[i] = h[i];
    }
    delete[]h;
    s[size].block = new block_struct[block_size];
    s[size].occupied = true;
    short k = size;
    size = size * 2;
    return k;
}
void Delete(list* s,const int k,const int size) {
    // s - указатель на массив
    // k - номер , который освободить
    // size - размер массива
    if (k < size) {
        if (s[k].occupied == true) {
            delete[]s[k].block;
            s[k].occupied = false;
        }
    }
}

short Delete(list* s, const int size) {
    // s - указатель на массив
    // size - размер массива
    for (short i = 0; i < size; i++) {
        if (s[i].occupied == true) {
            return i;
        }
    }
    return -1;
}
int main()
{
    short n = 10; // размер массива
    list* s = new list[n]; // массив для управления блоками

    // добавление
    for (short i = 0; i < 100; i++) {
        cout << add(s, n) << endl;
    }
    //освобождение конкретного места (индекс 5)
    Delete(s, 5, n);
    Delete(s, 5, n);
    Delete(s, 5, n);

    //освобождение любого заполненного места
    cout << Delete(s, n) << endl;
    cout << Delete(s, n) << endl;
    cout << Delete(s, n) << endl;
    cout << Delete(s, n) << endl;

    
    
        
}
