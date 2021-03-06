//
//  main.cpp
//  TSP
//
//  Created by Oscar Alejandro Hernández López on 13/08/21.
//


#include "Header.h"
#include "TSP.hpp"
#include "CPLEXSolver.hpp"

int main(int argc, const char * argv[]) {
    
    if(argc!=3){
        
        cout<<"Error: missing arguments"<<endl;
        exit(10);
    }
    
    string pathname(argv[1]); cout<<pathname<<endl;
    double TimLim=atof(argv[2]);
    
    TSP *data = new TSP(pathname);
    
    Algorithm *Cplex = new CplexModel(data);
    //CplexModel *p = new CplexModel(data);
    
    
    return 0;
}
