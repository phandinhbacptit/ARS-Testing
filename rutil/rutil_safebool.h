/*!
 * \file
 * \author Miroslav Kubik <mkubik2@retia.cz>
 * \brief Base class offering reusable implementation of the safe bool idiom.
 *
 * Based on The Safe Bool Idiom article by Bjorn Karlsson which can be found
 * at http://www.artima.com/cppsource/safebool.html
 */
#ifndef RUTIL_SAFE_BOOL_H
#define RUTIL_SAFE_BOOL_H

namespace rutil
{

/*
   Here's how to use safe bool:
   class Testable : public SafeBool<Testable>
   {
   public:
       bool toBool() const
       {
            // class specific boolean logic
       }
   };
 */

class SafeBoolBase
{
protected:
    // BoolType is a pointer to a const member function of SafeBoolBase
    typedef void (SafeBoolBase::*BoolType)() const;
    void comparisonsNotSupported() const {}
    
    SafeBoolBase() {}
    SafeBoolBase(const SafeBoolBase&) {}
    SafeBoolBase &operator=(const SafeBoolBase&) { return *this; }
    ~SafeBoolBase() {}
};


template <typename T = void>
class SafeBool : public SafeBoolBase
{
public:
    operator BoolType() const
    {
        return (static_cast<const T*>(this))->toBool()
	    ? &SafeBoolBase::comparisonsNotSupported : 0;
    }
protected:
    ~SafeBool() {}
};

template <typename T, typename U>
void operator==(const SafeBool<T> &first, const SafeBool<U> &second)
{
    first.comparisonsNotSupported(); // forces compilation error on instantiation
    return (void)false;
}

template <typename T, typename U>
void operator!=(const SafeBool<T> &first, const SafeBool<U> &second)
{
    first.comparisonsNotSupported(); // forces compilation error on instantiation
    return (void)false;
}

} // end namespace rutil

#endif // RUTIL_SAFE_BOOL_H
