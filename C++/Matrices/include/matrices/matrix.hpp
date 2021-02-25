#ifndef MATRIX_HPP
#define MATRIX_HPP

#include<iostream>
#include<fstream>
#include<string>

class matrix{
    private:
    int cols,rows;
    double **data;
    
    public:
        matrix();
        matrix(int R, int C);
        ~matrix();
        void make_matrix();
        void make_matrix(int R, int C);
        void delete_matrix();
        int get_cols();
        int get_rows();
        double data_i(int r, int c);
        void data_i(int r, int c,double d);
        void set_cols(int c);
        void set_rows(int r);
        
        void print_matrix();
        void save_matrix();
        void save_matrix(std::string name);
        void save_matrix(std::string name, int extencion);
        
        
        void load_matrix(std::string Filename);
        

};


#endif
