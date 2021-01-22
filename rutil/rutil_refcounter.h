/*!
 * \file
 * \author Miroslav Kubik <mkubik2@retia.cz>
 * \brief Header file for \link rutil::RefCounter \endlink class.
 */
#ifndef RUTIL_REF_COUNTER_H
#define RUTIL_REF_COUNTER_H

#include <map>

using namespace std;

namespace rutil
{

template <typename T> class WeakPtr;

/*!
 * \brief Class storing necessary information for a single object.
 *
 * Number of shared and weak pointers to the object, deleter.
 */
class RefCounter
{
private:

    class IDeleter
    {
        public:
        virtual ~IDeleter() {}
    };

    // type erasure for object deletion

    template <typename T>
    class RawPtrDeleter : public IDeleter
    {
        public:
        RawPtrDeleter(T *rawPointer = NULL) : rawPointer_(rawPointer) {}

        virtual ~RawPtrDeleter()
        {
            delete rawPointer_;
        }

        private:
        T *rawPointer_;
    };

    /*!
     * \brief Deletes the pointed-to object.
     */
    void clear();

public:

    /*!
     * \brief Constructs a reference counter for given object.
     *
     * The object must be created via new.
     * \param rawPointer ... a pointer to the object
     */
     template <typename T>
     RefCounter(T *rawPointer);

    /*!
     * \brief Clears the counter.
     *
     * The pointed-to object is
     * deleted.
     * \see clear
     */
    ~RefCounter();

    /*!
     * \brief Increments the shared count.
     */
    void grabShared();

    /*!
     * \brief Increments the weak count.
     */
    void grabWeak();

    /*!
     * \brief Decrements the shared count.
     *
     * Returns \c true if the counter is no longer referenced by shared pointers
     * or weak pointers and should be deleted.
     * \return \c True if the counter should be deleted, \c false otherwise.
     */
    bool dropShared();

    /*!
     * \brief Decrements the weak count.
     *
     * Returns \c true if the counter is no longer referenced by shared pointers
     * or weak pointers and should be deleted.
     * \return \c True if the counter should be deleted, \c false otherwise.
     */
    bool dropWeak();

    /*!
     * \brief Retrieves the current number of shared pointers to the object.
     * \return The current shared count.
     */
    unsigned int getSharedCount() const;

    /*!
     * \brief Retrieves the current number of weak pointers to the object.
     * \return The current weak count.
     */
    unsigned int getWeakCount() const;

    /*!
     * \brief Retrieves whether the pointed-to object has been deleted.
     */
    bool isEmpty() const ;

    private:

    unsigned int sharedCount_;
    unsigned int weakCount_;

    IDeleter *deleter_;
};



// method definitions

template <typename T>
RefCounter::RefCounter(T *rawPointer)
    : sharedCount_(0), weakCount_(0), deleter_(new RawPtrDeleter<T>(rawPointer))
{}

inline
void RefCounter::grabShared()
{
    ++sharedCount_;
}

inline
void RefCounter::grabWeak()
{
    ++weakCount_;
}

inline
bool RefCounter::dropShared()
{
    if (--sharedCount_ == 0)
    {
        clear();
    }
    return (sharedCount_ == 0) && (weakCount_ == 0);
}

inline
bool RefCounter::dropWeak()
{
    return (--weakCount_ == 0) && (sharedCount_ == 0);
}

inline
unsigned int RefCounter::getSharedCount() const
{
    return sharedCount_;
}

inline
unsigned int RefCounter::getWeakCount() const
{
    return weakCount_;
}

inline
bool RefCounter::isEmpty() const
{
    return deleter_ == NULL;
}

inline
RefCounter::~RefCounter()
{
    clear();
}

inline
void RefCounter::clear()
{
    delete deleter_;
    deleter_ = NULL;
}

} // end namespace rutil

#endif

