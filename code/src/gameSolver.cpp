#include "gameSolver.h"

#include <iostream>


using namespace DriveYaNuts;

GameSolver::GameSolver()
{
    populateList();
}

void GameSolver::start()
{
    for (size_t i = 0; i < NUMBER_OF_NUTS; i++)
    {
        int positionCounter = 0;
        Nut center = m_NutList[i];
        m_SolvedNutList.insert({m_NutPositions[positionCounter], center});
        positionCounter++;
        for (int i = 0; i < NUMBER_OF_NUTS; i++)
        {
            if(m_NutList[i] == center)
            {
                continue;
            }

            if(center.compareSides(m_NutList[i]))
            {
                center.rotateRight();
                m_SolvedNutList.insert({m_NutPositions[positionCounter], m_NutList[i]});
                positionCounter++;
            }
            
        }
        if (positionCounter>1)
        {
            break;
        }
        else
        {
            positionCounter = 0;
            m_SolvedNutList.clear();
        }
    }
    

    
}


void GameSolver::printNuts()
{
    std::cout<<"Nuts: "<<std::endl;
    for (auto &nut : m_NutList)
    {
        nut.printValues();
    }
}


void GameSolver::printSolution()
{
    std::cout<<"Solution: "<<std::endl;
    for (auto &nut : m_SolvedNutList)
    {
        std::cout<<nut.first<<" - ";
        nut.second.printValues();
    }
}


void GameSolver::populateList()
{
    int values[NUMBER_OF_NUTS][NUT_SIZE] = {
        {1,2,3,4,5,6}, //South 
        {1,6,4,2,5,3}, //SW
        {2,1,6,5,4,3}, //NW
        {1,4,6,2,3,5}, //North
        {4,5,3,1,6,2}, //Center
        {1,6,5,3,2,4}, //NE
        {6,5,2,1,4,3} //SE
    };

    for(int i=0; i < NUMBER_OF_NUTS; i++)
    {
        Nut nut (values[i]);
        m_NutList.push_back(nut);
    }

    m_NutPositions = {"Center",
                      "North",
                      "NorthEast",
                      "SouthEast",
                      "South",
                      "SouthWest",
                      "NorthWest" };
    
}

void GameSolver::changeNuts(int values[NUMBER_OF_NUTS][NUT_SIZE])
{
    m_NutList.clear();

    for(int i=0; i < NUMBER_OF_NUTS; i++)
    {
        Nut nut (values[i]);
        m_NutList.push_back(nut);
    }
}