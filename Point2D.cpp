#include "Point2D.h"

#include <cmath>

#define ZERO_LIMIT (1. / 10000.)
#define NEAR_ZERO(exp) (std::abs(exp) <= ZERO_LIMIT)
#define NEAR_EQUAL(v1, v2) (NEAR_ZERO((v1) - (v2)))

namespace geom
{

Point2D::Point2D()
:   x(0),
    y(0)
{}


Point2D::Point2D(float x, float y)
:   x(x),
    y(y)
{}


Point2D::~Point2D()
{}


Point2D::Point2D(const Point2D& other)
:   x(other.x),
    y(other.y)
{}


Point2D&
Point2D::operator=(const Point2D& rhs)
{
    if (this != &rhs)
    {
        this->x = rhs.x;
        this->y = rhs.y;
    }
    return *this;
}


Point2D&
Point2D::operator+=(const Point2D& rhs)
{
    this->x += rhs.x;
    this->y += rhs.y;
    return *this;
}


Point2D&
Point2D::operator-=(const Point2D& rhs)
{
    this->x -= rhs.x;
    this->y -= rhs.y;
    return *this;
}


Point2D&
Point2D::operator*=(const Point2D& rhs)
{
    this->x *= rhs.x;
    this->y *= rhs.y;
    return *this;
}


Point2D&
Point2D::operator/=(const Point2D& rhs)
{
    this->x /= rhs.x;
    this->y /= rhs.y;
    return *this;
}


Point2D&
Point2D::operator*=(float factor)
{
    this->x *= factor;
    this->y *= factor;
    return *this;
}


Point2D&
Point2D::operator/=(float divisor)
{
    this->x /= divisor;
    this->y /= divisor;
    return *this;
}


const Point2D
Point2D::operator-() const
{
    return Point2D(-x, -y);
}


const Point2D
Point2D::operator+(const Point2D& other) const
{
    return Point2D(*this) += other;
}


const Point2D
Point2D::operator-(const Point2D& other) const
{
    return Point2D(*this) -= other;
}


const Point2D
Point2D::operator*(const Point2D& other) const
{
    return Point2D(*this) *= other;
}


const Point2D
Point2D::operator/(const Point2D& other) const
{
    return Point2D(*this) /= other;
}


const Point2D
Point2D::operator*(float factor) const
{
    return Point2D(*this) *= factor;
}


const Point2D
Point2D::operator/(float divisor) const
{
    return Point2D(*this) /= divisor;
}


bool
Point2D::operator==(const Point2D& rhs) const
{
    return NEAR_EQUAL(x, rhs.x) && NEAR_EQUAL(y, rhs.y);
}


bool
Point2D::operator!=(const Point2D& rhs) const
{
    return !(*this == rhs);
}


bool
Point2D::operator<(const Point2D& rhs) const
{
    return (x < rhs.x) && (y < rhs.y);
}


bool
Point2D::operator>(const Point2D& rhs) const
{
    return (x > rhs.x) && (y > rhs.y);
}


bool
Point2D::operator<=(const Point2D& rhs) const
{
    return (x <= rhs.x) && (y <= rhs.y);
}


bool
Point2D::operator>=(const Point2D& rhs) const
{
    return (x >= rhs.x) && (y >= rhs.y);
}


const Point2D
Point2D::abs() const
{
    return Point2D(std::abs(x), std::abs(y));
}


bool
Point2D::isIn(const Point2D list[], int listSize) const
{
    for (int i = 0; i < listSize; ++i)
    {
        if (list[i] == *this)
        {
            return true;
        }
    }
    return false;
}


const Point2D
min(const Point2D& p1, const Point2D& p2)
{
    return Point2D(std::min(p1.x, p2.x), std::min(p1.y, p2.y));
}


const Point2D
max(const Point2D& p1, const Point2D& p2)
{
    return Point2D(std::max(p1.x, p2.x), std::max(p1.y, p2.y));
}


std::ostream&
operator<<(std::ostream& out, const Point2D& point)
{
    out << "Point2D(" << point.x << ", " << point.y << ")";
    return out;
}


float
dist(const Point2D& p1, const Point2D& p2)
{
	return (float)(std::sqrt((float)(
        (p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y))));
}


} // namespace geom

