
#include <omp.h>
#include <iostream>
#include <iomanip>
#include "CStopWatch.h"

double serialPi(int n, int numThreads=1) {
   double sum = 0.0;
   double factor = 1.0;
   double retValue = 0;


    #pragma omp parallel for num_threads(numThreads) reduction(+:sum) private(factor)
    for (int i = 0; i < n; i++) {
        
    
        sum += factor/(2*i+1);
        // factor = -factor;

        if(i%2 == 0){ factor = 1.0;}
        else        { factor = -1.0; }
      
    }
   retValue = 4.0*sum;

   return retValue;

}

int main(){

    int numThreads;
    int threadMin, threadMax, threadStep;
    int n;
    CStopWatch timer;
    double result;

    n = 1000;
    threadMin = 1; threadMax = 10; threadStep = 1;

    for(numThreads=threadMin; numThreads<=threadMax; numThreads+=threadStep){
        for(int curTrial=0; curTrial<1; curTrial++){
            result = 0.0;
            omp_set_num_threads(numThreads);
            timer.startTimer();
            result = serialPi(n, numThreads); 
            timer.stopTimer();
            std::cout << numThreads << ", " << n << ", " << std::setprecision(20) << result << ", " << std::setprecision(5) << std::fixed << timer.getElapsedTime() << "\n";
        }
    }


    return 0;
}