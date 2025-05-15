#pragma once
#include <iostream>


const double EPSILON = 1e-5; //the specified accuracy is epsilon

class Vector3D
{
private:
    double X;
    double Y;
    double Z;
public:
    double get_x() const; //getters of fields of the Vector3D class
    double get_y() const;
    double get_z() const;

    Vector3D(double x, double y, double z ); //constructor of the Vector3D class

    Vector3D operator+ (const Vector3D& value) const;  //overloading the addition operator for a class of vectors
    Vector3D operator- (const Vector3D& value) const;   //overloading the subtraction operator for a vector class
    Vector3D operator* (double scalar) const; //overloading the multiplication operator to multiply a vector by a scalar
   
    friend Vector3D operator*(double scalar, const Vector3D& value); //a friendly function for implementing scalar-vector multiplication

    double operator* (const Vector3D& value) const; //overloading the multiplication operator for two vectors
    Vector3D operator/ (double scalar) const; //dividing a vector by a scalar
    Vector3D cross_product(const Vector3D& value) const; //vector product
   
    double length() const; //definition of the norm/length of the vector
   
    Vector3D normalize() const; //normalization of a vector, dividing it by a scalar corresponding to its length
   
    bool is_zero() const; //checking whether a vector is a point
    bool equals(const Vector3D& other) const;  //checking the equality of two vectors
};


