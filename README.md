Thrift_ASIO
===========

Thrift with ASIO for C++ including some tweaks.

Additions:
 - TAsioServer extended with port() method and paramter allowing you to create a server with a port of 0 to receive a system assigned port and then retrieve that port later.
 - Added tutorial/cpp-asio/ClassCppClient.cpp which demonstrates using connected callback in a class environment.