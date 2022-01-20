# pongSFML
Le projet consiste à créer un jeux 2D avec C++ Utilisant la SFML


## Getting Started

SFML est une interface de programmation destinée à construire des jeux vidéo ou des programmes interactifs. Elle est écrite en C++, mais également disponible dans divers langages comme C, D, Python, Ruby, OCaml ou Microsoft .NET. Elle a entre autres pour but de proposer une alternative orientée objet


## Installing

l'installation du package sfml avec toute les bibliothèque

    https://www.sfml-dev.org/download/sfml/2.5.1/index-fr.php


Après l'installation en extrait le fichier zip


## Configuration de SFML sur Mon projet 
 
https://github.com/youneshimi/pongSFML/blob/main/SFML%20(1).gif

## input.h

```ts
#ifndef INPUT_H
#define INPUT_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Input
{
	struct Button { bool left, right, up, down, escape; };

public:
	
	Input();
	
	Button GetButton(void) const;
	void InputHandler(Event event, RenderWindow& window);

private:
	Button button;
};

#endif
```


Bibliothèque `SFML` pour gérer la partie graphique et la fenêtre : 
```ts
#include <SFML/Graphics.hpp>
```
