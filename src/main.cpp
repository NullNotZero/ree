
#include <omp.h>
#include <iostream>
#include <iomanip>
#include "CStopWatch.h"


double serialPi(int n, int numThreads = 1){
    double sum = 0.0;
    double factor = 1.0;
    double retValue = 0.0;

    #pragma omp parallel for num_threads(numThreads) reduction(+:sum) private(factor)
    for(int i=0; i< n; i++){

        if(i%2 == 0){ factor = 1.0;}
        else        { factor = -1.0;}

        sum += factor/(2*i+1);
       
    }
    retValue = 4.0*sum;

    return retValue;
}

int main(){

    int n = 100000;
    double result =0;
    int maxThreads = 12;

    for(int numThreads=1; numThreads<maxThreads; numThreads++){
        result = serialPi(n, numThreads);
        std::cout << result << std::endl;
    }
    return 0;   
}
