#ifndef SERVERENTITYMANAGER_HPP
#define SERVERENTITYMANAGER_HPP

#include <iostream>

#include <SFML/Network.hpp>

#include "../EntityManager.hpp"

#include "../test/SpriteComponent.hpp"
#include "../test/RenderSystem.hpp"

class ServerEntityManager : public EntityManager
{
    public:
        ServerEntityManager();

        void sendPacket(sf::Packet& packet);
        void handlePackets();
        void handlePacket(sf::Packet& packet);

    private:
        sf::TcpListener mListener;
        sf::TcpSocket mSocket;
        bool mConnected;
};

#endif // SERVERENTITYMANAGER_HPP
