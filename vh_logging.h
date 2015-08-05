#ifndef VH_LOGGING
#define VH_LOGGING

#include <QLoggingCategory>

#ifdef VF_NO_DEBUG
#define vCDebug(X) QNoDebug()
#else
#define vCDebug(X) qCDebug(X)
#endif

#endif // VH_LOGGING

