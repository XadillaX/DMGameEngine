/** 
 * @file    dmbasescene.h
 * @brief   DM Game Engine base scene header.
 * @author  XadillaX
 * @version 1.0 
 * @date    2013.12.16
 */
#ifndef __DMBASESCENE_H__
#define __DMBASESCENE_H__
#pragma once
#include "dmobject.h"
#include "dmrenderhelper.h"

class DMGECORE_API DMBaseScene : public DMObject
{
public:
    DMBaseScene(void);
    virtual ~DMBaseScene(void);

    virtual bool                Initialize();
    virtual void                Destroy();

    virtual bool                Update(float fDeltaTime);
    virtual bool                Render(float fDeltaTime);

protected:
    DMRenderHelper*             m_pRender;
    DMBaseHelper*               m_pHelper;
    char                        m_szSceneName;
};

#endif
