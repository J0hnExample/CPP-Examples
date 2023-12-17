#ifndef PAYLOAD_H
#define PAYLOAD_H

#include <memory>
#include <iostream>
#include "trackmymoves.h"
/*
 *  Payload serves for testing containers. It
 *  counts how many instances of this type
 *  currently exist, via a static counter.
 *
 */
class Payload //: public TrackMyMoves
{

public:
    // data
    float x, y, z;
    //unmark the first comment in the trackmymoves.h file when switch to true
    bool trackmymoves_SWITCH = false;

    // constructors
    Payload(float xx = 0, float yy = 0, float zz = 0) : x(xx), y(yy), z(zz) 
    { 
        count_++;
        if (trackmymoves_SWITCH == true)
        {
            trackmymoves_ = TrackMyMoves("Payload default constructed");
        }
        
        
    }
    Payload(const Payload &rhs) : x(rhs.x), y(rhs.y), z(rhs.z)
    {
        count_++;
        copyCount_++;
        if (trackmymoves_SWITCH == true)
        {
            trackmymoves_ = TrackMyMoves("Payload copy constructed");
        }
        
    }
    //Copy constructor
    Payload(const Payload &&rhs) : x(rhs.x), y(rhs.y), z(rhs.z)
    {
        count_++;
        moveCount_++;
        //trackmymoves_ = TrackMyMoves("Payload copy constructed");
        if (trackmymoves_SWITCH == true)
        {
            trackmymoves_ = TrackMyMoves("Payload move constructed");
        }
        
    }

    // destructor
    ~Payload() { count_--; }

    // assignment - keeps count the same
    Payload &operator=(const Payload &rhs)
    {
        //TrackMyMoves::operator=(rhs);
        if (trackmymoves_SWITCH == true)
        {
            trackmymoves_ = TrackMyMoves("Payload assigned");
        }
        x = rhs.x;
        y = rhs.y;
        z = rhs.z;
        copyCount_++;
        return *this;
    }
    Payload &operator=(const Payload &&rhs)
    {
        //TrackMyMoves::operator=(std::move(rhs));
        if (trackmymoves_SWITCH == true)
        {
            trackmymoves_ = TrackMyMoves("Payload moved");
        }
        x = rhs.x;
        y = rhs.y;
        z = rhs.z;
        moveCount_++;
        return *this;
    }

    // comparison
    bool operator==(const Payload &rhs) const { return x == rhs.x && y == rhs.y && z == rhs.z; }
    bool operator!=(const Payload &rhs) const { return !(*this == rhs); }

    // tell count
    static size_t count()
    {
        std::cout << " count: " << count_ << " copy: " << copyCount_ << " move: " << moveCount_ << std::endl;
        return count_;
    }

private:
    static size_t count_;
    static size_t copyCount_;
    static size_t moveCount_;
    TrackMyMoves trackmymoves_;
};

#endif // PAYLOAD_H
