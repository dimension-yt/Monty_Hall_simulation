#include "simulation.h"



// Crée une simulation

Simulation::Simulation()
{
	door_changed = false;
	nb_total = 0;
	nb_failure = 0;
	nb_success = 0;
	nb_ratio = 0.;
}



// Crée une simulation à partir des données du menu

Simulation::Simulation(const Menu& menu)
{
	texture.create(menu.width, menu.height);
	texture.clear(sf::Color(20, 20, 200));
	texture.display();
	sprite = sf::Sprite(texture.getTexture());

	door_changed = menu.variables[0].bool_value;

	nb_total = 0;
	nb_failure = 0;
	nb_success = 0;
	nb_ratio = 0;

	text_total.setString("Nombre de cas :");
	text_total.setCharacterSize(resize(50, menu.width));
	text_total.setFont(menu.texts_font);
	text_total.setFillColor(sf::Color::White);
	text_total.setOrigin(text_total.getLocalBounds().width / 2., resize(50. / 1.35, menu.width));
	text_total.setPosition(resize(600., menu.width), resize(200., menu.width));

	nb_text_total = text_total;
	nb_text_total.setString("0");
	nb_text_total.setOrigin(nb_text_total.getLocalBounds().width / 2., resize(50. / 1.35, menu.width));
	nb_text_total.setPosition(resize(600., menu.width), resize(300., menu.width));

	text_failure = text_total;
	text_failure.setString("Réussites :");
	text_failure.setOrigin(text_failure.getLocalBounds().width / 2., resize(50. / 1.35, menu.width));
	text_failure.setPosition(resize(600., menu.width), resize(500., menu.width));

	nb_text_failure = text_total;
	nb_text_failure.setString("0");
	nb_text_failure.setOrigin(nb_text_failure.getLocalBounds().width / 2., resize(50. / 1.35, menu.width));
	nb_text_failure.setPosition(resize(600., menu.width), resize(600., menu.width));

	text_success = text_total;
	text_success.setString("Echecs :");
	text_success.setOrigin(text_success.getLocalBounds().width / 2., resize(50. / 1.35, menu.width));
	text_success.setPosition(resize(600., menu.width), resize(800., menu.width));

	nb_text_success = text_total;
	nb_text_success.setString("0");
	nb_text_success.setOrigin(nb_text_success.getLocalBounds().width / 2., resize(50. / 1.35, menu.width));
	nb_text_success.setPosition(resize(600., menu.width), resize(900., menu.width));

	text_ratio = text_total;
	text_ratio.setString("Probabilité :");
	text_ratio.setOrigin(text_ratio.getLocalBounds().width / 2., resize(50. / 1.35, menu.width));
	text_ratio.setPosition(resize(1300., menu.width), resize(450., menu.width));

	nb_text_ratio = text_total;
	nb_text_ratio.setString("0");
	nb_text_ratio.setOrigin(nb_text_ratio.getLocalBounds().width / 2., resize(50. / 1.35, menu.width));
	nb_text_ratio.setPosition(resize(1300., menu.width), resize(550., menu.width));

	draw_simulation(menu);
}



// Recrrée une simulation à partir des données du menu

