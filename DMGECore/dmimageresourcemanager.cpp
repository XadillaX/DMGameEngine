/** 
 * @file    dmimageresourcemanager.cpp
 * @brief   DM Game Engine image resource manager impl.
 * @author  XadillaX
 * @version 1.0 
 * @date    2013.12.18
 */
#include "dmimageresourcemanager.h"
#include "module\hge\include\hge.h"

DMImageResource::DMImageResource(ImageID id, string name, bool org, DMResourceBuffer* buff)
{
    m_dwID = id;
    m_szName = name;
    m_bOriginal = org;
    m_pBuffer = buff;

    m_pPixel = NULL;
}

int DMImageResource::Width()
{
    return DMGlobal::g_HGEHelper.GetObj()->Texture_GetWidth(m_dwID, true);
}

int DMImageResource::Height()
{
    return DMGlobal::g_HGEHelper.GetObj()->Texture_GetHeight(m_dwID, true);
}

SIZE DMImageResource::Size()
{
    SIZE sz;
    sz.cx = Width();
    sz.cy = Height();

    return sz;
}

DMPixArray DMImageResource::GetPixel(bool bReadOnly, int left, int top, int width, int height)
{
    if(m_pPixel) return NULL;

    HGE* pHGE = DMGlobal::g_HGEHelper.GetObj();
    m_pPixel = pHGE->Texture_Lock(m_dwID, bReadOnly, left, top, width, height);

    return m_pPixel;
}

bool DMImageResource::UnlockPixel()
{
    if(!m_pPixel) return false;

    HGE* pHGE = DMGlobal::g_HGEHelper.GetObj();

    pHGE->Texture_Unlock(m_dwID);
    m_pPixel = NULL;

    return true;
}

DMImageResource::~DMImageResource()
{
}

DMSINGLETON_IMPL(DMImageResourceManager);

DMImageResourceManager::~DMImageResourceManager(void)
{
    ClearCache();
}

DMImageResource* DMImageResourceManager::GetImage(const char* szName)
{
    map<string, ImageResourceSet>::iterator it = m_mpImageCache.find(szName);
    if(it != m_mpImageCache.end())
    {
        if(it->second[0]->IsOriginal())
        {
            return it->second[0];
        }
    }

    DMResourceBuffer* buff = GetResource(szName);
    if(!buff)
    {
        return NULL;
    }

    /**
     * TODO: the 3rd param (true or false).
     */
    ImageID id = m_pHelper->GetObj()->Texture_Load((char*)buff->m_pBuff, buff->m_dwBuffSize, true);
    if(!id)
    {
        RemoveResource(szName);
        return NULL;
    }

    /**
     * TODO: get it from OBJECT POOL.
     */
    DMImageResource* pIR = new DMImageResource(id, szName, true, buff);
    m_mpImageCache[szName].push_front(pIR);

    return pIR;
}

DMImageResource* DMImageResourceManager::CloneImage(DMImageResource* pImageManagedByManager)
{
    map<string, ImageResourceSet>::iterator it = m_mpImageCache.find(pImageManagedByManager->Name());
    if(it == m_mpImageCache.end())
    {
        return NULL;
    }

    DMResourceBuffer* buff = new DMResourceBuffer();
    buff->m_szName = pImageManagedByManager->Buffer()->m_szName;
    buff->m_dwBuffSize = pImageManagedByManager->Buffer()->m_dwBuffSize;
    buff->m_pBuff = new char[buff->m_dwBuffSize];
    memcpy(buff->m_pBuff, pImageManagedByManager->Buffer()->m_pBuff, buff->m_dwBuffSize * sizeof(char));

    ImageID id = m_pHelper->GetObj()->Texture_Load((char*)buff->m_pBuff, buff->m_dwBuffSize, true);
    if(!id)
    {
        SAFEDEL_ARRAY(buff->m_pBuff);
        SAFEDEL(buff);

        return NULL;
    }

    DMImageResource* pIR = new DMImageResource(id, pImageManagedByManager->Name(), false, buff);

    it->second.push_back(pIR);

    return pIR;
}

bool DMImageResourceManager::RemoveImage(DMImageResource* &pImage)
{
    map<string, ImageResourceSet>::iterator it = m_mpImageCache.find(pImage->Name());
    if(it == m_mpImageCache.end())
    {
        return false;
    }

    for(ImageResourceSet::iterator sit = it->second.begin(); sit != it->second.end(); sit++)
    {
        if(pImage->ID() == (*sit)->ID())
        {
            /** Original: delete it from resource cache */
            if(pImage->IsOriginal())
            {
                /** clear buffer via resource manager */
                this->RemoveResource(pImage->Name().c_str());

                if(pImage != *sit)
                {
                    SAFEDEL(pImage);
                }
                SAFEDEL(*sit);
            }
            else
            {
                if(pImage != *sit)
                {
                    SAFEDEL(pImage);
                }

                /** clear buffer manually */
                SAFEDEL_ARRAY((*sit)->Buffer()->m_pBuff);
                SAFEDEL(*sit);
            }

            it->second.erase(sit);
            if(it->second.empty())
            {
                m_mpImageCache.erase(it);
            }

            pImage = NULL;

            return true;
        }
    }

    return false;
}

bool DMImageResourceManager::RemoveAllImage(const char* szName)
{
    map<string, ImageResourceSet>::iterator it = m_mpImageCache.find(szName);
    if(it == m_mpImageCache.end())
    {
        return false;
    }

    DMImageResource* pIR = NULL;
    while(it->second.size() > 1)
    {
        pIR = it->second.front();
        RemoveImage(pIR);
    }

    pIR = it->second.front();
    RemoveImage(pIR);

    return true;
}

void DMImageResourceManager::ClearCache()
{
    map<string, ImageResourceSet>::iterator it;
    while(!m_mpImageCache.empty())
    {
        it = m_mpImageCache.begin();
        RemoveAllImage(it->second[0]->Name().c_str());
    }
}
