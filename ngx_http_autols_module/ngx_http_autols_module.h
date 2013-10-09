#ifndef _NGX_HTTP_AUTOLS_MODULE_INCLUDED_
#define _NGX_HTTP_AUTOLS_MODULE_INCLUDED_

#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_http.h>
#include "ngxStringBuilder.h"

#if NGX_PCRE && !_MSC_VER
#define USE_REGEX 1
#else
#define USE_REGEX 0
#endif


#define STRING_PREALLOCATE  50
#if STRING_PREALLOCATE < 1
#error STRING_PREALLOCATE must at least be higher than 0
#endif

#define CLOSE_DIRECTORY_OK 0
#define CLOSE_DIRECTORY_ERROR 1


#define logHttpDebugMsg0(log, fmt)                                                 ngx_log_debug0(NGX_LOG_DEBUG_HTTP, log, 0, fmt)
#define logHttpDebugMsg1(log, fmt, arg1)                                           ngx_log_debug1(NGX_LOG_DEBUG_HTTP, log, 0, fmt, arg1)
#define logHttpDebugMsg2(log, fmt, arg1, arg2)                                     ngx_log_debug2(NGX_LOG_DEBUG_HTTP, log, 0, fmt, arg1, arg2)
#define logHttpDebugMsg3(log, fmt, arg1, arg2, arg3)                               ngx_log_debug3(NGX_LOG_DEBUG_HTTP, log, 0, fmt, arg1, arg2, arg3)
#define logHttpDebugMsg4(log, fmt, arg1, arg2, arg3, arg4)                         ngx_log_debug4(NGX_LOG_DEBUG_HTTP, log, 0, fmt, arg1, arg2, arg3, arg4)
#define logHttpDebugMsg5(log, fmt, arg1, arg2, arg3, arg4, arg5)                   ngx_log_debug5(NGX_LOG_DEBUG_HTTP, log, 0, fmt, arg1, arg2, arg3, arg4, arg5)
#define logHttpDebugMsg6(log, fmt, arg1, arg2, arg3, arg4, arg5, arg6)             ngx_log_debug6(NGX_LOG_DEBUG_HTTP, log, 0, fmt, arg1, arg2, arg3, arg4, arg5, arg6)
#define logHttpDebugMsg7(log, fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7)       ngx_log_debug7(NGX_LOG_DEBUG_HTTP, log, 0, fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7)
#define logHttpDebugMsg8(log, fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) ngx_log_debug8(NGX_LOG_DEBUG_HTTP, log, 0, fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8)

static ngx_str_t ptnReplyCharSetStr = ngx_string("ReplyCharSet");
static ngx_str_t ptnRequestUriStr = ngx_string("RequestUri");

static ngx_str_t ptnJsVariableStartStr = ngx_string("JSVariableStart");
static ngx_str_t ptnJsVariableEndStr = ngx_string("JSVariableEnd");

static ngx_str_t ptnJsSourceStartStr = ngx_string("JSSourceStart");
static ngx_str_t ptnJsSourceEndStr = ngx_string("JSSourceEnd");

static ngx_str_t ptnCssSourceStartStr = ngx_string("CSSSourceStart");
static ngx_str_t ptnCssSourceEndStr = ngx_string("CSSSourceEnd");

static ngx_str_t ptnBodyStartStr = ngx_string("BodyStart");
static ngx_str_t ptnBodyEndStr = ngx_string("BodyEnd");

static ngx_str_t ptnEntryStartStr = ngx_string("EntryStart");
static ngx_str_t ptnEntryIsDirectoryStr = ngx_string("EntryIsDirectory");
static ngx_str_t ptnEntryModifiedOnStr = ngx_string("EntryModifiedOn");
static ngx_str_t ptnEntrySizeStr = ngx_string("EntrySize");
static ngx_str_t ptnEntryNameStr = ngx_string("EntryName");
static ngx_str_t ptnEntryEndStr = ngx_string("EntryEnd");


static ngx_str_t ptnAttNoCountStr = ngx_string("NoCount");
static ngx_str_t ptnAttStartAtStr = ngx_string("StartAt");
static ngx_str_t ptnAttEscapeStr = ngx_string("Escape");
static ngx_str_t ptnAttUriComponentStr = ngx_string("UriComponent");
static ngx_str_t ptnAttHttpStr = ngx_string("Http");
static ngx_str_t ptnAttUriStr = ngx_string("Uri");
static ngx_str_t ptnAttFormatStr = ngx_string("Format");
static ngx_str_t ptnAttMaxLengthStr = ngx_string("MaxLength");

static u_char defaultPagePattern[] =
    "<!DOCTYPE html>" CRLF
    "<html>" CRLF
    "  <head>" CRLF
    "    <meta charset=\"&{ReplyCharSet}\">" CRLF
    "    <title>Index of &{RequestUri}</title>&{JSVariableStart}" CRLF
    "    <script type=\"text/javascript\">" CRLF
    "      var dirListing = [&{EntryStart}" CRLF
    "        {" CRLF
    "          \"isDirectory\": &{EntryIsDirectory}," CRLF
    "          \"modifiedOn\": \"&{EntryModifiedOn}\"," CRLF
    "          \"size\": &{EntrySize}," CRLF
    "          \"name\": \"&{EntryName}\"" CRLF
    "        },&{EntryEnd}" CRLF
    "      ]" CRLF
    "    </script>&{JSVariableEnd}&{JSSourceStart}" CRLF
    "    <script type=\"text/javascript\" src=\"&{JSSource}\"></script>&{JSSourceEnd}&{CSSSourceStart}" CRLF
    "    <link rel=\"stylesheet\" type=\"text/css\" href=\"&{CSSSource}\">&{CSSSourceEnd}" CRLF
    "  </head>" CRLF
    "  <body bgcolor=\"white\">&{BodyStart}" CRLF
    "    <h1>Index of &{RequestUri}</h1>" CRLF
    "    <hr>" CRLF
    "    <pre>&{EntryStart}<a href=\"&{EntryName?Escape=Uri&NoCount}\">&{EntryName?MaxLength=66}</a>&{EntryModifiedOn?StartAt=82} &{EntrySize?Format=%24s}&{EntryEnd}</pre>&{BodyEnd}" CRLF
    "  </body>" CRLF
    "</html>";

