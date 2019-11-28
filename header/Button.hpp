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

    Button( sf::RenderWindow& window, std::string name );
    Button( std::string name );
    ~Button();

    sf::RectangleShape& getShape();
    sf::Text& getText();

private:
    void setButtonColor();
    void setButtonPosition();
    float getPositionX();
    float getPositionY();
    void setFont();
    void setText();
    void setTextPosition();

    static int buttonCounter;

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
