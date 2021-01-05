#include "Webservice.hpp"
#include "resource/ResourceFactory.hpp"

Webservice::Webservice(std::string &address,
                       std::string &port)
    : address(address)
{
    this->address.append(port);
}

void Webservice::initialize()
{
    uri_builder uri(address);

    for(int i = 0; i != (int)ResourceFactory::resourceType::Last; i++) {
        std::shared_ptr<Resource> resource = ResourceFactory::create(
            static_cast<ResourceFactory::resourceType>(i), uri);

        resource->open().wait();
        resourceList.push_back(resource);
    }
}

void Webservice::shutdown()
{
    for(std::shared_ptr<Resource> resource : resourceList) {
        resource->close().wait();
    }
}

