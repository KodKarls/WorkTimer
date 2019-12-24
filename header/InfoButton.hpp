#ifndef INFO_BUTTON_HPP
#define INFO_BUTTON_HPP

#include "Button.hpp"

class InfoButton : public Button
{
public:
	InfoButton( std::string name, int width, int height );
	virtual ~InfoButton();

private:
	virtual void setButtonPosition() override;
    virtual void setTextPosition() override;
};

#endif