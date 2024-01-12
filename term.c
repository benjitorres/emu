// code copied from [https://www.uninformativ.de/git/eduterm/commit/94cbafa06db99c5deb7d13b046b06d2604a454a1.html]

#define _XOPEN_SOURCE 600
#include <ctype.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

/* Font selection has not been implemented*/

#define FONT_W 8
#define FONT_H 16
#define FONT_ASC 13