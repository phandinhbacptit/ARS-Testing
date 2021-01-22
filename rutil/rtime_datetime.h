/*!
 * \file
 * \author Miroslav Kubik <mkubik2@retia.cz>
 * \brief Header file for \link rtime::DateTime \endlink.
 */
#ifndef RTIME_DATETIME_H
#define RTIME_DATETIME_H

#include "rtime_constants.h"
#include "rtime_platform.h"

#include <ctime>
#include <ostream>

namespace rtime
{

enum Dst
{
    DstUnknown = -1,
    DstNo,
    DstYes
};
typedef enum Dst Dst;

/*!
 * \brief Class for representing calendar date and time (up to nanosecond
 * precision).
 */
class DateTime
{
public:

    /*!
     * A constructor.
     * \param timeInfo ... a pointer to time info structure
     * \param nanoseconds ... nanoseconds <0; 1000000000)
     */
    DateTime(const struct tm *timeInfo, int nanoseconds);

    /*!
     * Retrieves year.
     * \return The year.
     */
    int getYear() const;

    /*!
     * Retrieves month of the year.
     * \return The month, in <1; 12>.
     */
    int getMonth() const;

    /*!
     * Retrieves day of the month.
     * \return The day, in <1; 31>.
     */
    int getDay() const;

    /*!
     * Retrieves hours since midnight.
     * \return The hours since midnight, in <0; 24).
     */
    int getHour() const;

    /*!
     * Retrieves minutes after the hour.
     * \return The minutes after the hour, in <0; 60).
     */
    int getMinute() const;

    /*!
     * Retrieves seconds after the minute.
     * \return The seconds after the minute, in <0; 61>.
     */
    int getSecond() const;

    /*!
     * Retrieves milliseconds.
     * \return The milliseconds, in <0; 1000).
     */
    int getMilliseconds() const;

    /*!
     * Retrieves microseconds.
     * \return The microseconds, in <0; 1000000).
     */
    int getMicroseconds() const;

    /*!
     * Retrieves nanoseconds.
     * \return The nanoseconds, in <0; 1000000000).
     */
    int getNanoseconds() const;

    /*!
     * Retrieves daylight saving time status.
     * \return The daylight saving time status.
     */
    Dst getDst() const;

    friend std::ostream &operator<<(std::ostream &stream,
            const DateTime &dateTime);

private:
    struct tm timeInfo;
    int nanoseconds;
};

/*!
 * Standard operator for output to a stream. It follows "dd/mm/yy hh:mm:ss.sss"
 * format.
 * \param stream ... the stream to write to
 * \param dateTime ... the date time to output
 * \return A reference to the stream.
 */
std::ostream &operator<<(std::ostream &stream, const DateTime &dateTime);


// definitions

inline
DateTime::DateTime(const struct tm *timeInfo, int nanoseconds) :
    nanoseconds(0)
{
#if RTIME_LINUX
    struct tm result;
#endif
    if (timeInfo == NULL)
    {
        time_t seconds = 0;
#if RTIME_LINUX
        gmtime_r(&seconds, &result);
        timeInfo = &result;
#else
        timeInfo = gmtime(&seconds);
#endif
    }
    this->timeInfo = *timeInfo;
    if ((nanoseconds < 0) || (nanoseconds >= Constants::SEC_TO_NANO))
    {
        this->nanoseconds = 0;
    }
    else
    {
        this->nanoseconds = nanoseconds;
    }
}

inline
int DateTime::getYear() const
{
    return timeInfo.tm_year + 1900;
}

inline
int DateTime::getMonth() const
{
    return timeInfo.tm_mon + 1;
}

inline
int DateTime::getDay() const
{
    return timeInfo.tm_mday;
}

inline
int DateTime::getHour() const
{
    return timeInfo.tm_hour;
}

inline
int DateTime::getMinute() const
{
    return timeInfo.tm_min;
}

inline
int DateTime::getSecond() const
{
    return timeInfo.tm_sec;
}

inline
int DateTime::getMilliseconds() const
{
    return nanoseconds / Constants::MILLI_TO_NANO;
}

inline
int DateTime::getMicroseconds() const
{
    return nanoseconds / Constants::MICRO_TO_NANO;
}

inline
int DateTime::getNanoseconds() const
{
    return nanoseconds;
}

inline
Dst DateTime::getDst() const
{
    if (timeInfo.tm_isdst < 0)
    {
        return DstUnknown;
    }
    else if (timeInfo.tm_isdst == 0)
    {
        return DstNo;
    }
    else // > 0
    {
        return DstYes;
    }
}

} // end namespace rtime

#endif /* RTIME_DATETIME_H */
