/*!
 * \file
 * \author Miroslav Kubik <mkubik2@retia.cz>
 * \brief Retia Object Notation related classes.
 *
 * Retia Object Notation is a lightweight-text based language similar to JSON.
 * In contrast to JSON it offers possibility for comments on input (C++ style
 * line and block comments) and more compact notation for simple identifiers
 * (without double quotes) - it is effectively a superset of JSON. Suitable
 * for both configuration files and performance non-critical interprocess
 * messaging.
 */
#ifndef RUTIL_RON_H
#define RUTIL_RON_H

#include "rutil_features.h"

#if RUTIL_LIBXML2
#include "libxml/parser.h"
#endif

//#include "rutil_stringbuilder.h"
#include "rutil_safebool.h"
#include "rutil_sharedptr.h"
#include "rutil_stringbuilder.h"
#include "rutil_ostreamstatesaver.h"
#include "rutil_unused.h"

#include <stdint.h>
#include <string.h>

#include <limits> // uint8_t
#include <cmath> // pow
#include <exception>
#include <fstream>
#include <iomanip>
#include <istream>
#include <list>
#include <map>
#include <ostream>
#include <vector>

namespace rutil
{

enum RonCharacterType
{
    RctAlphabetic,
    RctDigit,
    RctLeftBrace,
    RctRightBrace,
    RctLeftBracket,
    RctRightBracket,
    RctComma,
    RctColon,
    RctSlash,
    RctAsterisk,
    RctUnderscore,
    RctBackslash,
    RctPlus,
    RctMinus,
    RctDot,
    RctWhitespace,
    RctDoubleQuote,
    RctSpecial,
    RctEof
};

/*!
 * Helper method for character type recognition. Used by the tokenizer.
 * \param character ... the character to recognize
 * \return The character type.
 */
inline
static RonCharacterType getCharType(char character)
{
    if ((character >= 'a' && character <= 'z') || (character >= 'A'
            && character <= 'Z'))
    {
        return RctAlphabetic;
    }
    if (character >= '0' && character <= '9')
    {
        return RctDigit;
    }
    if (character == ' ' || character == '\t' || character == '\n'
            || character == '\r')
    {
        return RctWhitespace;
    }
    if (character == '[')
    {
        return RctLeftBrace;
    }
    if (character == ']')
    {
        return RctRightBrace;
    }
    if (character == '{')
    {
        return RctLeftBracket;
    }
    if (character == '}')
    {
        return RctRightBracket;
    }
    if (character == '\"')
    {
        return RctDoubleQuote;
    }
    if (character == ',')
    {
        return RctComma;
    }
    if (character == ':')
    {
        return RctColon;
    }
    if (character == '.')
    {
        return RctDot;
    }
    if (character == '/')
    {
        return RctSlash;
    }
    if (character == '\\')
    {
        return RctBackslash;
    }
    if (character == '*')
    {
        return RctAsterisk;
    }
    if (character == '_')
    {
        return RctUnderscore;
    }
    if (character == '+')
    {
        return RctPlus;
    }
    if (character == '-')
    {
        return RctMinus;
    }
    return RctSpecial;
}


enum RonTokenType
{
    RttError = 0,
    RttPlainString,
    RttQuotedString,
    RttNumber,
    RttBoolean,
    RttNull,
    RttLeftBrace,
    RttRightBrace,
    RttLeftBracket,
    RttRightBracket,
    RttComma,
    RttColon,
    RttLineComment,
    RttBlockComment,
    RttDot,
    RttEof
};
typedef enum RonTokenType RonTokenType;

/*!
 * Retrieves printable form of token type.
 * \param type ... the token type
 * \return A null-terminated string.
 */
inline
const char *toString(RonTokenType type)
{
    static const char *typeStrings[] = { "Error", "PlainString",
            "QuotedString", "Number", "Boolean", "Null", "LeftBrace",
            "RightBrace", "LeftBracket", "RightBracket", "Comma", "Colon",
            "LineComment", "BlockComment", "Dot", "EoF" };
    if (type > RttEof) { return "?"; }
    return typeStrings[type];
}


class RonTokenizer;


/*!
 * Class for representing individual RON tokens produced by the tokenizer.
 */
class RonToken
{
public:
    friend class RonTokenizer;

    /*!
     * Constructs the end of input (EoF) token.
     */
    RonToken()
    {
        reset();
    }

    /*!
     * Resets the token to EoF.
     */
    void reset()
    {
        type = RttEof;
        isLine = false;
        stringValue.assign("");
        isInt = true;
        integerValue = 0;
        realValue = 0.0;
        boolean = false;
    }

    /*!
     * Retrieves the token type.
     * \return The token type.
     */
    RonTokenType getType() const { return type; }

    /*!
     * Retrieves the character string attribute of the token. Applies for plain
     * string, quoted string, line comment, block comment and error tokens.
     * Returns empty string for other tokens.
     * \return A character string, may contain null character.
     * \see getStringLength
     */
    const char *getString() const
    {
        if (type == RttPlainString || type == RttQuotedString
                || type == RttLineComment || type == RttBlockComment
                || type == RttError)
        {
            return stringValue.c_str();
        }
        else
        {
            return "";
        }
    }

    /*!
     * Returns the length of the string retrieved via \link RonToken::getString
     * \endlink.
     * \return The length of the string attribute.
     * \see getString
     */
    unsigned int getStringLength() const
    {
        return stringValue.size();
    }

    /*!
     * Returns whether the number attribute is integer (as opposed to floating
     * point). Applies for number tokens, returns \c true for other tokens.
     * \return \c True if the number attribute is integer, \c false otherwise.
     */
    bool isInteger() const
    {
        return (type == RttNumber && isInt);
    }

    /*!
     * Retrieves the integer attribute of number token. Returns zero for other
     * tokens.
     * \return The integer attribute.
     */
    int getInteger() const
    {
        if (type != RttNumber)
        {
            return 0;
        }
        return integerValue;
    }

    /*!
     * Retrieves the floating point attribute of number token. Returns zero
     * for other tokens.
     * \return The floating point attribute.
     */
    double getReal() const
    {
        if (type != RttNumber)
        {
            return 0.0;
        }
        return realValue;
    }

    /*!
     * Retrieves the boolean attribute. Applies for boolean tokens, returns
     * \c false for other tokens.
     * \return The boolean attribute.
     */
    bool getBoolean() const
    {
        if (type != RttBoolean)
        {
            return false;
        }
        return boolean;
    }

    /*!
     * Output operator, writes the token type and potential attribute to
     * the stream.
     * \param o ... the stream to write to
     * \param token ... the token to output
     * \return Reference to the stream.
     */
    friend std::ostream &operator<<(std::ostream &o, const RonToken &token)
    {
        o << toString(token.type);
        if (token.type == RttQuotedString || token.type == RttPlainString
                || token.type == RttLineComment || token.type == RttBlockComment || token.type == RttError)
        {
            const char *str = token.stringValue.c_str();
            o << '(' << str;
            if (strlen(str) < token.stringValue.size())
            {
                o << "\\0...";
            }
            o << ')';
        }
        else if (token.type == RttBoolean)
        {
            o << '(' << token.boolean << ')';
        }
        else if (token.type == RttNumber)
        {
            o << '(';
            if (token.isInt) { o << token.integerValue; }
            else { o << token.realValue; }
            o << ')';
        }
        return o;
    }

private:

    RonTokenType type;
    bool isLine;
    std::string stringValue;
    bool isInt;
    int integerValue;
    double realValue;
    bool boolean;
};


/*!
 * Encodes given Unicode code point using UTF-8 encoding. If \a destination
 * is not specified or NULL, the function just returns the number of bytes
 * necessary for encoding the code point.
 * \param codePoint ... the code point to encode
 * \param destination ... the destination for encoded bytes
 * \return The number of encoded bytes.
 */
inline
unsigned int encodeUtf8(uint16_t codePoint, uint8_t *destination = NULL)
{
    if (codePoint <= 0x7f)
    {
        if (destination)
        {
            destination[0] = codePoint;
        }
        return 1;
    }
    if (codePoint <= 0x7ff)
    {
        if (destination)
        {
            destination[0] = 0xc0; // 1100 0000
            destination[1] = 0x80; // 1000 0000
            destination[0] |= ((codePoint >> 6) & 0x1f); // 5b
            destination[1] |= (codePoint & 0x3f); // 6b
        }
        return 2;
    }
    // codePoint <= 0xffff
    if (destination)
    {
        destination[0] = 0xe0; // 1110 0000
        destination[1] = 0x80;
        destination[2] = 0x80;
        destination[0] |= ((codePoint >> 12) & 0xf); // 4b
        destination[1] |= ((codePoint >> 6) & 0x3f); // 6b
        destination[2] |= (codePoint & 0x3f); // 6b
    }
    return 3;
}

/*!
 * \brief RON lexical analyser.
 *
 * Performs lexical analysis of given UTF-8 encoded Unicode text and produces
 * Retia Object Notation tokens, some of which are attributed. The tokens match
 * the following regular expressions
 * <boolean> := "true" | "false"
 * <null> := "null"
 * <plain-string> := ('a'...'z'|'A'...'Z')('a'...'z'|'A'...'Z'|'_'|<digit>)* - "true" - "false" - "null"
 * <quoted-string> := '"' (<unicode-character> - '\' - '"' | <escape-sequence>)* '"'
 * <number> := [-](0|'1'...'9'<digit>*)['.'<digit><digit>*][('e'|'E')['+'|'-']<digit><digit>*]
 * <left-brace> ::= '['
 * <right-brace> ::= ']'
 * <left-bracket> ::= '{'
 * <right-bracket> ::= '}'
 * <comma> ::= ','
 * <colon> ::= ':'
 * <line-comment> ::= '/' '/' (<unicode-character> - '\n')*
 * <block-comment> ::= '/' '*' <unicode-character>* '*' '/'
 * <dot> ::= '.'
 * where
 * <escape-sequence> ::= '\' ('"' | '\' | '/' | 'b' | 'f' | 'n' | 'r' | 't' | 'u'<hex><hex><hex><hex>)
 * <digit> ::= '0'...'9'
 * <hex> ::= (<digit>| 'a'...'f'| 'A'...'F')
 *
 * White space characters are generally ignored, comments are optionally
 * ignored. <boolean> has a boolean attribute, <number> has an integral or
 * a floating point attribute, <plain-string>, <quoted-string>,
 * <line-comment> and <block-comment> have a character string attribute.
 * A special token with a string attribute is produced on error (RttError).
 * Another special token represents end of the input (RttEof).
 */
class RonTokenizer
{
public:

    /*!
     * Constructor. Creates a new tokenizer.
     */
    RonTokenizer() : skipComments(true)
    {
        setMessage(NULL);
    }

    /*!
     * Sets flag indicating silent skipping of comment tokens. The tokenizer
     * skips comments by default.
     * \param skip ... the flag value
     */
    void setSkipComments(bool skip)
    {
        skipComments = skip;
    }

    /*!
     * Sets the input stream. An alternative to \link RonTokenizer::setMessage
     * \endlink.
     * \param stream ... the input stream
     * \see setMessage
     */
    void setStream(std::istream& stream)
    {
        StringBuilder builder;
        while (stream.good())
        {
            char c = stream.get();
            if (!stream.good()) { break; }
            builder.append(c);
        }
        message.assign(builder.getString(), builder.getLength());
        init();
    }

    /*!
     * Sets the message to tokenize. If \a length is unspecified
     * or zero, it is assumed that message is a null-terminated string.
     * \param message ... the message to tokenize
     * \param length ... the length of the message
     * \see nextToken
     */
    void setMessage(const char *message, unsigned int length = 0)
    {
        if (message == NULL)
        {
            this->message.assign("");
        }
        else
        {
            if (length == 0)
            {
                length = strlen(message);
            }
            this->message.assign(message, length);
        }
        init();
    }

