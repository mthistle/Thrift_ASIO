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

#ifndef _TASYNC_H_
#define _TASYNC_H_ 1

#include <boost/function.hpp>
#include <transport/TTransport.h>
#include <boost/shared_ptr.hpp>

namespace apache { namespace thrift { namespace async {

class TAsyncOutputTransport : public transport::TTransport {
  // Asynchronous transport.
  //
  // The asynchronousity gives us an interesting asymmetry. We are
  // free to write to an underlying socket at any time, but cannot
  // read from it in any way. This class is simply meant to be a
  // superclass of unidirectional nonblocking out transports,
  // disallowing the read method.

 public:
  virtual void write_virt(const uint8_t* /* buf */, uint32_t /* len */) = 0;
  virtual void flush() = 0;

  virtual uint32_t read_virt(uint8_t* /* buf */, uint32_t /* len */) {
    // This method should not be overridden!!
    throw transport::TTransportException(transport::TTransportException::NOT_OPEN, "Asynchronous transports cannot read.");
  }

  virtual ~TAsyncOutputTransport() {}
};

// More stuff should go here, so far not enough generalization has been done

} } }

#endif
