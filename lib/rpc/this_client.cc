#include "rpc/this_client.h"

namespace rpc {

  this_client_t &this_client() {
    static thread_local this_client_t instance;
    return instance;
  }

  void this_client_t::clear() {
    address_.clear();
    port_ = 0;
    is_v4_ = false;
    is_v6_ = false;
  }

  void this_client_t::set_address(const std::string &address) { address_ = address; }

  void this_client_t::set_port(const int &port) { port_ = port; }

  void this_client_t::set_is_v4(const bool &is_v4) { is_v4_ = is_v4; }

  void this_client_t::set_is_v6(const bool &is_v6) { is_v6_ = is_v6; }

} // namespace rpc
