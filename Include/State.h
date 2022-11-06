#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>

namespace Engine
{
    class State
    {
        public:
           State(){};
           virtual ~State(){};

           virtual void Init() = 0;
           virtual void ProcessInput() = 0;
           virtual void Update() = 0;
           virtual void Draw() = 0;

           virtual void Pause(){};
           virtual void Start(){};
    };

}

#endif