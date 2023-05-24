
#ifndef __TERMUX_STRINGS_H
#define __TERMUX_STRINGS_H
#include_next <strings.h>
#include <string.h>
#if defined (__ANDROID__)

#ifndef __TERMUX_STRING // to avoid issues if both string.h and strings.h are included
#define __TERMUX_STRING

#if defined (__cplusplus)
extern "C" {
#endif /* __cplusplus */

#include <unistd.h>
#undef index
#undef rindex
#undef bzero
#undef bcmp
#undef bcopy

static const char *index(const char *s, int c) {
	return strchr(s, c);
}

static const char *rindex(const char *s, int c) {
	return strrchr(s, c);
}

static void bzero(void *poi, size_t len) {
	memset(poi, 0, len);
}

static int bcmp(const void *s1, const void *s2, int n) {
	return memcmp(s1, s2, n);
}

static void bcopy(const void *s, void *d, size_t len) {
	memmove(d, s, len);
}

#if defined (__cplusplus)
}
#endif /* __cplusplus */

#endif /* __TERMUX_STRING */

#endif /* __ANDROID__ */
#endif /* __TERMUX_STRINGS_H */
