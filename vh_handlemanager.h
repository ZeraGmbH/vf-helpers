#ifndef VH_HANDLE
#define VH_HANDLE

#include <QVector>
#include <QHash>

namespace VeinHelper
{
  /**
   * @b This class implements a Handle management system
   * @note the type Key must be default constructible and must provide operator==() and operator++()
   */
  template<typename Key, typename T> class HandleManager
  {
  public:
    HandleManager() : m_max(Key()) {}

    /**
     * @brief returns the first handle with the value t_Value
     */
    Key key(const T &t_value, const Key &t_defaultKey) const { return m_currentHandles.key(t_value, t_defaultKey); }

    /**
     * @brief returns the value stored with Key t_Key or the t_DefaultValue if not found
     */
    T value(const Key &t_key, const T &t_defaultValue) const { return m_currentHandles.value(t_key, t_defaultValue); }

    Key append(const T &t_value)
    {
      Key k = nextKey();
      m_currentHandles.insert(k, t_value);
      return k;
    }

    void remove(const Key &t_key)
    {
      if(m_currentHandles.remove(t_key)>0)
      {
        m_recycledHandles.append(t_key);
      }
    }

    void clear()
    {
      m_currentHandles.clear();
      m_recycledHandles.clear();
      m_max = Key();
    }

    QList<T> values() const { return m_currentHandles.values(); }




  private:
    Key nextKey()
    {
      Key retVal;
      if(m_recycledHandles.isEmpty())
      {
        retVal = m_max;
        m_max++;
      }
      else
      {
        retVal = m_recycledHandles.takeFirst();
      }

      return retVal;
    }


    QVector<Key> m_recycledHandles;
    QHash<Key, T> m_currentHandles;
    Key m_max;
  };
}

#endif // VH_HANDLE

