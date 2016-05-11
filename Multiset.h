//
// Created by gri on 28.04.16.
//

#ifndef HOMETASK8_MULTISET_H
#define HOMETASK8_MULTISET_H

#include "IObject.h"

class Multiset {

private:
    IObject **elem;
    int size;
    int capacity;

    void resize();

public:
    void delete_equal();

    friend std::ostream& operator << (std::ostream& ostream, Multiset& multiset);

    Multiset();
    Multiset(int size);
    ~Multiset();
    Multiset(Multiset &multiset);

    void insert(IObject* object);
    bool include(IObject* object);
    void erase();
    void erase(int n);

    Multiset* intersection(Multiset* multiset); // Пересечение
    Multiset* _union(Multiset* multiset); // Объединение
    Multiset* difference(Multiset* multiset); //Разница двух множеств

    int get_size();

    int get_capacity();

    IObject* get_elem(int n);

    void operator = (Multiset &multiset);
    void operator = (Multiset &&multiset);


};


#endif //HOMETASK8_MULTISET_H
