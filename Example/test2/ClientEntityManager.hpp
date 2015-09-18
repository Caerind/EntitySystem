#ifndef CLIENTENTITYMANAGER_HPP
#define CLIENTENTITYMANAGER_HPP

#include <iostream>

#include <SFML/Network.hpp>

#include "../EntityManager.hpp"

#include "../test/SpriteComponent.hpp"
#include "../test/RenderSystem.hpp"

class ClientEntityManager : public EntityManager
{
    public:
        ClientEntityManager();

        void sendPacket(sf::Packet& packet);
        void handlePackets();
        void handlePacket(sf::Packet& packet);

    private:
        sf::TcpSocket mSocket;
        bool mConnected;
};

#endif // CLIENTENTITYMANAGER_HPP
