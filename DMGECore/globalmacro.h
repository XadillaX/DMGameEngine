/** 
 * @file    globalmacro.h
 * @brief   DM Game Engine global macro(s).
 * @author  XadillaX
 * @version 1.0 
 * @date    2013.12.15 
 */
#ifndef __GLOBALMACRO_H__
#define __GLOBALMACRO_H__

#define NULL 0

#ifdef DMGECORE_EXPORTS
#define DMGECORE_API __declspec(dllexport)
#else
#define DMGECORE_API __declspec(dllimport)
#endif

/**
 * Safely delete one pointer.
 */
#define SAFEDEL(p)          { if(p) { delete p; p = NULL; } }

/**
 * Safely delete one pointer of array.
 */
#define SAFEDEL_ARRAY(p)    { if(p) { delete []p; p = NULL; } }

/**
 * Defination of singleton.
 */
#define DMSINGLETON_IMPL(T) template<> \
    T& DMSingleton<T>::Instance() \
    { \
        static T instance; \
        return instance; \
    }

#endif
