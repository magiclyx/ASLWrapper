//
//  log.h
//  testLog
//
//  Created by Yuxi Liu on 9/25/12.
//  Copyright (c) 2012 Yuxi Liu. All rights reserved.
//



#ifndef _YXASL_LOG_H_
#define _YXASL_LOG_H_

#include <asl.h>

typedef void* HSL_Handle;
typedef int SL_BOOL;
#define SL_FALSE 0
#define SL_TRUE (!(0))


HSL_Handle YXASL_InitUserLog(const char *ident, const char *facility, const char* dirName, const char* fileName);
HSL_Handle YXASL_InitSyeLog(const char *ident, const char *facility, const char* dirName, const char* fileName);


int YXASL_bindLogFile(HSL_Handle handle, const char* dirName, const char* fileName);

void YXASL_setIdent(HSL_Handle handle, const char* ident);
void YXASL_setFacility(HSL_Handle handle, const char* facility);

const char* YXASL_Identifier(HSL_Handle handle);
const char* YXASL_Facility(HSL_Handle handle);
const char* YXASL_DirName(HSL_Handle handle);
const char* YXASL_FileName(HSL_Handle handle);


void YXASL_ReleaseUserLog(HSL_Handle* handleRef);
void YXASL_Log(HSL_Handle handle, int level, const char* msg);
void YXASL_LogFmt(HSL_Handle handle, int level, const char* fmt, ...);
void YXASL_SetLevel(HSL_Handle handle, int level);


//int asl_set(aslmsg msg, const char *key, const char *value);
//int SL_SetContext(HSL_Handle handle, const char *key, const char *value);


#define YXASL_ERR_MSG(handle, msg)      YXASL_Log(handle, ASL_LEVEL_ERR, msg);
#define YXASL_WARN_MSG(handle, msg)     YXASL_Log(handle, ASL_LEVEL_WARNING, msg);
#define YXASL_DEBUG_MSG(handle, msg)    YXASL_Log(handle, ASL_LEVEL_DEBUG, fmt, msg);
#define YXASL_INFO_MSG(handle, msg)     YXASL_Log(handle, ASL_LEVEL_INFO, fmt, msg);
#define YXASL_FATAL_MSG(handle, msg)    YXASL_Log(handle, ASL_LEVEL_CRIT, fmt, msg);


#define YXASL_ERR_FMT(handle, fmt, ...)      YXASL_LogFmt(handle, ASL_LEVEL_ERR, fmt, __VA_ARGS__);
#define YXASL_WARN_FMT(handle, fmt, ...)     YXASL_LogFmt(handle, ASL_LEVEL_WARNING, fmt, __VA_ARGS__);
#define YXASL_DEBUG_FMT(handle, fmt, ...)    YXASL_LogFmt(handle, ASL_LEVEL_DEBUG, fmt, __VA_ARGS__);
#define YXASL_INFO_FMT(handle, fmt, ...)     YXASL_LogFmt(handle, ASL_LEVEL_INFO, fmt, __VA_ARGS__);
#define YXASL_FATAL_FMT(handle, fmt, ...)    YXASL_LogFmt(handle, ASL_LEVEL_CRIT, fmt, __VA_ARGS__);


#endif //_YXASL_LOG_H_
                                                                                                                          



