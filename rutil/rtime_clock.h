/*!
 * \file
 * \author Miroslav Kubik <mkubik2@retia.cz>
 * \brief Header file for \link rtime::Clock \endlink class.
 */
#ifndef RTIME_CLOCK_H
#define RTIME_CLOCK_H

#include "rtime_constants.h"
#include "rtime_duration.h"
#include "rtime_platform.h"
#include "rtime_timestamp.h"

#if RTIME_WINDOWS
    #include <sys/time.h> // gettimeofday
    #include <windows.h> // QueryPerformanceCounter,...
#endif

namespace rtime
{

enum ClockType
{
    CtSystem = 0,
    CtMonotonic
};

typedef enum ClockType ClockType;


/*!
 * \brief Clocks are objects whose purpose is creating time stamps.
 *
 * The system clock may be changed by the end-user anytime, changes according
 * arbitrary DST rules, etc. The monotonic clock is guaranteed to flow
 * continuously forward.
 */
class Clock
{
    public:

    Clock(ClockType type = CtSystem);

    ClockType getType() const;

    TimeStamp now() const;

    private:

#if RTIME_WINDOWS
    LARGE_INTEGER counterFrequency;

     /*!
     * Converts native high-precision representation of time to a corresponding
     * time value.
     * \param counter ... the performance counter value
     * \return The time value.
     */
    TimeValue toTimeValue(LARGE_INTEGER counter) const
    {
        if (counterFrequency.QuadPart != 0)
        {
            time_t seconds = counter.QuadPart / counterFrequency.QuadPart;
            int nanoseconds = (int)((double) (counter.QuadPart
                    % counterFrequency.QuadPart)
                    * (double) Constants::SEC_TO_NANO
                    / counterFrequency.QuadPart);
            return TimeValue(seconds, nanoseconds);
        }
        else
        {
            return TimeValue();
        }
    }
#else
    /*!
     * Converts native high-precision representation of time to a corresponding
     * time value.
     * \param timeSpec ... the timespec struct, e.g. retrieved via clock_gettime
     * \return The time value.
     */
    TimeValue toTimeValue(const struct timespec &timeSpec) const
    {
        return TimeValue(timeSpec.tv_sec, timeSpec.tv_nsec);
    }
#endif

    Duration monotonicOffset;
    ClockType type;
};

inline
Clock::Clock(ClockType type) : type(type)
{
    if (type==CtMonotonic)
    {
#if RTIME_WINDOWS
        LARGE_INTEGER counterStart;
        QueryPerformanceFrequency(&counterFrequency);
        QueryPerformanceCounter(&counterStart);
        monotonicOffset
            = Duration(toTimeValue(counterStart));
#else
        struct timespec timeSpec;
        int retVal = clock_gettime(CLOCK_MONOTONIC, &timeSpec);
        if (retVal == 0)
        {
            monotonicOffset = Duration(toTimeValue(timeSpec));
        }
#endif
    }
}

inline
ClockType Clock::getType() const { return type; }

inline
TimeStamp Clock::now() const
{
    TimeStamp timeStamp;
    switch (type)
    {
        case CtSystem:
        {
#if RTIME_WINDOWS
            struct timeval timeVal;
            gettimeofday(&timeVal, NULL);
            timeStamp.timeValue.set(timeVal.tv_sec, timeVal.tv_usec * Constants::MICRO_TO_NANO);
#else
            struct timespec timeSpec;
            int retVal = clock_gettime(CLOCK_REALTIME, &timeSpec);
            if (retVal == 0)
            {
                timeStamp.timeValue.set(timeSpec.tv_sec, timeSpec.tv_nsec);
            }
#endif
            break;
        }
        case CtMonotonic:
        {
#if RTIME_WINDOWS
            if (counterFrequency.QuadPart != 0)
            {
                LARGE_INTEGER counterNow;
                QueryPerformanceCounter(&counterNow);
                timeStamp = TimeStamp(toTimeValue(counterNow))
                    - monotonicOffset;
            }
#else
            struct timespec timeSpec;
            int retVal = clock_gettime(CLOCK_MONOTONIC, &timeSpec);
            if (retVal == 0)
            {
                timeStamp = TimeStamp(toTimeValue(timeSpec))
                    - monotonicOffset;
            }
#endif
            break;
        }
    }
    return timeStamp;
}

} // end namespace rtime

#endif /* RTIME_CLOCK_H */