    /*!
     * Parses another token from the message. This method is usually called
     * on demand or until an error or the end of input occurs (indicated
     * via special tokens).
     * \return  A reference to the parsed token.
     */
    const RonToken &nextToken()
    {
        unsigned int state = 0;
        currentToken.type = RttError;

        bool negativeValue = false, negativeExponent = false;
        int exponent = 0;
        double fractionMultiplier = 0.1;
        bool tokenParsed = false;
        uint16_t codePoint;

        while (!tokenParsed)
        {
            switch (state)
            {
                case 0: // root
                    if (character.type == RctWhitespace)
                    {
                        nextChar();
                    }
                    else if (character.type == RctSlash)
                    {
                        state = 1;
                        nextChar();
                    }
                    else if (character.type == RctAlphabetic)
                    {
                        builder.reset();
                        builder.append((char)character.value);
                        state = 5;
                        nextChar();
                    }
                    else if (character.type == RctDigit)
                    {
                        currentToken.isInt = true;
                        negativeValue = false;
                        currentToken.integerValue = digitToValue(character.value);
                        currentToken.realValue = currentToken.integerValue;
                        if (character.value == '0')
                        {
                            state = 7; // leading zero
                        }
                        else
                        {
                            state = 8;
                        }
                        nextChar();
                    }
                    else if (character.type == RctMinus)
                    {
                        currentToken.isInt = true;
                        negativeValue = true;
                        state = 6;
                        nextChar();
                    }
                    else if (character.type == RctDoubleQuote)
                    {
                        builder.reset();
                        state = 14;
                        nextChar();
                    }
                    else if (character.type == RctLeftBrace)
                    {
                        currentToken.type = RttLeftBrace;
                        tokenParsed = true;
                        nextChar();
                    }
                    else if (character.type == RctRightBrace)
                    {
                        currentToken.type = RttRightBrace;
                        tokenParsed = true;
                        nextChar();
                    }
                    else if (character.type == RctLeftBracket)
                    {
                        currentToken.type = RttLeftBracket;
                        tokenParsed = true;
                        nextChar();
                    }
                    else if (character.type == RctRightBracket)
                    {
                        currentToken.type = RttRightBracket;
                        tokenParsed = true;
                        nextChar();
                    }
                    else if (character.type == RctComma)
                    {
                        currentToken.type = RttComma;
                        tokenParsed = true;
                        nextChar();
                    }
                    else if (character.type == RctColon)
                    {
                        currentToken.type = RttColon;
                        tokenParsed = true;
                        nextChar();
                    }
                    else if (character.type == RctDot)
                    {
                        currentToken.type = RttDot;
                        tokenParsed = true;
                        nextChar();
                    }
                    else if (character.type == RctEof)
                    {
                        tokenParsed = true;
                        currentToken.type = RttEof;
                    }
                    else
                    {
                        tokenParsed = true;
                        currentToken.type = RttError;
                        setErrorString("unexpected character '%c'(%u)", character.value, (unsigned int)character.value);
                        nextChar();
                    }
                    break;
                case 1: // after slash (potential comment)
                    if (character.type == RctSlash)
                    {
                        state = 2;
                        builder.reset();
                        nextChar();
                    }
                    else if (character.type == RctAsterisk)
                    {
                        state = 3;
                        builder.reset();
                        nextChar();
                    }
                    else
                    {
                        tokenParsed = true;
                        currentToken.type = RttError;
                        setErrorString("unexpected character '/'");
                    }
                    break;
                case 2: // inside line comment
                    if (character.type != RctEof && character.value != '\n')
                    {
                        if (!skipComments)
                        {
                            builder.append((char)character.value);
                        }
                        nextChar();
                    }
                    else
                    {
                        if (skipComments)
                        {
                            state = 0;
                        }
                        else
                        {
                            tokenParsed = true;
                            currentToken.type = RttLineComment;
                        }
                    }
                    break;
                case 3: // inside block comment
                    if (character.type == RctEof)
                    {
                        tokenParsed = true;
                        currentToken.type = RttError;
                        setErrorString("unexpected EoF inside a block comment");
                    }
                    else if (character.type == RctAsterisk)
                    {
                        state = 4;
                        nextChar();
                    }
                    else
                    {
                        builder.append((char)character.value);
                        nextChar();
                    }
                    break;
                case 4: // after asterisk in a block comment
                    if (character.type == RctEof)
                    {
                        tokenParsed = true;
                        currentToken.type = RttError;
                        setErrorString("unexpected EoF inside a block comment");
                    }
                    else if (character.type == RctSlash)
                    {
                        if (skipComments)
                        {
                            state = 0;
                        }
                        else
                        {
                            tokenParsed = true;
                            currentToken.type = RttBlockComment;
                        }
                        nextChar();
                    }
                    else
                    {
                        builder.append('*');
                        builder.append((char)character.value);
                        state = 3;
                        nextChar();
                    }
                    break;
                case 5: // plain string
                    if (character.type == RctAlphabetic || character.type
                            == RctDigit || character.type == RctUnderscore)
                    {
                        builder.append((char)character.value);
                        nextChar();
                    }
                    else
                    {
                        if (strcmp(builder.getString(), "true") == 0)
                        {
                            currentToken.type = RttBoolean;
                            currentToken.boolean = true;
                        }
                        else if (strcmp(builder.getString(), "false") == 0)
                        {
                            currentToken.type = RttBoolean;
                            currentToken.boolean = false;
                        }
                        else if (strcmp(builder.getString(), "null") == 0)
                        {
                            currentToken.type = RttNull;
                        }
                        else
                        {
                            currentToken.type = RttPlainString;
                        }
                        tokenParsed = true;
                    }
                    break;
                case 6: // after minus
                    if (character.type != RctDigit)
                    {
                        tokenParsed = true;
                        currentToken.type = RttError;
                        setErrorString("unexpected character or EoF following '-'");
                    }
                    else
                    {
                        currentToken.integerValue = digitToValue(character.value);
                        currentToken.realValue = currentToken.integerValue;
                        if (character.value == '0')
                        {
                            state = 7;
                        }
                        else
                        {
                            state = 8;
                        }
                        nextChar();
                    }
                    break;
                case 7: // after leading zero
                    if (character.type == RctDot)
                    {
                        currentToken.isInt = false;
                        state = 9;
                        nextChar();
                    }
                    else if (character.value == 'e' || character.value == 'E')
                    {
                        negativeExponent = false;
                        state = 11;
                        nextChar();
                    }
                    else
                    {
                        currentToken.type = RttNumber;
                        tokenParsed = true;
                    }
                    break;
                case 8: // after one non-zero digit
                    if (character.type == RctDigit)
                    {
                        currentToken.integerValue *= 10;
                        currentToken.realValue *= 10.0;
                        currentToken.integerValue += digitToValue(character.value);
                        currentToken.realValue += digitToValue(character.value);
                        nextChar();
                    }
                    else if (character.type == RctDot)
                    {
                        currentToken.isInt = false;
                        state = 9;
                        nextChar();
                    }
                    else if (character.value == 'e' || character.value == 'E')
                    {
                        negativeExponent = false;
                        state = 11;
                        nextChar();
                    }
                    else
                    {
                        tokenParsed = true;
                        currentToken.type = RttNumber;
                        if (negativeValue)
                        {
                            currentToken.integerValue = -currentToken.integerValue;
                            currentToken.realValue = -currentToken.realValue;
                        }
                    }
                    break;
                case 9: // after dot
                    if (character.type != RctDigit)
                    {
                        tokenParsed = true;
                        currentToken.type = RttError;
                        setErrorString("unexpected character or EoF following '.' (expecting a digit)");
                    }
                    else
                    {
                        currentToken.realValue += fractionMultiplier * digitToValue(character.value);
                        fractionMultiplier /= 10;
                        state = 10;
                        nextChar();
                    }
                    break;
                case 10: // after first fraction digit
                    if (character.type == RctDigit)
                    {
                        currentToken.realValue += fractionMultiplier * digitToValue(
                                character.value);
                        fractionMultiplier /= 10.0;
                        nextChar();
                    }
                    else if (character.value == 'e' || character.value == 'E')
                    {
                        negativeExponent = false;
                        state = 11;
                        nextChar();
                    }
                    else
                    {
                        tokenParsed = true;
                        currentToken.type = RttNumber;
                        if (negativeValue)
                        {
                            currentToken.integerValue = -currentToken.integerValue;
                            currentToken.realValue = -currentToken.realValue;
                        }
                    }
                    break;
                case 11: // after e or E
                    if (character.type == RctDigit)
                    {
                        exponent = digitToValue(character.value);
                        state = 12;
                        nextChar();
                    }
                    else if (character.type == RctPlus)
                    {
                        state = 13;
                        nextChar();
                    }
                    else if (character.type == RctMinus)
                    {
                        negativeExponent = true;
                        state = 13;
                        nextChar();
                    }
                    else
                    {
                        tokenParsed = true;
                        currentToken.type = RttError;
                        setErrorString("unexpected character or EoF following 'e' or 'E' (expecting sign or a digit)");
                    }
                    break;
                case 12: // after first exponent digit
                    if (character.type == RctDigit)
                    {
                        exponent *= 10;
                        exponent += digitToValue(character.value);
                        nextChar();
                    }
                    else
                    {
                        tokenParsed = true;
                        currentToken.type = RttNumber;
                        if (negativeValue)
                        {
                            currentToken.integerValue = -currentToken.integerValue;
                            currentToken.realValue = -currentToken.realValue;
                        }
                        if (negativeExponent)
                        {
                            exponent = -exponent;
                        }
                        currentToken.integerValue *= (int)pow(10, exponent);
                        currentToken.realValue *= pow(10.0, exponent);
                    }
                    break;
                case 13: // after exponent sign
                    if (character.type != RctDigit)
                    {
                        tokenParsed = true;
                        currentToken.type = RttError;
                        setErrorString("unexpected character or EoF following exponent sign (expecting a digit)");
                    }
                    else
                    {
                        exponent = digitToValue(character.value);
                        state = 12;
                        nextChar();
                    }
                    break;
                case 14: // inside double quoted string
                    if (character.type == RctEof)
                    {
                        tokenParsed = true;
                        currentToken.type = RttError;
                        setErrorString("unexpected EoF inside a quoted string");
                    }
                    else if (character.type == RctBackslash)
                    {
                        state = 15;
                        nextChar();
                    }
                    else if (character.type == RctDoubleQuote)
                    {
                        tokenParsed = true;
                        currentToken.type = RttQuotedString;
                        nextChar();
                    }
                    else
                    {
                        builder.append((char)character.value);
                        nextChar();
                    }
                    break;
                case 15: // after backslash
                    if (character.type == RctDoubleQuote || character.type
                            == RctSlash || character.type == RctBackslash)
                    {
                        state = 14;
                        builder.append((char)character.value);
                        nextChar();
                    }
                    else if (character.value == 'b')
                    {
                        state = 14;
                        builder.append('\b');
                        nextChar();
                    }
                    else if (character.value == 'f')
                    {
                        state = 14;
                        builder.append('\f');
                        nextChar();
                    }
                    else if (character.value == 'n')
                    {
                        state = 14;
                        builder.append('\n');
                        nextChar();
                    }
                    else if (character.value == 'r')
                    {
                        state = 14;
                        builder.append('\r');
                        nextChar();
                    }
                    else if (character.value == 't')
                    {
                        state = 14;
                        builder.append('\t');
                        nextChar();
                    }
                    else if (character.value == 'u')
                    {
                        state = 16;
                        nextChar();
                    }
                    else
                    {
                        tokenParsed = true;
                        currentToken.type = RttError;
                        setErrorString("unrecognized escape sequence");
                    }
                    break;
                case 16: // after /u escape sequence
                    codePoint = 0;
                    for (unsigned int i = 0; i < 4; ++i)
                    {
                        if (character.type == RctEof)
                        {
                            tokenParsed = true;
                            currentToken.type = RttError;
                            setErrorString("unexpected EoF in \\u escape sequence");
                            break;
                        }
                        else if (isHex(character.value))
                        {
                            codePoint *= 16;
                            codePoint += hexToValue((char)character.value);
                            nextChar();
                            if (i == 3)
                            {
                                uint8_t encodedUtf8[4];
                                unsigned int bytes = encodeUtf8(codePoint, encodedUtf8);
                                for (unsigned int i = 0; i < bytes; ++i)
                                {
                                    builder.append((char)encodedUtf8[i]);
                                }
                                state = 14;
                                break;
                            }
                        }
                        else
                        {
                            tokenParsed = true;
                            currentToken.type = RttError;
                            setErrorString("unexpected character in \\u escape sequence (expecting hexadecimal digit)");
                            break;
                        }
                    }
                    break;
                default:
                    tokenParsed = true;
                    currentToken.type = RttError;
                    setErrorString("unrecognized tokenizer state");
                    break;
            }
        };

        RonTokenType type = currentToken.type;
        if (type == RttPlainString || type == RttQuotedString
                || type == RttLineComment || type == RttBlockComment
                || type == RttError)
        {
           currentToken.stringValue.assign(builder.getString(), builder.getLength());
        }

        return currentToken;
    }

    /*!
     * Retrieves the current row, starting with 1.
     * \return The row number.
     */
    unsigned int getRow() const
    {
        return row;
    }

    /*!
     * Retrieves the current column, starting with 1.
     * \return The column number.
     */
    unsigned int getColumn() const
    {
        return column;
    }

private:

    void init()
    {
        readPosition = 0;
        row = 1;
        column = 1;
        nextChar();
        currentToken.reset();
    }

    void setErrorString(const char *format, ...)
    {
        builder.reset();
        builder.appendVariadic("%u:%u: ", row, column);
        va_list arguments;
        va_start(arguments, format);
        builder.append(format, arguments);
        va_end(arguments);
    }

    void nextChar()
    {
        if (character.value == '\n')
        {
            ++row;
            column = 1;
        }
        if (readPosition < message.size())
        {
            character = CharacterInfo(message[readPosition]);
            ++readPosition;
            ++column;
        }
        else
        {
            // EoF
            character = CharacterInfo();
        }
    }

    int digitToValue(uint8_t asciiDigit) const
    {
        if (asciiDigit >= '0' && asciiDigit <= '9')
        {
            return asciiDigit - '0';
        }
        return 0;
    }

    int hexToValue(uint8_t asciiHex) const
    {
        if (asciiHex >= '0' && asciiHex <= '9') { return asciiHex - '0'; }
        if (asciiHex >= 'a' && asciiHex <= 'f') { return asciiHex - 'a' + 10; }
        if (asciiHex >= 'A' && asciiHex <= 'F') { return asciiHex - 'A' + 10; }
        return 0;
    }

    bool isHex(uint8_t asciiChar) const
    {
        return (asciiChar >= '0' && asciiChar <= '9') || (asciiChar >= 'a'
                && asciiChar <= 'f') || (asciiChar >= 'A' && asciiChar <= 'F');
    }

