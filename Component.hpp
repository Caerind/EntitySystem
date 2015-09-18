#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <memory>
#include <string>

class Component
{
    public:
        Component();
        virtual ~Component();

        typedef std::unique_ptr<Component> Ptr;

        static std::string getId();
};

#endif // COMPONENT_HPP
