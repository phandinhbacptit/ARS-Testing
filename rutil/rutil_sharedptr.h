/*!
 * \file
 * \author Miroslav Kubik <mkubik2@retia.cz>
 * \brief Header file containing \link rutil::SharedPtr \endlink
 * and \link rutil::WeakPtr \endlink template classes.
 */
#ifndef _RUTIL_SHARED_PTR_H_INCLUDED
#define _RUTIL_SHARED_PTR_H_INCLUDED

#include "rutil_refcounter.h"
#include "rutil_safebool.h"

#include <cassert>
#include <cstddef> // NULL

namespace rutil
{

template <typename T> class WeakPtr; // forward declaration

template <typename T>
struct TypeTrait
{
    typedef T &Reference;
};

template <>
struct TypeTrait<void>
{
    typedef void Reference;
};

/*!
 * \brief A reentrant shared pointer, semantically similar to boost::shared_ptr.
 *
 * See http://www.boost.org/doc/libs/1_42_0/libs/smart_ptr/shared_ptr.htm.
 *
 * Shared pointers are small memory management objects which share ownership of given
 * pointer - once the last shared pointer is destroyed the pointer is automatically deleted.
 * Be careful not to form a cycle of shared pointers - the objects in the cycle would never
 * be deleted. Use \link rutil::WeakPtr \endlink to break potential cycles.
 */
template <typename T>
class SharedPtr : public SafeBool<SharedPtr<T> >
{

public:

    template <typename Y>
    friend class SharedPtr;

    typedef T Type;

    /*!
     * \brief Constructs an empty shared pointer.
     */
    SharedPtr();

    /*!
     * \brief Constructs a shared pointer.
     *
     * The pointed-to object is deleted, once all the shared pointers referencing it
     * are destroyed.
     * \param pointer ... the raw pointer to encapsulate
     */
    template <typename Y>
    explicit SharedPtr(Y *pointer);

    /*!
     * \brief A copy constructor.
     *
     * \param other ... the shared pointer to copy
     * The constructed shared pointer points to the same object.
     */
    SharedPtr(const SharedPtr<T> &other);

    /*!
     * \brief A copy constructor.
     *
     * May be used for subclass to superclass conversion.
     * \param other ... the shared pointer to copy
     * The constructed shared pointer points to the same object.
     */
    template <typename Y>
    explicit SharedPtr(const SharedPtr<Y> &other);

    /*!
     * \brief A copy constructor.
     *
     * \param weakPointer ... the shared pointer to copy
     * The constructed shared pointer points to the same object.
     */
    template <typename Y>
    explicit SharedPtr(const WeakPtr<Y> &weakPointer);

    /*!
     * \brief A destructor.
     *
     * If this is the last shared pointer holding a pointer to the object, it is deleted
     * and locking weak pointers to the object shall return empty shared pointer.
     */
    ~SharedPtr();

    /*!
     * \brief Assigns given shared pointer.
     *
     * The shared pointers point to the same object after the assignment.
     * \param other ... the shared pointer to assign
     * \return Reference to this shared pointer.
     */
    SharedPtr<T> &operator=(const SharedPtr<T> &other);

    /*!
     * \brief Assigns given shared pointer.
     *
     * The shared pointers point to the same object after the assignment.
     * May be used for subclass to superclass pointer assignment.
     * \param other ... the shared pointer to assign
     * \return Reference to this shared pointer.
     */
    template <typename Y>
    SharedPtr<T> &operator=(const SharedPtr<Y> &other);

    /*!
     * \brief Assigns given raw pointer.
     *
     * The pointed-to object must be created via operator new.
     * \return Reference to this shared pointer.
     */
    SharedPtr<T> &operator=(T *pointer);

    /*!
     * \brief Assigns given raw pointer.
     *
     * The pointed-to object must be created via operator new. May be used
     * for subclass to superclass pointer assignment.
     * \return Reference to this shared pointer.
     */
    template <typename Y>
    SharedPtr<T> &operator=(Y *pointer); 

