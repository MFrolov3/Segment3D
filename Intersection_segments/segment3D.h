#pragma once
#include <iostream>
#include "vector3D.h"

class Segment3D
{
private:
    Vector3D start;
    Vector3D end;

   
    bool are_parallel(const Segment3D& segment) const;   //вспомогательные методы функции(метода) Intersect
    bool are_on_the_same_line(const Segment3D& segment) const;
    bool both_sectors_are_points(const Segment3D&) const;
    
public:
    Segment3D(const Vector3D& start_arg, const Vector3D& end_arg); //конструктор класса отрезков
    Vector3D get_start() const; //геттеры полей класса отрезков
    Vector3D get_end() const;
    Vector3D Intersect(const Segment3D& segment) const; //метод класса отрезков оперделения точки пересечения двух отрезков
};


