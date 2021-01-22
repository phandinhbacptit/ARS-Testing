/*!
 * \file
 * \author Miroslav Kubik <mkubik2@retia.cz>
 * \brief Header file for \link rutil::Noncopyable \endlink base class.
 */
#ifndef RUTIL_NONCOPYABLE_H
#define RUTIL_NONCOPYABLE_H

namespace rutil
{
    /*!
     * Derive from this class if you want to make the derived class objects
     * non-copyable and non-assignable.
     */
    class Noncopyable
    {
    protected:
        Noncopyable() {}
        ~Noncopyable() {}

    private:
        // declared privately to prevent the derived classes from accessing
        Noncopyable(const Noncopyable&);
        const Noncopyable &operator=(const Noncopyable&);
    };
}

#endif /* RUTIL_NONCOPYABLE_H */
