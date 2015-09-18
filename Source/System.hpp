#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <memory>
#include <string>
#include <vector>

#include "ComponentFilter.hpp"
#include "Packet.hpp"

class EntityManager;

class System
{
    public:
        System(std::shared_ptr<EntityManager> entityManager);
        virtual ~System();

        typedef std::unique_ptr<System> Ptr;

        static std::string getId();

        virtual void handlePacket(sf::Packet& packet);
        void entityUpdate(sf::Int32 const& entityId);

        std::size_t entitiesCount() const;

    protected:
        std::shared_ptr<EntityManager> mEntityManager;
        std::vector<sf::Int32> mEntities;
        ComponentFilter mFilter;
};

#endif // SYSTEM_HPP
