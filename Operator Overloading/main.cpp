/*
 * Name: Function Overloading C++
 * Author: Haider Ali Punjabi
 * EMail: haideralipunjabi@hackesta.org
 * Date: 8/5/2019
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <conio.h>

#define DEFAULT_ROWS 3
#define DEFAULT_COLS 3

using namespace std;

class Matrix {
private:
    vector<vector<int> > mMatrix;
    int mRowSize, mColSize;
public:
    Matrix(){
        Matrix(DEFAULT_ROWS,DEFAULT_COLS);
    }
    Matrix(int row_size, int col_size){
        int i;
        mRowSize = row_size;
        mColSize = col_size;
        mMatrix.resize(mRowSize);
        for(i =0; i< mRowSize; i++){
            mMatrix[i].resize(mColSize);
        }
    }
    Matrix(int size){
        int i;
        mRowSize = size;
        mColSize = size;
        mMatrix.resize(mRowSize);
        for(i =0; i< mRowSize; i++){
            mMatrix[i].resize(mColSize);
        }
    }
    void CreateMatrix(){
        int i,j;
        cout << "\tCreating Matrix" << endl;
        for(i =0; i< mRowSize; i++){
            for(j =0; j< mColSize; j++){
                cout << "Enter Data at " << i << "," << j<<": ";
                cin >> mMatrix[i][j];
            }
        }
        cout << endl;
    }
    void DisplayMatrix(){
        int i,j;
        cout << "\tDisplaying Matrix" << endl;
        for(i =0; i< mRowSize; i++){
            for(j =0; j< mColSize; j++){
                cout << mMatrix[i][j] << " ";
            }
        cout << endl;
        }
    }

    Matrix TransposeMatrix(){
        Matrix transposed = Matrix(mColSize,mRowSize);
        for(int i = 0; i < mRowSize;i++){
            for(int j = 0; j < mColSize;j++){
                transposed.mMatrix[j][i] = mMatrix[i][j];
            }
        }
        return transposed;
    }
    int Cofactor(int row,int col){
        if(mRowSize != mColSize)
            throw "Not a Square Matrix";
        if(row >= mRowSize || col >= mColSize)
            throw "Invalid Parameters";
        Matrix matrix = Matrix(mRowSize-1,mColSize-1);
        for(int i =0;i<mRowSize;i++){
            if(i==row) continue;
            for(int j = 0;j<mColSize;j++){
                if(j==col) continue;
                    matrix.mMatrix[i>row?i-1:i][j>col?j-1:j] = mMatrix[i][j];
            }
        }
        return pow(-1,row+col) * matrix.Determinant();

    }
    int Determinant(){
        if(mRowSize != mColSize){
            throw "Not a Square Matrix";
        }
        if(mRowSize == 2) return (mMatrix[0][0]*mMatrix[1][1]) - (mMatrix[0][1]*mMatrix[1][0]);
        int determinant = 0;
        for (int i =0; i < mColSize; i++){
            determinant += mMatrix[0][i] * Cofactor(0,i);
        }
        return determinant;
    }


    Matrix operator + (const Matrix &m2) {
        if(mRowSize != m2.mRowSize && mColSize != m2.mColSize) {
            throw "Addition of Matrices of unequal size";
        }
        Matrix m3 = Matrix(mRowSize,mColSize);
        for(int i = 0; i < mRowSize;i++){
            for(int j = 0; j < mColSize;j++){
                m3.mMatrix[i][j] = mMatrix[i][j] + m2.mMatrix[i][j];
            }
        }
        return m3;
    }

    Matrix operator + (const int &m) {
        Matrix m2 = Matrix(mRowSize, mColSize);
        for(int i = 0; i < mRowSize; i++){
            for(int j = 0; j < mColSize; j++){
                m2.mMatrix[i][j] = mMatrix[i][j] + m;
            }
        }
        return m2;
    }

    Matrix operator - (const Matrix &m2) {
        if(mRowSize != m2.mRowSize && mColSize != m2.mColSize) {
            throw "Subtraction of Matrices of unequal size";
        }
        Matrix m3 = Matrix(mRowSize,mColSize);
        for(int i = 0; i < mRowSize;i++){
            for(int j = 0; j < mColSize;j++){
                m3.mMatrix[i][j] = mMatrix[i][j] - m2.mMatrix[i][j];
            }
        }
        return m3;
    }

    Matrix operator - (const int &m) {
        Matrix m2 = Matrix(mRowSize, mColSize);
        for(int i = 0; i < mRowSize; i++){
            for(int j = 0; j < mColSize; j++){
                m2.mMatrix[i][j] = mMatrix[i][j] - m;
            }
        }
        return m2;
    }

    Matrix operator * (const Matrix &m2) {
        if(mColSize != m2.mRowSize) {
            throw "Multiplication of Matrices of unequal size";
        }
        Matrix m3 = Matrix(mRowSize, m2.mColSize);
        for(int i = 0; i < mRowSize;i++){
            for(int j = 0; j < m2.mColSize;j++){
                for(int k = 0; k < m2.mRowSize; k++){
                    m3.mMatrix[i][j] += mMatrix[i][k] * m2.mMatrix[k][j];
                }
            }
        }
        return m3;
    }
    Matrix operator * (const int &m) {
        Matrix m2 = Matrix(mRowSize, mColSize);
        for(int i = 0; i < mRowSize; i++){
            for(int j = 0; j < mColSize; j++){
                m2.mMatrix[i][j] = mMatrix[i][j] * m;
            }
        }
        return m2;
    }


};

int main()
{
    int choice,constant, rows, cols, determinant;
    Matrix m1,m2,out;

    while(1){

        system("CLS");
        cout << "\t\tMain Menu"<<endl;
        cout << "1. Add 2 Matrices\n2. Add Matrix & Constant\n3. Subtract 2 Matrices\n4. Subtract Matrix & Constant\n5. Multiply 2 Matrices\n6. Multiple Matrix & Constant\n7. Find Transpose of Matrix\n8. Find Determinant of Matrix\n0. Exit\nEnter Choice: " << endl;
        cin >> choice;
        if(choice==0)exit(0);
        system("CLS");
        cout << "Enter Matrix Row Size: " <<endl;
        cin >> rows;
        cout << "Enter Matrix Column Size: " <<endl;
        cin >> cols;
        system("CLS");
        cout << "Matrix 1: "<<endl;
        m1 = Matrix(rows,cols);
        m1.CreateMatrix();
        if(choice == 1 || choice == 3)
        {
            cout << "Matrix 2: "<<endl;
            m2 = Matrix(rows,cols);
            m2.CreateMatrix();
        }
        else if(choice == 5){
            rows = 0;
            cols = 0;
            system("CLS");
            cout << "Enter Matrix Row Size: " <<endl;
            cin >> rows;
            cout << "Enter Matrix Column Size: " <<endl;
            cin >> cols;
            system("CLS");
            cout << "Matrix 2: "<<endl;
            cout << rows << "," << cols;
            m2 = Matrix(rows,cols);
            m2.CreateMatrix();
        }
        else if(choice == 2 || choice == 4 || choice ==6){
            cout << "Enter Constant Value: ";
            cin >> constant;
        }
        system("CLS");
        try {
            switch(choice){
            case 1:
                out = m1 + m2;
                break;
            case 2:
                out = m1 + constant;
                break;
            case 3:
                out = m1 - m2;
                break;
            case 4:
                out = m1 - constant;
                break;
            case 5:
                out = m1 * m2;
                break;
            case 6:
                out = m1 * constant;
                break;
            case 7:
                out = m1.TransposeMatrix();
                break;
            case 8:
                determinant = m1.Determinant();
                cout << "Determinant: " << determinant <<endl;
                break;
            }
            if(choice != 8){
                out.DisplayMatrix();
            }
            getch();
        }
        catch(char const* msg){
            cout << "Error: "<< msg << endl;
            getch();
        }
    }

}
