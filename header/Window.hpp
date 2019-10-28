#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>

class Window
{
private:
    const int width_;
    const int height_;
    const std::string name_;

public:
    Window();
    ~Window();

    int getWidth() const;
    int getHeight() const;
    std::string getName() const;
};

#endif
