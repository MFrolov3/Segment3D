#pragma once
#include <iostream>


const double EPSILON = 1e-5; //�������� �������� �������

class Vector3D
{
private:
    double X;
    double Y;
    double Z;
public:
    double get_x() const; //������� ����� ������ Vector3D
    double get_y() const;
    double get_z() const;

    Vector3D(double x, double y, double z ); //����������� ������ Vector3D

    Vector3D operator+ (const Vector3D& value) const;   //���������� ��������� �������� ��� ������ ��������
    Vector3D operator- (const Vector3D& value) const;   //���������� ��������� ��������� ��� ������ ��������
    Vector3D operator* (double scalar) const; //���������� ��������� ��������� ��� ��������� ������� �� ������
   
    friend Vector3D operator*(double scalar, const Vector3D& value); //������������� ������� ��� ���������� ��������� ������� �� ������

    double operator* (const Vector3D& value) const; //���������� ��������� ��������� ��� ���� ��������
    Vector3D operator/ (double scalar) const; //������� ������� �� ������
    Vector3D cross_product(const Vector3D& value) const; //��������� ������������
   
    double length() const; //����������� �����/����� �������
   
    Vector3D normalize() const; //������������� �������, ������� ��� �� ������, �������������� ��� �����
   
    bool is_zero() const; //�������� �������� �� ������ ������
    bool equals(const Vector3D& other) const;  //�������� ��������� ���� �������� 
};


