/*!
 * \file
 * \author Miroslav Kubik <mkubik2@retia.cz>
 * \brief Header file for \link rtime::Duration \endlink.
 */
#ifndef RTIME_DURATION_H
#define RTIME_DURATION_H

#include "rtime_constants.h"
#include "rtime_timevalue.h"

#include <cmath> // floor, modf

namespace rtime
{

class Clock; // forward declaration

/*!
 * \brief Class for representing time intervals.
 *
 * The range is app. 68 years on the supported platforms. Overflows resulting
 * from operations are currently silently ignored.
 */
class Duration
{
public:
    friend class Clock; // to access the private constructors

    friend class TimeStamp;

    /*!
     * Creates a duration instance.
     * \param days ... the amount of days
     * \return The duration.
     */
    static Duration days(double days);

    /*!
     * Creates a duration instance.
     * \param hours ... the amount of hours
     * \return The duration.
     */
    static Duration hours(double hours);

    /*!
     * Creates a duration instance.
     * \param minutes ... the amount of minutes
     * \return The duration.
     */
    static Duration minutes(double minutes);

    /*!
     * Creates a duration instance.
     * \param seconds ... the amount of seconds
     * \return The duration.
     */
    static Duration seconds(double seconds);

    /*!
     * Creates a duration instance.
     * \param milliseconds ... the amount of milliseconds
     * \return The duration.
     */
    static Duration milliseconds(double milliseconds);

    /*!
     * Creates a duration instance.
     * \param microseconds ... the amount of microseconds
     * \return The duration.
     */
    static Duration microseconds(double microseconds);

    /*!
     * Creates a duration instance.
     * \param nanoseconds ... the amount of nanoseconds
     * \return The duration.
     */
    static Duration nanoseconds(double nanoseconds);

    /*!
     * A constructor for zero-length duration.
     */
    Duration();

    /*!
     * Tests for zero-length duration.
     * \return \c True if the interval is zero length, \c false otherwise.
     */
    bool isZero() const;

    /*!
     * Tests for negative duration. Typical test for results of timestamp
     * subtraction.
     * \return \c True if the duration is negative, \c false otherwise.
     */
    bool isNegative() const;

    /*!
     * Retrieves hours after the whole day.
     * \return The hours, in <0; 24).
     */
    int getHour() const;

    /*!
     * Retrieves minutes after the whole hour.
     * \return The minutes, in <0; 60).
     */
    int getMinute() const;

    /*!
     * Retrieves seconds after the whole minute.
     * \return The seconds, in <0; 60).
     */
    int getSecond() const;

    /*!
     * Retrieves milliseconds after the whole second.
     * \return The milliseconds, in <0; 1000).
     */
    int getMilliseconds() const;

    /*!
     * Retrieves microseconds after the whole second.
     * \return The microseconds, in <0; 1000000).
     */
    int getMicroseconds() const;

    /*!
     * Retrieves nanoseconds after the whole second.
     * \return The nanoseconds, in <0; 1000000000).
     */
    int getNanoseconds() const;

    /*!
     * Converts the duration to a double value.
     * \return The duration expressed in seconds.
     */
    double asDouble() const;

    /*!
     * Retrieves the total whole seconds.
     * \return The seconds, in <0;...).
     */
    time_t getSeconds() const;

    /*!
     * Retrieves the total whole days.
     * \return The days, in <0;...).
     */
    int getDays() const;

    // arithmetic operators - self-explanatory

    Duration operator+(const Duration &duration) const;
    Duration &operator+=(const Duration &duration);

    Duration operator-(const Duration &duration) const;
    Duration &operator-=(const Duration &duration);

    Duration operator*(double value) const;
    Duration operator/(double value) const;
    double operator/(const Duration &duration) const;
    Duration operator-() const;
    friend Duration operator*(double value, const Duration &duration);

    // relational operators - self-explanatory

    bool operator>(const Duration &duration) const;
    bool operator>=(const Duration &duration) const;
    bool operator<(const Duration &duration) const;
    bool operator<=(const Duration &duration) const;
    bool operator==(const Duration &duration) const;
    bool operator!=(const Duration &duration) const;

    friend std::ostream &operator<<(std::ostream &stream,
            const Duration &duration);

private:

    /*!
     * A constructor.
     * \param seconds ... the whole seconds
     * \param nanoseconds ... the nanosecond part
     */
    Duration(time_t seconds, int nanoseconds);

    /*!
     * A constructor.
     * \param timeValue ... time value to use for initialization
     */
    Duration(const TimeValue &timeValue);

