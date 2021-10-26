#ifndef GAMESOLVER_H_
#define GAMESOLVER_H_

#include "nut.h"
#include <vector>
#include <map>
#include <array>

#define NUMBER_OF_NUTS 7

namespace DriveYaNuts
{
    class GameSolver
    {    
        public:
            GameSolver();
            void start();  
            void printNuts();
            void printSolution();
            void changeNuts(int values[NUMBER_OF_NUTS][NUT_SIZE]);
        
        protected:
            void populateList();
            std::array<std::string, NUMBER_OF_NUTS> m_NutPositions;
            std::vector<Nut> m_NutList;
            std::map<std::string, Nut> m_SolvedNutList;       
    };
}

#endif /* GAMESOLVER_H_ */

// EOF