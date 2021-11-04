#include "ClientHandler.hpp"
#include "CGIHandler.hpp"

// Constructor and destructor
ClientHandler::ClientHandler(int client_fd) : _fd(client_fd), _cgi(NULL)
{
}

ClientHandler::~ClientHandler()
{
}

// Operator overload
bool ClientHandler::operator==(ClientHandler const& rhs) const
{
    return (_fd == rhs.fd());
}

bool ClientHandler::operator!=(ClientHandler const& rhs) const
{
    return !(*this == rhs);
}

// Accessors
int ClientHandler::fd() const
{
    return (_fd);
}

std::vector<Request>& ClientHandler::requests()
{
    return (_requests);
}

std::vector<FileHandler>& ClientHandler::files()
{
    return (_files);
}

ClientHandler::Response& ClientHandler::response()
{
    return (_response);
}

CGIHandler* ClientHandler::cgi()
{
    return (_cgi);
}

void ClientHandler::set_cgi(CGIHandler* cgi)
{
    _cgi = cgi;
}
