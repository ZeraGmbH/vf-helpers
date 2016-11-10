#ifndef VH_LOGGING
#define VH_LOGGING

#include <QLoggingCategory>

#ifdef VF_NO_DEBUG
#define vCDebug(X) QNoDebug()
#else
#define vCDebug(X) qCDebug(X)
#endif

// if __PRETTY_FUNCTION__ does not work with your comiler then add some conditions here
#define VF_ASSERT(test, what) Q_ASSERT_X(test, __PRETTY_FUNCTION__, what)
#define QStringC(X) (X).toStdString().c_str()

#endif // VH_LOGGING

