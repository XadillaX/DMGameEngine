/** 
 * @file    dmbasehelper.h
 * @brief   DM Game Engine base wrapper header.
 * @author  XadillaX
 * @version 1.0 
 * @date    2013.12.15 
 */
#ifndef __DMBASEHELPER_H__
#define __DMBASEHELPER_H__
#pragma once
#include "globalmacro.h"

class HGE;
class DMGECORE_API DMBaseHelper
{
public:
    DMBaseHelper(void);
    virtual ~DMBaseHelper(void);

    bool                Initialize();
    bool                Start();
    void                Shutdown();

    void                Destroy();

    HGE*                GetObj();

private:
    HGE*                m_pHGE;
};

#endif
