#include "rpc/this_client.h"

namespace rpc {

this_client_t &this_client() {
    static thread_local this_client_t instance;
    return instance;
}

void this_client_t::clear() {
    address_ = "";
    port_ = 0;
}

void this_client_t::set_address(const std::string &address) { address_ = address; }

void this_client_t::set_port(const int &port) { port_ = port; }

} // namespace rpc
