#include "ResourceFactory.hpp"

std::shared_ptr<Resource> ResourceFactory::create(enum ResourceFactory::resourceType type,
                                                  const uri_builder &uri)
{
    std::shared_ptr<Resource> result;

    switch(type) {
    case resourceType::Catalog:
        result = std::shared_ptr<Catalog>(new Catalog(uri));
        break;
    case resourceType::Customer:
        result = std::shared_ptr<Customer>(new Customer(uri));
        break;
    case resourceType::Last:
        // TODO: Error handling!!!
        break;
    }

    return result;
}