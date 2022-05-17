#include "Array.h"
//#include "Matrix.h"
int Array::counter = 0;


//devo capire perchè passando una reference sono in grado di leggere il private ma funziona cosi

Array Array::operator+(const Array &other) const{
            Array temp;
            if(len != other.len) return temp;
            temp.reAllocate(len);
            for(int i = 0; i < len; i++){
                temp.set(array[i] + other.array[i], i);
            }
            return temp;
            
            }
Array Array::operator*(const Array &other) const{
            Array temp;
            if (len != other.len) return temp;
            temp.reAllocate(len);
            for (int i = 0; i < len; i++) {
                temp.set(array[i] * other.array[i], i);
            }
            return temp;
}
/*
//Assumes a row Array
Matrix Array::operator*(const Matrix &other){
    Matrix temp;
    if(len != other.row()) return temp;
    temp.reAllocate(1, other.col());
    temp.zero();
    for(int i = 0; i < other.col(); i++){
        for(int j = 0; j < other.row(); j++){
            temp.add(other.get(i,j) * array[j], i, j);
        }
    }
    return temp;


}
*/

//increment operators, only work on Non-Const objects
Array& Array::operator++(){
            for (int i = 0; i < len; i++) {
                array[i]++;
            }return *this;
}
Array& Array::operator++(int){
            for (int i = 0; i < len; i++) {
                array[i]++;
            }return *this;
}
Array& Array::operator--(){
            for (int i = 0; i < len; i++) {
                array[i]--;
            }return *this;
}
Array& Array::operator--(int){
            for (int i = 0; i < len; i++) {
                array[i]--;
            }return *this;
}

//Copy constructor
Array::Array(const Array &other) {
            len = other.len;
            array = new float[len];
            for (int k = 0; k < len; k++) {
                array[k] = other.array[k];
            }
            Array::counter++;
}
//Void constructor
Array::Array(){
            array = nullptr;
}
//Default constructor
Array::Array(const int l){
            //array = malloc(l*sizeof(float));      //Doesn't work and is deprecated
            array = new float[l]();
            len = l;
            Array::counter++;
        }
//Destructor (cleans the array* pointer (float))
Array::~Array(){

            //std::cout << "\n\nEnd of scope" << std::endl;
            if(array != nullptr) {
                delete[] array;
                //std::cout << "Cleaning memory ./." << std::endl << "Done..." << std::endl;
                Array::counter--;

            }//else std::cout << "Already cleaned at RunTime!" << std::endl;
        }

//static
Array Array::create(){
    int temp_len;
    std::cout << "Array length: ";
    std::cin >> temp_len;
    std::cout << std::endl;
    Array temp(temp_len);
    return temp;
}


const int Array::length() const{
            if(array == nullptr) return 0;
            return len;
        }
void Array::set(float temp, int i) const{
            if (!(i >= len) && !(i < 0) && array != nullptr){
                array[i] = temp;
                return;
            }else if(array == nullptr){
                std::cout << "Array deleted..." << std::endl;
                return;
            }else{
                std::cout << "Out of range" << std::endl;
                return;
            }
        }
const float Array::get(int i) const{
            if (!(i >= len) && !(i < 0) && array != nullptr){
                return array[i];
            }else if(array == nullptr){
                std::cout << "Array deleted..." << std::endl;
                return 0;
            }else{
                std::cout << "Out of range" << std::endl;
                return 0;
            }
        }
void Array::compile() const{

            for(int i = 0; i < len; i++){
                float temp;
                std::cout << "Add new element[" << i << "]: ";
                std::cin >> temp;
                set(temp,i);
                std::cout << std::endl;
            }
        }
void Array::show() const{
            if(array == nullptr) return;
            for(int i = 0; i < len; i++){
                std::cout << "Array[" << i << "]: " << array[i] << std::endl;
            }
        }
float* Array::ptr() const{
    return array;
}


//handles new dynamic allocation (change in size)
void Array::reAllocate(int l){
            if(array != nullptr){
                free();
            }
            len = l;
            array = new float[len]();
        }
void Array::free(){
            if(array != nullptr){
                delete[] array;
                array = nullptr;
                std::cout << "Memory area cleaned!" << std::endl;
                Array::counter--;
            }
            return;
        }
