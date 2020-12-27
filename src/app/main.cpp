#include "../resource/customer/Customer.hpp"
#include "../resource/catalog/Catalog.hpp"

std::unique_ptr<Customer> g_httpDealer1;
std::unique_ptr<Catalog> g_httpDealer2;

void on_initialize(const string_t& address)
{
    // Build our listener's URI from the configured address and the hard-coded path "blackjack/dealer"
    uri_builder uri(address);

    /* customer */
    g_httpDealer1 = std::unique_ptr<Customer>(new Customer(uri));
    g_httpDealer1->open().wait();

    /* catalog */
    g_httpDealer2 = std::unique_ptr<Catalog>(new Catalog(uri));
    g_httpDealer2->open().wait();

    return;
}

void on_shutdown()
{
    g_httpDealer1->close().wait();
    g_httpDealer2->close().wait();
    return;
}

int main(int argc, char* argv[])
{
#if 0
    std::cout << "Hello World!\n";

    return 0;
#else
    utility::string_t port = U("34568");
    if (argc == 2)
    {
        port = argv[1];
    }

    utility::string_t address = U("http://localhost:");
    address.append(port);

    on_initialize(address);
    std::cout << "Press ENTER to exit." << std::endl;

    std::string line;
    std::getline(std::cin, line);

    on_shutdown();
    return 0;
#endif
}