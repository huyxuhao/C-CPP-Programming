#include <iostream>

class Shape
{
public:
    // A virtual function signals that this function can be overridden in derived classes
    virtual void draw()
    {
        std::cout << "Drawing a shape" << std::endl;
    }
};

class Circle : public Shape
{
public:
    // Override the base class fuction
    void draw() override
    {
        std::cout << "Drawing a circle" << std::endl;
    }
};

class Square : public Shape
{
public:
    // Override the base class function
    void draw() override
    {
        std::cout << "Drawing a square" << std::endl;
    }
};

// This function can accept any object that is a "Shape" or derived from it
void drawAnyShape(Shape *shape)
{
    // The correct 'draw' is called here
    shape->draw();
}

int main()
{
    Circle circle;
    Square square;

    drawAnyShape(&circle); // Outputs: Drawing a circle
    drawAnyShape(&square); // Outputs: Drawing a square

    return 0;
}