    class CharacterInfo
    {
    public:
        CharacterInfo(uint8_t character) :
            value(character), type(getCharType(character))
        {
        }

        CharacterInfo() :
            value('\0'), type(RctEof)
        {
        }

        uint8_t value;
        RonCharacterType type;
    };

    RonToken currentToken;

    StringBuilder builder;

    CharacterInfo character;

    unsigned int readPosition;
    unsigned int row, column;

    std::string message;

    bool skipComments;
};


enum RonNodeType
{
    RntDummy = 0,
    RntObject,
    RntArray,
    RntNumber,
    RntIdentifier,
    RntBoolean,
    RntNull,
    RntComment
};
typedef enum RonNodeType RonNodeType;

/*!
 * Retrieves printable form of node type.
 * \param type ... the node type
 * \return A null-terminated string.
 */
inline
const char *toString(RonNodeType type)
{
    static const char *typeStrings[] = { "Dummy", "Object",
            "Array", "Number", "Identifier", "Boolean", "Null", "Comment" };
    if (type > RntComment) { return "?"; }
    return typeStrings[type];
}

inline
bool isSimple(RonNodeType nodeType)
{
    return nodeType != RntObject && nodeType != RntArray;
}

class IRonNode;
typedef SharedPtr<IRonNode> HRonNode;


/*!
 * Base class for asbtract syntax tree nodes. A dummy node with no-op methods
 * if instantiated.
 *
 * Note that the array, object, identifier, etc. interface methods are
 * described in the way the subclasses behave. When calling a method which does
 * not correspond with the node type, the no-op implementation of this base
 * class is executed (if a return value is required, a default value is
 * returned - a dummy node, zero, false, empty string,...).
 */
class IRonNode : public SafeBool<IRonNode>, public Noncopyable
{
public:

    /*!
     * A special instance which is returned when accessing non-existent child
     * nodes.
     */
    static IRonNode dummy;

    enum OutputFormat
    {
        OfRon = 0,
        OfJson,
        OfXml,
        OfCount
    };
    typedef enum OutputFormat OutputFormat;

    /*!
     * A virtual destructor.
     */
    virtual ~IRonNode() {}

    /*!
     * A "virtual" deep copy method.
     */
    virtual HRonNode clone() const { return HRonNode(new IRonNode()); }

    /*!
     * Retrieves the node type. To be overriden in subclasses.
     * \return The node type.
     */
    virtual RonNodeType getType() const { return RntDummy; }

    // safe bool
    /*!
     * Tests whether the node is a valid node (not a dummy). Enables using
     * the nodes in boolean conditions in a way similar to pointers, see
     * safe bool idiom. Not to be confused with \link asBoolean \endlink method
     * which retrieves the value of boolean nodes.
     */
    bool toBool() const
    {
        return getType() != RntDummy;
    }

    /*!
     * Tests for node equality. The nodes are equal when they are of the same
     * type and contain equal values or equal child nodes.
     * \param other ... the node to compare with
     * \return \c True if the nodes are equal, \c false otherwise.
     */
    bool operator==(const IRonNode &other) const
    {
        RonNodeType type = getType();
        if (type != other.getType()) { return false; }

        switch (type)
        {
            case RntDummy: return true;
            case RntObject:
            {
                std::list<std::string> attr = getAttributes();
                if (attr.size() != other.getAttributes().size()) { return false; }
                for (std::list<std::string>::const_iterator it = attr.begin(); it != attr.end(); ++it)
                {
                    const IRonNode &n1 = (*this)[*it];
                    const IRonNode &n2 = other[*it];
                    if (n1 != n2)
                    {
                        return false;
                    }
                }
                return true;
            }
            case RntArray:
            {
                if (getSize() != other.getSize()) { return false; }
                for (unsigned int i = 0; i < getSize(); ++i)
                {
                    if ((*this)[i] != other[i]) { return false; }
                }
                return true;
            }
            case RntNumber:
                if (isInteger() && other.isInteger())
                {
                    return asInteger() == other.asInteger();
                }
                return asReal() == other.asReal();
            case RntComment:
                if (isLine() != other.isLine()) { return false; }
                // fall-through
            case RntIdentifier:
                if (getLength() != other.getLength()) { return false; }
                return memcmp(asString(), other.asString(), getLength()) == 0;
            case RntBoolean:
                return asBoolean() == other.asBoolean();
            case RntNull:
                return true;
        }
        return false;
    }

    /*!
     * Tests for node non-equality.
     * \param other ... the node to compare with
     * \return \c True if the nodes are not equal, \c false otherwise.
     */
    bool operator!=(const IRonNode &other) const
    {
        return !(*this==other);
    }

    /*!
     * Resets the node, removing the child nodes or setting the default value.
     */
    virtual void clear() {}

    // object/array interface
    /*!
     * Retrieves the number of child nodes (object attributes or array items).
     * \param The number of child nodes.
     */
    virtual unsigned int getSize() const
    {
       return 0;
    }

    // object interface

    /*!
     *
     * Accesses given attribute. Returns a dummy node when the object does not
     * have such attribute. Can not be used for inserting.
     * \param name ... the attribute name
     * \return Reference to the attribute.
     */
    virtual const IRonNode &operator[](const std::string &name) const
    {
        R_UNUSED(name);
        return dummy;
    }

    /*!
     * Non-const version of the operator.
     */
    virtual IRonNode &operator[](const std::string &name)
    {
        R_UNUSED(name);
        return dummy;
    }

    /*!
     * Removes given attribute.
     * \param attribute ... the attribute name
     */
    virtual void removeAttribute(const std::string &name)
    {
        R_UNUSED(name);
    }

    /*!
     * Sets given attribute.
     * \param name ... the attribute name
     * \param node ... the attribute
     */
    virtual void setAttribute(const std::string &name, const HRonNode &node)
    {
        R_UNUSED(name);
        R_UNUSED(node);
    }

    /*!
     * Retrieves given attribute. Returns an empty handle when the object does
     * not have such attribute.
     * \param attribute ... the attribute name
     * \return Handle to the attribute.
     */
    virtual HRonNode getAttribute(const std::string &name) const
    {
        R_UNUSED(name);
        return HRonNode();
    }

    /*!
     * Retrieves the list of attribute names.
     * \return The attribute names.
     */
    virtual std::list<std::string> getAttributes() const
    {
        return std::list<std::string>();
    }

    // array interface

    /*!
     * Accesses given array item with given index. Returns a dummy node when
     * there is no such item (index out of bounds). Can not be used for
     * inserting.
     * \param index ... the item index
     * \return Reference to the item.
     */
    virtual const IRonNode &operator[](unsigned int index) const
    {
        R_UNUSED(index);
        return dummy;
    }

    /*!
     * Non-const version of the operator.
     */
    virtual IRonNode &operator[](unsigned int index)
    {
        R_UNUSED(index);
        return dummy;
    }

    /*!
     * Adds an item to the end of the array.
     * \param node ... the item to add
     */
    virtual void pushBack(const HRonNode &node)
    {
        R_UNUSED(node);
    }

    /*!
     * Removes an item from the end of the array.
     */
    virtual void popBack() {}

    /*!
     * Retrieves item with given index. Returns an empty handle when there is
     * no such item.
     * \param index ... the item's index
     * \return Handle to the item.
     */
    virtual HRonNode getItem(unsigned int index) const
    {
        R_UNUSED(index);
        return HRonNode();
    }

    // number interface

    /*!
     * Tests whether the number node is integer.
     * \return \c True if the number node is integer, \c false otherwise.
     */
    virtual bool isInteger() const { return true; }

    /*!
     * Retrieves the integer value of the number node.
     * \param val ... the value to return if this is not a number node
     * \return The integer value.
     */
    virtual int asInteger(int val = 0) const { return val; }

    /*!
     * Retrieves the floating point value of the number node.
     * \param val ... the value to return if this is not a number node
     * \return The floating point value.
     */
    virtual double asReal(double val = 0.0) const { return val; }

    /*!
     * Sets the integer value of the number node.
     * \param value ... the value to set
     */
    virtual void setNumber(int value) { R_UNUSED(value); }

    /*!
     * Sets the floating point value of the number node.
     * \param value ... the value to set
     */
    virtual void setNumber(double value) { R_UNUSED(value); }

    // identifier/comment interface

    /*!
     * Retrieves the string value of identifier or comment nodes.
     * \param val ... the value to return if this node is not identifier or comment
     * \return The string, may contain null character.
     * \see getLength
     */
    virtual const char *asString(const char *val = "") const { return val; }

    /*!
     * Retrieves the length of the string value.
     * \return The length of the string value.
     * \see asString
     */
    virtual unsigned int getLength() const { return 0; }

    // identifier interface

    /*!
     * Sets the identifier string value. If \a length is zero, it is assumed
     * that \a string is null-terminated.
     * \param string ... the string value
     * \param length ... the length of the string
     */
    virtual void setIdentifier(const char *string, unsigned int length = 0)
    {
        R_UNUSED(string);
        R_UNUSED(length);
    }

    // comment interface

