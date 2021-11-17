#include <iostream>
#include <crownguard.h>
#include <stdexcept>
#include <config.h>

/*
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 */
int main()
{
  std::cout << cg::header << std::endl;
  try
  {
    asio::io_context io_context{};
    cg::TCP_Server server{io_context};
    io_context.run();
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }
}
