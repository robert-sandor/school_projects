//
// Created by robert on 6/4/15.
//

#include "Balloon.h"

bool Balloon::operator==(const Balloon &other) const {
    return _x == other._x &&
           _y == other._y &&
           _radius == other._radius;
}

bool Balloon::operator!=(const Balloon &other) const {
    return !operator==(other);
}

bool Balloon::operator<(const Balloon &other) const {
    return (int)(_x + _radius) < (int)(other._x + other._radius);
}

bool Balloon::operator<=(const Balloon &other) const {
    return !operator>(other);
}

bool Balloon::operator>(const Balloon &other) const {
    return (_x + _radius) > (other._x + other._radius);
}

bool Balloon::operator>=(const Balloon &other) const {
    return !operator<(other);
}
