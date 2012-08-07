#ifndef POINT2D_H_
#define POINT2D_H_

#include <ostream>

namespace geom
{


/** A simple 2D point class. */
class Point2D
{

public:

    Point2D();

    Point2D(float x, float y);

    Point2D(const Point2D& other);

    virtual ~Point2D();

    Point2D& operator=(const Point2D& rhs);

    Point2D& operator+=(const Point2D& rhs);

    Point2D& operator-=(const Point2D& rhs);

    Point2D& operator*=(const Point2D& rhs);

    Point2D& operator/=(const Point2D& rhs);

    Point2D& operator*=(float factor);

    Point2D& operator/=(float divisor);

    const Point2D operator-() const;

    const Point2D operator+(const Point2D& other) const;

    const Point2D operator-(const Point2D& other) const;

    const Point2D operator*(const Point2D& other) const;

    const Point2D operator/(const Point2D& other) const;

    const Point2D operator*(float factor) const;

    const Point2D operator/(float divisor) const;

    bool operator==(const Point2D& rhs) const;

    bool operator!=(const Point2D& rhs) const;

    bool operator<(const Point2D& rhs) const;

    bool operator>(const Point2D& rhs) const;

    bool operator<=(const Point2D& rhs) const;

    bool operator>=(const Point2D& rhs) const;

    const Point2D abs() const;

    bool isIn(const Point2D list[], int listSize) const;

    friend const Point2D min(const Point2D& p1, const Point2D& p2);

    friend const Point2D max(const Point2D& p1, const Point2D& p2);

    friend std::ostream& operator<<(std::ostream& out, const Point2D& point);

public:

    float x;

    float y;

}; // class Point2D


float dist(const Point2D& p1, const Point2D& p2);


} // namespace geom


#endif // POINT2D_H_
