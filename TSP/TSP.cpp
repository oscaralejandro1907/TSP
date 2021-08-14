//
//  TSP.cpp
//  TSP
//
//  Created by Oscar Alejandro Hernández López on 13/08/21.
//

#include "TSP.hpp"


Node::Node(long id, long x, long y){
    _id=id;
    _x=x;
    _y=y;
}


TSP::TSP(string filepath){
    _file=filepath;
    ifstream input(_file.c_str());
    
    if(!input.is_open() ){
        cout<<"Error: cannot open file "<<_file<<endl;
        exit(15);
    }
    
    string buffer;
    do {
        input>>buffer;
    } while (buffer != "DIMENSION");
    input>>buffer;
    input>>_nnodes;
    
    _Nodes = new Node*[_nnodes];
    do {
        input>>buffer;
    } while (buffer!="NODE_COORD_SECTION");
    
    for (long i=0; i<_nnodes; i++) {
        long id,x,y;
        input>>id>>x>>y;
        _Nodes[i]=new Node(id,x,y);
    }
    
    input.close();
}

double TSP::distance(long i, long j){
    return sqrt(pow(_Nodes[i]->getx()-_Nodes[j]->getx(), 2) + pow(_Nodes[i]->gety()-_Nodes[j]->gety(), 2));
}

TSP::~TSP(){
    for (long i=0; i<_nnodes; i++) {
        delete _Nodes[i];
    }
    
    delete [] _Nodes;
}
