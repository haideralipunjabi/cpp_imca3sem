#include <iostream>
#include <vector> 
#include <cmath>

using namespace std;

class Matrix {
private:
    vector<vector<int>> mMatrix;
    int mRowSize, mColSize;
public:
    Matrix(int row_size, int col_size){
        int i,j;
        mRowSize = row_size;
        mColSize = col_size;
        mMatrix.resize(mRowSize);
        for(i =0; i< mRowSize; i++){
            mMatrix[i].resize(mColSize); 
        }
    }
    Matrix(int size){
        int i,j;
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
    

    Matrix operator + (Matrix m2) {
        if(mRowSize != m2.mRowSize && mColSize != m2.mColSize) {
            throw "Addition of Matricies of unequal size";
        }
        Matrix m3 = Matrix(mRowSize,mColSize);
        for(int i = 0; i < mRowSize;i++){
            for(int j = 0; j < mColSize;j++){
                m3.mMatrix[i][j] = mMatrix[i][j] + m2.mMatrix[i][j];
            }   
        }
        return m3;
    }
    Matrix operator - (Matrix m2) {
        if(mRowSize != m2.mRowSize && mColSize != m2.mColSize) {
            throw "Subtraction of Matricies of unequal size";
        }
        Matrix m3 = Matrix(mRowSize,mColSize);
        for(int i = 0; i < mRowSize;i++){
            for(int j = 0; j < mColSize;j++){
                m3.mMatrix[i][j] = mMatrix[i][j] - m2.mMatrix[i][j];
            }   
        }
        return m3;
    }
    Matrix operator * (Matrix m2) {
        if(mColSize != m2.mRowSize) {
            throw "Multiplication of Matricies of unequal size";
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
    Matrix operator * (int m) {
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
    Matrix m1 = Matrix(4,4);
    m1.CreateMatrix();
    m1.DisplayMatrix();
    try{
        cout << m1.Determinant() << endl;
    }
    catch(const char* msg){
        cerr << msg << endl;
    }
}
