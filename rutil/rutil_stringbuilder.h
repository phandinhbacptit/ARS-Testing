/*!
 * \file
 * \author Miroslav Kubik <mkubik2@retia.cz>
 * \brief Header file for \link rutil::StringBuilder \endlink.
 */
#ifndef RUTIL_STRINGBUILDER_H
#define RUTIL_STRINGBUILDER_H

#include <cstdarg> // va_list,...
#include <cstring> // strlen, memcpy
#include <sstream> // stringstream

namespace rutil
{

enum Justify
{
    JLeft = 0,
    JRight
};
typedef enum Justify Justify;

/*!
 * \brief High-performance string builder optimized for repeated usage.
 */
class StringBuilder
{
public:

    /*!
     * A constructor.
     * \param charCapacity ... initial capacity, in characters
     */
    StringBuilder(unsigned int charCapacity = 80);

    /*!
     * A copy constructor. Note that the next field modifiers and stream
     * contents are not copied.
     */
    StringBuilder(const StringBuilder& other);

    /*!
     * A destructor, releases acquired resources.
     */
    ~StringBuilder();

    /*!
     * Assignment operator. Note that the next field modifiers and stream
     * contents are not assigned.
     * \param other ... the string builder to assign
     * \return A reference to this object.
     */
    StringBuilder& operator=(const StringBuilder& other);

    // string building

    /*!
     * Clears the contents.
     */
    void reset();

    /*!
     * Appends a single character.
     * \param character ... the character to append
     */
    void append(char character);

    /*!
     * Appends a null-terminated string.
     * \param string ... the string to append (null termination not included)
     */
    void append(const char *string);

    /*!
     * Appends given number of bytes from given position.
     * \param string ... the starting position
     * \param length ... the number of bytes to append
     */
    void append(const char *string, unsigned int length);

    /*!
     * Appends given string.
     * \param string ... the string to append
     */
    void append(const std::string& string);

    /*!
     * Appends formatted time information.
     * \param format ... strftime format string
     * \param timeInfo ... the time information
     */
    void append(const char *format, const struct tm *timeInfo);

    /*!
     * Appends given object, assuming it has defined the operator writing
     * to a stream.
     * \param object ... the object to append
     */
    template<typename T>
    void append(const T& object);

    /*!
     * Appends formatted string, similarly to printf function.
     * \param format ... printf format string
     */
    void appendVariadic(const char *format, ...);

    /*!
     * Appends formatted string, similarly to vprintf function.
     * \param format ... printf format string
     * \param arguments ... arguments to insert into the string
     */
    void append(const char *format, va_list arguments);

    // result

    /*!
     * Retrieves length of the resulting string.
     * \return The length of the result (not including null termination)
     */
    unsigned int getLength() const;

    /*!
     * Retrieves the resulting string. The returned value is guaranteed
     * to stay valid a non-const method is called.
     * \return A pointer to internally stored string (null-terminated).
     */
    const char *getString() const;

    // stream interface

    /*!
     * Retrieves stream to write to.
     * \return A reference to an internal stream to write to.
     * \see appendStream
     */
    std::ostream &getStream();

    /*!
     * Clears the contents of the stream.
     * \see getStream
     */
    void resetStream();

    /*!
     * Appends the contents of the stream.
     * \see getStream
     */
    void appendStream();

    // field formatting

    /*!
     * Sets the default field formatting. This formatting applies for all
     * the appending methods unless any "next" field parameter is set.
     * \param width ... the field width
     * \param justify ... the field content's alignment
     * \param fill ... the fill character
     */
    void setDefaultField(unsigned int width, Justify justify =
            JLeft, char fill = ' ');

    /*!
     * Retrieves the default field width.
     * \return The default field width.
     */
    unsigned int getDefaultWidth() const;

    /*!
     * Retrieves the default field justification.
     * \return The default field justification.
     */
    Justify getDefaultJustify() const;

    /*!
     * Retrieves the default fill character.
     * \return The default fill character.
     */
    char getDefaultFill() const;

    /*!
     * Sets the field formatting for a single following append call.
     * \param width ... the field width
     * \param justify ... the field content's alignment
     * \param fill ... the fill character
     * \see resetNextField
     */
    void setNextField(unsigned int width, Justify justify = JLeft,
            char fill = ' ');

    /*!
     * Sets width for the next field.
     * \param width ... the field width
     */
    void setNextWidth(unsigned int width);

    /*!
     * Sets justification for the next field.
     * \param justify ... the field content's alignment
     */
    void setNextJustify(Justify justify);

    /*!
     * Sets fill character for the next field.
     * \param fill ... the fill character
     */
    void setNextFill(char fill);

    /*!
     * Cancels any effects of "setNext..." methods.
     * \see setNextField, setNextWidth, setNextJustify, setNextFill
     */
    void resetNextField();

private:

    /*!
     * \brief Structure storing the field parameters - width, justification
     * and the fill character.
     */
    struct Field
    {
        unsigned int width;
        Justify justify;
        char fill;

        Field() : width(0), justify(rutil::JLeft), fill(' ')
        {
        }
    };

    typedef struct Field Field;

    /*!
     * Retrieves field parameters for the next appending.
     * \return A reference to field parameters.
     */
    const Field &getField() const;

    /*!
     * Ensures that given number of characters may be appended without
     * resizing the buffer.
     * \param charCapacity ... the capacity to reserve
     */
    void reserve(unsigned int charCapacity);

    /*!
     * Retrieves current position in the internal buffer.
     * \return The current buffer position.
     */
    char *getPosition() const;

    /*!
     * Retrieves number of characters which can be written to the buffer
     * without resizing.
     * \return The character count.
     */
    unsigned int getFree() const;

    /*!
     * Advances the buffer position given number of characters.
     * \param length ... the length to advance
     */
    unsigned int advance(unsigned int length);

    /*!
     * Resizes the internal buffer to given length. The content is truncated
     * if the length is too small. Note that the buffer needs one character
     * for the null termination of the resulting string.
     * \param size ... the new internal buffer size
     */
    void resize(unsigned int size);

    /*!
     * Inserts any potential fill characters on the left side of a field
     * after(!) the field content is appended.
     * \param length ... the length of the field content
     * \see leftFill
     */
    void insertLeftFill(unsigned int length);

    /*!
     * Appends any potential fill characters on the left side of a field before
     * the field content is appended.
     * \param length ... length of the field content
     */
    void leftFill(unsigned int length);

    /*!
     * Appends any potential fill characters on the right side of a field after
     * the field content is appended.
     * \param length ... length of the field content
     */
    void rightFill(unsigned int length);

    /*!
     * Appends a single character given number of times.
     * \param length ... the number of repetitions
     * \param character ... the character to fill with
     */
    void fill(unsigned int length, char character);

    char *bufferStart;
    unsigned int bufferSize;

    char *bufferPosition;
    unsigned int bufferFree;
    unsigned int bufferFilled;

    Field defaultField;
    Field nextField; // not copied
    bool useNextField; // not copied

    // not copied
    std::stringstream objectStream;
    std::stringstream stream;
};

} // end namespace rutil

#endif /* RUTIL_STRINGBUILDER_H */
