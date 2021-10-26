#include "nut.h"

#include <iostream>
#include <algorithm>



using namespace DriveYaNuts;

Nut::Nut(int values[])
{
    std::copy(values, values+NUT_SIZE, m_values);
    m_currentIndex = 0;
}

void Nut::printValues()
{
    for (auto &value : m_values)
    {
        std::cout<<value<<" "; 
    }
    std::cout<<std::endl;
}

void Nut::getValues(int * values) const
{
    for (size_t i = 0; i < NUT_SIZE; i++)
    {
        values[i] = m_values[i];
    }
    
}

int Nut::getLeftIndex()
{
    return (m_currentIndex + NUT_SIZE - 1) % NUT_SIZE;
}

int Nut::getRightIndex()
{
    return (m_currentIndex + 1) % NUT_SIZE;
}


int Nut::getCurrentSide()
{
    return m_values[m_currentIndex];
}

int Nut::getLeftSide()
{
    return m_values[getLeftIndex()];
}

int Nut::getRightSide()
{
    return m_values[getRightIndex()];
}

int Nut::rotateLeft()
{
    m_currentIndex = getLeftIndex();
    return m_values[m_currentIndex];
}

int Nut::rotateRight()
{
    m_currentIndex = getRightIndex();
    return m_values[m_currentIndex];
}

bool Nut::compareSides(Nut nut)
{
    bool result = false;
    if(nut.getCurrentSide()==this->getCurrentSide())
    {
        if((nut.getLeftSide()!=this->getLeftSide()) && (nut.getRightSide()!=this->getRightSide()))
        {
            result = true;
        }
    }

    return result;
}

bool Nut::operator == (const Nut& lhs) const 
{
    bool status = true;
    int lhs_values[6];
    int rhs_values[6];

    lhs.getValues(lhs_values);
    this->getValues(rhs_values);

    for (size_t i = 0; i < NUT_SIZE; i++)
    {
    

        if(lhs_values[i] != rhs_values[i])
        {
            status = false;
            break;
        }
    }
    
    return status;
}