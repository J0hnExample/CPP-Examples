class Vec2 {
public:
    // Default constructor with default values
    Vec2(float x=0, float y=0);

    // Accessors !cant change the values
    float x() const { return x_; }
    float y() const { return y_; }
    //  Mutators !can change the values
    void set_x(float x);
    void set_y(float y);

    // Unary operator method
    Vec2 Vec2::operator-() const 
    {
        return Vec2(-x_, -y_);
    }
    // Binary overloading operator method
    //rhs = right hand side convention
    Vec2 Vec2::operator+( Vec2 rhs) const
    {
        return Vec2(x()+rhs.x(), y()+rhs.y());
    }
    Vec2 Vec2::operator*(float rhs) const
    {
        return Vec2(x()*rhs, y()*rhs);
    }


    private:
        float x_, y_;

};