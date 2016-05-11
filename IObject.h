//
// Created by gri on 28.04.16.
//

#ifndef HOMETASK8_IOBJECT_H
#define HOMETASK8_IOBJECT_H

#include "iostream"
class Multiset;
class IObject {
private:

    virtual std::string print() = 0;

    friend std::ostream& operator << (std::ostream& ostream, Multiset& multiset);

public:

    //IObject();
    virtual ~IObject() {};

    virtual bool equal(IObject*) = 0;
    virtual IObject* clone() = 0;




};


class IntObject : public IObject {

private:

    int elem;

    std::string print();

public:

    IntObject(int elem);
    ~IntObject();

    bool equal(IObject*);
    IObject* clone();




};




class DoubleObject : public IObject {

private:

    double elem;
    std::string print();
public:
    DoubleObject(double elem);
    ~DoubleObject();

    bool equal(IObject*);
    IObject* clone();




};

class StringObject : public IObject {

private:
    std::string elem;
    std::string print();
public:
    StringObject(std::string elem);
    ~StringObject();


    bool equal(IObject*);
    IObject* clone();



};


// определение функций вне класса.
#endif //HOMETASK8_IOBJECT_H
