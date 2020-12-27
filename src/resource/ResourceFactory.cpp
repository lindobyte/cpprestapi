#include "ResourceFactory.hpp"

std::unique_ptr<Resource> ResourceFactory::create(enum ResourceFactory::resourceType type,
                                                  const uri_builder &uri)
{
    std::unique_ptr<Resource> result;

    switch(type) {
    case resourceType::Catalog:
        result = std::unique_ptr<Catalog>(new Catalog(uri));
        break;
    case resourceType::Customer:
        result = std::unique_ptr<Customer>(new Customer(uri));
        break;
    }

    return std::move(result);
}