//
// Created by robert on 6/4/15.
//

#ifndef SDA_PROJECT_NEW_BALLOON_H
#define SDA_PROJECT_NEW_BALLOON_H


class Balloon {
public:
    Balloon(int _x, int _y, unsigned int _radius) : _x(_x), _y(_y), _radius(_radius) { }

    Balloon(const Balloon &other) : _x(other._x), _y(other._y), _radius(other._radius) { }

    Balloon(Balloon &other) : _x(other._x), _y(other._y), _radius(other._radius) { }

    Balloon() { }

    virtual ~Balloon() { }

    int get_x() const {
        return _x;
    }

    int get_y() const {
        return _y;
    }

    unsigned int get_radius() const {
        return _radius;
    }

    bool operator==(const Balloon &other) const;

    bool operator!=(const Balloon &other) const;

    bool operator<(const Balloon &other) const;

    bool operator<=(const Balloon &other) const;

    bool operator>(const Balloon &other) const;

    bool operator>=(const Balloon &other) const;

private:
    int _x;
    int _y;
    unsigned int _radius;
};


#endif //SDA_PROJECT_NEW_BALLOON_H
