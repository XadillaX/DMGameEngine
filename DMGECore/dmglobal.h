/** 
 * @file    dmglobal.h
 * @brief   DM Game Engine global header.
 * @author  XadillaX
 * @version 1.0 
 * @date    2013.12.15 
 */
#ifndef __DMGLOBAL_H__
#define __DMGLOBAL_H__
#pragma once
#include <windows.h>
#include "module\hge\include\hgecolor.h"
#include "globalmacro.h"
#include "dmbasehelper.h"

typedef DWORD DMBlend;
typedef hgeVertex DMVertex;
typedef hgeColor DMColorObject;
typedef DWORD DMColor;

namespace DMGlobal
{
    extern DMBaseHelper         g_HGEHelper;
};

#endif
