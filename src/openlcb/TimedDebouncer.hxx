/** \copyright
 * Copyright (c) 2024, Balazs Racz
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
 * \file TimedDebouncer.hxx
 * A debouncer that adds time-based delays to state transitions.
 *
 * @author Balazs Racz
 * @date 4 May 2024
 */

#ifndef _OPENLCB_TIMEDDEBOUNCER_HXX_
#define _OPENLCB_TIMEDDEBOUNCER_HXX_

#include "utils/Debouncer.hxx"
#include "openlcb/RefreshLoop.hxx"

namespace openlcb {

/// A debouncer class that combines a CountingDebouncer with time delays for
/// turn-on and turn-off transitions.
class TimedDebouncer : public ::CountingDebouncer, public Polling
{
public:
    struct Options {
        /// Options for the underlying counting debouncer.
        ::CountingDebouncer::Options debouncer_opts;
        /// Time to wait (in ms) before transitioning from 0 to 1.
        uint32_t on_delay_ms;
        /// Time to wait (in ms) before transitioning from 1 to 0.
        uint32_t off_delay_ms;
        /// The refresh loop to attach to for timing.
        RefreshLoop* refresh_loop;
    };

    /// Constructor.
    /// @param opts configuration options.
    TimedDebouncer(const Options& opts)
        : ::CountingDebouncer(opts.debouncer_opts)
        , on_delay_ticks_(ms_to_ticks(opts.on_delay_ms))
        , off_delay_ticks_(ms_to_ticks(opts.off_delay_ms))
        , timer_(0)
        , pending_state_(0)
        , current_output_state_(0)
    {
        opts.refresh_loop->add_member(this);
    }

    /// Initializes the debouncer state.
    /// @param state initial state.
    void initialize(bool state)
    {
        ::CountingDebouncer::initialize(state);
        current_output_state_ = state ? 1 : 0;
        pending_state_ = current_output_state_;
        timer_ = 0;
    }

    /// Overrides the debouncer state.
    /// @param new_state desired state.
    void override(bool new_state)
    {
        initialize(new_state);
    }

    /// @return the current visible (reported) state.
    bool current_state()
    {
        return current_output_state_;
    }

    /// Updates the state based on a new measurement.
    /// @param measurement the raw input value.
    /// @return true if the reported state has changed.
    bool update_state(bool measurement)
    {
        bool cd_changed = ::CountingDebouncer::update_state(measurement);
        bool cd_state = ::CountingDebouncer::current_state();

        if (cd_changed)
        {
            if (cd_state == current_output_state_)
            {
                // We reverted back to the output state before the timer expired.
                timer_ = 0;
                pending_state_ = cd_state;
            }
            else
            {
                // New target state different from output. Start timer.
                pending_state_ = cd_state;
                timer_ = pending_state_ ? on_delay_ticks_ : off_delay_ticks_;
            }
        }

        // Check if we can apply the pending state.
        if (timer_ == 0 && pending_state_ != current_output_state_)
        {
            current_output_state_ = pending_state_;
            return true;
        }

        return false;
    }

    /// Periodic callback from RefreshLoop.
    void poll_33hz(WriteHelper*, Notifiable* done) override
    {
        if (timer_ > 0)
        {
            --timer_;
        }
        done->notify();
    }

private:
    /// Helper to convert milliseconds to ticks.
    static uint16_t ms_to_ticks(uint32_t ms)
    {
        return (ms + POLLING_INTERVAL_MS - 1) / POLLING_INTERVAL_MS;
    }

    uint16_t on_delay_ticks_;
    uint16_t off_delay_ticks_;
    uint16_t timer_;
    uint8_t pending_state_ : 1;
    uint8_t current_output_state_ : 1;
};

} // namespace openlcb

#endif // _OPENLCB_TIMEDDEBOUNCER_HXX_
