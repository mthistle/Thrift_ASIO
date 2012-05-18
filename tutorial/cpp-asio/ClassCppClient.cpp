/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements. See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

#include <async/TAsioAsync.h>
#include <protocol/TBinaryProtocol.h>

#include "Calculator.h"

using namespace apache::thrift;

class Foo {
public:
	Foo() {};
	void connect() {
		try
	  	{
		    boost::asio::io_service io_service;

		    boost::shared_ptr<protocol::TProtocolFactory> protocolFactory(new protocol::TBinaryProtocolFactory());
    
		    boost::shared_ptr<async::TAsioClient> client (
								  new async::TAsioClient(
											 io_service,
											 protocolFactory,
											 protocolFactory));

		    client->connect("localhost", 9090, this->connected);

		    io_service.run(); // Will block

		    printf("Done, returning\n");
		  }
		  catch (std::exception& e)
		  {
		    std::cout << "Exception: " << e.what() << "\n";
		  }
	}
	
	void pingCallback() {
  		printf("ping()\n");
	}

	void pingErrback(const tutorial::Calculator_ping_result& result) {
	  printf("Exception caught\n");
	}

	void connected(boost::shared_ptr<tutorial::CalculatorAsyncClient> client) {
	  std::cout << "connected!!!" << std::endl;

	  // Will return immediately
	  client->ping().setCallback(pingCallback).setErrback(pingErrback);
	}
};

int main(int argc, char* argv[])
{
	Foo foo;
	foo.connect();
	
	return 0;
}
