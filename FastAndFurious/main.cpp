#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf; 

int main()
{
	RenderWindow window(VideoMode(800, 600), "FastAndFurious");


	//establecer posicion del objeto//
	Vector2f position(50.0f, 400.0f);
	//establecer velocidades horizontal y verticall//
	//la velocidad vertical no es necesaria para este ejercicio, se podría hacer con una variable común//
	Vector2f velocity(3.5f, 0.0f);

	//provesar eventos en el bucle//
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		//establecer el deltaTime a 60fps//
		float deltaTime = 1.0f / 60.0f;
		
		//aplicar el movimiento ajustando la posición a la velocidad//
		position += velocity * deltaTime;

		//condicional para que cada vez que el objeto salga por la derecha de la pantalla 
		//vuelga a salir por la izquierda
		if (position.x > 800.0f)
		{
			position.x = -50.0f;
			velocity.x += 3.0f;
		}
		//otro condicional ajustando que se detenga cuan alcance la velocidad final (que también podría fijarse como una variable)
		//sumando la condición para que el objeto se detenga en el centro de la pantalla
		if (( velocity.x >= 21.0f) && (position.x >= 400.0f))
		{
			velocity.x = 0.0f;
			
		}
		

		window.clear();
		//creación del objeto
		CircleShape object;
		object.setRadius(25);
		object.setPosition(position);
		object.setFillColor(Color::Blue);
		window.draw(object);

		window.display();
	}

	return 0;


}