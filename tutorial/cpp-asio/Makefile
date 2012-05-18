#
# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements. See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership. The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License. You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied. See the License for the
# specific language governing permissions and limitations
# under the License.
#

BOOST_DIR = /usr/local/boost_1_49_0/boost/
THRIFT_DIR = /Users/mthistle/git/rialto/ossbuilds/include/thrift
LIB_DIR = /Users/mthistle/git/rialto/ossbuilds/lib/

DEFINES = -DHAVE_INTTYPES_H -DHAVE_NETINET_IN_H

GEN_SRC = ../gen-cpp/SharedService.cpp ../gen-cpp/shared_types.cpp ../gen-cpp/tutorial_types.cpp ../gen-cpp/Calculator.cpp

default: server client classClient

server: CppServer.cpp
	g++ -o CppServer -I${THRIFT_DIR} -I${BOOST_DIR}  -I../gen-cpp -L${LIB_DIR}  ${DEFINES}  CppServer.cpp ${GEN_SRC} -lthrift -lthriftasio -lboost_system

client: CppClient.cpp
	g++ -o CppClient -I${THRIFT_DIR} -I${BOOST_DIR}  -I../gen-cpp -L${LIB_DIR}  ${DEFINES}  CppClient.cpp ${GEN_SRC} -lthrift -lthriftasio -lboost_system

classClient: ClassCppClient.cpp
	/opt/local/bin/g++-mp-4.6 -o classClient -I${THRIFT_DIR} -I${BOOST_DIR}  -I../gen-cpp -L${LIB_DIR}  ${DEFINES}  ClassCppClient.cpp ${GEN_SRC} -lthrift -lthriftasio -lboost_system

clean:
	$(RM) -r CppClient CppServer classCppClient
