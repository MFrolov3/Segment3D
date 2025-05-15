#pragma once
#include <iostream>
#include "vector3D.h"

class Segment3D
{
private:
    Vector3D start;
    Vector3D end;

   
    bool are_parallel(const Segment3D& segment) const;   //auxiliary methods of the Intersect function(method)
    bool are_on_the_same_line(const Segment3D& segment) const;
    bool both_sectors_are_points(const Segment3D&) const;
    
public:
    Segment3D(const Vector3D& start_arg, const Vector3D& end_arg); //constructor of the segment class
    Vector3D get_start() const; //getters of segment class fields
    Vector3D get_end() const;
    Vector3D Intersect(const Segment3D& segment) const; //method of the segment class for separating the intersection point of two segments
};