    /*!
     * Tests whether the comment node is a line (as opposed to a block).
     * \return \c True for line comment, \c false otherwise.
     */
    virtual bool isLine() const { return true; }

    /*!
     * Sets the comment node string value. If \a length is zero, it is assumed,
     * that \a string is null-terminated.
     * \param comment ... the string value
     * \param line ... indication of line comment
     * \param length ... the length of the comment
     */
    virtual void setComment(const char *comment, bool line, unsigned int length = 0)
    {
        R_UNUSED(comment);
        R_UNUSED(line);
        R_UNUSED(length);
    }

    // boolean interface

    /*!
     * Retrieves the boolean value of the boolean node.
     * \param val ... the value to return if this is not a boolean node
     * \return The boolean value.
     */
    virtual bool asBoolean(bool val = false) const { return val; }

    /*!
     * Sets the boolean value of the boolean node.
     * \param value ... the value to set
     */
    virtual void setBoolean(bool value)
    {
        R_UNUSED(value);
    }

    /*!
     * Output operator. Serializes the node to a stream.
     * \param o ... the stream to write to
     * \param node ... the node to output
     * \return Reference to the stream.
     */
    friend std::ostream &operator<<(std::ostream &o, const IRonNode &node)
    {
        node.emitRON(o); //VTC HERE
        return o;
    }

    /*!
     * Serializes the node to given stream. May be used to write pure JSON
     * output (without comments and unquoted identifiers) or XML output.
     * \param o ... the stream to write to
     * \param indent ... the current indentation level
     * \param format ... the output format
     */
    virtual void emitRON(std::ostream &o, unsigned int indent = 0, OutputFormat format = OfRon) const
    {//VTC HERE
        R_UNUSED(o);
        R_UNUSED(indent);
        R_UNUSED(format);
    }

protected:

    std::ostream &indentLine(std::ostream &o, unsigned int indent) const
    {
        for (unsigned int i = 0; i < indent; ++i)
        {
            o << "  ";
        }
        return o;
    }
};


inline
bool isSimple(const IRonNode &node)
{
    RonNodeType type = node.getType();
    switch (type)
    {
        case RntObject: return node.getSize() == 0;
        case RntArray:
        {
            bool simple = true;
            for (unsigned int i = 0; i < node.getSize(); ++i)
            {
                if (!isSimple(node[i]))
                {
                    simple = false;
                    break;
                }
            }
            return simple;
        }
        default: return true;
    }
}


/*!
 * Returns whether it is necessary to enclose the identifier with double
 * quotes (as opposed to printing as a plain string).
 * \param identifier ... the identifier to test
 * \return \c True if the double quotes are necessary, \c false otherwise.
 */
inline
bool hasDoubleQuotes(const std::string &identifier)
{
    if (identifier.size() == 0) { return true; }
    for (unsigned int i = 0; i < identifier.size(); ++i)
    {
        RonCharacterType type = getCharType(identifier[i]);
        if (i == 0)
        {
            if (type != RctAlphabetic)
            {
                return true;
                break;
            }
        }
        else
        {
            if (type != RctAlphabetic && type != RctDigit
                    && type != RctUnderscore)
            {
                return true;
                break;
            }
        }
    }
    return false;
}


/*!
 * Object nodes represent an attributed object. The attributes (child nodes)
 * are accessed via identifier.
 */
class RonObjectNode : public IRonNode
{
public:

    virtual HRonNode clone() const
    {
        RonObjectNode *copy = new RonObjectNode();
        for (AttributeMap::const_iterator it = attributes.begin(); it != attributes.end(); ++it)
	{
	    copy->setAttribute(it->first, it->second->clone());
	}
	return HRonNode(copy);
    }

    virtual RonNodeType getType() const { return RntObject; }

    virtual bool isDummy() const { return false; }

    virtual void clear()
    {
        attributes.clear();
    }

    // object/array interface

    virtual unsigned int getSize() const
    {
        return attributes.size();
    }

    // object interface

    virtual const IRonNode &operator[](const std::string &name) const
    {
        AttributeMap::const_iterator it = attributes.find(name);
        return it != attributes.end() ? *it->second : dummy;
    }

    virtual IRonNode &operator[](const std::string &name)
    {
        AttributeMap::iterator it = attributes.find(name);
        return it != attributes.end() ? *it->second : dummy;
    }

    using IRonNode::operator[]; // reintroducing hidden method

    virtual void removeAttribute(const std::string &name)
    {
        attributes.erase(name);
    }

    virtual void setAttribute(const std::string &name, const HRonNode &node)
    {
        attributes.erase(name);
        if (node)
        {
            attributes[name] = node;
        }
    }

    virtual HRonNode getAttribute(const std::string &name) const
    {
        AttributeMap::const_iterator it = attributes.find(name);
        return it != attributes.end() ? it->second : HRonNode();
    }

    virtual std::list<std::string> getAttributes() const
    {
        std::list<std::string> attr;
        for (AttributeMap::const_iterator it = attributes.begin(); it != attributes.end(); ++it)
        {
            attr.push_back(it->first);
        }
        return attr;
    }

    virtual void emitRON(std::ostream &o, unsigned int indent = 0, OutputFormat format = OfRon) const
    {
        if (format == OfRon || format == OfJson) { emitRONOn(o, indent, format); }
        else if (format == OfXml) { emitRONXml(o, indent); }
    }

private:

    void emitRONOn(std::ostream &o, unsigned int indent = 0, OutputFormat format = OfRon) const
    {
        indentLine(o, indent) << '{';
        std::list<std::string> attr = getAttributes();
        if (attr.size() > 0)
        {
            bool first = true;
            for (std::list<std::string>::const_iterator it = attr.begin(); it != attr.end(); ++it)
            {
                if (!first)
                {
                    o << ',';
                }
                o << '\n';
                indentLine(o, indent + 1);
                bool quotes = (format == OfJson) || hasDoubleQuotes(*it);
                if (quotes)
                {
                    o << '"';
                }
                o << *it;
                if (quotes)
                {
                    o << '"';
                }
                o << ':';
                const IRonNode &item = (*this)[*it];
                bool simple = isSimple(item);
                o << (simple ? ' ' : '\n');
                item.emitRON(o, simple ? 0 : indent + 1, format);
                first = false;
            }
            o << '\n';
        }
        if (attr.size() > 0)
        {
            indentLine(o, indent);
        }
        o << '}';

    }

    void emitRONXml(std::ostream &o, unsigned int indent = 0) const
    {
        std::list<std::string> attr = getAttributes();
        for (std::list<std::string>::const_iterator it = attr.begin(); it != attr.end(); ++it)
        {
            indentLine(o, indent) << '<' << *it << ">";
            const IRonNode &item = (*this)[*it];
            bool simple = isSimple(item.getType());
            if (!simple) { o << '\n'; }
            item.emitRON(o, simple ? 0 : indent + 1, OfXml);
            indentLine(o, simple ? 0 : indent) << "</" << *it << ">\n";
        }
    }

    typedef std::map<std::string, HRonNode> AttributeMap;
    AttributeMap attributes;
};

typedef SharedPtr<RonObjectNode> HRonObjectNode;


/*!
 * Array nodes represent a linear sequence of nodes. The child nodes are
 * accessed via index.
 */
class RonArrayNode : public IRonNode
{
public:

    virtual HRonNode clone() const
    {
        RonArrayNode *copy = new RonArrayNode();
	for (unsigned int i = 0; i < items.size(); ++i)
	{
	    copy->pushBack(items[i]->clone());
	}
	return HRonNode(copy);
    }

    virtual RonNodeType getType() const { return RntArray; }

    virtual bool isDummy() const { return false; }

    virtual void clear()
    {
        items.clear();
    }

    // object/array interface

    virtual unsigned int getSize() const
    {
        return items.size();
    }

    // array interface

    virtual const IRonNode &operator[](unsigned int index) const
    {
        if (index >= items.size()) { return dummy; }
        return *items[index];
    }

    virtual IRonNode &operator[](unsigned int index)
    {
        if (index >= items.size()) { return dummy; }
        return *items[index];
    }

    using IRonNode::operator[]; // reintroducing hidden method

    virtual void pushBack(const HRonNode &node)
    {
        if (!node) { return; }
        items.push_back(node);
    }

    virtual void popBack()
    {
        items.pop_back();
    }

    virtual HRonNode getItem(unsigned int index) const
    {
        return index < items.size() ? items[index] : HRonNode();
    }

    virtual void emitRON(std::ostream &o, unsigned int indent = 0, OutputFormat format = OfRon) const
    {
        if (format == OfRon || format == OfJson) { emitRONOn(o, indent, format); }
        else if (format == OfXml) { emitRONXml(o, indent); }
    }

private:

