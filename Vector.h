#pragma once
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
//перегрузить оператор + - *(скалярное произведение). Длина вектора. Нормализация вектора. Конструкторы копирования и присваивания(подумать не делать).
template<class T>
class Vector
{
protected:
    T* _array;
    size_t _size;
    size_t _startIndex;
    size_t _sizeZero;
public:
    Vector() : _size(10), _startIndex(0){
        _array = new T[_size];
        for (int i = 0; i < _size; i++){
            _array[i] = 0;
        }
    }

    Vector(size_t size, size_t startIndex){
        _array = new T[size];
        _size = size;
        _startIndex = startIndex;
        for (int i = 0; i < _size; i++){
            _array[i] = 0;
        }
    };
    
    Vector(size_t size) : _size(size), _startIndex(0){
        _array = new T[_size];
        for (int i = 0; i < _size; i++){
            _array[i] = 0;
        }
    }

    Vector(size_t size, size_t startIndex, T* array) : _size(size), _array(new T[size]), _startIndex(startIndex){
        for (int i = 0; i < _size; i++){
            _array[i] = array[i];
        }
    }

    Vector(const Vector<T>& vec) : _size(vec._size), _array(new T[vec._size]){
        for (int i = 0; i < _size; i++){
            _array[i] = vec._array[i];
        }
    }

    Vector(Vector<T>&& vec) noexcept : _array(vec._array), _size(vec._size), _startIndex(vec._startIndex) {
        vec._array = nullptr;
        vec._size = 0;
        vec._startIndex = 0;
}

    size_t GetSize() const{
       return _size; 
    };

    ~Vector(){
        delete [] _array;
        _array = nullptr;
    }

    T& GetElem(size_t i){
        if (i >= _size){
            throw "Out of range";
        }
        return _array[i];
    };

    size_t GetStartIndex() const{
        return _startIndex;
    };

    Vector operator+(const T& tmp) const{
        Vector ans(*this);
        for (size_t i = 0; i < _size; i++)
            ans[i] += tmp;
        return ans;
    };
    Vector operator-(const T& tmp) const{
        Vector ans(*this);
        for (size_t i = 0; i < _size; i++)
            ans[i] -= tmp;
        return ans;
    };

    Vector operator*(const T& tmp) const{
        Vector ans(*this);
        for (size_t i = 0; i < _size; i++)
            ans[i] *= tmp;
        return ans;
    };


    Vector& operator=(const Vector<T>& vec){
        _size = vec._size;
        _startIndex = vec._startIndex;
        delete [] _array;
        _array = nullptr;
        _array = new T[_size];
        for (int i = 0; i < _size; i++){
            _array[i] = vec._array[i];
        }
        return *this;
    }

    T& operator[](int index){
        return _array[index];
    }

    friend istream& operator>>(istream& in, Vector& vec)
    {
        for (int i = 0; i < vec._size; i++)
            in >> vec._array[i];
        return in;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector& tmp){
        for (int i = 0; i < tmp._size; i++){
            os << tmp._array[i];
            if (i + 1 != tmp._size) os << ", ";
        }
        return os;
    }


   
};