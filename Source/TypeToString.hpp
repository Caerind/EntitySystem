#ifndef SES_TYPETOSTRING_HPP_INCLUDED
#define SES_TYPETOSTRING_HPP_INCLUDED

// Code found here : http://www.cplusplus.com/forum/beginner/100627/
// Thanks to http://www.cplusplus.com/user/JLBorges/ for this

#include <iostream>
#include <string>
#include <typeinfo>

#ifdef __GNUG__ // GCC

#include <cxxabi.h>
#include <cstdlib>

namespace ses
{

static std::string readable_name( const char* mangled_name )
{
    int status ;
    char* temp = __cxxabiv1::__cxa_demangle( mangled_name, nullptr, nullptr, &status ) ;
    if(temp)
    {
        std::string result(temp) ;
        std::free(temp) ;
        return result ;
    }
    else return mangled_name ;
}

} // namespace ses

#else // not GCC

namespace ses
{

std::string readable_name( const char* mangled_name ) { return mangled_name ; }

} // namespace ses

#endif // __GNUG__

namespace ses
{

template < typename T > std::string type_to_string()
{ return readable_name( typeid(T).name() ) ; }

template < typename T > std::string type_to_string( const T& obj )
{ return readable_name( typeid(obj).name() ) ; }

} // namespace ses

#endif // SES_TYPETOSTRING_HPP_INCLUDED
