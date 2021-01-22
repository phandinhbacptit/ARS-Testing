/*!
 * \file
 * \author Miroslav Kubik <mkubik2@retia.cz>
 * \brief Constants for time unit conversions.
 */
#ifndef RTIME_TIME_H
#define RTIME_TIME_H

namespace rtime
{

/*!
 * \brief Contains various time unit conversion constants.
 */
class Constants
{
public:
    static const int SEC_TO_NANO = 1000000000;
    static const int SEC_TO_MICRO = 1000000;
    static const int SEC_TO_MILLI = 1000;
    static const int MICRO_TO_NANO = 1000;
    static const int MILLI_TO_NANO = 1000000;
    static const int MIN_TO_SEC = 60;
    static const int HOUR_TO_SEC = 3600;
    static const int DAY_TO_SEC = 86400;
};

} // end namespace rtime

#endif /* RTIME_TIME_H */