    void emitRONOn(std::ostream &o, unsigned int indent = 0, OutputFormat format = OfRon) const
    {
        bool simple = isSimple(*this);
        indentLine(o, indent) << '[';
        if (getSize() > 0)
        {
            bool first = true;
            for (unsigned int i = 0; i < getSize(); ++i)
            {
                if (!first)
                {
                    o << ',';
                }
                const IRonNode &item = (*this)[i];
                o << (simple ? ' ' : '\n');
                item.emitRON(o, simple ? 0 : indent + 1, format);
                first = false;
            }
            if (!simple)
            {
                o << '\n';
                indentLine(o, indent);
            }
            else
            {
                o << ' ';
            }
        }
        o << ']';
    }

    void emitRONXml(std::ostream &o, unsigned int indent = 0) const
    {
        for (unsigned int i = 0; i < getSize(); ++i)
        {
            indentLine(o, indent) << "<item>";
            const IRonNode &item = (*this)[i];
            bool simple = isSimple(item.getType());
            if (!simple) { o << '\n'; }
            item.emitRON(o, simple ? 0 : indent + 1, OfXml);
            indentLine(o, simple ? 0 : indent) << "</item>\n";
        }
    }

    typedef std::vector<HRonNode> ItemArray;
    ItemArray items;
};

typedef SharedPtr<RonArrayNode> HRonArrayNode;


/*!
 * Number nodes represent a numeric value, either integer or a floating point.
 */
class RonNumberNode : public IRonNode
{
public:
    RonNumberNode(int value = 0)
    {
        setNumber(value);
    }

    RonNumberNode(double value)
    {
        setNumber(value);
    }

    virtual HRonNode clone() const
    {
        if (isInt)
	{
	    return HRonNode(new RonNumberNode(intValue));
	}
	else
	{
	    return HRonNode(new RonNumberNode(realValue));
	}
    }

    virtual RonNodeType getType() const { return RntNumber; }

    virtual bool isDummy() const { return false; }

    virtual void clear()
    {
        isInt = true;
        intValue = 0;
        realValue = 0.0;
    }

    // number interface

    virtual void setNumber(int value)
    {
        isInt = true;
        intValue = value;
        realValue = value;
    }

    virtual void setNumber(double value)
    {
        isInt = false;
        realValue = value;
        double rounded = floor(value + 0.5);
        if (rounded > std::numeric_limits<int>::max())
        {
            intValue = std::numeric_limits<int>::max();
            return;
        }
        if (rounded < std::numeric_limits<int>::min())
        {
            intValue = std::numeric_limits<int>::min();
            return;
        }
        intValue = (int)rounded;
    }

    virtual bool isInteger() const { return isInt; }

    virtual int asInteger(int val = 0) const
    {
        R_UNUSED(val);
        return intValue;
    }

    virtual double asReal(double val = 0) const
    {
        R_UNUSED(val);
        return realValue;
    }

    virtual void emitRON(std::ostream &o, unsigned int indent = 0, OutputFormat format = OfRon) const
    {
        R_UNUSED(format);
        indentLine(o, indent);
        if (isInt)
        {
            o << intValue;
        }
        else
        {
            OstreamStateSaver saver(o);
            o.setf(std::ios::showpoint | std::ios::fixed);
            o.precision(2);
            o << realValue;
        }
    }

private:

    bool isInt;
    int intValue;
    double realValue;
};

typedef SharedPtr<RonNumberNode> HRonNumberNode;


/*!
 * Identifier nodes represent a character string.
 */
class RonIdentifierNode : public IRonNode
{
public:
    RonIdentifierNode(const char *identifier = NULL, unsigned int length = 0) : doubleQuoted(false)
    {
        setIdentifier(identifier, length);
    }

    virtual HRonNode clone() const
    {
        return HRonNode(new RonIdentifierNode(identifier.c_str()));
    }

    virtual RonNodeType getType() const { return RntIdentifier; }

    virtual bool isDummy() const { return false; }

    virtual void clear()
    {
        setIdentifier("");
    }

    // identifier interface

    virtual const char *asString(const char *val = "") const
    {
        R_UNUSED(val);
        return identifier.c_str();
    }

    virtual void setIdentifier(const char *string, unsigned int length = 0)
    {
        if (string)
        {
            if (length == 0) { length = strlen(string); }
            identifier.assign(string, length);
        }
        else
        {
            identifier.assign("");
        }
        doubleQuoted = hasDoubleQuotes(identifier);
    }

    virtual unsigned int getLength() const { return identifier.size(); }

    virtual void emitRON(std::ostream &o, unsigned int indent = 0, OutputFormat format = OfRon) const
    {
        indentLine(o, indent);
        if (format == OfJson || ((format == OfRon) && doubleQuoted))
        {
            o << '"';
        }
        o << identifier;
        if (format == OfJson || ((format == OfRon) && doubleQuoted))
        {
            o << '"';
        }
    }

private:

    bool doubleQuoted;
    std::string identifier;
};

typedef SharedPtr<RonIdentifierNode> HRonIdentifierNode;


/*!
 * Boolean nodes represent a boolean value.
 */
class RonBooleanNode : public IRonNode
{
public:
    RonBooleanNode(bool value = false) : value(value) {}

    virtual HRonNode clone() const { return HRonNode(new RonBooleanNode(value)); }

    virtual RonNodeType getType() const { return RntBoolean; }

    virtual bool isDummy() const { return false; }

    virtual void clear() { value = false; }

    // boolean interface

    virtual bool asBoolean(bool val = false) const { R_UNUSED(val); return value; }

    virtual void setBoolean(bool value) { this->value = value; }

    virtual void emitRON(std::ostream &o, unsigned int indent = 0, OutputFormat format = OfRon) const
    {
        R_UNUSED(format);
        indentLine(o, indent);
        o << (value ? "true" : "false");
    }

private:

    bool value;
};

typedef SharedPtr<RonBooleanNode> HRonBooleanNode;


/*!
 * Null nodes represent a null value.
 */
class RonNullNode : public IRonNode
{
public:

    virtual HRonNode clone() const { return HRonNode(new RonNullNode()); }

    virtual RonNodeType getType() const { return RntNull; }

    virtual bool isDummy() const { return false; }

    virtual void emitRON(std::ostream &o, unsigned int indent = 0, OutputFormat format = OfRon) const
    {
        R_UNUSED(format);
        indentLine(o, indent);
        o << "null";
    }
};

typedef SharedPtr<RonNullNode> HRonNullNode;


/*!
 * Comment nodes represent a line or block comments.
 */
class RonCommentNode : public IRonNode
{
public:
    RonCommentNode(const char *comment, bool line, unsigned int length = 0)
    {
        setComment(comment, line, length);
    }
    
    virtual HRonNode clone() const { return HRonNode(new RonCommentNode(comment.c_str(), line)); }

    virtual RonNodeType getType() const
    {
        return RntComment;
    }

    virtual bool isDummy() const
    {
        return false;
    }

    virtual void clear() { setComment("", true); }

    // comment interface

    virtual const char *asString(const char *val = "") const
    {
        R_UNUSED(val);
        return comment.c_str();
    }

    virtual void setComment(const char *comment, bool line, unsigned int length = 0)
    {
        this->line = line;
        if (comment)
        {
            if (length == 0) { length = strlen(comment); }
            this->comment.assign(comment, length);
        }
        else
        {
            this->comment.assign("");
        }
    }

    virtual unsigned int getLength() const { return comment.size(); }

    virtual bool isLine() const
    {
        return line;
    }

    virtual void emitRON(std::ostream &o, unsigned int indent = 0, OutputFormat format = OfRon) const
    {
        if (format == OfRon || format == OfJson)
        {
            if (line)
            {
                indentLine(o, indent) << "//" << comment << '\n';
            }
            else
            {
                o << "/*" << comment << "*/";
            }
        }
        else if (format == OfXml)
        {
            if (line)
            {
                indentLine(o, indent) << "<!--" << comment << "-->\n";
            }
            else
            {
                o << "<!--\n" << comment << "\n-->\n";
            }
        }
    }

private:

    bool line;
    std::string comment;
};

typedef SharedPtr<RonCommentNode> HRonCommentNode;


// factory functions for abstract syntax tree nodes

/*!
 * Creates an integer number node.
 * \param value ... the integer attribute
 * \return Handle to the node.
 */
inline
HRonNumberNode createNode(int value)
{
    return HRonNumberNode(new RonNumberNode(value));
}

/*!
 * Creates a floating point number node.
 * \param value ... the floating point attribute
 * \return Handle to the node.
 */
inline
HRonNumberNode createNode(double value)
{
    return HRonNumberNode(new RonNumberNode(value));
}

/*!
 * Creates a boolean node.
 * \param value ... the boolean attribute
 * \return Handle to the node.
 */
inline
HRonBooleanNode createNode(bool value)
{
    return HRonBooleanNode(new RonBooleanNode(value));
}

/*!
 * Creates an identifier node. If \a length is zero or unspecified, it is
 * assumed that the \a identifier is a null-terminated string.
 * \param identifier ... the string attribute
 * \param length ... the string attribute length
 * \return Handle to the node.
 */
inline
HRonIdentifierNode createNode(const char *identifier, unsigned int length = 0)
{
    return HRonIdentifierNode(new RonIdentifierNode(identifier, length));
}

/*!
 * Creates a comment node. If \a length is zero or unspecified, it is assumed
 * that the \a comment is a null-terminated string.
 * \param comment... the string attribute
 * \param line ... indication of line comment (as opposed to block one)
 * \param length ... the string attribute length
 * \return Handle to the node.
 */
inline
HRonCommentNode createNode(const char *comment, bool line, unsigned int length = 0)
{
    return HRonCommentNode(new RonCommentNode(comment, line, length));
}

/*!
 * Creates a null node.
 * \return Handle to the node.
 */
inline
HRonNullNode createNullNode()
{
    return HRonNullNode(new RonNullNode());
}

/*!
 * Creates an array node.
 * \return Handle to the node.
 */
inline
HRonArrayNode createArrayNode()
{
    return HRonArrayNode(new RonArrayNode());
}

/*!
 * Creates an object node.
 * \return Handle to the node.
 */
inline
HRonObjectNode createObjectNode()
{
    return HRonObjectNode(new RonObjectNode());
}


/*!
 * Used internally by \link RonParser \endlink to jump through multiple levels
 * of recursion and signal an error.
 */
class RonParsingException : public std::exception
{
public:

