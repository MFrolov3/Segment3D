#include <cmath>
#include "vector3D.h"
#include "segment3D.h"

Segment3D::Segment3D(const Vector3D& start_arg, const Vector3D& end_arg) : start(start_arg), end(end_arg) {};
Vector3D Segment3D::get_start() const { return start; }
Vector3D Segment3D::get_end() const { return end; }

bool Segment3D::are_parallel(const Segment3D& segment) const
{
    Vector3D dir1 = get_end() - get_start();
    Vector3D dir2 = segment.get_end() - segment.get_start();
    return dir1.cross_product(dir2).is_zero();
}
bool Segment3D::are_on_the_same_line(const Segment3D& segment) const
{
    Vector3D delta_r = segment.get_start() - get_end();
    Vector3D dir1 = get_end() - get_start();
    Vector3D dir2 = segment.get_end() - segment.get_start();
    return dir1.cross_product(dir2).is_zero() && delta_r.cross_product(dir1).is_zero();
}
bool Segment3D::both_sectors_are_points(const Segment3D& segment) const
{
    return (get_end() - get_start()).is_zero() &&
        (segment.get_end() - segment.get_start()).is_zero();
}

//������ ��������� ���� ��������
//r1+t*dir1, ��� t ������ �������� �� 0 �� 1, 
//r1 ������ �� ������ ������� �� ������ �������, 
//dir1 ����������� ������� (������� �� ��� ������ �� ��� �����)
//�� �������� ��� ������� ������� r2 + s * dir2
//�� r1+t*dir1 = r2+s*dir2 => (r2-r1).cross_product(dir2) = t*(dir1).cross_product(dir2) (*)
//�� ��������� (*) ����� ����� t, � ��������� ������� 0=<t<=1, ����� t ����� ���������
//����� �����������. ��� ������� ��������� ����� ��������� ��� ������� ������������, 
//����������� �� ����� ���� � ������ ����� ��������� �������� t

Vector3D Segment3D::Intersect(const Segment3D& segment) const
{
    
    Vector3D dir1 = get_end() - get_start();
    Vector3D dir2 = segment.get_end() - segment.get_start();
    Vector3D r1 = get_start();
    Vector3D r2 = segment.get_start();

    Vector3D delta_r = r2 - r1; //���������� ����� ������� ���� ��������

    Vector3D cross1 = delta_r.cross_product(dir2); //��������� ������������ 
    Vector3D cross2 = dir1.cross_product(dir2);

    double cross2_length = cross2.length();
    double cross1_length = cross1.length();

    //��� ������� - ����� (������� �����)
    if (both_sectors_are_points(segment)) 
    {
        return (r1.equals(r2) ? r1 : Vector3D(NAN, NAN, NAN));
    }

    //������ ���� ������ �����
    if (dir1.is_zero())
    {
       double s = (r1 - r2).length() / dir2.length();
       if (s >= -EPSILON && s <= 1 + EPSILON && (r1 - r2).cross_product(dir2).is_zero())
       {
            return r1;
       }
       std::cout << "One sector is a point that has no intersection with another sector" << std::endl;
       return Vector3D(NAN, NAN, NAN);
    }

    //������ ���������� (� �� ���������), �������� ��� ����������� �� �����
    if (are_parallel(segment) && !(are_on_the_same_line(segment)))
    {
        std::cout << "Sectors are parallel. No intersection" << std::endl;
        return Vector3D(NAN, NAN, NAN);
    }
    //������ ���� �������� ���������
    if (are_on_the_same_line(segment))
    {
        //���� ���������� �������� ������ ������� �� ������
        //��� ������� (1) r2 + t_0*dir2 ������������ ��������� �������
        // 0 <= t_0 <= 1 ������ �����������

        double t_0 = (delta_r * dir1) / (dir1 * dir1);
        double t_1 = ((segment.get_end() - r1) * dir1) / (dir1 * dir1);
        double t_min = std::min(t_0, t_1);
        double t_max = std::max(t_0, t_1);

        if (t_min <= 1 + EPSILON && t_max >= -EPSILON)
        {
            return r1 + (std::max(0.0, t_min) * dir1);
        }
        else
        {
            std::cout << "No intersection. Segments are on the same line" << std::endl;
            return Vector3D(NAN, NAN, NAN);
        }
    }
    //��� ��������� ������ ������� ����� ������� ���� ����� �� ����� � ������������
    Vector3D cross = cross1.cross_product(cross2);
    double t_0 = cross1_length / cross2_length;

    if (cross.is_zero() && t_0 >= 0 && t_0 <= 1)
    {
        return r1 + t_0 * dir1;
    }

    std::cout << "No segment intersection" << std::endl;
    return Vector3D(NAN, NAN, NAN);
}