//
// Created by 肖应雄 on 2021/12/27.
//

#ifndef STL__3_2_2_MYLIST_H
#define STL__3_2_2_MYLIST_H

#include <iostream>
using namespace std;

// 声明
template<typename T>
class ListItem;


template<typename T>
class List{
public:
    void insert_front(T value);
    void insert_end(T value);
    void display(ostream &os = cout ) const;
    ListItem<T>* front(){
        return _front;
    }

    List() ;

private:
    ListItem<T> *_end;
    ListItem<T> *_front;
    long _size;
};

template<typename T>
List<T>::List() {
    _size = 0;
    _front = NULL;
    _end = NULL;
}

template<typename T>
void List<T>::insert_front(T value) {
    ListItem<T> *temp = new ListItem<T>(value);
    temp->set_next(_front);
    _front = temp;
    ++ _size;
}

template <typename T>
void List<T>::insert_end(T value) {
    ListItem<T>* temp = new ListItem<T>(value);
    ListItem<T> *last = _front;
    while (last->next() != _end)
        last = last->next();
    last->set_next(temp);
    _end = temp->next();
    _size++;
}

template<typename T>
void List<T>::display(ostream &os) const {
    auto temp = _front;
    while (temp != _end){
        cout << temp->value() << " ";
        temp = temp->next();
    }
    cout << endl;
}




template<typename T>
class ListItem{
public:
    T value() const{
        return _value;
    }
    ListItem* next() const{
        return _next;
    }
    void set_next(ListItem* i){
        _next = i;
    }
    ListItem(T value): _value(value){
        _next = NULL;
    }

private:
    T _value;
    ListItem *_next;
};

#endif //STL__3_2_2_MYLIST_H
