#pragma once
#include <iostream>
#include <random>
#include <ctime>
//#include "Matrix.h"

class Array{
    private:
        
        float* array;
        int len;
    public:
        //Constructors / Destructors
        Array(const Array &other);
        Array();
        Array(const int l);
        ~Array();

        //static variables
        static int counter;

        //static methods
        static Array create();

        //methods
        const int length() const;
        void set(float temp, int i) const;
        const float get(int i) const;
        void compile() const;
        void show() const;
        float* ptr() const;

        //only work on Non-Const objects
        void free();
       
        void reAllocate(int l);

        //IMPORTANT, OPERATOR TAKES A REFERENCE (or pointer) NOT AN INSTANCE

        Array operator+(const Array &other) const;
        Array operator*(const Array &other) const;
        //Matrix operator*(const Matrix &other); matrix * array
        Array& operator++();
        Array& operator++(int);
        Array& operator--();
        Array& operator--(int);

};