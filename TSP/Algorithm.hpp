//
//  Algorithm.hpp
//  TSP
//
//  Created by Oscar Alejandro Hernández López on 13/08/21.
//

#ifndef Algorithm_hpp
#define Algorithm_hpp

#include "Header.h"
#include "TSP.hpp"

class Algorithm {
protected:
    string _AlgoName;
    TSP *_dataTSP;
    
    double _TimLim;
    double _MaxIter;
    double _Gap;
    
public:
    
    Algorithm(TSP *data, string AlgoName){
        _dataTSP = data;
        _AlgoName = AlgoName;
        
        _TimLim=3600;
        _MaxIter=1000;
        _Gap=0.01;
    }
    
    string getSolverName() {return _AlgoName;}
};  //This will be the parent class for all algorithms/solvers

#endif /* Algorithm_hpp */
