//
// Created by gri on 28.04.16.
//

#include "Multiset.h"
#include <typeinfo>
Multiset::Multiset()
{
    elem = new IObject*[2];
    size = 0;
    capacity = 2;
}

Multiset::Multiset(int size)
{
    elem = new IObject*[size];
    this->size = 0;
    capacity = size;
}


Multiset::~Multiset()
{
  //  std::cout << "Вызван деструктор" << "\n";
    for (int i = 0; i < size; ++i) {
        delete(elem[i]);
    }
    delete[] elem;

}

Multiset::Multiset(Multiset &multiset)
{
    elem = new IObject*[multiset.size];
    size = multiset.size;

    for (int i = 0; i < size; ++i) {
        elem[i] = multiset.elem[i]->clone();
    }
}




void Multiset::insert(IObject* object1)
{
    IObject *object = object1->clone();
    if (size != 0 && typeid(object) != typeid(elem[size-1])) {
        std::cout << "error: объекты должны быть одного типа.\n" ;
        std::__throw_bad_function_call();
    }

    if (size + 1 <= capacity) {
        elem[size] = object;
        size++;
    }
    else {
        resize();
        elem[size] = object;
        size++;
    }
    object = nullptr;
}

void Multiset::resize()
{

    IObject **tmp = new IObject*[capacity*2];

    for (int i = 0; i < size; ++i) {
        tmp[i] = elem[i]->clone();
    }

    for (int j = 0; j < size; ++j) {
        delete(elem[j]);
    }
    delete[] elem;
    elem = tmp;
    tmp = nullptr;
    capacity = capacity * 2;

}

bool Multiset::include(IObject* object)
{
    for (int i = 0; i < size; ++i) {
        if (elem[i]->equal(object)) return true;
    }
    return false;
}

void Multiset::erase()
{
    delete elem[size-1];
    size--;
}

void Multiset::erase(int n)
{
    if (n >= size) std::__throw_out_of_range("erase");

    delete elem[n];

    for (int i = n; i < size - 1; ++i) {
        elem[i] = elem[i+1];
    }
    size--;


}

IObject* Multiset::get_elem(int n)
{
    return elem[n];
}

Multiset* Multiset::intersection(Multiset* multiset)
{

    int min = 0;
    int max = 0;
    bool flag = false; // первый больше

    if (size < multiset->size) {
        min = size;
        max = multiset->size;
        flag = true; // второй больше
    }
    else {
        min = multiset->size;
        max = size;

    }

    Multiset *inter = new Multiset(min);

    for (int i = 0; i < min; ++i) {
        for (int j = 0; j < max; ++j) {
            if (!flag) {
                if (multiset->elem[i]->equal(elem[j])) {
                    inter->insert(elem[j]);
                    j = max;
                }

            }
            else {
                if (multiset->elem[j]->equal(elem[i])) {
                    inter->insert(elem[i]);
                    j = max;
                }

            }
        }
    }

    inter->delete_equal();

    return inter;
}

void Multiset::delete_equal()
{
    for (int i = 0; i < this->size; ++i) {
        for (int j = i+1; j < this->size; ++j) {
            if (elem[i]->equal(elem[j])) {
                this->erase(j);
                j--;
            }
        }
    }
}

Multiset* Multiset::_union(Multiset* multiset)
{
    int new_size = size + multiset->size;

    Multiset *un = new Multiset(new_size);

    for (int i = 0; i < size; ++i) {
        un->insert(elem[i]);
    }
    for (int j = 0; j < multiset->size; ++j) {
        un->insert(multiset->elem[j]);
    }
    return un;
}

Multiset* Multiset::difference(Multiset* multiset)
{
    Multiset *diff = new Multiset();

    *diff = *this;


    for (int i = 0; i < diff->size; ++i) {
        for (int j = 0; j < multiset->size; ++j) {
            if (diff->elem[i]->equal(multiset->elem[j])) {
                diff->erase(i);
                i--;
                break;
            }
        }
    }
    return diff;
}

int Multiset::get_size()
{
    return size;
}

int Multiset::get_capacity()
{
    return capacity;
}

void Multiset::operator = (Multiset &multiset)
{

    delete[] elem;

    elem = new IObject*[multiset.size];
    size = multiset.size;

    for (int j = 0; j < size; ++j) {
        elem[j] = multiset.elem[j]->clone();
    }
  //  return *this;
}

void Multiset::operator = (Multiset &&multiset)
{
    delete[] elem;

    elem = multiset.elem;
    size = multiset.size;
    capacity = multiset.capacity;


    //  return *this;
}