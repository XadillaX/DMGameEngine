/** 
 * @file    dmrenderworker.cpp
 * @brief   DM Game Engine render worker impl.
 * @author  XadillaX
 * @version 1.0 
 * @date    2013.12.15 
 */
#include "dmrenderworker.h"
#include "dmscenemanager.h"
#include "module\hge\include\hge.h"

bool _DMRenderWorker::_DMRenderRender()
{
    return DMSCENE.Render();
}

bool _DMRenderWorker::_DMRenderUpdate()
{
    return DMSCENE.Update();
}
