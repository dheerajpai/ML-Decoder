#ifndef RBM_H
#define RBM_H

#include <vector>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include "MersenneTwister.h"
#include <Eigen/Core>

using namespace std;
using namespace Eigen;

class rbm {
    
    public:
        
        // RBM Parameters
        int epochs;
        int mini_batch_size;
        int batch_size;
        int CD_order;
        int n_h;
        int n_v;
        double L2_par;
        double learning_rate;
        
        MatrixXd W;
        VectorXd b;
        VectorXd c;

        MatrixXd dW;
        VectorXd dB;
        VectorXd dC;
        
        // Constructor
        rbm(MTRand & random);
        
        // Sample functions
        MatrixXd hidden_activation(MatrixXd v_state);
        MatrixXd visible_activation(MatrixXd h_state);

        MatrixXd sample_hidden(MTRand & random,MatrixXd v_state);
        MatrixXd sample_visible(MTRand & random, MatrixXd h_state);
        
        // Core Functions
        void CD_k(MTRand & random, MatrixXd batch); 
        void train(MTRand & random, MatrixXd dataset);
        void sample(MTRand & random, ofstream & output);
        void training_sweep(MTRand & random, MatrixXd batch);
 
        // Utilities
        double reconstruction_error(MatrixXd data, MatrixXd h_state);
        void printM(MatrixXd matrix);
        void printM_file(MatrixXd matrix, ofstream & file);
        MatrixXd sigmoid(MatrixXd matrix); 
        MatrixXd MC_sampling(MTRand & random, MatrixXd activation);

};

#endif
