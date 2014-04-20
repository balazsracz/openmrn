/** \copyright
 * Copyright (c) 2014, Balazs Racz
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
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
 * \file NMRAnetEndianHelper.hxx
 *
 * Helper functions for dealing with network byte order and NMRAnet identifiers.
 *
 * @author Balazs Racz
 * @date 6 Mar 2014
 */

#ifndef _NMRAnetEndianHelper_hxx_
#define _NMRAnetEndianHelper_hxx_

#include "endian.h"
#include "nmranet/NMRAnetIf.hxx"

namespace NMRAnet {

/** Takes six bytes (big-endian) from *data, and returns the node ID they
 * represent. */
NodeID NetworkToNodeID(const uint8_t* data) {
    uint64_t ret = 0;
    memcpy(&ret, data, 6);
    return be64toh(ret);
}

/** Takes a node id from @param id, and copies 6 bytes network-endian into
 * *dst. */
void NodeIDToNetwork(const NodeID id, uint8_t* dst) {
    uint64_t be_id = htobe64(id);
    memcpy(dst, &be_id, 6);
}

/** Takes 8 bytes (big-endian) from *data, and returns the event id they
 * represent. */
uint64_t NetworkToEventID(const uint8_t* data) {
    uint64_t ret = 0;
    memcpy(&ret, data, 8);
    return be64toh(ret);
}

/** Takes an event id from id, and copies it network-endian into *data. */
void EventIDToNetwork(const uint64_t event_id, uint8_t* dst) {
    uint64_t be_id = htobe64(id);
    memcpy(dst, &be_id, 8);
}

}  // namespace NRMAnet

#endif // _NMRAnetEndianHelper_hxx_
