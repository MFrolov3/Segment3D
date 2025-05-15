#include <cmath>
#include "vector3D.h"

//implementation of methods of the vector class
double Vector3D::get_x() const { return X; }
double Vector3D::get_y() const { return Y; }
double Vector3D::get_z() const { return Z; }

Vector3D::Vector3D(double x = 0, double y = 0, double z = 0) : X(x), Y(y), Z(z) {};

Vector3D Vector3D::operator+ (const Vector3D& value) const
{
    return Vector3D(X + value.X, Y + value.Y, Z + value.Z);
};

Vector3D Vector3D::operator- (const Vector3D& value) const
{
    return Vector3D(X - value.X, Y - value.Y, Z - value.Z);
};

Vector3D Vector3D::operator* (double scalar) const
{
    return Vector3D(X * scalar, Y * scalar, Z * scalar);
};

double Vector3D::operator* (const Vector3D& value) const
{
    return X * value.X + Y * value.Y + Z * value.Z;
}

Vector3D Vector3D::operator/ (double scalar) const
{
    if (std::abs(scalar) < EPSILON)
    {
        throw std::invalid_argument("Invalid scalar argument. Try to choose smth different from 0");
    }
    return Vector3D(X / scalar, Y / scalar, Z / scalar);
}

Vector3D Vector3D::cross_product(const Vector3D& value) const
{
    return Vector3D(Y * value.Z - value.Y * Z, value.X * Z - X * value.Z, X * value.Y - value.X * Y);
}

double Vector3D::length() const
{
    return std::sqrt(X * X + Y * Y + Z * Z);
}

Vector3D Vector3D::normalize() const
{
    double len = length();
    if (len == 0)
    {
        return *this;
    }
    return (*this) / len;
}

bool Vector3D::is_zero() const
{
    return (std::abs(X) < EPSILON) && (std::abs(Y) < EPSILON) && (std::abs(Z) < EPSILON);
}

bool Vector3D::equals(const Vector3D& other) const
{
    return (std::abs(X - other.X) < EPSILON) && (std::abs(Y - other.Y) < EPSILON) && (std::abs(Z - other.Z) < EPSILON);
}

Vector3D operator*(double scalar, const Vector3D& value)
{
    return value * scalar;
}


