#ifndef SES_COMPONENT_HPP
#define SES_COMPONENT_HPP

#include <memory>

namespace ses
{

class Component
{
    public:
        Component();
        virtual ~Component();

        typedef std::unique_ptr<Component> Ptr;
};

} // namespace ses

#endif // SES_COMPONENT_HPP
