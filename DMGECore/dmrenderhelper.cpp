/** 
 * @file    dmrenderhelper.cpp
 * @brief   DM Game Engine render helper impl.
 * @author  XadillaX
 * @version 1.0 
 * @date    2013.12.18
 */
#include "dmrenderhelper.h"
#include "module\hge\include\hge.h"

DMRenderHelper::DMRenderHelper(void) :
    m_pHGE(NULL)
{
    m_pHGE = hgeCreate(HGE_VERSION);
}

DMRenderHelper::~DMRenderHelper(void)
{
    if(m_pHGE)
    {
        m_pHGE->Release();
    }

    m_pHGE = NULL;
}

void DMRenderHelper::ClearScreen(DMColorObject color)
{
    ClearScreen(color.GetHWColor());
}

void DMRenderHelper::ClearScreen(DMColor color)
{
    m_pHGE->Gfx_Clear(color);
}

void DMRenderHelper::DrawLine(float x1, float y1, float x2, float y2, DMColor color, float z)
{
    m_pHGE->Gfx_RenderLine(x1, y1, x2, y2, color, z);
}

void DMRenderHelper::DrawTriple(DMTripleDrawer* triple)
{
    hgeTriple tp;
    tp.blend = triple->Blend;
    tp.tex = triple->ImageId;
    memcpy(tp.v, triple->Vertex, sizeof(tp.v));

    m_pHGE->Gfx_RenderTriple(&tp);
}
