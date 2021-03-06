#ifndef DECODER_H
#define DECODER_H

#include <fstream>
#include "MersenneTwister.h"
#include <Eigen/Core>
#include "utilities.cpp"

using namespace std;
using namespace Eigen;

class Decoder {
    
    public:

        int L;
        int N;
        int Nqubits;
        
        vector<vector<int> > Coordinates;
        vector<vector<int> > Neighbors;
        vector<vector<int> > plaqQubits;
        vector<vector<int> > starQubits;
        vector<vector<int> > qubitStars; 
        Decoder(int L_);
        
        vector<int> generateError(MTRand & random, double p);
        vector<int> getSyndrome(vector<int> E);
        int measureStar(vector<int> E, int star);
        vector<int> getCycle(vector<int> E0, vector<int> E);
        int syndromeCheck(vector<int> E0, vector<int> E);
        int getLogicalState(vector<int> C);
        int getHomologyClass(vector<int> C);

        int qIndex(int j, int s);
        int index(int x, int y);
        void printToricCodeInfo();
        void printVector(vector<int> Vector);
        void writeVector(vector<int> Vector, ofstream & file);

        void generateDataset(MTRand & random, double p, ofstream & file_S, ofstream & file_E);
        void testDecoder(MTRand & random);
};

#endif
