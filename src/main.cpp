#ifdef _OPENMP
    #include <omp.h>
#endif
#include <iostream>

double serialPi(int n) {
   double sum = 0.0;
   double factor = 1.0;
   double retValue = 0;


    for (int i = 0; i < n; i++) {
        sum += factor/(2*i+1);
        factor = -factor;
    }
   retValue = 4.0*sum;

   return retValue;

}

int main(){

    #ifdef _OPENMP
        int myRank = omp_get_thread_num();
        int numThreads = omp_get_num_threads();
    #else
        int myRank = 0;
        int numThreads = 1;
    #endif


    return 0;
}