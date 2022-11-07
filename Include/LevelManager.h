#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include <list>
#include <SFML/Graphics.hpp>


#include "Game.h"
#include "SoundManager.h"
#include "TextManager.h"
#include "State.h"



class LevelManager : public Engine::State
{
    private:

    sf::Font font;
    sf::Sprite swag;
    sf::Texture swaglogo;

    SoundManager sound;

    sf::Texture t1;
    sf::Texture t2;
    sf::Texture t3;
    sf::Texture t4;

    sf::RenderWindow play; 
 
    std::shared_ptr<Context> m_context;

    public:
    LevelManager(std::shared_ptr<Context> &context);
    ~LevelManager();

    void ThrustHandler();
    void SplashScreen();

    void Draw() override;
    void Init() override;
    void ProcessInput() override;
    void Update() override;

    void Pause() override;
    void Start() override;

};

#endif 