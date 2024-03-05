//
// Created by Conni Bilham on 10/07/2023.
//

#ifndef INC_2D_ENGINE_VECTOR_H
#define INC_2D_ENGINE_VECTOR_H

class Vector {

public:
    double x, y, z;

    Vector(double x, double y, double z);
    Vector(double x, double y);
    Vector(double x);
    Vector();

    template<typename T>
    Vector operator+(T &other);

    template<typename T>
    Vector operator-(T &other);

    template<typename T>
    Vector operator*(const T &other) const;

    template<typename T>
    Vector operator/(T &other);


    bool operator==(const Vector &other);
    bool operator!=(const Vector &other);

    double magnitude();
    Vector normalize();
    double dot(const Vector &other);
    Vector cross(const Vector &other);

    Vector direction(Vector &other);
};


#endif//INC_2D_ENGINE_VECTOR_H
