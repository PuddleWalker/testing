#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

void circle(Shape& shape) {
	shape.setPosition(shape.getPosition().x + 4, shape.getPosition().y + 4);
}
void circle2(Shape& shape) {
	shape.setPosition(shape.getPosition().x - 4, shape.getPosition().y + 4);
}
void circleMgnum(CircleShape& shape, CircleShape& shape2, RenderWindow& window) {
	if (shape.getPosition().x <= 0) {
		shape2.setPosition((float)window.getSize().x + shape.getPosition().x, shape2.getPosition().y);
		if (shape.getPosition().x < (1 - (float)window.getSize().x)) {
			shape.setPosition(0, shape.getPosition().y);
		}
	}
	if (shape.getPosition().y <= 0) {
		shape2.setPosition(shape2.getPosition().x, (float)window.getSize().y + shape.getPosition().y);
		if (shape.getPosition().y < (1 - (float)window.getSize().y)) {
			shape.setPosition(shape.getPosition().x, 0);
		}
	}
	if (shape.getPosition().x + shape.getRadius() * 2 >= window.getSize().x) {
		shape2.setPosition(-(float)window.getSize().x + shape.getPosition().x, shape2.getPosition().y);
		if (shape.getPosition().x + shape.getRadius() * 2 - (float)window.getSize().x > window.getSize().x) {
			shape.setPosition(-shape.getRadius() * 2, shape.getPosition().y);
		}
	}
	if (shape.getPosition().y + shape.getRadius() * 2 >= window.getSize().y) {
		shape2.setPosition(shape2.getPosition().x, -(float)window.getSize().y + shape.getPosition().y);
		if (shape.getPosition().y + shape.getRadius() * 2 - (float)window.getSize().x > window.getSize().y) {
			shape.setPosition(shape.getPosition().x, -shape.getRadius() * 2);
		}
	}
}
void circleMgnum2(RectangleShape& shape, RectangleShape& shape2, RenderWindow& window) {
	if (shape.getPosition().x >= (float)window.getSize().x - shape.getSize().x) {
		shape2.setPosition(shape.getPosition().x - (float)window.getSize().x, shape2.getPosition().y);
		if (shape.getPosition().x > ((float)window.getSize().x) * 2 - 1) {
			shape.setPosition((float)window.getSize().x - shape.getSize().x, shape.getPosition().y);
		}
	}
	if (shape.getPosition().y <= 0) {
		shape2.setPosition(shape2.getPosition().x, (float)window.getSize().y + shape.getPosition().y);
		if (shape.getPosition().y < (1 - (float)window.getSize().y)) {
			shape.setPosition(shape.getPosition().x, 0);
		}
	}
	if (shape.getPosition().x <= 0) {
		shape2.setPosition((float)window.getSize().x + shape.getPosition().x, shape2.getPosition().y);
		if (-shape.getPosition().x > window.getSize().x) {
			shape.setPosition(window.getSize().x, shape.getPosition().y);
		}
	}
	if (shape.getPosition().y + shape.getSize().x >= window.getSize().y) {
		shape2.setPosition(shape2.getPosition().x, -(float)window.getSize().y + shape.getPosition().y);
		if (shape.getPosition().y + shape.getSize().x - (float)window.getSize().x > window.getSize().y) {
			shape.setPosition(shape.getPosition().x, -shape.getSize().x);
		}
	}
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 400), "Project");
	window.setFramerateLimit(30);
	sf::CircleShape shape(30.f);
	RectangleShape shap(Vector2f(50, 50));

	shape.setFillColor(sf::Color::Red);
	shap.setFillColor(sf::Color::Black);

	RectangleShape recShape(Vector2f(window.getSize()));

	CircleShape shape2;
	RectangleShape shap2;
	shap.setPosition((float)window.getSize().x - shape.getRadius() * 2, 0);
	shape2 = shape;
	shap2 = shap;
	shape2.setPosition((Vector2f)window.getSize());
	shap2.setPosition(0, (float)window.getSize().x - shape.getRadius() * 2);
	int x = 0, y = 0;
	while (window.isOpen())
	{
		Event event;
		if (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		circleMgnum(shape, shape2, window);
		circleMgnum2(shap, shap2, window);
		circle(shape);
		circle2(shap);
		window.clear();
		window.draw(recShape);
		window.draw(shape);
		window.draw(shap);
		window.draw(shape2);
		window.draw(shap2);
		window.display();
	}

	return 0;
}