/** 
 * @file    dmbasehelper.cpp
 * @brief   DM Game Engine base impl.
 * @author  XadillaX
 * @version 1.0 
 * @date    2013.12.15 
 */
#include "DMBaseHelper.h"
#include "module/hge/include/hge.h"

DMBaseHelper::DMBaseHelper(void) :
    m_pHGE(NULL)
{
    m_pHGE = hgeCreate(HGE_VERSION);
}

DMBaseHelper::~DMBaseHelper(void)
{
    Destroy();
}

bool DMBaseHelper::Initialize()
{
    return m_pHGE->System_Initiate();
}

bool DMBaseHelper::Start()
{
    return m_pHGE->System_Start();
}

void DMBaseHelper::Shutdown()
{
    m_pHGE->System_Shutdown();
}

void DMBaseHelper::Destroy()
{
    /**
     * Release HGE referince
     */
    if(m_pHGE)
    {
        m_pHGE->Release();
    }

    /**
     * Safe deleting HGE pointer
     */
    m_pHGE = NULL;
}

HGE* DMBaseHelper::GetObj()
{
    return m_pHGE;
}
