#ifndef CHOOSE_BUTTON_HPP
#define CHOOSE_BUTTON_HPP

#include "Button.hpp"

class ChooseButton : public Button
{
public:
	ChooseButton( std::string name, int width, int height );
	virtual ~ChooseButton();

	void changeButtonPosition( float posX, float posY );

	virtual void setButtonPosition() override;
	virtual void setTextPosition() override;
};

#endif