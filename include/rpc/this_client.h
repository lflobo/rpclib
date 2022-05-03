#pragma once

#ifndef THIS_CLIENT_H_HTS95N7G
#define THIS_CLIENT_H_HTS95N7G

#include "rpc/config.h"
#include <atomic>
#include <string>

namespace rpc {

  namespace detail {
    class server_session;
  }

  //! \brief Encapsulates information about the remote endpoint obtained
  //! from the current socket.
  class this_client_t {
  public:
    //! \brief Returns the ip address of the client.
    std::string address() const { return address_; };

    //! \brief Returns the ip address of the client.
    int port() const { return port_; };

    //! \brief Wether the address is v4
    bool is_v4() const { return is_v4_; }

    //! \brief Wether the address is v6
    bool is_v6() const { return is_v6_; }

    friend class rpc::detail::server_session;

  private:
    void clear();

    void set_address(const std::string &address);
    void set_port(const int &port);
    void set_is_v4(const bool &is_v4);
    void set_is_v6(const bool &is_v5);

    std::string address_;
    int port_{0};
    bool is_v4_{false};
    bool is_v6_{false};
  };

  //! \brief A thread-local object that can be used to obtain the remote endpoint
  //! information.
  //! \note Accessing this object outside of handlers while a server is
  //! running is potentially unsafe.
  this_client_t &this_client();

} // namespace rpc

#endif /* end of include guard: THIS_CLIENT_H_HTS95N7G */
