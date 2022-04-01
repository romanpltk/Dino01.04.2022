#include "cactus.h"
#include "settings.h"

std::string Cactus::barrier_file_names[] = {"spike A.png", "spike B.png" ,"spike C.png" ,"spike D.png" };
Cactus::Cactus() {
	
	size_t num = rand() % CACTUS_TYPE_QTY;
	texture.loadFromFile(IMAGES_FOLDER + barrier_file_names[num]);
	sprite.setTexture(texture);
	sprite.setScale(0.27f, 0.43f);
	spawn();
	

}
void Cactus::update() {
	
	sf::Vector2f speed = sf::Vector2f(-8.f, 0.f);
	sprite.move(speed);

	if (sprite.getPosition().x <= -WINDOW_WIDTH) {

		sf::FloatRect g_bound = sprite.getGlobalBounds();
		float line = rand() % (static_cast<size_t>(WINDOW_WIDTH) -
			static_cast<size_t>(g_bound.width));



		sprite.setPosition(WINDOW_WIDTH+line, WINDOW_HEIGHT / 1.3 - g_bound.height);
		spawn();
	}
	spawn();
}
void Cactus::draw(sf::RenderWindow& window) { window.draw(sprite); }
void Cactus::spawn(){
	sf::FloatRect g_bound = sprite.getGlobalBounds();
	float x = WINDOW_WIDTH + rand() % (static_cast<size_t>(WINDOW_WIDTH) -
		static_cast<size_t>(g_bound.width));
	float y = WINDOW_HEIGHT / 1.3 - 100;
	sprite.setPosition(x, y);
	
}
sf::Sprite Cactus::getSprite() { return sprite; }
sf::FloatRect Cactus::getHitBox() { return sprite.getGlobalBounds(); }
sf::Vector2f Cactus::getPosition() { return sprite.getPosition(); }
