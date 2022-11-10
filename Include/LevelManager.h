#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include <list>
#include <SFML/Graphics.hpp>

#include "DrawMap.h"
#include "Game.h"
#include "RaceCar.h"
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

    RaceCar m_race;
    DrawMap draw;

    sf::Vector2f m_CarDirection;
    float RaceCarX = 350; 
    float RaceCarY = 350;
    
    bool m_isPaused; 
 
    std::shared_ptr<Context> m_context;

    public:
    LevelManager(std::shared_ptr<Context> &context);
    ~LevelManager();

    void ThrustHandler();
    void SplashScreen();

    void Draw() override;
    void Init() override;
    void ProcessInput() override;
    void Update(sf::Time deltaTime) override;

    void Pause() override;
    void Start() override;

};

#endif 