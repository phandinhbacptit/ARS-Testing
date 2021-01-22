/*!
 * \file
 * \author Miroslav Kubik <mkubik2@retia.cz>
 * \brief Header file for \link rtime::TimeStamp \endlink.
 */
#ifndef RTIME_TIMESTAMP_H
#define RTIME_TIMESTAMP_H

#include "rtime_platform.h"
#include "rtime_datetime.h"
#include "rtime_duration.h"

#include <iomanip> // setw
#include <ostream>

namespace rtime
{

class Clock; // forward declaration

/*!
 * \brief Class for representing a moment in time.
 *
 * Both system and monotonic \link rtime::Clock \endlink can be used to retrieve
 * valid time stamps. The time stamps are expressed via seconds and nanoseconds
 * relative to the Unix epoch (January 1st 1970, 00:00:00 UTC) or initalization
 * of the monotonic clock, respectively. Note that you should not compare or
 * subtract time stamps of different types.
 */
class TimeStamp
{
public:

    friend class Clock; // for accessing the private constructors

    /*!
     * A constructor of zero time stamp. Use \link rtime::Clock::now
     * \endlink to retrieve the current time stamp.
     */
    TimeStamp();

    /*!
     * Retrieves the total whole seconds, since the epoch or initialization
     * of monotonic clock.
     * \return The seconds.
     */
    time_t getSeconds() const;

    /*!
     * Retrieves nanoseconds after the whole second.
     * \return The nanoseconds, in <0; 1000000000).
     */
    int getNanoseconds() const;

    /*!
     * Tests whether this is a zero time stamp.
     * \return \c True if this is a zero time stamp, \c false otherwise.
     */
    bool isZero() const;

    /*!
     * Invalidates the time stamp.
     * \see isZero
     */
    void reset();

    // arithmetic operators - self-explanatory

    TimeStamp operator+(const Duration &duration) const;
    TimeStamp &operator+=(const Duration &duration);
    TimeStamp operator-(const Duration &duration) const;
    TimeStamp &operator-=(const Duration &duration);

    Duration operator-(const TimeStamp &stamp) const;

    // relational operators - self-explanatory

    bool operator>(const TimeStamp &stamp) const;
    bool operator>=(const TimeStamp &stamp) const;
    bool operator<(const TimeStamp &stamp) const;
    bool operator<=(const TimeStamp &stamp) const;
    bool operator==(const TimeStamp &stamp) const;
    bool operator!=(const TimeStamp &stamp) const;

    /*!
     * Converts the time stamp to date time, usually used for printing
     * the calendar time. Note that the date time conversion of monotonic
     * clock time stamps does not make much sense - in that case using
     * \link rtime::TimeStamp::asDuration \endlink should be considered instead.
     * \param local ... \c true for local time, \c false for UTC time
     * \return The date time.
     */
    DateTime asDateTime(bool local = true) const;

    /*!
     * Converts the time stamp to duration since the epoch or initialization
     * of monotonic clock.
     * \return The duration.
     */
    Duration asDuration() const;

    /*!
     * Converts the time stamp to duration in seconds since the epoch or
     * initialization of monotonic clock.
     * \return The duration in seconds.
     */
    double asDouble() const;

    friend std::ostream& operator<<(std::ostream &stream, const TimeStamp &timeStamp);

    /*!
     * A constructor. Parameters are relative to either the epoch or
     * initialization of the monotonic clock. May be used when converting
     * from various native structs.
     * \param seconds ... the seconds
     * \param nanoseconds ... the nanosecond part
     */
    TimeStamp(time_t seconds, int nanoseconds);

private:

    /*!
     * A constructor.
     * \param timeValue ... the time value to use
     */
    TimeStamp(const TimeValue &timeValue);

    TimeValue timeValue;
};

/*!
 * Standard operator for output to a stream. It writes the time stamp as
 * duration since the epoch or initialization of the monotonic clock. The value
 * is printed in seconds, with the fraction part zero-padded to 9 digits.
 * \param stream ... the stream to write to
 * \param timeStamp ... the time stamp to output
 * \return A reference to the stream.
 */
std::ostream& operator<<(std::ostream &stream, const TimeStamp &timeStamp);


// definitions

inline
TimeStamp::TimeStamp()
{
}

inline
time_t TimeStamp::getSeconds() const
{
	return timeValue.getSeconds();
}

inline
int TimeStamp::getNanoseconds() const
{
	return timeValue.getNanoseconds();
}

inline
bool TimeStamp::isZero() const
{
    return timeValue.isZero();
}

inline
void TimeStamp::reset()
{
    timeValue.set(0, 0);
}

inline
TimeStamp TimeStamp::operator+(const Duration &duration) const
{
    return TimeStamp(timeValue + duration.timeValue);
}

inline
TimeStamp &TimeStamp::operator+=(const Duration &duration)
{
    timeValue += duration.timeValue;
    return *this;
}

inline
TimeStamp TimeStamp::operator-(const Duration &duration) const
{
    return TimeStamp(timeValue - duration.timeValue);
}

inline
TimeStamp &TimeStamp::operator-=(const Duration &duration)
{
    timeValue -= duration.timeValue;
    return *this;
}

inline
Duration TimeStamp::operator-(const TimeStamp &stamp) const
{
    return Duration(timeValue - stamp.timeValue);
}

inline
bool TimeStamp::operator>(const TimeStamp &stamp) const
{
    return timeValue > stamp.timeValue;
}

inline
bool TimeStamp::operator>=(const TimeStamp &stamp) const
{
    return timeValue >= stamp.timeValue;
}

inline
bool TimeStamp::operator<(const TimeStamp &stamp) const
{
    return timeValue < stamp.timeValue;
}

inline
bool TimeStamp::operator<=(const TimeStamp &stamp) const
{
    return timeValue <= stamp.timeValue;
}

inline
bool TimeStamp::operator==(const TimeStamp &stamp) const
{
    return timeValue == stamp.timeValue;
}

inline
bool TimeStamp::operator!=(const TimeStamp &stamp) const
{
    return timeValue != stamp.timeValue;
}

inline
double TimeStamp::asDouble() const
{
    return timeValue.asDouble();
}

inline
Duration TimeStamp::asDuration() const
{
     return Duration(timeValue);
}

inline
TimeStamp::TimeStamp(time_t seconds, int nanoseconds) :
    timeValue(seconds, nanoseconds)
{
}

inline
TimeStamp::TimeStamp(const TimeValue &timeValue) :
    timeValue(timeValue)
{
}

inline
std::ostream& operator<<(std::ostream &stream, const TimeStamp &value)
{
    DateTime dateTime(value.asDateTime());
    char fill = stream.fill();
    stream.fill('0');
    stream << std::setw(2) << dateTime.getHour() << ':'
           << std::setw(2) << dateTime.getMinute() << ':'
	   << std::setw(2) << dateTime.getSecond() << '.'
	   << std::setw(3) << dateTime.getMilliseconds();
    stream.fill(fill);
    return stream;
}

} // end namespace rtime

#endif /* RTIME_TIMESTAMP_H */
