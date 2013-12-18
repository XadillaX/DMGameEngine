/** 
 * @file    dmsystemconfiguration.cpp
 * @brief   DM Game Engine system configuration impl.
 * @author  XadillaX
 * @version 1.0 
 * @date    2013.12.15 
 */
#include "dmsystemconfiguration.h"
#include "module\hge\include\hge.h"

DMSystemConfiguration::DMSystemConfiguration(void) :
    m_pHelper(NULL)
{
    m_pHelper = &DMGlobal::g_HGEHelper;

    m_pHelper->GetObj()->System_SetState(HGE_USESOUND, true);
    m_pHelper->GetObj()->System_SetState(HGE_ZBUFFER, true);
    m_pHelper->GetObj()->System_SetState(HGE_DONTSUSPEND, true);
    m_pHelper->GetObj()->System_SetState(HGE_SHOWSPLASH, false);

    m_pHelper->GetObj()->System_SetState(HGE_TITLE, "Death Moon Game Engine");
}

DMSystemConfiguration::~DMSystemConfiguration(void)
{
}

void DMSystemConfiguration::SetIcon(char* pMAKEINTRESOURCE)
{
    m_pHelper->GetObj()->System_SetState(HGE_ICON, pMAKEINTRESOURCE);
}

void DMSystemConfiguration::SetTitle(char* szTitle)
{
    m_pHelper->GetObj()->System_SetState(HGE_TITLE, szTitle);
}

void DMSystemConfiguration::SetIniFile(char* szIniFile)
{
    m_pHelper->GetObj()->System_SetState(HGE_INIFILE, szIniFile);
}

void DMSystemConfiguration::SetLogFile(char* szLogFile)
{
    m_pHelper->GetObj()->System_SetState(HGE_LOGFILE, szLogFile);
}

void DMSystemConfiguration::SetFullScreen(bool bFullScreen)
{
    m_pHelper->GetObj()->System_SetState(HGE_WINDOWED, !bFullScreen);
}

void DMSystemConfiguration::SetShowMouse(bool bShow)
{
    m_pHelper->GetObj()->System_SetState(HGE_HIDEMOUSE, !bShow);
}

void DMSystemConfiguration::SetScreenSize(int nWidth, int nHeight, int nBPP)
{
    SetScreenWidth(nWidth);
    SetScreenHeight(nHeight);
    SetScreenBPP(nBPP);
}

void DMSystemConfiguration::SetScreenWidth(int nWidth)
{
    m_pHelper->GetObj()->System_SetState(HGE_SCREENWIDTH, nWidth);
}

void DMSystemConfiguration::SetScreenHeight(int nHeight)
{
    m_pHelper->GetObj()->System_SetState(HGE_SCREENHEIGHT, nHeight);
}

void DMSystemConfiguration::SetScreenBPP(int nBPP)
{
    m_pHelper->GetObj()->System_SetState(HGE_SCREENBPP, nBPP);
}

void DMSystemConfiguration::SetFPS(int nFPS)
{
    m_pHelper->GetObj()->System_SetState(HGE_FPS, nFPS);
}

void DMSystemConfiguration::SetSampleRate(int nRate)
{
    m_pHelper->GetObj()->System_SetState(HGE_SAMPLERATE, nRate);
}

void DMSystemConfiguration::SetFxVolume(int nVolume)
{
    m_pHelper->GetObj()->System_SetState(HGE_FXVOLUME, nVolume);
}

void DMSystemConfiguration::SetMusicVolume(int nVolume)
{
    m_pHelper->GetObj()->System_SetState(HGE_MUSVOLUME, nVolume);
}

void DMSystemConfiguration::SetStreamVolume(int nVolume)
{
    m_pHelper->GetObj()->System_SetState(HGE_STREAMVOLUME, nVolume);
}

void DMSystemConfiguration::SetTextureFilter(bool bUse)
{
    m_pHelper->GetObj()->System_SetState(HGE_TEXTUREFILTER, bUse);
}