    /*!
     * Constructor.
     * \param row ... the row on which the error occurred
     * \param column ...the column on which the error occured
     */
    RonParsingException(unsigned int row, unsigned int column) throw()
    : row(row), column(column)
    {
    }

    /*!
     * Retrieves the string representation of the exception.
     * \return A null-terminated string.
     */
    virtual const char* what() const throw()
    {
        return "RON parsing exception";
    }

    /*!
     * Retrieves the row on which the parsing error occured.
     * \return The row number.
     */
    unsigned int getRow() const { return row; }

    /*!
     * Retrieves the column on which the parsing error occured.
     * \return The column number.
     */
    unsigned int getColumn() const { return column; }

private:
    unsigned int row, column;
};


/*!
 * \brief RON syntactical analyser.
 *
 * Performs syntactical analysis of Retia Object Notation language and produces
 * abstract syntax tree. This recursive descent parser internally uses \link
 * RonTokenizer \endlink and is based on the following LL(1) grammar:
 * <value> ::= <object> | <array> | RttNumber | <identifier> | RttBoolean | RttNull
 * <object> ::= '{' <object-rest>
 * <object-rest> ::= '}' | <pair> <pairs-rest>
 * <pair> ::= <identifier> ':' <value>
 * <pairs-rest> ::= ',' <pair> <pairs-rest> | '}'
 * <array> ::= '[' <array-rest>
 * <array-rest> ::= ']' | <value> <items-rest>
 * <items-rest> ::= ',' <value> <items-rest> | ']'
 * <identifier> ::= RttPlainString | RttQuotedString
 */
class RonParser
{
public:

    /*!
     * Constructs a parser.
     */
    RonParser() : parsingFile(false) {}

    /*!
     * Parses the RON message. If \a length is zero, it is assumed the message
     * is a null-terminated string and will be parsed up to the termination.
     *
     * The parsing process halts on first error and the information about
     * the error can be subsequently retrieved.
     *
     * Comments are currently ignored during the parsing.
     *
     * \param message ... the message to parse, UTF-8 encoded Unicode
     * \param length ... the length of the message to parse
     * \return Handle to the root node, invalid handle on error.
     * \see getError
     */
    HRonNode parse(const char *message, unsigned int length = 0)
    {
        errorBuilder.reset();
        source = "string";
        if (!message)
        {
            errorBuilder.append("invalid string pointer (null)");
            return HRonNode();
        }
        tokenizer.setMessage(message, length);
        return parse();
    }

    /*!
     * Parses the RON message from a stream. An alternative to \link
     * RonParser::parse(const char *message, unsigned int length) \endlink
     * method.
     * \param stream ... the input stream
     * \return Handle to the root node, invalid handle on error.
     * \see getError
     */
    HRonNode parse(std::istream &stream)
    {
        errorBuilder.reset();
        if (!parsingFile)
        {
            source = "stream";
        }
        if (!stream.good())
        {
            errorBuilder.append("stream not good");
            return HRonNode();
        }
        tokenizer.setStream(stream);
        return parse();
    }

    /*!
     * Parses a file containing RON data. Another alternative to previous
     * methods.
     * \param pathName ... the path name
     * \return Handle to the root node, invalid handle on error.
     * \see getError
     */
    HRonNode parseFile(const char *pathName)
    {
        errorBuilder.reset();
        if (!pathName)
        {
            errorBuilder.append("invalid path name (null)");
            return HRonNode();
        }
        source = pathName;
        std::ifstream fStream;
        fStream.open(pathName);
        if (!fStream.is_open())
        {
            errorBuilder.appendVariadic("could not open file '%s'", pathName);
            return HRonNode();
        }
        parsingFile = true;
        HRonNode result = parse(fStream);
        fStream.close();
        parsingFile = false;
        return result;
    }

    /*!
     * Parses a file containing XML data.
     * \param pathName ... the path name
     * \return Handle to the root node, invalid handle on error.
     * \see getError
     */
    HRonNode parseXmlFile(const char *pathName)
    {
        errorBuilder.reset();
        if (!pathName)
        {
            errorBuilder.append("invalid path name (null)");
            return HRonNode();
        }
        source = pathName;
        #if RUTIL_LIBXML2
        xmlDocPtr doc = xmlReadFile(pathName, "UTF-8",
                XML_PARSE_NOBLANKS | XML_PARSE_NOERROR | XML_PARSE_NOWARNING);
        if (!doc)
	    {
            xmlErrorPtr lastError = xmlGetLastError();
            if (lastError)
            {
                errorBuilder.appendVariadic("%s:%u:%u: %s",
                        source.c_str(), lastError->line, lastError->int2, lastError->message);
            }
            else
            {
                errorBuilder.appendVariadic("%s: unknown libxml2 error", source.c_str());
            }
	        return HRonNode();
	    }
        HRonNode rootNode = extractRonNode(xmlDocGetRootElement(doc));
	    xmlFreeDoc(doc);
	    xmlCleanupParser();
	    return rootNode;
        #else
	    errorBuilder.appendVariadic("%s: XML parsing not supported", source.c_str());
	    return HRonNode();
	#endif
    }

    /*!
     * Converts the RON message to JSON. If \a length is zero, it is assumed
     * the message is a null-terminated string and will be parsed up to
     * the termination.
     *
     * Helper method.
     *
     * \param message ... the message to convert, UTF-8 encoded Unicode
     * \param length ... the length of the message to convert
     * \return JSON message, empty string on error.
     * \see getError
     */
    std::string toJson(const char *message, unsigned int length = 0)
    {
        HRonNode root = parse(message, length);
        std::string result;
        if (root)
        {
            StringBuilder builder;
            root->emitRON(builder.getStream(), 0, IRonNode::OfJson);
            builder.appendStream();
            result.assign(builder.getString(), builder.getLength());
        }
        return result;
    }

    /*!
     * Converts the RON message to XML.
     * \param message ... the message to convert, UTF-8 encoded Unicode
     * \param length ... the length of the message to convert
     * \return XML message, empty string on error.
     * \see getError
     */
    std::string toXml(const char *message, unsigned int length = 0)
    {
       HRonNode root = parse(message, length);
       std::string result;
       if (root)
       {
           StringBuilder builder;
           builder.append("<?xml version=\'1.0\' encoding=\'utf-8\'?>\n<root>\n");
           root->emitRON(builder.getStream(), 1, IRonNode::OfXml);
           builder.appendStream();
           builder.append("</root>\n");
           result.assign(builder.getString(), builder.getLength());
       }
       return result;
    }

    /*!
     * Retrieves error information. The string contains information about
     * location of the error (row, column) and further description.
     * \return The error information, empty string if no error was encountered.
     */
    const char *getError() const
    {
        return errorBuilder.getString();
    }

private:

#if RUTIL_LIBXML2
    HRonNode extractRonNode(xmlNodePtr node) const
    {
        if (!node) { return HRonNode(); }
        RonNodeType type = getRonNodeType(node);
        return extractRonNode(node, type);
    }

