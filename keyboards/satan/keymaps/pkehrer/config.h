/*
Copyright 2017 Paul Kehrer

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "config_common.h"

/* USB Device descriptor parameter */
#undef MANUFACTURER
#define MANUFACTURER    Paul Kehrer
#undef DESCRIPTION
#define DESCRIPTION     Badass GH60 keyboard

#undef BACKLIGHT_LEVELS
#define BACKLIGHT_LEVELS 5
#define BACKLIGHT_BREATHING
#define BREATHING_PERIOD 1

/*MOUSE CONFIG OPTIONS*/

#define MOUSEKEY_INTERVAL       20
#define MOUSEKEY_DELAY          0
#define MOUSEKEY_TIME_TO_MAX    45
#define MOUSEKEY_MAX_SPEED      3
#define MOUSEKEY_WHEEL_DELAY 	0

#endif