    /*!
     * \brief Resets the pointer to empty state.
     */
    void reset();

    /*!
     * \brief Retrieves pointer to the pointed-to object in order to access one
     * of its members.
     *
     * The shared pointer must not be empty when calling this method.
     * \return The pointer to the pointed-to object.
     */
    T *operator->() const;

    /*!
     * \brief Retrieves reference to the pointed-to object.
     *
     * The shared pointer must not be empty when calling this method.
     * \return The reference to the pointed-to object.
     */
    typename TypeTrait<T>::Reference operator*() const;

    /*!
     * \brief Retrieves the pointer to the pointed-to object.
     * \return The pointer to the pointed-to object, \c NULL if the shared pointer is empty.
     */
    T *getPtr() const;

    /*!
     * \brief Conversion to a boolean value.
     * 
     * Enables using shared pointers in conditions (along with SafeBool superclass).
     * \return \c True if the shared pointer holds an object, \c false otherwise.
     */
    bool toBool() const;

    /*!
     * \brief Tests whether this is the only shared pointer to the object.
     * \return \c True if this is the only shared pointer, \c false otherwise.
     */
    bool isUnique() const;

    /*!
     * \brief Retrieves the number of shared pointers to the object.
     *
     * For debugging purposes mostly.
     * \return The number of shared pointers to the object.
     */
    unsigned int getCount() const;

    /*!
     * \brief Swaps the content with given shared pointer.
     * \param other ... the shared pointer to swap the object with
     */
    void swap(SharedPtr<T> &other);

private:

    /*!
     * \brief Private constructor used by weak pointer when locking.
     * \param pointer ... the shared object
     * \param counter ... the reference counter
     */
    SharedPtr(T *pointer, RefCounter *counter);

    T *ptr_;
    RefCounter *counter_;

    friend class WeakPtr<T>;
    
    template <typename A, typename B>
    friend bool operator==(const SharedPtr<A> &p1, const SharedPtr<B> &p2);
    
    template <typename A, typename B>
    friend bool operator!=(const SharedPtr<A> &p1, const SharedPtr<B> &p2);
    
    template <typename A, typename B>
    friend bool operator<(const SharedPtr<A> &p1, const SharedPtr<B> &p2);

    template <typename A, typename B>
    friend SharedPtr<A> dynamic_pointer_cast(const SharedPtr<B> &p);
};

/*!
 * \brief Tests if the pointed-to objects are the same.
 * \param p1 ... the first pointer
 * \param p2 ... the second pointer
 * \return \c True if the pointed-to objects are the same, \c false otherwise.
 */
template <typename A, typename B>
bool operator==(const SharedPtr<A> &p1, const SharedPtr<B> &p2)
{
    return p1.counter_ == p2.counter_;
}

/*!
 * \brief Tests if the pointed-to objects are not the same.
 * \param p1 ... the first pointer
 * \param p2 ... the second pointer
 * \return \c True if the pointed-to objects are not the same, \c false otherwise.
 */
template <typename A, typename B>
bool operator!=(const SharedPtr<A> &p1, const SharedPtr<B> &p2)
{
    return p1.counter_ != p2.counter_;
}

/*!
 * \brief Compares two shared pointers (strict weak ordering).
 * \param p1 ... the first pointer
 * \param p2 ... the second pointer
 * \return \c True if the first pointer is lesser, \c false otherwise.
 */
template <typename A, typename B>
bool operator<(const SharedPtr<A> &p1, const SharedPtr<B> &p2)
{
    return p1.counter_ < p2.counter_;
}

/*!
 * \brief Performs dynamic cast of the shared pointer.
 * 
 * May be used for safe down-casting in class hierarchies.
 * \param p ... the pointer to cast
 * \return Empty shared pointer on error, cast shared pointer sharing the ownership
 * otherwise.
 */
template <typename A, typename B>
SharedPtr<A> dynamic_pointer_cast(const SharedPtr<B> &p)
{
    if (!p) // empty
    {
        return SharedPtr<A>();
    }
    A *ptr = dynamic_cast<A*>(p.ptr_);
    if (!ptr) // cast failed
    {
        return SharedPtr<A>();
    }
    // success
    return SharedPtr<A>(ptr, p.counter_);
}


/*!
 * \brief A reentrant weak pointer, semantically similar to boost::weak_ptr.
 *
 * See http://www.boost.org/doc/libs/1_42_0/libs/smart_ptr/weak_ptr.htm.
 *
 * Weak pointers are complementary objects for shared pointers. The difference
 * is that weak pointers do not claim ownership of the passed objects, they merely
 * observe them - the pointed-to object might be deleted while there are still weak
 * pointers referencing it.
 *
 * User must lock the weak pointer before any manipulation with the pointed-to object.
 * If the object is already deleted, lock returns empty shared pointer.
 */
template <typename T>
class WeakPtr
{

public:

