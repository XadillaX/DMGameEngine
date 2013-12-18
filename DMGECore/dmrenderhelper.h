/** 
 * @file    dmrenderhelper.h
 * @brief   DM Game Engine render helper header.
 * @author  XadillaX
 * @version 1.0 
 * @date    2013.12.18
 */
#ifndef __DMRENDERHELPER_H__
#define __DMRENDERHELPER_H__
#pragma once
#include "dmobject.h"
#include "dmimageresourcemanager.h"

class HGE;

struct DMGECORE_API DMTripleDrawer
{
    ImageID                 ImageId;
    DMVertex                Vertex[3];
    DMBlend                 Blend;

    DMTripleDrawer()
    {
        ImageId = 0;
        Blend = BLEND_ALPHAADD | BLEND_COLORMUL | BLEND_ZWRITE;
        for(int i = 0; i < 3; i++)
        {
            Vertex[i].col = 0xffffffff;
            Vertex[i].x = Vertex[i].y =
            Vertex[i].tx = Vertex[i].ty = 0;
            Vertex[i].z = 0.5f;
        }
    }
};

class DMGECORE_API DMRenderHelper : public DMObject
{
public:
    DMRenderHelper(void);
    virtual ~DMRenderHelper(void);

    void                    ClearScreen(DMColorObject color);
    void                    ClearScreen(DMColor color = 0xff000000);

    void                    DrawLine(float x1, float y1, float x2, float y2, DMColor color = 0xff000000, float z = 0.5f);
    void                    DrawTriple(DMTripleDrawer* triple);
    void                    DrawQuad(){}///< TODO.

private:
    HGE*                    m_pHGE;
};

#endif
