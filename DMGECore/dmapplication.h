/** 
 * @file    dmapplication.h
 * @brief   DM Game Engine application header.
 * @author  XadillaX
 * @version 1.0 
 * @date    2013.12.15 
 */
#ifndef __DMAPPLICATION_H__
#define __DMAPPLICATION_H__
#pragma once
#include "dmobject.h"
#include "dmsingleton.h"
#include "dmbasehelper.h"
#include "dmscenemanager.h"
#include "dmsystemconfiguration.h"

class DMGECORE_API DMApplication : public DMObject, public DMSingleton<DMApplication>
{
public:
    virtual ~DMApplication(void);

    void                                InitializeEnviroment();

    DMBaseHelper*                       GetHelper();
    DMSystemConfiguration*              GetConfig();

    bool                                Initialize();
    bool                                Start();
    void                                Shutdown();

private:
    DMBaseHelper*                       m_pBaseHelper;
    DMSystemConfiguration*              m_pSystemConfiguration;
};

#define DMAPP DMApplication::Instance()
#define DMAPP_INIT DMApplication::Instance().InitializeEnviroment

#endif
