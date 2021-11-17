#pragma once

#include <asio/include/asio.hpp>
#include <functional>
#include <iostream>
#include <memory>
#include <string_view>

namespace cg
{
    
class TCP_Connection : public std::enable_shared_from_this<TCP_Connection>
{
  public:
    using pointer = std::shared_ptr<TCP_Connection>;

    static pointer create(asio::io_context &io_context)
    {
        return pointer(new TCP_Connection(io_context));
    }

    asio::ip::tcp::socket &socket()
    {
        return socket_;
    }

    void start()
    {
        message_ = "Welcome to fcrownguard\n";

        asio::async_write(
            socket_, asio::buffer(message_),
            std::bind(&TCP_Connection::handle_write, shared_from_this(), std::placeholders::_1, std::placeholders::_2));
    }

  private:
    TCP_Connection(asio::io_context &io_context) : socket_(io_context)
    {
    }

    void handle_write(std::error_code const & /*error*/, size_t /*bytes_transferred*/)
    {
    }
    asio::ip::tcp::socket socket_;
    std::string_view message_;
};

class TCP_Server
{
  public:
    TCP_Server(asio::io_context &io_context)
        : io_context_(io_context), acceptor_(io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), 5567))
    {
        start_accept();
    }

  private:
    void start_accept()
    {
        TCP_Connection::pointer new_connection = TCP_Connection::create(io_context_);

        acceptor_.async_accept(new_connection->socket(),
                               std::bind(&TCP_Server::handle_accept, this, new_connection, std::placeholders::_1));
    }

    void handle_accept(TCP_Connection::pointer new_connection, std::error_code const &error)
    {
        char buf[255];
        if (!error)
        {
            new_connection->start();
        }

        start_accept();

        // asio::streambuf response;
        // size_t s = asio::read(new_connection->socket(), response, ec); // no
        // condition, so read till EOF

        std::error_code ec;

        size_t len = new_connection->socket().read_some(asio::buffer(buf, 255), ec);

        if (error == asio::error::eof)
        {
            new_connection->socket().close();
        }
        else if (error)
        {
            std::cerr << "Error" << std::endl;
        }

        std::cout.write(buf, len);
    }
    asio::io_context &io_context_;
    asio::ip::tcp::acceptor acceptor_;
};
} // namespace cg