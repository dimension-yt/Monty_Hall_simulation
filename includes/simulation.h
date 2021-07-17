#ifndef SIMULATION_H
#define SIMULATION_H
#include "menu.h"
#include <vector>



// Classe définissant la simulation

class Simulation
{

public:

	bool				door_changed;
	sf::Text			text_total;
	sf::Text			text_failure;
	sf::Text			text_success;
	sf::Text			text_ratio;
	int					nb_total;
	int					nb_failure;
	int					nb_success;
	double				nb_ratio;
	sf::Text			nb_text_total;
	sf::Text			nb_text_failure;
	sf::Text			nb_text_success;
	sf::Text			nb_text_ratio;
	sf::RenderTexture	texture;		// La texture sur laquelle sont dessinés les pixels
	sf::Sprite			sprite;			// Le sprite servant à afficher la texture

	Simulation();
	Simulation(const Menu& menu);

	void restart(const Menu& menu);
	void draw_simulation(const Menu& menu);
	void update();
	void draw(sf::RenderWindow& window, const Menu& menu);
};

#endif