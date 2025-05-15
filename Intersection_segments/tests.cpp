#include <cassert>
#include "vector3D.h"
#include "segment3D.h"


//тесты для проверки работы метода/функции Intersect()
bool is_nan_vector(const Vector3D& v) { //вспомогательная функция для тестирования
    return std::isnan(v.get_x()) && std::isnan(v.get_y()) && std::isnan(v.get_z());
}

void test_parallel_non_intersecting() {
    Segment3D s1(Vector3D(0, 0, 0), Vector3D(1, 0, 0));
    Segment3D s2(Vector3D(0, 1, 0), Vector3D(1, 1, 0));
    Vector3D intersection = s1.Intersect(s2);
    assert(is_nan_vector(intersection));
    if (!is_nan_vector(intersection)) {
        std::cerr << "test_parallel_non_intersecting failed (" << intersection.get_x() << ", " << intersection.get_y() << ", " << intersection.get_z() << ")" << std::endl;
    }
}

void test_collinear_intersecting() {
    Segment3D s1(Vector3D(0, 0, 0), Vector3D(1, 0, 0));
    Segment3D s2(Vector3D(0.5, 0, 0), Vector3D(1.5, 0, 0));
    Vector3D intersection = s1.Intersect(s2);
    Vector3D expected(0.5, 0, 0);
    assert(intersection.equals(expected));
    if (!intersection.equals(expected)) {
        std::cerr << "test_collinear_intersecting failed: expected (" << expected.get_x() << ", " << expected.get_y() << ", " << expected.get_z() << "), got (" << intersection.get_x() << ", " << intersection.get_y() << ", " << intersection.get_z() << ")" << std::endl;
    }
}

void test_collinear_non_intersecting() {
    Segment3D s1(Vector3D(0, 0, 0), Vector3D(1, 0, 0));
    Segment3D s2(Vector3D(2, 0, 0), Vector3D(3, 0, 0));
    Vector3D intersection = s1.Intersect(s2);
    assert(is_nan_vector(intersection));
    if (!is_nan_vector(intersection)) {
        std::cerr << "test_collinear_non_intersecting failed: expected NAN, got (" << intersection.get_x() << ", " << intersection.get_y() << ", " << intersection.get_z() << ")" << std::endl;
    }
}

void test_segments_in_3d() {
    Segment3D s1(Vector3D(0, 0, 0), Vector3D(1, 1, 1));
    Segment3D s2(Vector3D(0, 0, 1), Vector3D(1, 1, 0));
    Vector3D intersection = s1.Intersect(s2);
    Vector3D expected(0.5, 0.5, 0.5);
    assert(intersection.equals(expected));
    if (!intersection.equals(expected)) {
        std::cerr << "test_segments_in_3d failed: expected (" << expected.get_x() << ", " << expected.get_y() << ", " << expected.get_z() << "), got (" << intersection.get_x() << ", " << intersection.get_y() << ", " << intersection.get_z() << ")" << std::endl;
    }
}

void test_segments_intersect_at_endpoint() {
    Segment3D s1(Vector3D(0, 0, 0), Vector3D(1, 0, 0));
    Segment3D s2(Vector3D(1, 0, 0), Vector3D(1, 1, 0));
    Vector3D intersection = s1.Intersect(s2);
    Vector3D expected(1, 0, 0);
    assert(intersection.equals(expected));
    if (!intersection.equals(expected)) {
        std::cerr << "test_segments_intersect_at_endpoint failed: expected (" << expected.get_x() << ", " << expected.get_y() << ", " << expected.get_z() << "), got (" << intersection.get_x() << ", " << intersection.get_y() << ", " << intersection.get_z() << ")" << std::endl;
    }
}

void test_segments_nearly_parallel() {
    Segment3D s1(Vector3D(0, 0, 0), Vector3D(1, 0.000001, 0));
    Segment3D s2(Vector3D(0, 1, 0), Vector3D(1, 1.000001, 0));
    Vector3D intersection = s1.Intersect(s2);
    assert(is_nan_vector(intersection));
    if (!is_nan_vector(intersection)) {
        std::cerr << "test_segments_nearly_parallel failed: expected NAN, got (" << intersection.get_x() << ", " << intersection.get_y() << ", " << intersection.get_z() << ")" << std::endl;
    }
}

