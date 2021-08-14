//
//  CPLEXSolver.cpp
//  TSP
//
//  Created by Oscar Alejandro Hernández López on 13/08/21.
//

#include "CPLEXSolver.hpp"

CplexModel::CplexModel(TSP *data):Algorithm(data, "CplexSolver"){
    
    //Object Initialization
    _model=IloModel(_env);
    _cplex=IloCplex(_model);
    _obj = IloAdd(_model, IloMinimize(_env,0));
    _Constraints = IloRangeArray(_env);
    
    _x = IloArray<IloNumVarArray> (_env,_dataTSP->getnnodes());
    _u = IloNumVarArray(_env);
    
    
    //Creating Variables x
    for (long i=0; i<_dataTSP->getnnodes(); i++) {
        _x[i]=IloNumVarArray(_env);
        for (long j=0; j<_dataTSP->getnnodes(); j++) {
            ostringstream label;
            label<<"x_"<<i<<"_"<<j;
            _x[i].add(IloNumVar(_env,0,1,ILOINT,label.str().c_str()));
        }
    }
    
    //Creating Variables u
    for (long i=0; i<_dataTSP->getnnodes(); i++) {
        ostringstream label;
        label<<"u_"<<i;
        _u.add(IloNumVar(_env,1,_dataTSP->getnnodes(),ILOINT,label.str().c_str()));
    }
    _u[0].setUB(1);
    
    //Creating Objective Function
    IloExpr obj(_env);
    for (long i=0; i<_dataTSP->getnnodes(); i++) {
        for (long j=0; j<_dataTSP->getnnodes(); j++) if(i!=j){
            obj+=_dataTSP->euclideanDistance(i, j)*_x[i][j];
        }
    }
    _obj.setExpr(obj);
    obj.end();
    
    
    
    //Export Model
    _cplex.exportModel("TSP_Model.lp");
    
}
