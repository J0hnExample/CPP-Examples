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


    private:
        float x_, y_;

};