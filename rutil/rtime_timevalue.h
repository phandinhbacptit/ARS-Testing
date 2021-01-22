/*!
 * \file
 * \author Miroslav Kubik <mkubik2@retia.cz>
 * \brief Header file for \link rtime::TimeValue \endlink.
 */
#ifndef RTIME_TIMEVALUE_H
#define RTIME_TIMEVALUE_H

#include "rtime_constants.h"

#include <cmath>
#include <ctime>
#include <limits>
#include <ostream>

namespace rtime
{

/*!
 * \brief Common type for internal representation of time stamps and durations.
 *
 * A general purpose time value expressed in seconds and nanoseconds. The user
 * should not need to use this class.
 */
class TimeValue
{
public:

    static TimeValue max();
    
    static TimeValue min();

    /*!
     * A constructor.
     * \param seconds ... the seconds
     * \param nanoseconds ... the fraction part, in nanoseconds
     */
    TimeValue(time_t seconds = 0, int nanoseconds = 0);

    /*!
     * Sets the time value.
     * \param seconds ... the seconds
     * \param nanoseconds ... the fraction part, in nanoseconds
     */
    void set(time_t seconds, int nanoseconds);

    /*!
     * Set the seconds.
     * \param seconds ... the seconds to set
     */
    void setSeconds(time_t seconds);

    /*!
     * Retrieves Set the seconds.
     * \return The seconds.
     */
    time_t getSeconds() const;

    /*!
     * Sets the fraction part, nanoseconds.
     * \param nanoseconds ... the nanoseconds to set
     */
    void setNanoseconds(int nanoseconds);

    /*!
     * Retrieves the fraction part, nanoseconds.
     * \return The nanoseconds, in <0; 1000000000).
     */
    int getNanoseconds() const;

    /*!
     * Converts the time value to a double.
     * \return The time value, in seconds.
     */
    double asDouble() const;

    // arithmetic operators - self-explanatory

    TimeValue operator+(const TimeValue &value) const;
    TimeValue& operator+=(const TimeValue &value);
    TimeValue operator-(const TimeValue &value) const;
    TimeValue& operator-=(const TimeValue &value);

    TimeValue operator-() const;
    TimeValue operator*(double value) const;
    TimeValue operator/(double value) const;
    friend TimeValue operator*(double value,
            const TimeValue &timeValue);

    // relational operators - self-explanatory

    bool operator>(const TimeValue &value) const;
    bool operator>=(const TimeValue &value) const;
    bool operator<(const TimeValue &value) const;
    bool operator<=(const TimeValue &value) const;
    bool operator==(const TimeValue &value) const;
    bool operator!=(const TimeValue &value) const;

    /*!
     * Tests for zero time value.
     * \return \c True if this is a zero time value, \c false otherwise.
     */
    bool isZero() const;

    /*!
     * Tests for negative time value.
     * \return \c True if the value is negative, \c false otherwise.
     */
    bool isNegative() const;

    friend std::ostream &operator<<(std::ostream &stream,
            const TimeValue &value);

private:

    /*!
     * Normalizes the internal representation, so that nanoseconds fit
     * into <0; 1000000000).
     */
    void normalize();