void test_segments_nearly_collinear() {
    Segment3D s1(Vector3D(0, 0, 0), Vector3D(1, 0, 0));
    Segment3D s2(Vector3D(0.5, 0.000001, 0), Vector3D(1.5, 0.000001, 0));
    Vector3D intersection = s1.Intersect(s2);
    Vector3D expected(0.5, 0, 0);
    assert(intersection.equals(expected));
    if (!intersection.equals(expected)) {
        std::cerr << "test_segments_nearly_collinear failed: expected (" << expected.get_x() << ", " << expected.get_y() << ", " << expected.get_z() << "), got (" << intersection.get_x() << ", " << intersection.get_y() << ", " << intersection.get_z() << ")" << std::endl;
    }
}
void test_zero_length_segment() {
    Segment3D s1(Vector3D(0, 0, 0), Vector3D(0, 0, 0));
    Segment3D s2(Vector3D(0, 0, 0), Vector3D(1, 1, 0));
    Vector3D intersection = s1.Intersect(s2);
    Vector3D expected(0, 0, 0);
    assert(intersection.equals(expected));
    if (!intersection.equals(expected)) {
        std::cerr << "test_zero_length_segment failed: expected (" << expected.get_x() << ", " << expected.get_y() << ", " << expected.get_z() << "), got (" << intersection.get_x() << ", " << intersection.get_y() << ", " << intersection.get_z() << ")" << std::endl;
    }

    Segment3D s3(Vector3D(1, 1, 1), Vector3D(2, 2, 2));
    Segment3D s4(Vector3D(1, 1, 1), Vector3D(1, 1, 1));
    intersection = s3.Intersect(s4);
    Vector3D expected2(1, 1, 1);
    if (!intersection.equals(expected2)) {
        std::cerr << "test_zero_length_segment failed: expected (" << expected2.get_x() << ", " << expected2.get_y() << ", " << expected2.get_z() << "), got (" << intersection.get_x() << ", " << intersection.get_y() << ", " << intersection.get_z() << ")" << std::endl;
    }

}

void test_perpendicular_segments() {
    Segment3D s1(Vector3D(0, 0, 0), Vector3D(1, 0, 0));
    Segment3D s2(Vector3D(0.5, -1, 0), Vector3D(0.5, 1, 0));
    Vector3D intersection = s1.Intersect(s2);
    Vector3D expected(0.5, 0, 0);
    assert(intersection.equals(expected));
    if (!intersection.equals(expected)) {
        std::cerr << "test_perpendicular_segments failed: expected (" << expected.get_x() << ", " << expected.get_y() << ", " << expected.get_z() << "), got (" << intersection.get_x() << ", " << intersection.get_y() << ", " << intersection.get_z() << ")" << std::endl;
    }
}

void test_segments_skew_lines() {
    Segment3D s1(Vector3D(0, 0, 0), Vector3D(1, 1, 0));
    Segment3D s2(Vector3D(0, 0, 1), Vector3D(1, -1, 1));
    Vector3D intersection = s1.Intersect(s2);
    assert(is_nan_vector(intersection));
    if (!is_nan_vector(intersection)) {
        std::cerr << "test_segments_skew_lines failed: expected NAN, got (" << intersection.get_x() << ", " << intersection.get_y() << ", " << intersection.get_z() << ")" << std::endl;
    }
}

void test_segments_intersect_outside_range() {
    Segment3D s1(Vector3D(0, 0, 0), Vector3D(1, 1, 0));
    Segment3D s2(Vector3D(2, 2, 0), Vector3D(3, 1, 0));
    Vector3D intersection = s1.Intersect(s2);
    assert(is_nan_vector(intersection));
    if (!is_nan_vector(intersection)) {
        std::cerr << "test_segments_intersect_outside_range failed: expected NAN, got (" << intersection.get_x() << ", " << intersection.get_y() << ", " << intersection.get_z() << ")" << std::endl;
    }
}
void test_one_segment_is_a_point() {
    Segment3D s1(Vector3D(1, 1, 1), Vector3D(1, 1, 1));
    Segment3D s2(Vector3D(0, 0, 0), Vector3D(2, 2, 2));
    Vector3D intersection = s1.Intersect(s2);
    Vector3D expected(1, 1, 1);
    if (!intersection.equals(expected)) {
        std::cerr << "test_one_segment_is_a_point failed: expected (" << expected.get_x() << ", " << expected.get_y() << ", " << expected.get_z() << "), got (" << intersection.get_x() << ", " << intersection.get_y() << ", " << intersection.get_z() << ")" << std::endl;
    }
}

void test_one_segment_is_a_point_no_intersect() {
    Segment3D s1(Vector3D(1, 1, 1), Vector3D(1, 1, 1));
    Segment3D s2(Vector3D(0, 0, 0), Vector3D(0.5, 0.5, 0.5));
    Vector3D intersection = s1.Intersect(s2);
    if (!is_nan_vector(intersection)) {
        std::cerr << "test_one_segment_is_a_point_no_intersect failed: expected NAN, got (" << intersection.get_x() << ", " << intersection.get_y() << ", " << intersection.get_z() << ")" << std::endl;
    }
}

