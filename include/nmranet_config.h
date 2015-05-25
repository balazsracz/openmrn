/** \copyright
 * Copyright (c) 2013, Stuart W Baker
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
 * \file nmranet_config.h
 * This file defines configuration options specific to NMRAnet.  These options
 * are typcially applied in the same file as @ref appl_main (main.c/main.cxx).
 * For example:
 *
 * @code
 * #include "nmranet_config.h"
 *
 * const char *nmranet_manufacturer = "Stuart W. Baker";
 * const char *nmranet_hardware_rev = "N/A";
 * const char *nmranet_software_rev = "0.1";
 * const size_t ALIAS_POOL_SIZE = 2;
 * const size_t DOWNSTREAM_ALIAS_CACHE_SIZE = 2;
 * const size_t UPSTREAM_ALIAS_CACHE_SIZE = 2;
 * @endcode
 *
 * @author Stuart W. Baker
 * @date 9 February 2013
 */

#ifndef _nmranet_config_h_
#define _nmranet_config_h_

#include <stdlib.h>

#include "utils/constants.hxx"

/** Defines the default bit-rate for CAN devices. */
DECLARE_CONST(nmranet_can_bitrate);
/** Defines the default bit-rate for the second CAN device (aka /dev/can1). */
DECLARE_CONST(can2_bitrate);

/** The priority of main thread. Used in FreeRTOS. 0 = default priority
 * (middle). Larger number gets the CPU over smaller number. The limit is
 * configMAX_PRIORITIES from FreeRTOSConfig.h */
DECLARE_CONST(main_thread_priority);
/** Stack size of main thread. Used in FreeRTOS. */
DECLARE_CONST(main_thread_stack_size);

/** Prescaler for performing select calls.
 *
 * Executors will run this many Executables (if there is anything scheduled)
 * before two calls to select. This helps in reducing the overhead of the
 * select calls.
 */
DECLARE_CONST(executor_select_prescaler);

/** Max select sleep time (in msec).
 *
 * Executors will sleep at most this much time before checking that something
 * got scheduled on the executor.
 */
DECLARE_CONST(executor_max_sleep_msec);

/** Number of packets to queue in the CANbus device driver for send. Each packet
 * takes 16 bytes of RAM. */
DECLARE_CONST(can_tx_buffer_size);
/** Number of packets to queue in the CANbus device driver for receive. Each
 * packet takes 16 bytes of RAM. */
DECLARE_CONST(can_rx_buffer_size);

/** Number of bytes to queue in the serial driver for send. */
DECLARE_CONST(serial_tx_buffer_size);
/** Number of bytes to queue in the serial driver for receive. */
DECLARE_CONST(serial_rx_buffer_size);

/** Number of entries in the remote alias cache */
DECLARE_CONST(remote_alias_cache_size);

/** Number of entries in the local alias cache */
DECLARE_CONST(local_alias_cache_size);

/** Maximum number of local nodes */
DECLARE_CONST(local_nodes_count);

/** Number of datagram registry entries. This is how many datagram handlers can
 * be registered (e.g. memory config protocol is one). */
DECLARE_CONST(num_datagram_registry_entries);

/** Number of datagram clients. This is how many datagram send operations can
 * happen concurrently. */
DECLARE_CONST(num_datagram_clients);

/** Maximum number of memory spaces that can be registered for the MemoryConfig
 * datagram handler. */
DECLARE_CONST(num_memory_spaces);

/** Set to CONSTANT_TRUE if you want to export an "all memory" memory space
 * from the SimpleStack. */
DECLARE_CONST(enable_all_memory_space);

/** Set to CONSTANT_TRUE if you want the nodes to send out producer / consumer
 * identified messages at boot time. This is required by the OpenLCB
 * standard. */
DECLARE_CONST(node_init_identify);


#endif /* _nmranet_config_h_ */
