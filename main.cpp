/* Ludmyla Almeida
   Comp IV
   January 27, 2020
*/

#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(900, 600), "SUPER MARIO BROS. 1985");

    bool buttonClicked = false;

    sf::Texture start_image;
    if (!start_image.loadFromFile("sprite.png")) {
        cout << "error loading image\n";
    }

    sf::Sprite start;
    start.setTexture(start_image);

    sf::Texture bg_image;
    if (!bg_image.loadFromFile("main_bg.png")) {
        cout << "error loading image\n";
    }

    sf::Sprite background;

    sf::Texture mario_img;
    if (!mario_img.loadFromFile("mario.png")) {
        cout << "error loading image\n";
    }

    sf::Sprite mario;
    mario.setTexture(mario_img);
    mario.setPosition(200.0f, 460.0f);

    sf::Texture mush_img;
    if(mush_img.loadFromFile("mushroom.png")){
        cout << "error loading mush image" << endl;
    }

    sf::Sprite mush;
    mush.setPosition(300.0f, 225.0f);
    // create button image
    sf::Texture btn_image;
    if (!btn_image.loadFromFile("button.png")) {
        cout << "error loading image\n";
    }
    sf::Sprite btn;
    btn.setTexture(btn_image);
    //set position of button in the screen
    btn.setPosition(300.0f, 330.0f);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {

                // get mouse position
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                // get button position
                sf::Vector2f translatedPos = window.mapPixelToCoords(mousePos);

                // if mouse position contains button position
                if (btn.getGlobalBounds().contains(translatedPos)) {
                    btn.setColor(sf::Color::Transparent);
                    start.setColor(sf::Color::Transparent);
                    mush.setTexture(mush_img);
                    background.setTexture(bg_image);

                    buttonClicked = true;
                }
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    if(mario.getPosition().y == 460.0f){
                        mario.move(0,-50.f);
                    } else {
                        mario.move(0, 50.f );
                    }

                } if (event.key.code == sf::Keyboard::Down) {
                    mario.move(0,0);
                } if (event.key.code == sf::Keyboard::Right) {
                    if(mario.getPosition().x < 700){
                        mario.move(30.0f,0);
                    }

                }
                if (event.key.code == sf::Keyboard::Left) {
                    if(mario.getPosition().x > 0){
                        mario.move(-30.0f,0);
                    }

                }
            }
        }

        auto new_pos = mush.getPosition();
        if(new_pos.x > 500.f){
            new_pos.x = 300.f;
        } else {
            new_pos.x += .30f;
        }

        mush.setPosition(new_pos);


        window.clear();
        window.draw(start);
        window.draw(background);
        window.draw(btn);
        window.draw(mario);
        window.draw(mush);
        window.display();
    }

    return 0;
}