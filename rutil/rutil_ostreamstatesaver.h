/*!
 * \file
 * \author Miroslav Kubik <mkubik2@retia.cz>
 * \brief Header file for \link rutil::OstreamStateSaver \endlink class.
 */
#ifndef RUTIL_OSTREAMSTATESAVER_H
#define RUTIL_OSTREAMSTATESAVER_H

#include "rutil_noncopyable.h"

#include <iomanip>
#include <iostream>

namespace rutil
{

/*!
 * Simple utility class for saving and restoration of a standard ostream's
 * state. Internally stores formatting flags, fill character and precision
 * information.
 */
class OstreamStateSaver : private Noncopyable
{
public:

    /*!
     * Constructor. Extracts the state information from the stream.
     * A reference to the stream is stored in the saver, the caller
     * must ensure that the stream is not destroyed before the saver.
     * \param ostream ... the stream whose state is to be stored
     */
    OstreamStateSaver(std::ostream &ostream)
    {
        this->ostream = &ostream;

        flags = ostream.flags();
        fill = ostream.fill();
        precision = ostream.precision();
    }

    /*!
     * Restores the state of the stream.
     */
    void restore() const
    {
        ostream->flags(flags);
        ostream->fill(fill);
        ostream->precision(precision);
    }

    /*!
     * A destructor. Restores the state of the stream.
     */
    ~OstreamStateSaver()
    {
        restore();
    }

private:
    std::ostream* ostream;

    std::ios_base::fmtflags flags;
    char fill;
    std::streamsize precision;
};

} // end namespace rutil

#endif /* RUTIL_OSTREAMSTATESAVER_H */