    time_t secs;
    int nanosecs;
};

/*!
 * Standard operator for output to a stream. It writes the time value in
 * seconds, with the fraction part zero-padded to 9 digits.
 * \param stream ... the stream to write to
 * \param value ... the time value to output
 * \return A reference to the stream.
 */
std::ostream &operator<<(std::ostream &stream, const TimeValue &value);

template <typename SInt>
inline
SInt boundedAddition(SInt a, SInt b, bool *min = NULL, bool *max = NULL)
{
    if (min) { *min = false; }
    if (max) { *max = false; }
    SInt result = a + b;
    // different signs (or zeros)
    if ((a >= 0 && b <= 0) || (b >= 0 && a <= 0))
    {
        return result;
    }
    // same signs
    else
    {
        if (a > 0 && result < 0)
	{
	    if (max) { *max = true; }
	    return std::numeric_limits<SInt>::max();
	}
	else if (a < 0 && result >= 0)
	{
	    if (min) { *min = true; }
	    return std::numeric_limits<SInt>::min();
	}
	else
	{
	    return result;
	}
    }
}

template <typename SInt>
inline
SInt boundedSubtraction(SInt a, SInt b, bool *min = NULL, bool *max = NULL)
{
    if (min) { *min = false; }
    if (max) { *max = false; }
    SInt result = a - b;
    // same signs (or zeros)
    if ((a >= 0 && b >= 0) || (a <= 0 && b <= 0))
    {
        return result;
    }
    // different signs
    else
    {
        if (a > 0 && result < 0)
	{
	    if (max) { *max = true; }
	    return std::numeric_limits<SInt>::max();
	}
	else if (a < 0 && result >= 0)
	{
	    if (min) { *min = true; }
	    return std::numeric_limits<SInt>::min();
	}
	else
	{
	    return result;
	}
    }
}

// definitions

inline
TimeValue TimeValue::max()
{
    return TimeValue(std::numeric_limits<time_t>::max(), Constants::SEC_TO_NANO - 1);
}

inline
TimeValue TimeValue::min()
{
    return TimeValue(std::numeric_limits<time_t>::min(), 0);
}

inline
TimeValue::TimeValue(time_t seconds, int nanoseconds) :
    secs(seconds), nanosecs(nanoseconds)
{
    //normalize();
}

inline
void TimeValue::set(time_t seconds, int nanoseconds)
{
    secs = seconds;
    nanosecs = nanoseconds;
    //normalize();
}

inline
void TimeValue::setSeconds(time_t seconds)
{
    secs = seconds;
}

inline
time_t TimeValue::getSeconds() const
{
    return secs;
}

inline
void TimeValue::setNanoseconds(int nanoseconds)
{
    nanosecs = nanoseconds;
    normalize();
}

inline
int TimeValue::getNanoseconds() const
{
    return nanosecs;
}

inline
double TimeValue::asDouble() const
{
    return (double)secs + (double)nanosecs / Constants::SEC_TO_NANO;
}

inline
TimeValue TimeValue::operator+(const TimeValue &value) const
{
    bool min, max;
    time_t resultSec = boundedAddition<time_t>(secs, value.secs, &min, &max);
    int resultNSec;
    if (min) { resultNSec = 0; }
    else if (max) { resultNSec = Constants::SEC_TO_NANO - 1; }
    else { resultNSec = nanosecs + value.nanosecs; }
    return TimeValue(resultSec, resultNSec);
}

inline
TimeValue& TimeValue::operator+=(const TimeValue &value)
{
    // a bit inefficient but elegant
    *this = *this + value;
    return *this;
}

inline
TimeValue TimeValue::operator-(const TimeValue &value) const
{
    bool min, max;
    time_t resultSec = boundedSubtraction<time_t>(secs, value.secs, &min, &max);
    int resultNSec;
    if (min) { resultNSec = 0; }
    else if (max) { resultNSec = Constants::SEC_TO_NANO - 1; }
    else { resultNSec = nanosecs - value.nanosecs; }
    return rtime::TimeValue(resultSec, resultNSec);
}

inline
TimeValue& TimeValue::operator-=(const TimeValue &value)
{
    // a bit inefficient but elegant
    *this = *this - value;
    return *this;
}

inline
TimeValue TimeValue::operator-() const
{
    time_t minSecs = std::numeric_limits<time_t>::min();
    time_t maxSecs = std::numeric_limits<time_t>::max();
    if (secs == minSecs)
    {
        if (nanosecs == 0)
	{
	    // overflow
	    return TimeValue::max();
        }
	else // nanosecs > 0
	{
	    return TimeValue(maxSecs, Constants::SEC_TO_NANO - nanosecs);
	}
    }
    else
    {
        return TimeValue(-secs, -nanosecs);
    }
}

inline
TimeValue TimeValue::operator*(double value) const
{
    // zero or NaN
    if (isZero() || (value != value))
    {
        return TimeValue();
    }
    // multiplication by +-infinity
    if (value == std::numeric_limits<double>::infinity())
    {
        return isNegative() ? TimeValue::min() : TimeValue::max();
    }
    else if (value == -std::numeric_limits<double>::infinity())
    {
        return isNegative() ? TimeValue::max() : TimeValue::min();
    }
    // ordinary case
    double newFraction, newInteger;
    double integer;
    newFraction = modf(secs * value, &integer);
    newInteger = integer;
    newFraction = modf(nanosecs * value / Constants::SEC_TO_NANO + newFraction, &integer);
    newInteger += integer;
    if (newInteger <= std::numeric_limits<time_t>::min())
    {
        return TimeValue::min();
    }
    else if (newInteger > std::numeric_limits<time_t>::max())
    {
        return TimeValue::max();
    }
    else
    {
        return TimeValue((time_t)newInteger, (int)(newFraction * Constants::SEC_TO_NANO));
    }
}

inline
TimeValue TimeValue::operator/(double value) const
{
    return *this * (1 / value);
}

inline
TimeValue operator*(double value, const TimeValue &timeValue)
{
    return timeValue * value;
}

inline
bool TimeValue::operator>(const TimeValue &value) const
{
    return (secs> value.secs) || ((secs == value.secs) && (nanosecs> value.nanosecs));
}

inline
bool TimeValue::operator>=(const TimeValue &value) const
{
    return (secs> value.secs) || ((secs == value.secs) && (nanosecs >= value.nanosecs));
}

inline
bool TimeValue::operator<(const TimeValue &value) const
{
    return (secs < value.secs) || ((secs == value.secs) && (nanosecs < value.nanosecs));
}

inline
bool TimeValue::operator<=(const TimeValue &value) const
{
    return (secs < value.secs) || ((secs == value.secs) && (nanosecs <= value.nanosecs));
}

inline
bool TimeValue::operator==(const TimeValue &value) const
{
    return (secs == value.secs) && (nanosecs == value.nanosecs);
}

inline
bool TimeValue::operator!=(const TimeValue &value) const
{
    return (secs != value.secs) || (nanosecs != value.nanosecs);
}

inline
bool TimeValue::isZero() const
{
    return (secs == 0) && (nanosecs == 0);
}

inline
bool TimeValue::isNegative() const
{
    return secs < 0;
}

} // end namespace rtime

#endif /* RTIME_TIMEVALUE_H */
