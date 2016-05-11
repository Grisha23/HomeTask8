#include <iostream>
#include "Multiset.h"
std::ostream& operator << (std::ostream& ostream, Multiset& multiset)
{
    for (int i = 0; i < multiset.size; ++i) {

        ostream << ((*(multiset.elem[i])).print()) ;
        if (i < multiset.size - 1) ostream << ", ";
    }
    return ostream;
}



int main() {

    IObject *object5 = new IntObject(5);
    IObject *object6 = new IntObject(6);
    IObject *object7 = new IntObject(7);
    IObject *object8 = new IntObject(8);
    IObject *object9 = new IntObject(9);
    IObject *object10 = new IntObject(10);
    IObject *object11 = new IntObject(11);
    IObject *object12 = new IntObject(12);
    IObject *object13 = new IntObject(13);
    IObject *object14 = new IntObject(14);

   /* IObject *object5 = new IntObject("Вася");
    IObject *object6 = new IntObject("Ксюша");
    IObject *object7 = new IntObject("Гриша");
    IObject *object8 = new IntObject("---");
    IObject *object9 = new IntObject("Маша");
    IObject *object10 = new IntObject("Лена");
    IObject *object11 = new IntObject("Боря");
    IObject *object12 = new IntObject("Настя");
    IObject *object13 = new IntObject("Аня");
    IObject *object14 = new IntObject("Кирилл");*/

    Multiset mult;

    mult.insert(object5);
    mult.insert(object6);
    mult.insert(object7);
    mult.insert(object8);
    mult.insert(object8);
    mult.insert(object11);
    mult.insert(object13);
    mult.insert(object9);
    mult.insert(object14);
    mult.insert(object9);


    std::cout << "Первое множество : \n" << mult << "\n";

    Multiset mult1;

    mult1.insert(object5);
    mult1.insert(object8);
    mult1.insert(object9);
    mult1.insert(object5);
    mult1.insert(object8);
    mult1.insert(object12);
    mult1.insert(object14);

    std::cout << "Второе множество : \n" << mult1 << "\n";


    Multiset *tmp;
    tmp = mult.intersection(&mult1);
    std::cout << "Пересечение: \n" << *tmp <<std::endl;
    delete(tmp);
    tmp = mult._union(&mult1);
    std::cout << "Объединение: \n" << *tmp <<std::endl;;
    delete(tmp);
    tmp = mult.difference(&mult1);
    std::cout << "Разность 1-2: \n" << *tmp <<std::endl;;
    delete(tmp);
    tmp = nullptr;

    mult1.erase();
    std::cout << "Удаляем последний из второго множества : \n" << mult1 << "\n";

    std::cout << "Принадлежность элемента 10 к первому множеству - " << mult.include(object10) << "\n";


    std::cout << "Принадлежность элемента 8 ко второму множеству - " << mult1.include(object8) << "\n";
   // std::cout<< "Капасити = " << mult.get_capacity() << " Сайз = " << mult.get_size() << " ";

  //  std::cout << mult;

   // IObject *tmp = new DoubleObject(3.41);
    //std::cout << *tmp;

    delete(object5);
    delete(object6);
    delete(object7);
    delete(object8);
    delete(object9);
    delete(object10);
    delete(object11);
    delete(object12);
    delete(object13);
    delete(object14);

    return 0;
}