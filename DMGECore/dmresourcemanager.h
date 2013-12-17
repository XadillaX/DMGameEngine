/** 
 * @file    dmresourcemanager.h
 * @brief   DM Game Engine resource manager header.
 * @author  XadillaX
 * @version 1.0 
 * @date    2013.12.16
 */
#ifndef __DMRESOURCEMANAGER_H__
#define __DMRESOURCEMANAGER_H__
#pragma once
#include "dmobject.h"
#include <string>
#include <map>
using namespace std;

struct DMResourceBuffer
{
    string          m_szName;
    DWORD           m_dwBuffSize;
    void*           m_pBuff;
};
typedef map<string, DMResourceBuffer*> DMResourceMap;
typedef DMResourceBuffer* (DMResourceGetterCallback)(const char* szName);

class DMGECORE_API DMResourceManager : public DMObject
{
public:
    DMResourceManager(void);
    virtual ~DMResourceManager(void);

    virtual void                        ClearCache();

    DMResourceBuffer*                   GetResource(const char* szName);
    void                                RemoveResource(const char* szName);

protected:
    DMBaseHelper*                       m_pHelper;
    DMResourceMap                       m_mpCache;
    DMResourceGetterCallback*           m_pGetter;
};

#endif
