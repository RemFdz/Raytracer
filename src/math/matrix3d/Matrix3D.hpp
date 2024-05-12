/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
**
*/

#pragma once

#include "../vector3d/Vector3D.hpp"

namespace Math {

    /**
    * @brief Matrix3D class
    * @details Class for 3D matrices
    * @var elements 3x3 matrix elements
    * @var columns 3x3 matrix columns
    **/
    class Matrix3D {
    public:
        Matrix3D() {
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    elements[i][j] = 0.0;
                }
            }
        }

        Matrix3D(const Vec3& col0, const Vec3& col1, const Vec3& col2) {
            columns[0] = col0;
            columns[1] = col1;
            columns[2] = col2;
        }

        Matrix3D(const Matrix3D& other) {
            for (int i = 0; i < 3; ++i) {
                columns[i] = other.columns[i];
            }
        }

        Vec3 operator*(const Vec3& v) const {
            Vec3 result;
            for (int i = 0; i < 3; ++i) {
                result[i] = elements[i][0] * v.x() + elements[i][1] * v.y() + elements[i][2] * v.z();
            }
            return result;
        }

        Matrix3D operator*(const Matrix3D& other) const {
            Matrix3D result;
            for (int j = 0; j < 3; ++j) {
                for (int i = 0; i < 3; ++i) {
                    double sum = 0.0;
                    for (int k = 0; k < 3; ++k) {
                        sum += elements[k][i] * other.elements[j][k];
                    }
                    result.elements[j][i] = sum;
                }
            }
            return result;
        }

        static Matrix3D rotationMatrix(double angle, const Vec3& axis) {
            double c = cos(angle);
            double s = sin(angle);
            double t = 1 - c;
            double x = axis.x();
            double y = axis.y();
            double z = axis.z();
            return Matrix3D(
                Vec3(
                    t * x * x + c,
                    t * x * y - s * z,
                    t * x * z + s * y
                ),
                Vec3(
                    t * x * y + s * z,
                    t * y * y + c,
                    t * y * z - s * x
                ),
                Vec3(
                    t * x * z - s * y,
                    t * y * z + s * x,
                    t * z * z + c
                )
            );
        }

        Vec3& operator[](int index) {
            return columns[index];
        }

        const Vec3& operator[](int index) const {
            return columns[index];
        }

    private:
        double elements[3][3];
        Vec3 columns[3];
    };

} // namespace Math


