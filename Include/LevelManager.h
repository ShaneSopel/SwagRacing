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

    sf::Sprite back1;
    sf::Sprite back2;
    sf::Texture backg;
    sf::Sprite back;
    sf::View View2;

    float viewOffsetY = 0;
    float spriteOffsetY = 0;
    unsigned int textureHeight;

    SoundManager sound;

    TextManager oneuptext;
    TextManager HighScore;
    TextManager Lives;

    RaceCar m_race;

    sf::Vector2f m_CarDirection;
    float RaceCarX = 350; 
    float RaceCarY = 350;

    double BackgroundY1=0;
    double BackgroundY2=-600;

    bool m_isPaused; 
 
    std::shared_ptr<Context> m_context;

    public:
    LevelManager(std::shared_ptr<Context> &context);
    ~LevelManager();

    void ThrustHandler();
    void SplashScreen();
    void ScoreHandler();

    void Draw() override;
    void Init() override;
    void ProcessInput() override;
    void Update(sf::Time deltaTime) override;

    void Pause() override;
    void Start() override;

};

#endif 