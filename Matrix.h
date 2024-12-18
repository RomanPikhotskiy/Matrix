#pragma once
#include "Vector.h"

// Верхнетреугольная матрица
template <class T>
class Matrix : public Vector<Vector<T>>
{
private:
    bool _verh;
    size_t _rowSize;
public:

    Matrix concatHorizontally(const Matrix& mt) {
        if (this->_size != mt._size) {
            throw std::invalid_argument("Matrices must have the same number of rows for horizontal concatenation.");
        }

        Matrix result(this->_size, this->_rowSize + mt._rowSize);
        for (size_t i = 0; i < this->_size; ++i) {
            // Конкатенируем строки и обрабатываем сдвиг индекса
            Vector<T> newRow(this->_array[i].GetSize() + mt._array[i].GetSize(), i);
            for (size_t j = 0; j < this->_array[i].GetSize(); ++j) {
                newRow[j] = this->_array[i][j];
            }
            for (size_t j = 0; j < mt._array[i].GetSize(); ++j) {
                newRow[this->_array[i].GetSize() + j] = mt._array[i][j];
            }
            result._array[i] = newRow;
        }
    
        return result;
    }

    Matrix(size_t n, size_t m) : Vector<Vector<T>>(n,0), _rowSize(m){
        for (size_t i = 0; i < n; i++){
            this->_array[i] = Vector<T> (m, i);
        }
        _verh = false;
    }

    Matrix (size_t n) : Vector<Vector<T>>(n,0){
        for (size_t i = 0; i < n; i++){
            this->_array[i] = Vector<T> (n-i, i);
        }
        _verh = true;
    }
    Matrix(const Matrix& mt) : Vector<Vector<T>>(mt){
        _verh = true;
    }                    // копирование
    Matrix(const Vector<Vector<T> >& mt) : Vector<Vector<T>>(mt){
        _verh = true;
    } // преобразование типа
    Matrix& operator= (const Matrix& mt){
        this->_verh = mt._verh;
        this->_size = mt._size;
        this->_startIndex = mt._startIndex;
        for (size_t i = 0; i < this->_size; i++){
            delete [] this->_array[i];
            this->_array[i] = nullptr;
            this->_array[i] = mt._array[i];
        }

        return *this;
   }        // присваивание


    Matrix  operator+ (const Matrix& mt){
        return Vector<Vector<int>> :: operator+(mt);
    }        // сложение


    Matrix  operator- (const Matrix& mt){
        return Vector<Vector<int>> :: operator-(mt);
    }       // вычитание

    Matrix operator*(const Matrix& mt) {
    if (this->_size != mt._size) {
        throw std::invalid_argument("Matrices have incompatible sizes for multiplication.");
    }

    Matrix result(this->_size);

    for (size_t i = 0; i < this->_size; i++) { 
        for (size_t j = i; j < this->_size; j++) { 
            T sum = 0;

            for (size_t k = i; k <= j; k++) {
                if ((k - i) < this->_array[i].GetSize() && (j - k) < mt._array[k].GetSize()) {
                    sum += this->_array[i][k - i] * mt._array[k][j - k];
                }
            }

            result._array[i][j - i] = sum; 
        }
    }

    return result;
}

    // ввод / вывод
    friend istream& operator>>(istream& in, Matrix& mt)
    {
        for (int i = 0; i < mt._size; i++)
            in >> mt._array[i];
        return in;
    }
    friend ostream& operator<<(ostream& os, const Matrix& mt)
    {   
        cout << mt._verh;
        if (mt._verh)
        for (int i = 0; i < mt._size; i++){
        os << "|";
        for (size_t j = 0; j < i; j++) os << "0, ";
        os << mt._array[i] << "|" << endl;}
        else{
            for(int i = 0 ; i < mt._size; i ++){
                os << "|";
                os << mt._array[i] << "|" << endl;
            }
        }
        return os;
    }
};