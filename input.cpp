
// (c) 2022 by Younes Shimi _ Imane El Boukili 

#include "input.h"


// Constructeur
Input::Input()
{
	button.left = button.right = button.up = button.down = button.escape = false;
}

//Fonction qui accéde à button (struc) et nous donne l'info private
Input::Button Input::GetButton(void) const
{
	return button;

}

//Fonction de gestion des inputs
void Input::InputHandler(Event event, RenderWindow& window)
{





	//Fermer la fenetre si on clique sur la croix
	if (event.type == Event::Closed)
	{
		//On Ferme la fenetre
		window.close();

	}
  
	//Gestion des inputs (appuyés)
	if (event.type == Event::KeyPressed)
	{
		switch(event.key.code) //Code de la touche utilisée
		{
		case Keyboard::Escape:
			button.escape = true;
			break;

		case Keyboard::Left:
			button.left = true;
			break;

		case Keyboard::Right:
			button.right = true;
			break;

		case Keyboard::Down:
			button.down = true;
			break;
		default:
			break;
		}

	}

	//Touche relachée
	if (event.type == Event::KeyReleased)
	{

		// Touche relàchée
		switch (event.key.code)
		{
		case Keyboard::Escape:
				button.escape = false;
			break;

			case Keyboard::Left:
				button.left = false;
				break;

			case Keyboard::Right:
					button.right = false;
					break;

			case Keyboard::Down:
						button.down = false;
						break;

		    case Keyboard::Up:
							button.up = false;
							break;
			default:
				break;
		}
	}

}
