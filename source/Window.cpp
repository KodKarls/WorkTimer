#include "../header/Window.hpp"

Window::Window()    :   width_( 600 ), height_( 600 ), 
                        name_( "Work Timer")
{

}

Window::~Window()
{

}

int Window::getWidth() const
{
    return width_;
}

int Window::getHeight() const
{
    return height_;
}

std::string Window::getName() const
{
    return name_;
}
