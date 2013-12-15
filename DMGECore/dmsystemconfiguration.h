/** 
 * @file    dmsystemconfiguration.h
 * @brief   DM Game Engine system configuration header.
 * @author  XadillaX
 * @version 1.0 
 * @date    2013.12.15 
 */
#ifndef __DMSYSTEMCONFIGURATION_H__
#define __DMSYSTEMCONFIGURATION_H__
#pragma once
#include "dmobject.h"

class DMGECORE_API DMSystemConfiguration : public DMObject
{
public:
    DMSystemConfiguration(void);
    virtual ~DMSystemConfiguration(void);

public:
    void                        SetIcon(char* pMAKEINTRESOURCE);
    void                        SetTitle(char* szTitle);
    void                        SetFullScreen(bool bFullScreen = true);

    void                        SetIniFile(char* szIniFile);
    void                        SetLogFile(char* szLogFile);

    void                        SetScreenSize(int nWidth, int nHeight, int nBPP = 32);
    void                        SetScreenWidth(int nWidth);
    void                        SetScreenHeight(int nHeight);
    void                        SetScreenBPP(int nBPP);
    void                        SetFPS(int nFPS);

    void                        SetSampleRate(int nRate);
    void                        SetFxVolume(int nVolume);
    void                        SetMusicVolume(int nVolume);
    void                        SetStreamVolume(int nVolume);

    /**
     * @brief Whether to use texture interpolation or not.
     * Eg. it may be useful to temporarily disable texture filtering when rendering a tile map, as some videocard drivers have bugs resulting in incorrect tile junctions. This state may be set and changed at any time you want.
     *
     * @param bUse whether use or not
     * @refer http://hge.relishgames.com/doc/index.html?hgeconst_systemstate.html
     */
    void                        SetTextureFilter(bool bUse);

private:
    DMBaseHelper*               m_pHelper;
};

#endif
