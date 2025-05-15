#pragma once
#include <iostream>


const double EPSILON = 1e-5; //заданная точность эпсилон

class Vector3D
{
private:
    double X;
    double Y;
    double Z;
public:
    double get_x() const; //геттеры полей класса Vector3D
    double get_y() const;
    double get_z() const;

    Vector3D(double x, double y, double z ); //конструктор класса Vector3D

    Vector3D operator+ (const Vector3D& value) const;   //перегрузка оператора сложения для класса векторов
    Vector3D operator- (const Vector3D& value) const;   //перегрузка оператора вычитания для класса векторов
    Vector3D operator* (double scalar) const; //перегрузка оператора умножения для умножения вектора на скаляр
   
    friend Vector3D operator*(double scalar, const Vector3D& value); //дружественная функция для реализации умножения скаляра на вектор

    double operator* (const Vector3D& value) const; //перегрузка оператора умножения для двух векторов
    Vector3D operator/ (double scalar) const; //деление вектора на скаляр
    Vector3D cross_product(const Vector3D& value) const; //векторное произведение
   
    double length() const; //определение нормы/длины вектора
   
    Vector3D normalize() const; //нормированние вектора, деление его на скаляр, соотвествующий его длине
   
    bool is_zero() const; //проверка является ли вектор точкой
    bool equals(const Vector3D& other) const;  //проверка равенства двух векторов 
};


