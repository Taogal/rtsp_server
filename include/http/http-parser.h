#ifndef _http_parser_h_
#define _http_parser_h_

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct http_parser_t http_parser_t;

enum HTTP_PARSER_MODE { 
	HTTP_PARSER_CLIENT = 0, 
	HTTP_PARSER_SERVER = 1
};

/// get/set maximum body size(global setting)
/// @param[in] bytes 0-unlimited, other-limit bytes
int http_get_max_size();
int http_set_max_size(size_t bytes);

/// create
/// @param[in] mode 1-server mode, 0-client mode
/// @return parser instance
http_parser_t* http_parser_create(enum HTTP_PARSER_MODE mode);

/// destroy
/// @return 0-ok, other-error
int http_parser_destroy(http_parser_t* parser);

/// clear state
void http_parser_clear(http_parser_t* parser);

/// input data
/// @param[in] data content
/// @param[in/out] bytes out-remain bytes
/// @return 1-need more data, 0-receive done, <0-error
int http_parser_input(http_parser_t* parser, const void* data, size_t *bytes);

/// HTTP start-line
int http_get_version(http_parser_t* parser, char protocol[64], int *major, int *minor);
int http_get_status_code(http_parser_t* parser);
const char* http_get_status_reason(http_parser_t* parser);
const char* http_get_request_uri(http_parser_t* parser);
const char* http_get_request_method(http_parser_t* parser);

/// HTTP body(use with http_get_content_length)
const void* http_get_content(http_parser_t* parser);

/// HTTP headers
/// @return 0-ok, other-error
int http_get_header_count(http_parser_t* parser);
/// @return 0-ok, <0-don't have header
int http_get_header(http_parser_t* parser, int idx, const char** name, const char** value);
/// @return NULL-don't found header, other-header value
const char* http_get_header_by_name(http_parser_t* parser, const char* name);
/// @return 0-ok, <0-don't have header
int http_get_header_by_name2(http_parser_t* parser, const char* name, int *value);
/// @return >=0-content-length, <0-don't have content-length header
int http_get_content_length(http_parser_t* parser);
/// @return 1-close, 0-keep-alive, <0-don't have connection header
int http_get_connection(http_parser_t* parser);
/// @return Content-Type, NULL-don't have this header
const char* http_get_content_type(http_parser_t* parser);
/// @return Content-Encoding, NULL-don't have this header
const char* http_get_content_encoding(http_parser_t* parser);
/// @return Transfer-Encoding, NULL-don't have this header
const char* http_get_transfer_encoding(http_parser_t* parser);
/// @return Set-Cookie, 0-don't have this header
const char* http_get_cookie(http_parser_t* parser);
/// @return Location, 0-don't have this header
const char* http_get_location(http_parser_t* parser);

#ifdef __cplusplus
}
#endif
#endif /* !_http_parser_h_ */
