//
// Created by robert on 6/3/15.
//

#ifndef PROJECTDSA_BALLOON_H
#define PROJECTDSA_BALLOON_H


class Balloon {
public:
    Balloon ( int _x, int _y, unsigned int _radius ) : _x ( _x ), _y ( _y ), _radius ( _radius ) { }

    Balloon () { }

    virtual ~Balloon () { }

    int get_x () const {
        return _x;
    }

    int get_y () const {
        return _y;
    }

    unsigned int get_radius () const {
        return _radius;
    }

    int get_left_bound () const {
        return _x - _radius;
    }

    int get_right_bound () const {
        return _x + _radius;
    }

    bool operator< ( const Balloon & other ) const {
        return get_right_bound () < other.get_right_bound ();
    }

    bool operator<= ( const Balloon & other ) const {
        return get_right_bound () <= other.get_right_bound ();
    }

    bool operator> ( const Balloon & other ) const {
        return get_right_bound () > other.get_right_bound ();
    }

    bool operator>= ( const Balloon & other ) const {
        return get_right_bound () >= other.get_right_bound ();
    }

    bool operator== ( const Balloon & other ) const {
        return _radius == other._radius && _x == other._x && _y == other._y;
    }

    bool operator!= ( const Balloon & other ) const {
        return !operator== ( other );
    }

private:
    int _x;
    int _y;
    unsigned int _radius;
};


#endif //PROJECTDSA_BALLOON_H
