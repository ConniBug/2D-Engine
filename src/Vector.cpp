//
// Created by Conni Bilham on 10/07/2023.
//

#include "Vector.h"
#include <cmath>

Vector::Vector(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector::Vector(double x, double y) {
    this->x = x;
    this->y = y;
    this->z = 0;
}

Vector::Vector(double x) {
    this->x = x;
    this->y = 0;
    this->z = 0;
}

Vector::Vector() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

template<typename T>
Vector Vector::operator+(T &other) {
    return {
            this->x + other.x,
            this->y + other.y,
            this->z + other.z};
}

template<typename T>
Vector Vector::operator-(T &other) {
    return {
            this->x - other.x,
            this->y - other.y,
            this->z - other.z};
}

template<typename T>
Vector Vector::operator*(const T &other) const {
    return {
            this->x * other.x,
            this->y * other.y,
            this->z * other.z};
}

template<typename T>
Vector Vector::operator/(T &other) {
    return {
            this->x / other.x,
            this->y / other.y,
            this->z / other.z};
}


bool Vector::operator==(const Vector &other) {
    return this->x == other.x && this->y == other.y && this->z == other.z;
}

bool Vector::operator!=(const Vector &other) {
    return this->x != other.x || this->y != other.y || this->z != other.z;
}

double Vector::magnitude() {
    return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}

Vector Vector::normalize() {
    double mag = this->magnitude();
    return {
            this->x / mag,
            this->y / mag,
            this->z / mag};
}

double Vector::dot(const Vector &other) {
    return this->x * other.x + this->y * other.y + this->z * other.z;
}

Vector Vector::cross(const Vector &other) {
    return {
            this->y * other.z - this->z * other.y,
            this->z * other.x - this->x * other.z,
            this->x * other.y - this->y * other.x};
}

Vector Vector::direction(Vector &other) {
    return (other - *this);
}
