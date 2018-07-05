#ifndef VH_MACROS_H
#define VH_MACROS_H

#include "veinhelpers_global.h"
#include <functional>
#include <QVariantMap>
#include <QLatin1String>
#include <QHash>

/// helper to save time with defining component metadata
#define VF_COMPONENT(componentIdentifier, componentNameString, componentDescriptionString) \
  static constexpr QLatin1String s_##componentIdentifier##ComponentName = QLatin1String(componentNameString); \
  static constexpr QLatin1String s_##componentIdentifier##ComponentDescription = QLatin1String(componentDescriptionString);

/// helper to save time with defining rpc function metadata
#define VF_RPC(rpcIdentifier, procedureNameString, procedureDescriptionString) \
  static constexpr QLatin1String s_##rpcIdentifier##ProcedureName = QLatin1String(procedureNameString); \
  static constexpr QLatin1String s_##rpcIdentifier##ProcedureDescription = QLatin1String(procedureDescriptionString);

/// helper to set up a map or hash of the remote procedures, mainly because qt creator breaks the indentation :(
#define VF_RPC_BIND(rpcIdentifier, rpcBind) \
{ \
s_##rpcIdentifier##ProcedureName, \
rpcBind \
}

namespace VeinEvent
{
  using RemoteProcedureAtlas = QHash<QString, std::function<QVariantMap(QVariantMap)> >;
}


#endif // VH_MACROS_H
