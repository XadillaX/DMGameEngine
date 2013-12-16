/** 
 * @file    dmapplication.cpp
 * @brief   DM Game Engine application impl
 * @author  XadillaX
 * @version 1.0 
 * @date    2013.12.15 
 */
#include "dmapplication.h"
#include "module\hge\include\hge.h"
#include "dmrenderworker.h"
#include "dmscenemanager.h"

HGE* _innerHGE = NULL;

DMSINGLETON_IMPL(DMApplication);

void DMApplication::InitializeEnviroment()
{
    // HGE
    _innerHGE = hgeCreate(HGE_VERSION);

    // BaseHelper
    m_pBaseHelper = &(DMGlobal::g_HGEHelper);

    // System configuration object
    m_pSystemConfiguration = new DMSystemConfiguration();

    // Scene manager
    DMSCENE.Initialize();

    _innerHGE->System_SetState(HGE_FRAMEFUNC, _DMRenderWorker::_DMRenderUpdate);
    _innerHGE->System_SetState(HGE_RENDERFUNC, _DMRenderWorker::_DMRenderRender);
}

DMApplication::~DMApplication(void)
{
    if(_innerHGE)
    {
        _innerHGE->Release();
        _innerHGE = NULL;
    }

    SAFEDEL(m_pSystemConfiguration);
}

DMBaseHelper* DMApplication::GetHelper()
{
    return m_pBaseHelper;
}

DMSystemConfiguration* DMApplication::GetConfig()
{
    return m_pSystemConfiguration;
}

bool DMApplication::Initialize()
{
    return m_pBaseHelper->Initialize();
}

bool DMApplication::Start()
{
    return m_pBaseHelper->Start();
}

void DMApplication::Shutdown()
{
    m_pBaseHelper->Shutdown();
}
