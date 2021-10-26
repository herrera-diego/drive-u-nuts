#ifndef NUT_H_
#define NUT_H_

// #ifdef __cplusplus
// extern "C" {
// #endif

#define NUT_SIZE 6

namespace DriveYaNuts
{
    class Nut
    {    
        public:
            Nut(int values[]); 
            int rotateLeft();
            int rotateRight();
            int getCurrentSide();  
            int getLeftSide();  
            int getRightSide();    
            void printValues();
            bool compareSides(Nut nut);
            void getValues(int * values) const;
            bool operator == (const Nut& nut) const;
        protected:
            int getLeftIndex();  
            int getRightIndex(); 
            int m_currentIndex;
            int m_values[NUT_SIZE];
    };
}

#endif /* NUT_H_ */

// EOF