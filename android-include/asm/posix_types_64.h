#if defined(__ANDROID_LINUX_HEADERS)
#include <x86_64-linux-android/asm/posix_types_64.h>
#else
#include_next <asm/posix_types_64.h>
#endif /* __ANDROID_LINUX_HEADERS */
