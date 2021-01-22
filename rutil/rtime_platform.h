/*!
 * \file
 * \author Miroslav Kubik <mkubik2@retia.cz>
 * \brief Header file for platform related definitions.
 */
#ifndef RTIME_PLATFORM_H
#define RTIME_PLATFORM_H

#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
    #define RTIME_WINDOWS 1
    #define RTIME_LINUX 0
#else // default platform
    #define RTIME_LINUX 1
    #define RTIME_WINDOWS 0
#endif

#endif /* RTIME_PLATFORM_H */
