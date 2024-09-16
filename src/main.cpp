
#include <omp.h>
#include <iostream>
#include <iomanip>
#include "CStopWatch.h"

double serialPi(int n, int numThreads=1) {
  

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