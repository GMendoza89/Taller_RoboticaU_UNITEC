#include"../include/matrices/matrix.hpp"

// clase Matrix

matrix::matrix(){
    cols = 0;
    rows = 0;
    data = NULL;
}
matrix::matrix(int R, int C){
    rows = R;
    cols = C;

    data = new double*[rows];
    for(int i1 = 0; i1<rows; ++i1){
        data[i1] = new double[cols];
    }
}
matrix::~matrix(){
    if(data!=NULL){
        for(int i0 = 0;i0<rows;++i0){
            delete data[i0];
        }
        delete data;
    }
}
int matrix::get_cols(){ return cols;}
int matrix::get_rows(){return rows;}
double matrix::data_i(int r, int c){ 
    return data[r][c];}
void matrix::set_cols(int C){cols = C;}
void matrix::set_rows(int R){rows = R;}
void matrix::make_matrix(){
    if(rows == 0){
        std::cout<<"Error de dimensiones"<<std::endl;
        return;
    }
    data = new double*[rows];
    for(int i1 = 0; i1<rows; ++i1){
        data[i1] = new double[cols];
    }
    return;
}
void matrix::make_matrix(int R, int C){
    rows = R;
    cols = C;
    if(rows == 0){
        std::cout<<"Error de dimensiones"<<std::endl;
        return;
    }
    data = new double*[rows];
    for(int i1 = 0; i1<rows; ++i1){
        data[i1] = new double[cols];
    }
}
void matrix::data_i(int r, int c, double d){
    data[r][c] = d;
}
void matrix::print_matrix(){
    for(int i2 = 0; i2 <rows; ++i2){
        for(int j2 = 0; j2<cols; ++j2){
            std::cout<<" ,"<<data[i2][j2];
        }
        std::cout<<std::endl;
    }
    return;
}
void matrix::save_matrix(){
    std::ofstream file;
    file.open("matrix.csv");
    for(int i3 = 0; i3 <rows; ++i3){
        for(int j3 = 0; j3<cols; ++j3){
            file<<data[i3][j3]<<", ";
        }
        std::cout<<std::endl;
    }
    file.close();
}
void matrix::delete_matrix(){
    if(data!=NULL){
        for(int i0 = 0;i0<rows;++i0){
            delete data[i0];
        }
        delete data;
    }
    data = NULL;

}

