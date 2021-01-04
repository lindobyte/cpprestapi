#include "Webservice.hpp"
#include "resource/ResourceFactory.hpp"

Webservice::Webservice(std::string &address,
                       std::string &port)
    : address(address)
{
    address.append(port);
}

void Webservice::initialize()
{

    /*for(int i = 0; i != ResourceFactory.resourceType.Last; i++) {

    }*/
}

void Webservice::shutdown()
{
}

