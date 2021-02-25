#include"../include/matrices/matrix.hpp"

int main(int argc, char** argv){


    matrix m1(3,3);
    matrix m2;
    matrix m3;
    matrix m4;

    for(int i =0;i<3;++i)
        for(int j = 0;j<3;++j){
            m1.data_i(i,j,3*i+j);
        }
    m1.print_matrix();

    m2 = m1;
    m2.print_matrix();
    m3 = m2+15.0;
    m3.print_matrix();
    m4 = m2 + m3;
    m4.print_matrix();

    m1.delete_matrix();
    m2.delete_matrix();
    m3.delete_matrix();
    m4.delete_matrix();
    
    return 0;
}