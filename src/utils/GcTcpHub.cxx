/** \copyright
 * Copyright (c) 2014, Balazs Racz
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are  permitted provided that the following conditions are met:
 *
 *  - Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 *  - Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \file GcTcpHub.cxx
 * A component that starts a gridconnect-protocol HUB listening on a TCP port.
 *
 * @author Balazs Racz
 * @date 26 Apr 2014
 */

#include <memory>

#include "utils/GcTcpHub.hxx"

#include "utils/gc_pipe.hxx"
#include "utils/PipeFlow.hxx"
#include "utils/HubDevice.hxx"

struct ClientInfo : public Notifiable
{
    ClientInfo(CanHubFlow *can_hub, int fd)
        : gcHub_(can_hub->service())
        , bridge_(GCAdapterBase::CreateGridConnectAdapter(&gcHub_, can_hub,
                                                          false))
        , gcWrite_(&gcHub_, fd, this)
    {
    }
    virtual ~ClientInfo() {}

    HubFlow gcHub_;
    std::unique_ptr<GCAdapterBase> bridge_;
    FdHubPort<HubFlow> gcWrite_;

    void notify() OVERRIDE
    {
        /* We get this call when something is wrong with the FDs and we need to
         * close the connection. It is guaranteed that by the time we got this
         * call the device is unregistered from the char bridge, and the
         * service thread is ready to be stopped. */
        delete this;
    }
};

void GcTcpHub::OnNewConnection(int fd)
{
    new ClientInfo(canHub_, fd);
}

GcTcpHub::GcTcpHub(CanHubFlow *can_hub, int port)
    : canHub_(can_hub)
    , tcpListener_(port, std::bind(&GcTcpHub::OnNewConnection, this,
                                   std::placeholders::_1))
{
}

GcTcpHub::~GcTcpHub()
{
}
