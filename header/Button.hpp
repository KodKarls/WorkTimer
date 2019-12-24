#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "Logger.hpp"
#include <SFML/Graphics.hpp>

class Button
{
public:
    struct Color
    {
        short red_;
        short green_;
        short blue_;
        short alpha_;

        void setColor( short red, short green, short blue, short alpha )
        {
            red_ = red;
            green_ = green;
            blue_ = blue;
            alpha_ = alpha;
        }
    };

    Button();
    virtual ~Button();

    sf::RectangleShape& getShape();
    sf::Text& getText();

protected:
    virtual void setButtonPosition() = 0;
    virtual void setTextPosition() = 0;

    void setButtonColor();
    float getPositionX();
    float getPositionY();
    void setFont();
    void setText();

    int width_;
    int height_;
    sf::RectangleShape rectangle_;
    Color color_;
    sf::Font font_;
    sf::Text text_;
    std::string name_;
    float positionX_;
    float positionY_;
};

#endif