    template <typename Y>
    friend class WeakPtr;

    friend class CounterMap; // to access ptr_

    typedef T Type;

    /*!
     * \brief Constructs an empty weak pointer.
     */
    WeakPtr();

    /*!
     * \brief Constructs a weak pointer.
     *
     * The constructed pointer points to the same object as \a sharedPointer .
     * \param sharedPointer ... the shared pointer to derive from
     */
    template <typename Y>
    WeakPtr(const SharedPtr<Y> &sharedPointer);

    /*!
     * \brief A copy constructor.
     *
     * The constructed weak pointer points to the same object.
     * \param other ... the weak pointer to copy
     */
    WeakPtr(const WeakPtr<T> &other);

    /*!
     * \brief A copy constructor.
     *
     * The constructed weak pointer points to the same object.
     * May be used for subclass to superclass assignment.
     * \param other ... the weak pointer to copy
     */
    template <typename Y>
    WeakPtr(const WeakPtr<Y> &other);

    /*!
     * \brief A destructor.
     */
    ~WeakPtr();

    /*!
     * \brief Assigns given weak pointer.
     *
     * The weak pointers point to the same object after the assignment.
     * \param other ... the weak pointer to assign
     * \return Reference to this weak pointer.
     */
    WeakPtr<T> &operator=(const WeakPtr<T> &other);

    /*!
     * \brief Assigns given weak pointer.
     *
     * The weak pointers point to the same object after the assignment.
     * \param other ... the weak pointer to assign
     * \return Reference to this weak pointer.
     */
    template <typename Y>
    WeakPtr<T> &operator=(const WeakPtr<Y> &other);

    /*!
     * \brief Assigns given shared pointer.
     *
     * The pointers point to the same object after the assignment.
     * \param sharedPointer ... the shared pointer to assign
     * \return Reference to this weak pointer.
     */
    WeakPtr<T> &operator=(const SharedPtr<T> &sharedPointer);

    /*!
     * \brief Tests if the pointer is expired (empty).
     * \return \c True if the pointer is expired, \c false otherwise.
     */
    bool isExpired() const;

    /*!
     * \brief Resets (empties) the pointer.
     */
    void reset();

    /*!
     * \brief Creates a shared pointer to the object.
     * \return The shared pointer (empty if the weak pointer is expired).
     */
    SharedPtr<T> lock() const;

    /*!
     * \brief Retrieves the number of shared pointers to the object.
     *
     * For debugging purposes mostly.
     * \return The number of shared pointers to the object.
     */
    unsigned int getCount() const;

    /*!
     * \brief Swaps the pointed-to objects.
     * \param other ... the pointer to swap content with
     */
    void swap(WeakPtr<T> &other);

private:

