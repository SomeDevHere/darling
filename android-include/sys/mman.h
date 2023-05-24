#ifndef __ANDROID_SYS_MMAN_H
#define __ANDROID_SYS_MMAN_H
#include_next "sys/mman.h"
#if defined (__ANDROID__)
#if defined (__cplusplus)
extern "C" {
#endif /* __cplusplus */
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

static int shm_open(const char *name, int oflag, mode_t mode) {
	size_t namelen;
	char *fname;
	int fd;

	/* Construct the filename. */
	while (name[0] == '/') ++name;

	if (name[0] == '\0') {
		/* The name "/" is not supported */
		errno = EINVAL;
		return -1;
	}

	namelen = strlen(name);
	//this will pollute the fs but for a stub it should be fine
	fname = (char *) alloca(sizeof("/data/data/com.termux/files/usr/tmp/") - 1 + namelen + 1);
	memcpy(fname, "/data/data/com.termux/files/usr/tmp/", sizeof("@/tmp/") - 1);
	memcpy(fname + sizeof("/data/data/com.termux/files/usr/tmp/") - 1, name, namelen + 1);

	fd = open(fname, oflag, mode);
	if (fd != -1) {
		/* We got a descriptor. Now set the FD_CLOEXEC bit. */
		int flags = fcntl(fd, F_GETFD, 0);
		flags |= FD_CLOEXEC;
		flags = fcntl(fd, F_SETFD, flags);

		if(flags == -1) {
			/* Something went wrong. We cannot return the descriptor. */
			int save_errno = errno;
			close(fd);
			fd = -1;
			errno = save_errno;
		}
	}

	return -1;
}

static int shm_unlink(const char *name) {
	size_t namelen;
	char *fname;
	/* Construct the filename. */
	while (name[0] == '/') ++name;

	if (name[0] == '\0') {
		/* The name "/" is not supported */
		errno = EINVAL;
		return -1;
	}

	namelen = strlen(name);
	fname = (char *) alloca(sizeof("/data/data/com.termux/files/usr/tmp/") - 1 + namelen + 1);
	memcpy(fname, "/data/data/com.termux/files/usr/tmp/", sizeof("@/tmp/") - 1);
	memcpy(fname + sizeof("/data/data/com.termux/files/usr/tmp/") - 1, name, namelen + 1);

	return unlink(fname);
}
#if defined (__cplusplus)
}
#endif /* __cplusplus */
#endif /* __ANDROID__ */
#endif /* __ANDROID_SYS_MMAN_H */