void test_all_same_points() {
    Segment3D s1(Vector3D(2, 2, 2), Vector3D(2, 2, 2));
    Segment3D s2(Vector3D(2, 2, 2), Vector3D(2, 2, 2));
    Vector3D intersection = s1.Intersect(s2);
    Vector3D expected(2, 2, 2);
    if (!intersection.equals(expected)) {
        std::cerr << "test_all_same_points failed: expected (" << expected.get_x() << ", " << expected.get_y() << ", " << expected.get_z() << "), got (" << intersection.get_x() << ", " << intersection.get_y() << ", " << intersection.get_z() << ")" << std::endl;
    }
}

void test_segments_skew_lines_very_close() {
    Segment3D s1(Vector3D(0, 0, 0), Vector3D(1, 1, 0));
    Segment3D s2(Vector3D(0, 0, 0.00001), Vector3D(1, -1, 0.00001)); // Очень близко
    Vector3D intersection = s1.Intersect(s2);
    assert(is_nan_vector(intersection));
    if (!is_nan_vector(intersection)) {
        std::cerr << "test_segments_skew_lines_very_close failed: expected NAN, got (" << intersection.get_x() << ", " << intersection.get_y() << ", " << intersection.get_z() << ")" << std::endl;
    }
}

void test_segments_nearly_collinear_3d() {
    Segment3D s1(Vector3D(0, 0, 0), Vector3D(1, 0, 0));
    Segment3D s2(Vector3D(0.5, 0.000001, 0.000001), Vector3D(1.5, 0.000001, 0.000001));
    Vector3D intersection = s1.Intersect(s2);
    Vector3D expected(0.5, 0, 0);
    assert(intersection.equals(expected));
    if (!intersection.equals(expected)) {
        std::cerr << "test_segments_nearly_collinear_3d failed: expected (" << expected.get_x() << ", " << expected.get_y() << ", " << expected.get_z() << "), got (" << intersection.get_x() << ", " << intersection.get_y() << ", " << intersection.get_z() << ")" << std::endl;
    }
}

void test_segments_intersect_outside_range_close() {
    Segment3D s1(Vector3D(0, 0, 0), Vector3D(1, 1, 0));
    Segment3D s2(Vector3D(1.000001, 1.000001, 0), Vector3D(2, 0, 0));
    Vector3D intersection = s1.Intersect(s2);
    assert(is_nan_vector(intersection));
    if (!is_nan_vector(intersection)) {
        std::cerr << "test_segments_intersect_outside_range_close failed: expected NAN, got (" << intersection.get_x() << ", " << intersection.get_y() << ", " << intersection.get_z() << ")" << std::endl;
    }
}

void test_zero_length_and_parallel() {
    Segment3D s1(Vector3D(0, 0, 0), Vector3D(0, 0, 0));
    Segment3D s2(Vector3D(1, 1, 0), Vector3D(2, 1, 0));
    Vector3D intersection = s1.Intersect(s2);
    assert(is_nan_vector(intersection));
    if (!is_nan_vector(intersection)) {
        std::cerr << "test_zero_length_and_parallel failed: expected NAN, got (" << intersection.get_x() << ", " << intersection.get_y() << ", " << intersection.get_z() << ")" << std::endl;
    }
}

void test_point_on_extended_segment() {
    Segment3D s1(Vector3D(0, 0, 0), Vector3D(1, 1, 0));
    Segment3D s2(Vector3D(2, 2, 0), Vector3D(2, 2, 0));
    Vector3D intersection = s1.Intersect(s2);
    assert(is_nan_vector(intersection));
    if (!is_nan_vector(intersection)) {
        std::cerr << "test_point_on_extended_segment failed: expected NAN, got (" << intersection.get_x() << ", " << intersection.get_y() << ", " << intersection.get_z() << ")" << std::endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    test_parallel_non_intersecting();
    test_collinear_intersecting();
    test_collinear_non_intersecting();
    test_segments_in_3d();
    test_segments_intersect_at_endpoint();
    test_segments_nearly_parallel();
    test_segments_nearly_collinear();
    test_zero_length_segment();
    test_perpendicular_segments();
    test_segments_skew_lines();
    test_segments_intersect_outside_range();
    test_one_segment_is_a_point();
    test_one_segment_is_a_point_no_intersect();
    test_all_same_points();
    test_segments_skew_lines_very_close();
    test_segments_nearly_collinear_3d();
    test_segments_intersect_outside_range_close();
    test_zero_length_and_parallel();
    test_point_on_extended_segment();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
