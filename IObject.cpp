//
// Created by gri on 28.04.16.
//

#include "IObject.h"

std::string IntObject::print()
{
    return std::to_string(elem);
}
std::string DoubleObject::print()
{
    return std::to_string(elem);
}
std::string StringObject::print()
{
    return elem;
}


IntObject::IntObject(int elem)
{
    this->elem = elem;
}

IntObject::~IntObject()
{
  //  std::cout << "Вызван деструктор."<< "\n";
}

bool IntObject::equal(IObject* object)
{
    return (this->elem == (dynamic_cast<IntObject*>(object))->elem);
}

IObject* IntObject::clone()
{
    IObject* tmp = new IntObject(elem);
    return tmp;
}



//=========================================================================================
//=========================================================================================


DoubleObject::DoubleObject(double elem)
{
    this->elem = elem;
}

DoubleObject::~DoubleObject()
{

}

bool DoubleObject::equal(IObject* object)
{
    DoubleObject *tmp = dynamic_cast<DoubleObject*>(object);
    if (tmp != nullptr)
    return (this->elem == (dynamic_cast<DoubleObject*>(object))->elem);
    else std::__throw_bad_cast();
}

IObject* DoubleObject::clone()
{
    IObject *tmp = new DoubleObject(elem);
    return tmp;
}


//=========================================================================================
//=========================================================================================

StringObject::StringObject(std::string elem)
{
    this->elem = elem;
}

StringObject::~StringObject()
{

}

bool StringObject::equal(IObject* object)
{
    return (this->elem == (dynamic_cast<StringObject*>(object))->elem);
}


IObject* StringObject::clone()
{
    IObject *tmp = new StringObject(elem);
    return tmp;
}


