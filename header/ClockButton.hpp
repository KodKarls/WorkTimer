#ifndef CLOCK_BUTTON_HPP
#define CLOCK_BUTTON_HPP

#include "Button.hpp"

class ClockButton : public Button
{
public:
	ClockButton( std::string name, int width, int height );
	virtual ~ClockButton();

private:
	virtual void setButtonPosition() override;
    virtual void setTextPosition() override;
};

#endif