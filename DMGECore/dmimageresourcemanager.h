/** 
 * @file    dmimageresourcemanager.h
 * @brief   DM Game Engine image resource manager header.
 * @author  XadillaX
 * @version 1.0 
 * @date    2013.12.18
 */
#ifndef __DMIMAGERESOURCEMANAGER_H__
#define __DMIMAGERESOURCEMANAGER_H__
#pragma once
#include "dmsingleton.h"
#include <map>
#include <set>
#include <string>
#include <deque>
#include "dmresourcemanager.h"
using namespace std;

class DMImageResourceManager;
typedef DWORD ImageID;
typedef DWORD* DMPixArray;
class DMGECORE_API DMImageResource
{
public:
    DMImageResource(ImageID id, string name, bool org, DMResourceBuffer* buff);

    ImageID             ID() { return m_dwID; }
    string              Name() { return m_szName; }
    bool                IsOriginal() { return m_bOriginal; }
    DMResourceBuffer*   Buffer() { return m_pBuffer; }

    int                 Width();
    int                 Height();
    SIZE                Size();

    DMPixArray          GetPixel(bool bReadOnly = false, int left = 0, int top = 0, int width = 0, int height = 0);
    bool                UnlockPixel();

protected:
    ~DMImageResource();

private:
    /**
     * Image ID (DWORD, or HTEXTURE in HGE).
     */
    ImageID             m_dwID;

    /**
     * Original name.
     */
    string              m_szName;

    /**
     * Is this an original file resource, or a resource cloned (modified) from another.
     */
    bool                m_bOriginal;

    /**
     * The binary buffer.
     */
    DMResourceBuffer*   m_pBuffer;

    DMPixArray          m_pPixel;

    friend class DMImageResourceManager;
};

typedef deque<DMImageResource*> ImageResourceSet;

class DMGECORE_API DMImageResourceManager : public DMResourceManager, public DMSingleton<DMImageResourceManager>
{
public:
    virtual ~DMImageResourceManager(void);

    DMImageResource*                            GetImage(const char* szName);
    DMImageResource*                            CloneImage(DMImageResource* pImageManagedByManager);

    bool                                        RemoveImage(DMImageResource* &pImage);
    bool                                        RemoveAllImage(const char* szName);

    virtual void                                ClearCache();

protected:
    map<string, ImageResourceSet>               m_mpImageCache;
};

#define DMIMGMANAGER DMImageResourceManager::Instance()

#endif
