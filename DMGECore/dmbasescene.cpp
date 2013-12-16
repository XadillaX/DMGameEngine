/** 
 * @file    dmbasescene.cpp
 * @brief   DM Game Engine base scene impl.
 * @author  XadillaX
 * @version 1.0 
 * @date    2013.12.16
 */
#include "dmbasescene.h"

DMBaseScene::DMBaseScene(void) :
    m_pHelper(&DMGlobal::g_HGEHelper)
{
}

DMBaseScene::~DMBaseScene(void)
{
}

bool DMBaseScene::Initialize()
{
    return true;
}

void DMBaseScene::Destroy()
{
}

bool DMBaseScene::Update(float fDeltaTime)
{
    return false;
}

bool DMBaseScene::Render(float fDeltaTime)
{
    return false;
}
