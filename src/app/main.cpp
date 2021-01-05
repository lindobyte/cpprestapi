#include "../Webservice.hpp"

int main(int argc, char* argv[])
{
    utility::string_t port = U("8885");
    utility::string_t address = U("http://localhost:");
    Webservice ws(address, port);

    ws.initialize();

    std::cout << "Press ENTER to exit." << std::endl;
    std::string line;
    std::getline(std::cin, line);

    ws.shutdown();

    return 0;
}