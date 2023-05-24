#if defined(__ANDROID_LINUX_HEADERS)
#if defined(__arm__)
#include <arm-linux-androideabi/asm/posix_types.h>
#endif
#if defined(__aarch64__)
#include <aarch64-linux-android/asm/posix_types.h>
#endif
#if defined(__i386__)
#include <i686-linux-android/asm/posix_types.h>
#endif
#if defined(__x86_64__)
#include <x86_64-linux-android/asm/posix_types.h>
#endif
#else
#include_next <asm/posix_types.h>
#endif /* __ANDROID_LINUX_HEADERS */
