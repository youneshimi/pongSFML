
// (c) 2022 by Younes Shimi _ Imane El Boukili 


#ifndef INPUT_H
#define INPUT_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Input
{
	struct Button { bool left, right, up, down, escape; };

public:
	//prototype de constructeur
	Input();
	//autres Protos
	Button GetButton(void) const;
	void InputHandler(Event event, RenderWindow& window);

private:
	Button button;
};

#endif