    HRonNode extractRonNode(xmlNodePtr node, RonNodeType asType) const
    {
        if (!node || asType == RntDummy) { return HRonNode(); }

        const char *text = NULL;
        for (xmlNodePtr child = node->children; child; child = child->next)
        {
            if (child->type == XML_TEXT_NODE)
            {
                text = (const char*)child->content;
                break;
            }
        }

        RonTokenizer tokenizer;
        tokenizer.setMessage(text);
        const RonToken &token = tokenizer.nextToken();

        switch (asType)
        {
            case RntObject:
            {
                HRonObjectNode objectNode = createObjectNode();
                for (xmlNodePtr child = node->children; child; child = child->next)
                {
                    if (child->type != XML_ELEMENT_NODE)
                    {
                        continue;
                    }
                    objectNode->setAttribute((const char*)child->name, extractRonNode(child));
                }
                for (xmlAttrPtr prop = node->properties; prop; prop = prop->next)
                {
                    if (objectNode->getAttribute((const char*)prop->name))
                    {
                        continue;
                    }
                    xmlChar *value = xmlGetProp(node, prop->name);
                    objectNode->setAttribute((const char*)prop->name,
                            extractRonNode(value));
                    xmlFree(value);
                }

                return HRonNode(objectNode);
            }
            case RntArray:
            {
                HRonArrayNode arrayNode = createArrayNode();
                for (xmlNodePtr child = node->children; child; child = child->next)
                {
                    if (child->type != XML_ELEMENT_NODE)
                    {
                        continue;
                    }
                    arrayNode->pushBack(extractRonNode(child));
                }
                return HRonNode(arrayNode);
            }
            case RntIdentifier:
            {
                return HRonNode(createNode(text));
            }
            case RntNumber:
            {
                if (token.isInteger())
                {
                    return HRonNode(createNode(token.getInteger()));
                }
                else
                {
                    return HRonNode(createNode(token.getReal()));
                }
            }
            case RntBoolean:
            {
                return HRonNode(createNode(token.getBoolean()));
            }
            case RntNull:
            {
                return HRonNode(createNullNode());
            }
            default: return HRonNode();
        }
    }

    HRonNode extractRonNode(xmlChar *attribute) const
    {
        if (!attribute) { return HRonNode(); }
        const char *text = (const char*)attribute;
        RonTokenizer tokenizer;
        tokenizer.setMessage(text);
        RonToken token = tokenizer.nextToken();
        RonToken followingToken = tokenizer.nextToken();
        if (followingToken.getType() == RttEof)
        {
            switch (token.getType())
            {
                case RttNumber:
                    if (token.isInteger())
                    {
                        return HRonNode(createNode(token.getInteger()));
                    }
                    else
                    {
                        return HRonNode(createNode(token.getReal()));
                    }
                case RttBoolean:
                    return HRonNode(createNode(token.getBoolean()));
                case RttNull:
                    return HRonNode(createNullNode());
                default:
                    return HRonNode(createNode(text));
            }
        }
        else
        {
            return HRonNode(createNode(text));
        }
    }

    RonNodeType getRonNodeType(xmlNodePtr node) const
    {
        if (!node) { return RntDummy; }

        unsigned int elementNodes = 0;
        unsigned int textNodes = 0;
        const char *text = NULL;
        bool nonItemElementNode = false;
        bool attributes = (node->properties != NULL);
        for (xmlNodePtr child = node->children; child; child = child->next)
        {
            if (child->type == XML_ELEMENT_NODE)
            {
                ++elementNodes;
                if (!xmlStrEqual(child->name, (xmlChar*)"item"))
                {
                    nonItemElementNode = true;
                }
            }
            else if (child->type == XML_TEXT_NODE)
            {
                ++textNodes;
                text = (const char*)child->content;
            }
        }
        if (elementNodes == 0 && attributes)
        {
            return RntObject;
        }
        if (elementNodes > 0)
        {
            if (nonItemElementNode)
            {
                return RntObject;
            }
            else
            {
                return RntArray;
            }
        }
        if (textNodes == 1 && text != NULL)
        {
            RonTokenizer tokenizer;
            tokenizer.setMessage(text);
            RonToken token = tokenizer.nextToken();
            RonToken followingToken = tokenizer.nextToken();
            if (followingToken.getType() != RttEof)
            {
                return RntIdentifier;
            }
            switch (token.getType())
            {
                case RttNumber: return RntNumber;
                case RttBoolean: return RntBoolean;
                case RttNull: return RntNull;
                default: return RntIdentifier;
            }
        }

        return RntDummy;
    }
#endif

    HRonNode parse()
    {
        errorBuilder.reset();
        HRonNode result;
        try
        {
            nextToken();
            result = parseValue();
            compare(RttEof);
        } catch (RonParsingException &exception)
        {
            result = NULL;
        }
        return result;
    }

    HRonNode parseValue()
    {
        HRonNode result;
        switch (currentToken.getType())
        {
            case RttLeftBracket:
                result = parseObject();
                break;
            case RttLeftBrace:
                result = parseArray();
                break;
            case RttNumber:
                result = parseNumber();
                break;
            case RttPlainString: // fall-through
            case RttQuotedString:
                result = parseIdentifier();
                break;
            case RttBoolean:
                result = parseBoolean();
                break;
            case RttNull:
                result = parseNull();
                break;
            default:
                onError("unexpected token '%s' while parsing value", toString(currentToken.getType()));
                break;
        }
        return result;
    }

    HRonNode parseObject()
    {
        compare(RttLeftBracket);
        HRonNode result(createObjectNode());
        parseObjectRest(result);
        return result;
    }

    void parseObjectRest(const HRonNode &object)
    {
        switch (currentToken.getType())
        {
            case RttRightBracket:
                compare(RttRightBracket);
                break;
            default:
                parsePair(object);
                parsePairsRest(object);
                break;
        }
    }

    void parsePair(const HRonNode &object)
    {
        HRonNode identifier = parseIdentifier();
        std::string name;
        name.assign(identifier->asString(), identifier->getLength());
        compare(RttColon);
        HRonNode value = parseValue();
        object->setAttribute(name, value);
    }

    void parsePairsRest(const HRonNode &object)
    {
        switch (currentToken.getType())
        {
            case RttComma:
                compare(RttComma);
                parsePair(object);
                parsePairsRest(object);
                break;
            case RttRightBracket:
                compare(RttRightBracket);
                break;
            default:
                onError("unexpected token '%s' while parsing object pairs", toString(currentToken.getType()));
                break;
        }
    }

    HRonNode parseArray()
    {
        compare(RttLeftBrace);
        HRonNode result(createArrayNode());
        parseArrayRest(result);
        return result;
    }

    void parseArrayRest(const HRonNode &array)
    {
        switch (currentToken.getType())
        {
            case RttRightBrace:
                compare(RttRightBrace);
                break;
            default:
                HRonNode item = parseValue();
                array->pushBack(item);
                parseItemsRest(array);
                break;
        }
    }

    void parseItemsRest(const HRonNode &array)
    {
        switch (currentToken.getType())
        {
            case RttComma:
            {
                compare(RttComma);
                HRonNode item = parseValue();
                array->pushBack(item);
                parseItemsRest(array);
            }
            break;
            case RttRightBrace:
                compare(RttRightBrace);
                break;
            default:
                onError("unexpected token '%s' while parsing array items", toString(currentToken.getType()));
                break;
        }
    }

    HRonNode parseNumber()
    {
        return compare(RttNumber);
    }

    HRonNode parseIdentifier()
    {
        HRonNode result;
        switch (currentToken.getType())
        {
            case RttPlainString:
                result = compare(RttPlainString);
                break;
            case RttQuotedString:
                result = compare(RttQuotedString);
                break;
            default:
                onError("unexpected token '%s' while parsing identifier", toString(currentToken.getType()));
                break;
        }
        return result;
    }

    HRonNode parseBoolean()
    {
        return compare(RttBoolean);
    }

    HRonNode parseNull()
    {
        return compare(RttNull);
    }

    HRonNode compare(RonTokenType type)
    {
        HRonNode result;
        if (currentToken.getType() == type)
        {
            switch (type)
            {
                case RttPlainString: // fall-through
                case RttQuotedString:
                    result = createNode(currentToken.getString(), currentToken.getStringLength());
                    break;
                case RttNumber:
                    if (currentToken.isInteger())
                    {
                        result = createNode(currentToken.getInteger());
                    }
                    else
                    {
                        result = createNode(currentToken.getReal());
                    }
                    break;
                case RttBoolean:
                    result = createNode(currentToken.getBoolean());
                    break;
                case RttNull:
                    result = createNullNode();
                    break;
                case RttLineComment: // fall-through
                case RttBlockComment:
                    result = createNode(currentToken.getString(),
                            type == RttLineComment, currentToken.getStringLength());
                    break;
                default:
                    // result stays empty
                    break;
            }
            nextToken();
        }
        else
        {
            onError("unexpected token '%s' (expected '%s')", toString(currentToken.getType()), toString(type));
        }
        return result;
    }

    void nextToken()
    {
        currentToken = tokenizer.nextToken();
        if (currentToken.getType() == RttError)
        {
            onError("tokenizer error: %s", currentToken.getString());
        }
    }

    void onError(const char *format,...)
    {
        errorBuilder.reset();
        errorBuilder.appendVariadic("%s:%u:%u: ", source.c_str(), tokenizer.getRow(), tokenizer.getColumn());
        va_list arguments;
        va_start(arguments, format);
        errorBuilder.append(format, arguments);
        va_end(arguments);
        throw RonParsingException(tokenizer.getRow(), tokenizer.getColumn());
    }

    StringBuilder errorBuilder;

    RonToken currentToken;

    RonTokenizer tokenizer;

    std::string source;
    bool parsingFile;
};

} // end namespace rutil


#endif /* RUTIL_RON_H */

namespace rutil
{
//IRonNode IRonNode::dummy;
}
