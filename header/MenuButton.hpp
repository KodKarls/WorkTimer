#ifndef MENU_BUTTON_HPP
#define MENU_BUTTON_HPP

#include "Button.hpp"

class MenuButton : public Button
{
public:
	MenuButton( std::string name );
	virtual ~MenuButton();

private:
	virtual void setButtonPosition() override;
    virtual void setTextPosition() override;

	static int buttonCounter;
};

#endif