static char defaultPagePattern2[] =
    "<!DOCTYPE html>" CRLF
    "<html>" CRLF
    "  <head>" CRLF
    "    <meta charset=\"<!--[ReplyCharSet]-->\">" CRLF
    "    <title>Index of <!--[RequestUri]--></title><!--{JSVariable}-->" CRLF
    "    <script type=\"text/javascript\">" CRLF
    "      var dirListing = [<!--{EntryLoop}-->" CRLF
    "        {" CRLF
    "          \"isDirectory\": <!--[EntryIsDirectory]-->," CRLF
    "          \"modifiedOn\": \"<!--[EntryModifiedOn]-->\"," CRLF
    "          \"size\": <!--[EntrySize]-->," CRLF
    "          \"name\": \"<!--[EntryName]-->\"" CRLF
    "        ]-->,<!--{/EntryLoop}-->" CRLF
    "      ]" CRLF
    "    </script><!--{/JSVariable}--><!--{JSSource}-->" CRLF
    "    <script type=\"text/javascript\" src=\"<!--[JSSource]-->\"></script><!--{/JSSource}--><!--{CSSSource}-->" CRLF
    "    <link rel=\"stylesheet\" type=\"text/css\" href=\"<!--[CSSSource]-->\"><!--{/CSSSource}-->" CRLF
    "  </head>" CRLF
    "  <body bgcolor=\"white\"><!--{Body}-->" CRLF
    "    <h1>Index of <!--[RequestUri]--></h1>" CRLF
    "    <hr>" CRLF
    "    <pre><!--{Entry}--><a href=\"<!--[EntryName?Escape=Uri&NoCount]-->\"><!--[EntryName?MaxLength=66]--></a><!--[EntryModifiedOn?StartAt=82]--> <!--[EntrySize?Format=%24s]--><!--[EntryEnd]--></pre><!--{/Body}-->" CRLF
    "  </body>" CRLF
    "</html>";

enum {
    CounterMainMergeCall, CounterSrvMergeCall, CounterLocMergeCall,
    CounterMainCreateCall, CounterSrvCreateCall, CounterLocCreateCall,
    CounterHandlerInvoke, CounterPatternParse, CounterFileCount, CounterLimit
};
static const char *counterNames[] = {
    "MainMergeCall","SrvMergeCall","LocMergeCall",
    "MainCreateCall","SrvCreateCall","LocCreateCall",
    "HandlerInvoke", "TemplateParse", "FileCount"
};
static int counters[CounterLimit];

#define ngx_str_compare(a,b) ((a)->len == (b)->len && !ngx_memcmp((a)->data, (b)->data, (a)->len))

typedef ngx_int_t ngx_rc_t;
ngx_rc_t ngx_http_autols_init(ngx_conf_t *cf);

void *ngx_http_autols_create_main_conf(ngx_conf_t *cf);
char *ngx_http_autols_init_main_conf(ngx_conf_t *cf, void *conf);

void *ngx_http_autols_create_loc_conf(ngx_conf_t *cf);
char *ngx_http_autols_merge_loc_conf(ngx_conf_t *cf, void *parent, void *child);

ngx_rc_t ngx_http_autols_handler(ngx_http_request_t *r);

char* ngx_conf_autols_regex_then_string_array_slot(ngx_conf_t *cf, ngx_command_t *cmd, void *conf);


typedef struct {
    ngx_pool_t *pool;

    ngx_array_t patterns;
} ngx_http_autols_main_conf_t;

typedef struct {
    ngx_flag_t enable, createJsVariable, createBody, localTime;
    ngx_str_t charSet, jsSourcePath, cssSourcePath, pagePatternPath;
    ngx_array_t *entryIgnores;
} ngx_http_autols_loc_conf_t;


typedef struct { ngx_str_t name, value; } alsPatternAttribute;

typedef struct {
    ngx_str_t name;
    size_t startAt, endAt;
    ngx_array_t attributes;
} alsPatternToken;

typedef struct {
    ngx_str_t path;

    ngx_str_t content;
    ngx_array_t tokens;
} alsPattern;


typedef struct {
    ngx_http_autols_main_conf_t *mainConf;
    ngx_http_autols_loc_conf_t *locConf;
    ngx_http_request_t *request;
    ngx_pool_t *pool;
    ngx_log_t *log;

    ngx_str_t requestPath;
	int32_t requestPathCapacity;

    int32_t ptnEntryStartPos;
} alsConnectionConfig;


typedef struct {
    ngx_array_t fileEntries;

	int64_t totalFileSize;

	int32_t totalFileNamesLength;
	int32_t totalFileNamesLengthUriEscaped;
    int32_t totalFileNamesLengthHtmlEscaped;
} alsFileEntriesInfo;

typedef struct {
    ngx_str_t name;

    unsigned isDirectory:1;
    ngx_tm_t modifiedOn;
	int64_t size;

	int32_t nameLenAsHtml, nameLenAsUri;
} alsFileEntry;


extern ngx_module_t  ngx_http_autols_module;

#endif