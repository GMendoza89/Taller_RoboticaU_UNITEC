#include"../include/matrices/matrix.hpp"

int main(int argc, char** argv){


    matrix m1(3,3);

    for(int i =0;i<3;++i)
        for(int j = 0;j<3;++j){
            m1.data_i(i,j,i*j);
        }
    m1.print_matrix();
    
    return 0;
}