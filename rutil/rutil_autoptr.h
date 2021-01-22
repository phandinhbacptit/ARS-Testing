/*!
 * \file
 * \author Martin Kubik <mkubik3@retia.cz>
 * \brief Header file containing \link rutil::AutoPtr \endlink class.
 */
#ifndef _RUTIL_AUTO_PTR_H_INCLUDED_
#define _RUTIL_AUTO_PTR_H_INCLUDED_

#include "rutil_safebool.h"

#include <cassert> // assert
#include <cstddef> // NULL

namespace rutil
{

/*!
 * \brief An auto pointer, semantically identical to the std::auto_ptr.
 */
template<class T>
class AutoPtr : public SafeBool<AutoPtr<T> >
{

public:

    template <typename Y>
    friend class AutoPtr;

    typedef T Type;

    /*!
     * \brief Constructs an auto pointer from a raw \a pointer.
     *
     * The auto pointer claims ownership of the pointed-to object
     * and calls the delete operator on the \a pointer in its destructor.
     * 
     * \param pointer ... the raw pointer to encapsulate
     * \see rutil::AutoPtr::~AutoPtr()
     */
    AutoPtr(T *pointer = NULL);

    /*!
     * \brief Constructs an auto pointer from an \a other auto pointer.
     *
     * The \a other auto pointer relinquishes the ownership of its pointer
     * in favor of the auto pointer.
     * \param other ... the auto pointer to use
     */
    AutoPtr(AutoPtr<T> &other);

    /*!
     * \brief Destructs the auto pointer and deletes its pointed-to object.
     */
    ~AutoPtr();

    /*!
     * \brief Assigns an \a other auto pointer to the auto pointer.
     *
     * The auto pointer's pointed-to object is deleted and the \a other auto pointer
     * relinquishes the ownership of its pointer in favor of the auto pointer.
     * \param other ... the auto pointer to assign
     * \return Reference to this auto pointer.
     */
    AutoPtr<T> &operator=(AutoPtr<T> &other);

    /*!
     * \brief Assigns an \a other auto pointer to the auto pointer.
     *
     * The auto pointer's pointed-to object is deleted and the \a other auto pointer
     * relinquishes the ownership of its pointer in favor of the auto pointer.
     * The \a other pointer type must be convertible to the auto pointer's type.
     * \param other ... the auto pointer to assign
     * \return Reference to this auto pointer.
     */
    template <typename Y>
    AutoPtr<T> &operator=(AutoPtr<Y> &other);

    /*!
     * \brief Assigns a raw \a pointer to the auto pointer.
     *
     * The auto pointer's pointed-to object is deleted
     * and the auto pointer claims ownership of the given pointed-to object.
     * \param pointer ... the raw pointer to assign
     * \return Reference to this pointer.
     */
    AutoPtr<T> &operator=(T *pointer);
    
    /*!
     * \brief Assigns a raw \a pointer to the auto pointer.
     * 
     * The auto pointer's pointed-to object is deleted and
     * the auto pointer claims owenrship of the given pointed-to object.
     * The \a pointer's type must be convertible to the auto pointer's type.
     * \param pointer ... the raw pointer to assign
     * \return Reference to this pointer.     
     */
    template <typename Y>
    AutoPtr<T> &operator=(Y *pointer);

    /*!
     * \brief Tests if the auto pointer contains given object.
     * \param pointer ... the object to compare
     * \return \c True if there is a match, \c false othewise.
     */
    bool operator==(const T *pointer) const;

    /*!
     * \brief Tests if the auto pointer does not contain given object.
     * \param pointer ... the object to compare
     * \return \c True if there is not a match, \c false otherwise.
     */
    bool operator!=(const T *pointer) const;

    /*!
     * \brief Converts the auto pointer to bool.
     *
     * Enables using auto pointer in conditions (along with SafeBool
     * superclass).
     * \return \c True if the auto pointer holds an object, \c false otherwise.
     */
    bool toBool() const;

    /*!
     * \brief Retrieves the pointed-to object in order to access one of its members.
     *
     * The auto pointer must not be empty when calling this method.
     * \return The pointed-to object.
     */
    T *operator->() const;

    /*!
     * \brief Retrieves reference to the pointed-to object.
     *
     * The auto pointer must not be empty when calling this method.
     * \return The reference to pointed-to object.
     */
    T &operator*() const;

    /*!
     * \brief Retrieves the pointed-to object.
     * \return The pointed-to object (\c NULL if the auto pointer is empty).
     */
    T *getPtr() const;

    /*!
     * \brief Releases the pointed-to object.
     *
     * The auto pointer is no longer responsible for deleting the object.
     * \return The pointed-to object (\c NULL if the auto pointer is empty).
     */
    T *release();

    /*!
     * \brief Resets the auto pointer, deleting the pointed-to object.
     */
    void reset();

private:

    T* ptr_;
};


// method definitions

template <typename T>
AutoPtr<T>::AutoPtr(T *pointer) : ptr_(pointer)
{
}

template <typename T>
AutoPtr<T>::AutoPtr(AutoPtr<T> &other) : ptr_(other.ptr_)
{
     other.ptr_ = NULL;
}

template <typename T>
AutoPtr<T>::~AutoPtr()
{
    if (ptr_) delete ptr_;
}

template <typename T>
AutoPtr<T> &AutoPtr<T>::operator=(AutoPtr<T> &other)
{
    if (ptr_ == other.ptr_)
    {
        other.ptr_ = NULL;
        return *this;
    }
    if (ptr_) delete ptr_;
    ptr_ = other.ptr_;
    other.ptr_ = NULL;
    return *this;
}

template <typename T>
template <typename Y>
AutoPtr<T> &AutoPtr<T>::operator=(AutoPtr<Y> &other)
{
    if (ptr_ == other.ptr_)
    {
	other.ptr_ = NULL;
	return *this;
    }
    if (ptr_) delete ptr_;
    ptr_ = other.ptr_;
    other.ptr_ = NULL;
    return *this;
}

template <typename T>
AutoPtr<T> &AutoPtr<T>::operator=(T *pointer)
{
    if (ptr_ == pointer)
    {
        return *this;
    }
    if (ptr_)
    {
        delete ptr_;
    }
    ptr_ = pointer;
    return *this;
}

template <typename T>
template <typename Y>
AutoPtr<T> &AutoPtr<T>::operator=(Y *pointer)
{
    if (ptr_ == pointer)
    {
	return *this;
    }
    if (ptr_)
    {
	delete ptr_;
    }
    ptr_ = pointer;
    return *this;
}

template <typename T>
bool AutoPtr<T>::operator==(const T *pointer) const
{
    return ptr_ == pointer;
}

template <typename T>
bool AutoPtr<T>::operator!=(const T *pointer) const
{
    return !(*this == pointer);
}

template <typename T>
bool AutoPtr<T>::toBool() const
{
    return ptr_ != NULL;
}

template <typename T>
T *AutoPtr<T>::operator->() const
{
    assert(ptr_ != NULL);

    return ptr_;
}

template <typename T>
T &AutoPtr<T>::operator*() const
{
    assert(ptr_ != NULL);
    return *ptr_;
}

template <typename T>
T *AutoPtr<T>::getPtr() const
{
    return ptr_;
}

template <typename T>
T *AutoPtr<T>::release()
{
    T *retPtr = ptr_;
    ptr_ = NULL;
    return retPtr;
}

template <typename T>
void AutoPtr<T>::reset()
{
    delete ptr_;
    ptr_ = NULL;
}

} // end namespace rutil

#endif /* _RUTIL_AUTO_PTR_H_INCLUDED_ */
