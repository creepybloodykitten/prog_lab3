#include <iostream>
#include <vector>
#include "Spis_array.h"
#include "Posled_array.h"
#include <typeinfo>


int main()
{
    //использование двухсвязного спиского контейнера
    std::cout<<"2connected: ";
    Spis2_array<int> m{1,2,3,4};
    for(int i=0;i<m.size();i++)
    {
        std::cout<<m[i]<<" ";
    }
    std::cout<<std::endl<<"insert(2,99): ";
    m.insert(2,99);
    for(int i=0;i<m.size();i++)
    {
        std::cout<<m[i]<<" ";
    }
    std::cout<<std::endl<<"pushback(22): ";
    m.pushback(22);
    for(int i=0;i<m.size();i++)
    {
        std::cout<<m[i]<<" ";
    }

    //использование односвязного спиского контейнера
    std::cout<<std::endl<<std::endl<<"1connected: ";
    Spis1_array<int> m1{1,2,3,4,5};
        for(int i=0;i<m1.size();i++)
    {
        std::cout<<m1[i]<<" ";
    }
    std::cout<<std::endl<<"erase(2,3): ";
    m1.erase(2,3);
    for(int i=0;i<m1.size();i++)
    {
        std::cout<<m1[i]<<" ";
    }


    //использование последовального контейнера
    std::cout<<std::endl<<std::endl<<"posled: ";
    Posled_arr<int> m3{1,2,2,4,5};
    for(int i=0;i<m3.size();i++)
    {
        std::cout<<m3[i]<<" ";
    }
    std::cout<<std::endl<<"creation serial arr with rvalue-link";
    Posled_arr<int> m3_1=std::move(m3);
    for(int i=0;i<m3_1.size();i++)
    {
        std::cout<<*(m3_1+i)<<" ";
    }
}
