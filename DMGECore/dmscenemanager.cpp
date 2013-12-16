/** 
 * @file    dmscenemanager.cpp
 * @brief   DM Game Engine scene manager impl.
 * @author  XadillaX
 * @version 1.0 
 * @date    2013.12.16
 */
#include "dmscenemanager.h"
#include "dmbasescene.h"
#include "module\hge\include\hge.h"

DMSINGLETON_IMPL(DMSceneManager);

DMSceneManager::~DMSceneManager(void)
{
    ClearScenes();
}

bool DMSceneManager::Initialize()
{
    m_pHelper = &DMGlobal::g_HGEHelper;

    return true;
}

bool DMSceneManager::AddScene(char* szName, DMBaseScene* pScene)
{
    if(m_mpScenes.find(szName) != m_mpScenes.end())
    {
        return false;
    }

    m_mpScenes[szName] = pScene;
    return true;
}

void DMSceneManager::RemoveScene(char* szName)
{
    map<string, DMBaseScene*>::iterator it = m_mpScenes.find(szName);
    if(it == m_mpScenes.end())
    {
        return;
    }

    it->second->Destroy();
    SAFEDEL(it->second);

    m_mpScenes.erase(it);
}

void DMSceneManager::ClearScenes()
{
    map<string, DMBaseScene*>::iterator it = m_mpScenes.begin();
    for(; it != m_mpScenes.end(); it++)
    {
        it->second->Destroy();
        SAFEDEL(it->second);
        it->second = NULL;
    }

    m_mpScenes.clear();
}

bool DMSceneManager::SetCurrentScene(char* szName)
{
    map<string, DMBaseScene*>::iterator it = m_mpScenes.find(szName);
    if(it == m_mpScenes.end())
    {
        return false;
    }

    m_pCurrentScene = it->second;

    return true;
}

bool DMSceneManager::Update()
{
    static HGE* hge = m_pHelper->GetObj();
    static float fDeltaTime = 0.0f;
    if(m_pCurrentScene)
    {
        if(!hge) hge = m_pHelper->GetObj();
        if(!hge) return false;

        fDeltaTime = hge->Timer_GetDelta();

        return m_pCurrentScene->Update(fDeltaTime);
    }

    return false;
}

bool DMSceneManager::Render()
{
    static HGE* hge = m_pHelper->GetObj();
    static float fDeltaTime = 0.0f;
    if(m_pCurrentScene)
    {
        if(!hge) hge = m_pHelper->GetObj();
        if(!hge) return false;

        fDeltaTime = hge->Timer_GetDelta();

        hge->Gfx_BeginScene();
        hge->Gfx_Clear(0xff000000);
        bool result = m_pCurrentScene->Render(fDeltaTime);
        hge->Gfx_EndScene();

        return result;
    }

    return false;
}
