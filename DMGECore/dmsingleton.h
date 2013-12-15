/** 
 * @file    dmsingleton.h
 * @brief   DM Game Engine singleton design pattern.
 * @author  XadillaX
 * @version 1.0 
 * @date    2013.12.15 
 */
#ifndef __DMSINGLETON_H__
#define __DMSINGLETON_H__
#pragma once
#include "globalmacro.h"

template <class T>
class DMGECORE_API DMSingleton
{
public:
    static T& Instance();

protected:
    DMSingleton(){}
    virtual ~DMSingleton(){}
    DMSingleton(DMSingleton const &){}
    DMSingleton & operator = (DMSingleton const &){return *this;}
};

#endif

