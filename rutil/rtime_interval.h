/*!
 * \file
 * \author Miroslav Kubik <mkubik2@retia.cz>
 * \brief Contains \link rtime::Interval \endlink class definitions.
 */
#ifndef RTIME_INTERVAL_H
#define RTIME_INTERVAL_H

#include "rtime_timestamp.h"

#include <ostream>

namespace rtime
{

/*!
 * Represents a continuous range of time stamps between two endpoints (time
 * stamps). Empty interval and intervals with infinite endpoints are supported.
 */
class Interval
{
public:

    // factory functions

    static Interval since(const TimeStamp &time)
    {
        Interval window;
        window.setBegin(time);
        return window;
    }

    static Interval till(const TimeStamp &time)
    {
        Interval window;
        window.setEnd(time);
        return window;
    }

    static Interval between(const TimeStamp &begin, const TimeStamp &end)
    {
        Interval window;
        window.setBegin(begin);
        window.setEnd(end);
        return window;
    }

    static Interval unlimited()
    {
        Interval window;
        window.setUnlimited();
        return window;
    }

    static Interval empty()
    {
        return Interval();
    }

    // constructs an empty interval
    Interval() :
        beginValid(false), endValid(false), emptyInterval(true), unlimitedInterval(
                false)
    {
    }

    void setEmpty()
    {
        beginValid = false;
        endValid = false;
        emptyInterval = true;
        unlimitedInterval = false;
        begin.reset();
        end.reset();
    }

    bool isEmpty() const
    {
        return emptyInterval;
    }

    void setUnlimited()
    {
        beginValid = false;
        endValid = false;
        emptyInterval = false;
        unlimitedInterval = true;
        begin.reset();
        end.reset();
    }

    bool isUnlimited() const
    {
        return unlimitedInterval;
    }

    bool contains(const TimeStamp &time)
    {
        if (emptyInterval)
        {
            return false;
        }
        if (unlimitedInterval)
        {
            return true;
        }
        if (hasBegin() && time < begin)
        {
            return false;
        }
        if (hasEnd() && time > end)
        {
            return false;
        }
        return true;
    }

    bool hasBegin() const
    {
        return beginValid;
    }

    TimeStamp getBegin() const
    {
        return begin;
    }

    void setBegin(const TimeStamp &time)
    {
        emptyInterval = false;
        unlimitedInterval = false;
        beginValid = true;
        begin = time;
    }

    bool hasEnd() const
    {
        return endValid;
    }

    TimeStamp getEnd() const
    {
        return end;
    }

    void setEnd(const TimeStamp &time)
    {
        emptyInterval = false;
        unlimitedInterval = false;
        endValid = true;
        end = time;
    }

    void move(const Duration &duration)
    {
        if (hasBegin())
        {
            begin += duration;
        }
        if (hasEnd())
        {
            end += duration;
        }
    }

    friend std::ostream &operator<<(std::ostream &o, const Interval &interval)
    {
        if (interval.emptyInterval) { o << "empty"; }
	else if (interval.unlimitedInterval) { o << "unlimited"; }
	else if (!interval.beginValid) { o << "till " << interval.end; }
	else if (!interval.endValid) { o << "since " << interval.begin; }
	else { o << interval.begin << "-" << interval.end; }
        return o;
    }

private:
    bool beginValid, endValid;
    bool emptyInterval, unlimitedInterval;
    TimeStamp begin, end;
};

} // end namespace rtime

#endif /* RTIME_INTERVAL_H */