void Simulation::restart(const Menu& menu)
{
	texture.create(menu.width, menu.height);
	texture.clear(sf::Color(20, 20, 200));
	texture.display();
	sprite = sf::Sprite(texture.getTexture());

	door_changed = menu.variables[0].bool_value;

	nb_total = 0;
	nb_failure = 0;
	nb_success = 0;
	nb_ratio = 0;

	text_total.setString("Nombre de cas :");
	text_total.setCharacterSize(resize(50, menu.width));
	text_total.setFont(menu.texts_font);
	text_total.setFillColor(sf::Color::White);
	text_total.setOrigin(text_total.getLocalBounds().width / 2., resize(50. / 1.35, menu.width));
	text_total.setPosition(resize(600., menu.width), resize(200., menu.width));

	nb_text_total = text_total;
	nb_text_total.setString("0");
	nb_text_total.setOrigin(nb_text_total.getLocalBounds().width / 2., resize(50. / 1.35, menu.width));
	nb_text_total.setPosition(resize(600., menu.width), resize(300., menu.width));

	text_failure = text_total;
	text_failure.setString("Réussites :");
	text_failure.setOrigin(text_failure.getLocalBounds().width / 2., resize(50. / 1.35, menu.width));
	text_failure.setPosition(resize(600., menu.width), resize(500., menu.width));

	nb_text_failure = text_total;
	nb_text_failure.setString("0");
	nb_text_failure.setOrigin(nb_text_failure.getLocalBounds().width / 2., resize(50. / 1.35, menu.width));
	nb_text_failure.setPosition(resize(600., menu.width), resize(600., menu.width));

	text_success = text_total;
	text_success.setString("Echecs :");
	text_success.setOrigin(text_success.getLocalBounds().width / 2., resize(50. / 1.35, menu.width));
	text_success.setPosition(resize(600., menu.width), resize(800., menu.width));

	nb_text_success = text_total;
	nb_text_success.setString("0");
	nb_text_success.setOrigin(nb_text_success.getLocalBounds().width / 2., resize(50. / 1.35, menu.width));
	nb_text_success.setPosition(resize(600., menu.width), resize(900., menu.width));

	text_ratio = text_total;
	text_ratio.setString("Probabilité :");
	text_ratio.setOrigin(text_ratio.getLocalBounds().width / 2., resize(50. / 1.35, menu.width));
	text_ratio.setPosition(resize(1300., menu.width), resize(450., menu.width));

	nb_text_ratio = text_total;
	nb_text_ratio.setString("0");
	nb_text_ratio.setOrigin(nb_text_ratio.getLocalBounds().width / 2., resize(50. / 1.35, menu.width));
	nb_text_ratio.setPosition(resize(1300., menu.width), resize(550., menu.width));

	draw_simulation(menu);
}



// Affiche la simulation

void Simulation::draw_simulation(const Menu& menu)
{
	texture.draw(text_total);
	texture.draw(text_failure);
	texture.draw(text_success);
	texture.draw(text_ratio);

	nb_text_total.setString(std::to_string(nb_total));
	nb_text_failure.setString(std::to_string(nb_failure));
	nb_text_success.setString(std::to_string(nb_success));
	nb_text_ratio.setString(std::to_string(nb_ratio));

	nb_text_total.setOrigin(nb_text_total.getLocalBounds().width / 2., resize(50. / 1.35, menu.width));
	nb_text_failure.setOrigin(nb_text_failure.getLocalBounds().width / 2., resize(50. / 1.35, menu.width));
	nb_text_success.setOrigin(nb_text_success.getLocalBounds().width / 2., resize(50. / 1.35, menu.width));
	nb_text_ratio.setOrigin(nb_text_ratio.getLocalBounds().width / 2., resize(50. / 1.35, menu.width));

	texture.draw(nb_text_total);
	texture.draw(nb_text_failure);
	texture.draw(nb_text_success);
	texture.draw(nb_text_ratio);
}



// Met à jour la simulation

void Simulation::update()
{
	int car_door = rand() % 3;
	int choice   = rand() % 3;
	
	if (door_changed)
	{
		if (choice == car_door)
		{
			if (car_door == 0)
				choice = rand() % 2 + 1;

			else if (car_door == 1)
				choice = (rand() % 2) * 2;

			else
				choice = rand() % 2;
		}

		else
			choice = car_door;
	}

	if (car_door == choice)
		nb_success++;

	else
		nb_failure++;

	nb_ratio = (double)nb_success / (double)nb_total;

	nb_total++;
}



// Affiche la simulation

void Simulation::draw(sf::RenderWindow& window, const Menu& menu)
{
	texture.clear(sf::Color(20, 20, 200));

	draw_simulation(menu);

	texture.display();
	sprite = sf::Sprite(texture.getTexture());
	window.draw(sprite);
}