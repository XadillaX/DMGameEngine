/** 
 * @file    dmresourcemanager.cpp
 * @brief   DM Game Engine resource manager impl.
 * @author  XadillaX
 * @version 1.0 
 * @date    2013.12.16
 */
#include "module\hge\include\hge.h"
#include "dmresourcemanager.h"

DMResourceBuffer* _defaultResourceGetter(const char* szName)
{
    DMResourceBuffer* buff = new DMResourceBuffer();

    buff->m_szName = szName;
    buff->m_dwBuffSize = 0;
    buff->m_pBuff = NULL;
    buff->m_pBuff = DMGlobal::g_HGEHelper.GetObj()->Resource_Load(szName, &buff->m_dwBuffSize);

    return buff;
}

DMResourceManager::DMResourceManager(void) :
    m_pHelper(&DMGlobal::g_HGEHelper)
{
    m_pGetter = _defaultResourceGetter;
}

DMResourceManager::~DMResourceManager(void)
{
    ClearCache();
}

void DMResourceManager::ClearCache()
{
    for(DMResourceMap::iterator it = m_mpCache.begin(); it != m_mpCache.end(); it++)
    {
        SAFEDEL_ARRAY(it->second->m_pBuff);
        SAFEDEL(it->second);
    }

    m_mpCache.clear();
}

DMResourceBuffer* DMResourceManager::GetResource(const char* szName)
{
    /**
     * Step 1.
     *   Get the resource from cache.
     */
    DMResourceMap::iterator it = m_mpCache.find(szName);
    if(it != m_mpCache.end())
    {
        return it->second;
    }

    /**
     * Step 2.
     *   If no cache, load it from filesystem.
     */
    DMResourceBuffer* buff = m_pGetter(szName);
    if(NULL != buff)
    {
        m_mpCache[szName] = buff;
    }

    return buff;
}

void DMResourceManager::RemoveResource(const char* szName)
{
    DMResourceMap::iterator it = m_mpCache.find(szName);
    if(it != m_mpCache.end())
    {
        SAFEDEL_ARRAY(it->second->m_pBuff);
        SAFEDEL(it->second);

        m_mpCache.erase(it);
    }
}