    T *ptr_;
    RefCounter *counter_;
};

/*!
 * \brief Compares pointed-to addresses.
 * \param p1 ... the first pointer
 * \param p2 ... the second pointer
 * \return \c True if the first address is lesser, \c false otherwise.
 */
template<typename T, typename U>
bool operator<(const WeakPtr<T> &p1, const WeakPtr<U> &p2)
{
    return p1.ptr_ < p2.ptr_;
}


// SharedPtr method definitions

template <typename T>
SharedPtr<T>::SharedPtr() : ptr_(NULL), counter_(NULL) {}

template <typename T>
template <typename Y>
SharedPtr<T>::SharedPtr(Y *pointer) : ptr_(pointer), counter_(NULL)
{
    if (pointer != NULL)
    {
        counter_ = new RefCounter(pointer);
        counter_->grabShared();
    }
}

template <typename T>
SharedPtr<T>::SharedPtr(const SharedPtr<T> &other)
    : SafeBool<SharedPtr<T> >(), ptr_(other.ptr_), counter_(other.counter_)
{
    if (counter_)
    {
        counter_->grabShared();
    }
}

template <typename T>
template <typename Y>
SharedPtr<T>::SharedPtr(const SharedPtr<Y> &other)
    : SafeBool<SharedPtr<T> >(), ptr_(other.ptr_), counter_(other.counter_)
{
    if (counter_)
    {
        counter_->grabShared();
    }
}

template <typename T>
template <typename Y>
SharedPtr<T>::SharedPtr(const WeakPtr<Y> &weakPointer)
    : ptr_(weakPointer.ptr_), counter_(weakPointer.counter_)
{
    if (counter_)
    {
        counter_->grabShared();
    }
}

template <typename T>
SharedPtr<T>::~SharedPtr()
{
    if (counter_ && counter_->dropShared())
    {
        delete counter_;
    }
}

template <typename T>
SharedPtr<T> &SharedPtr<T>::operator=(const SharedPtr<T> &other)
{
    if (other.counter_)
    {
        other.counter_->grabShared();
    }
    if (counter_ && counter_->dropShared())
    {
        delete counter_;
    }
    counter_ = other.counter_;
    ptr_ = other.ptr_;
    return *this;
}

template <typename T>
template <typename Y>
SharedPtr<T> &SharedPtr<T>::operator=(const SharedPtr<Y> &other)
{
    if (other.counter_)
    {
        other.counter_->grabShared();
    }
    if (counter_ && counter_->dropShared())
    {
        delete counter_;
    }
    counter_ = other.counter_;
    ptr_ = other.ptr_;
    return *this;
}

template <typename T>
SharedPtr<T> &SharedPtr<T>::operator=(T *pointer)
{
    if (counter_ && counter_->dropShared())
    {
        delete counter_;
    }
    counter_ = NULL;
    if (pointer)
    {
        counter_ = new RefCounter(pointer);
        counter_->grabShared();
    }
    ptr_ = pointer;
    return *this;
}

template <typename T>
template <typename Y>
SharedPtr<T> &SharedPtr<T>::operator=(Y *pointer)
{
    if (counter_ && counter_->dropShared())
    {
        delete counter_;
    }
    counter_ = NULL;
    if (pointer)
    {
        counter_ = new RefCounter(pointer);
        counter_->grabShared();
    }
    ptr_ = pointer;
    return *this;
}

template <typename T>
void SharedPtr<T>::reset()
{
    if (counter_ && counter_->dropShared())
    {
        delete counter_;
    }
    counter_ = NULL;
    ptr_ = NULL;
}

template <typename T>
T *SharedPtr<T>::operator->() const
{
    assert(ptr_ != NULL);
    return ptr_;
}

template <typename T>
typename TypeTrait<T>::Reference SharedPtr<T>::operator*() const
{
    assert(ptr_ != NULL);
    return *ptr_;
}

template <typename T>
T *SharedPtr<T>::getPtr() const
{
    return ptr_;
}

template <typename T>
bool SharedPtr<T>::toBool() const
{
    return ptr_ != NULL;
}

template <typename T>
bool SharedPtr<T>::isUnique() const
{
    return getCount() == 1;
}

template <typename T>
unsigned int SharedPtr<T>::getCount() const
{
   return counter_ ? counter_->getSharedCount() : 0;
}

template <typename T>
void SharedPtr<T>::swap(SharedPtr<T> &other)
{
    T *ptr = ptr_;
    ptr_ = other.ptr_;
    other.ptr_ = ptr;

    RefCounter *counter = counter_;
    counter_ = other.counter_;
    other.counter_ = counter;
}

template <typename T>
SharedPtr<T>::SharedPtr(T *pointer, RefCounter *counter)
    : ptr_(pointer), counter_(counter)
{
    if (counter_)
    {
        counter_->grabShared();
    }
}


// WeakPtr method definitions

template <typename T>
WeakPtr<T>::WeakPtr() : ptr_(NULL), counter_(NULL) {}

template <typename T>
template <typename Y>
WeakPtr<T>::WeakPtr(const SharedPtr<Y> &sharedPointer)
    : ptr_(sharedPointer.ptr_), counter_(sharedPointer.counter_)
{
    if (counter_)
    {
        counter_->grabWeak();
    }
}

template <typename T>
WeakPtr<T>::WeakPtr(const WeakPtr<T> &other)
    : ptr_(other.ptr_), counter_(other.counter_)
{
    if (counter_)
    {
        counter_->grabWeak();
    }
}

template <typename T>
template <typename Y>
WeakPtr<T>::WeakPtr(const WeakPtr<Y> &other)
    : ptr_(other.ptr_), counter_(other.counter_)
{
    if (counter_)
    {
        counter_->grabWeak();
    }
}

template <typename T>
WeakPtr<T>::~WeakPtr()
{
    if (counter_ && counter_->dropWeak())
    {
        delete counter_;
    }
}

template <typename T>
WeakPtr<T> &WeakPtr<T>::operator=(const WeakPtr<T> &other)
{
    if (counter_ == other.counter_)
    {
        return *this;
    }
    if (counter_ && counter_->dropWeak())
    {
        delete counter_;
    }
    ptr_ = other.ptr_;
    counter_ = other.counter_;
    if (counter_)
    {
        counter_->grabWeak();
    }
    return *this;
}

template <typename T>
template <typename Y>
WeakPtr<T> &WeakPtr<T>::operator=(const WeakPtr<Y> &other)
{
    if (counter_ == other.counter_)
    {
        return *this;
    }
    if (counter_ && counter_->dropWeak())
    {
        delete counter_;
    }
    ptr_ = other.ptr_;
    counter_ = other.counter_;
    if (counter_)
    {
        counter_->grabWeak();
    }
    return *this;
}

template <typename T>
WeakPtr<T> &WeakPtr<T>::operator=(const SharedPtr<T> &sharedPointer)
{
    if (counter_ == sharedPointer.counter_)
    {
        return *this;
    }
    if (counter_ && counter_->dropWeak())
    {
        delete counter_;
    }
    ptr_ = sharedPointer.ptr_;
    counter_ = sharedPointer.counter_;
    if (counter_)
    {
        counter_->grabWeak();
    }
    return *this;
}

template <typename T>
bool WeakPtr<T>::isExpired() const
{
    return counter_ == NULL || counter_->isEmpty();
}

template <typename T>
void WeakPtr<T>::reset()
{
    if (counter_ && counter_->dropWeak())
    {
        delete counter_;
    }
    ptr_ = NULL;
    counter_ = NULL;
}

template <typename T>
SharedPtr<T> WeakPtr<T>::lock() const
{
    return isExpired() ? SharedPtr<T>() : SharedPtr<T>(ptr_, counter_);
}

template <typename T>
unsigned int WeakPtr<T>::getCount() const
{
   return counter_ ? counter_->getSharedCount() : 0;
}

template <typename T>
void WeakPtr<T>::swap(WeakPtr<T> &other)
{
    T *ptr = ptr_;
    ptr_ = other.ptr_;
    other.ptr_ = ptr;
    
    RefCounter *counter = counter_;
    counter_ = other.counter_;
    other.counter_ = counter;
}

} // end namespace rutil

#endif /* _RUTIL_SHARED_PTR_H_INCLUDED */
