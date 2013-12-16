/** 
 * @file    dmscenemanager.h
 * @brief   DM Game Engine scene manager header.
 * @author  XadillaX
 * @version 1.0 
 * @date    2013.12.16
 */
#ifndef __DMSCENEMANAGER_H__
#define __DMSCENEMANAGER_H__
#pragma once
#include "dmsingleton.h"
#include "dmobject.h"
#include "dmrenderworker.h"
#include "dmbasescene.h"
#include <map>
#include <string>
using namespace std;

class DMBaseScene;
class DMGECORE_API DMSceneManager : public DMObject, public DMSingleton<DMSceneManager>
{
public:
    virtual ~DMSceneManager(void);

    bool                                Initialize();

    bool                                AddScene(char* szName, DMBaseScene* pScene);
    void                                RemoveScene(char* szName);
    void                                ClearScenes();

    bool                                SetCurrentScene(char* szName);

protected:
    bool                                Update();
    bool                                Render();

private:
    map<string, DMBaseScene*>           m_mpScenes;
    DMBaseScene*                        m_pCurrentScene;
    DMBaseHelper*                       m_pHelper;

    friend bool _DMRenderWorker::_DMRenderUpdate();
    friend bool _DMRenderWorker::_DMRenderRender();
};

#define DMSCENE DMSceneManager::Instance()

#endif
