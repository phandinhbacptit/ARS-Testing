/*!
 * \file
 * \author Miroslav Kubik <mkubik2@retia.cz>
 * \brief Contains compile time defines.
 *
 * Enabling/disabling various features and compatibility modes.
 *
 * See also config.h for version, default machine string, etc.
 */

#ifndef RTRACKER_FEATURES_H
#define RTRACKER_FEATURES_H

#define RTRACKER_MACH_STRING                 "UBUNTU"

#define RTRACKER_OLD_FD2COMM                 1
#define RTRACKER_LINK11B_MESSAGE             1

// communication formats
#define RTRACKER_FORMAT_H                    0
#define RTRACKER_FORMAT_CHUNK                0
#define RTRACKER_RTIM                        0
#define RTRACKER_PROJ4                       0
#define RTRACKER_RLOG                        0

// processing components...


#endif /* RTRACKER_FEATURES_H */
