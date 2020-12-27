#include "../Webservice.hpp"
#include "Resource.hpp"
#include "customer/Customer.hpp"
#include "catalog/Catalog.hpp"

class ResourceFactory {
public:
    enum class resourceType {
        Catalog,
        Customer
    };

    static std::unique_ptr<Resource> create(enum ResourceFactory::resourceType type,
                                            const uri_builder &uri);
};