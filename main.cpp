

// (c) 2022 by Younes Shimi _ Imane El Boukili 




#include "main.h"


// VAriables 

//La fenetre du jeu
RenderWindow window;
//Pour la gestion des inputs
Input input;
//Pour stocker la fonte 
Font font;
//Pour stocker le texte
Text txt;


//Pos Raquettes 
float posRaquettesLeftX = 50;
float posRaquettesRightX = WIN_WIDTH - 70;
float posRaquettesLeftY = WIN_HEIGHT / 2;
float posRaquettesRightY = posRaquettesLeftY;
float RaquettesSpeed = 0.25f;
int RaquettesHeight = 150;
int RaquettesWidth= 20;

//Infos de Balle
float ballSpeed = 0.75f;
Vector2f ballDir = Vector2f(1.5f, 2.0f);
float ballPosX = WIN_WIDTH / 2;
float ballPosY = WIN_HEIGHT / 2;

//Score 
int scoreJ1 = 0;
int scoreJ2 = 0;


// Mini IA
void RaquetteIA() 
{
	posRaquettesRightY = ballPosY;
}


  
void UpdateBall() {
	// Pos de Balle 
	ballPosX += ballDir.x * ballSpeed;
	ballPosY += ballDir.y * ballSpeed;

	// Collision balle 
	// raquete gauche ou droite touchée ?
	if ((ballPosX < posRaquettesLeftX + RaquettesWidth && ballPosX > posRaquettesLeftX && ballPosY+7
		< posRaquettesLeftY + RaquettesHeight && ballPosY+7 > posRaquettesLeftY)
		||
		(ballPosX > posRaquettesRightX - RaquettesWidth && ballPosX
			< posRaquettesRightX && ballPosY+7 < posRaquettesRightY + RaquettesHeight &&
			ballPosY+7 > posRaquettesRightY)) {

		ballDir.x *= -1;
	}
	// mur gauche 
	if (ballPosX < 0) {
		scoreJ2++;
		ballPosX = WIN_WIDTH / 2;
		ballPosY = WIN_HEIGHT / 2;
		ballDir.x = fabs(ballDir.x);
		ballDir.y *= -1;
		SetText(txt, std::to_string(scoreJ1) + " | " + std::to_string(scoreJ2));

	}
	// mur droite
	if (ballPosX < WIN_WIDTH) {
		scoreJ1++;
		ballPosX = WIN_WIDTH / 2;
		ballPosY = WIN_HEIGHT / 2;
		ballDir.x = -fabs(ballDir.x);
		ballDir.y *= -1;
		SetText(txt, std::to_string(scoreJ1) + " | " + std::to_string(scoreJ2));

	}

	// mur haut ou bas 
	if (ballPosY > WIN_HEIGHT || ballPosY < 0) {
		ballDir.y *= -1;
	}

} 


//Fonction main, point de départ du programme
int main()
{

	// Creéation d'une fenétre type RenderWindow
	window.create(VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "Pong C++", Style::Default);

	// Chargement fonte 
	font.loadFromFile("res/Poppins-Italic.ttf");

	// En régle toutes les propriétés de celui-ci
	SetText(txt, std::to_string(scoreJ1) + " | " + to_string(scoreJ2));

		//Préparation des Formes
		//Balle
		CircleShape circleShape(15);
	circleShape.setPosition(ballPosX, ballPosY);

	//Raquette gauche
	RectangleShape rectangleShape(Vector2f(RaquettesWidth, RaquettesHeight));
	rectangleShape.setPosition(posRaquettesLeftX, posRaquettesRightY);

		//RAquette Droite
	RectangleShape rectangleShape2(Vector2f(RaquettesWidth, RaquettesHeight));
	rectangleShape2.setPosition(posRaquettesRightX, posRaquettesRightY);

	//boucle qui tourne tant que la fenetr est ouverte

	while (window.isOpen())
	{

		Event event; //Variable pour gérer l'événement
		// On boucle sur les événements
		while (window.pollEvent(event))
		{
			//Gestion des inputs / events
			input.InputHandler(event, window);
		}
		//Gestion Clavier / Souris
		CheckBtn();
		RaquetteIA();
		// Position Raquettes, Balle
		rectangleShape.setPosition(posRaquettesLeftX, posRaquettesLeftY);
		rectangleShape2.setPosition(posRaquettesLeftX, posRaquettesLeftY);

			//Update Ball
			UpdateBall();
		circleShape.setPosition(ballPosX, ballPosY);

		//couleur de la fenetre en noir
		window.clear(Color::Black);

		//C'est ici que l'on dessine les éléments du jeu
		window.draw(txt);
		window.draw(circleShape);
		window.draw(rectangleShape);
		window.draw(rectangleShape2);
	}

// Fin du Programme 
	return 0;

}


void SetText(Text& txt, String str)
{
	// On Lui indique quelle police Utiliser 
	txt.setFont(font);

	//on indique la chaine de caractéres à afficher
	txt.setString(str);

	// indique la taille de la police d'écriture
	txt.setCharacterSize(26);

	// En indique La couleur
	txt.setFillColor(Color::White);

	//pos
	
	txt.setPosition((WIN_WIDTH / 2) - 40, 10);
}


void CheckBtn()
{
	// RAquette gauche
	if (input.GetButton().up == true)
	{
		posRaquettesLeftY -= RaquettesSpeed;
		if (posRaquettesLeftY < 0)
			posRaquettesLeftY = 0;
	}
	if (input.GetButton().down == true)
	{
		posRaquettesLeftY += RaquettesSpeed;
		if (posRaquettesLeftY + RaquettesHeight > WIN_HEIGHT)
			posRaquettesLeftY = WIN_HEIGHT - RaquettesHeight;
	}

	// RAquette Droite 

	if (input.GetButton().left == true)
	{
		posRaquettesRightY -= RaquettesSpeed;
		if (posRaquettesRightY < 0)
			posRaquettesRightY = 0;
	}
	if (input.GetButton().right == true)
	{
		posRaquettesRightY += RaquettesSpeed;
		if (posRaquettesRightY + RaquettesHeight > WIN_HEIGHT)
			posRaquettesRightY = WIN_HEIGHT - RaquettesHeight;
	}
	if (input.GetButton().escape == true)
	{
		window.close();
	}



}