    TimeValue timeValue;
};

/*!
 * Standard operator for output to a stream. It writes the duration in seconds,
 * with fraction part zero-padded to 9 digits.
 * \param stream ... the stream to write to
 * \param duration ... the duration to output
 * \return A reference to the stream.
 */
std::ostream &operator<<(std::ostream &stream, const Duration &duration);


// definitions

inline
Duration Duration::days(double days)
{
    return Duration::seconds(days * Constants::DAY_TO_SEC);
}

inline
Duration Duration::hours(double hours)
{
    return Duration::seconds(hours * Constants::HOUR_TO_SEC);
}

inline
Duration Duration::minutes(double minutes)
{
    return Duration::seconds(minutes * Constants::MIN_TO_SEC);
}

inline
Duration Duration::seconds(double seconds)
{
    double secs;
    int nanosecs = (int)(floor(modf(seconds, &secs) * Constants::SEC_TO_NANO));
    if (secs > std::numeric_limits<time_t>::max())
    {
        return Duration(TimeValue::max());
    }
    else if (secs <= std::numeric_limits<time_t>::min())
    {
        return Duration(TimeValue::min());
    }
    else
    {
        return Duration((time_t)secs, nanosecs);
    }
}

inline
Duration Duration::milliseconds(double milliseconds)
{
    return Duration::seconds(milliseconds / Constants::SEC_TO_MILLI);
}

inline
Duration Duration::microseconds(double microseconds)
{
    return Duration::seconds(microseconds / Constants::SEC_TO_MICRO);
}

inline
Duration Duration::nanoseconds(double nanoseconds)
{
    return Duration::seconds(nanoseconds / Constants::SEC_TO_NANO);
}

inline
Duration::Duration() :
    timeValue(0, 0)
{
}

inline
bool Duration::isZero() const
{
    return timeValue.isZero();
}

inline
bool Duration::isNegative() const
{
    return timeValue.isNegative();
}

inline
double Duration::asDouble() const
{
    return timeValue.asDouble();
}

inline
time_t Duration::getSeconds() const
{
    return timeValue.getSeconds();
}

inline
int Duration::getDays() const
{
    return timeValue.getSeconds() / Constants::DAY_TO_SEC;
}

inline
int Duration::getHour() const
{
    return timeValue.getSeconds() % Constants::DAY_TO_SEC
            / Constants::HOUR_TO_SEC;
}

inline
int Duration::getMinute() const
{
    return timeValue.getSeconds() % Constants::HOUR_TO_SEC
            / Constants::MIN_TO_SEC;
}

inline
int Duration::getSecond() const
{
    return timeValue.getSeconds() % Constants::MIN_TO_SEC;
}

inline
int Duration::getMilliseconds() const
{
    return timeValue.getNanoseconds() / Constants::MILLI_TO_NANO;
}

inline
int Duration::getMicroseconds() const
{
    return timeValue.getNanoseconds() / Constants::MICRO_TO_NANO;
}

inline
int Duration::getNanoseconds() const
{
    return timeValue.getNanoseconds();
}

inline
Duration Duration::operator+(const Duration &duration) const
{
    return Duration(timeValue + duration.timeValue);
}

inline
Duration &Duration::operator+=(const Duration &duration)
{
    timeValue += duration.timeValue;
    return *this;
}

inline
Duration Duration::operator-(const Duration &duration) const
{
    return Duration(timeValue - duration.timeValue);
}

inline
Duration &Duration::operator-=(const Duration &duration)
{
    timeValue -= duration.timeValue;
    return *this;
}

inline
Duration Duration::operator*(double value) const
{
    return Duration(timeValue * value);
}

inline
Duration Duration::operator/(double value) const
{
    return Duration(timeValue / value);
}

inline
double Duration::operator/(const Duration &duration) const
{
    return this->asDouble() / duration.asDouble();
}

inline
Duration Duration::operator-() const
{
    return Duration(-timeValue);
}

inline
Duration operator*(double value, const Duration &duration)
{
    return Duration(duration * value);
}

inline
bool Duration::operator>(const Duration &duration) const
{
    return timeValue > duration.timeValue;
}

inline
bool Duration::operator>=(const Duration &duration) const
{
    return timeValue >= duration.timeValue;
}

inline
bool Duration::operator<(const Duration &duration) const
{
    return timeValue < duration.timeValue;
}

inline
bool Duration::operator<=(const Duration &duration) const
{
    return timeValue <= duration.timeValue;
}

inline
bool Duration::operator==(const Duration &duration) const
{
    return timeValue == duration.timeValue;
}

inline
bool Duration::operator!=(const Duration &duration) const
{
    return timeValue != duration.timeValue;
}

inline
std::ostream &operator<<(std::ostream &stream, const Duration &duration)
{
    stream << duration.timeValue;
    return stream;
}

inline
Duration::Duration(time_t seconds, int nanoseconds) :
    timeValue(seconds, nanoseconds)
{
}

inline
Duration::Duration(const TimeValue &timeValue) :
    timeValue(timeValue)
{
}

} // end namespace rtime

#endif /* RTIME_DURATION_H */
