#ifndef MYENTITYMANAGER_HPP
#define MYENTITYMANAGER_HPP

#include "../EntityManager.hpp"
#include "RenderSystem.hpp"
#include "SpriteComponent.hpp"
#include "RectangleComponent.hpp"

class MyEntityManager : public EntityManager
{
    public:
        MyEntityManager();

        void handlePacket(sf::Packet& packet);
};

#endif // MYENTITYMANAGER_HPP
