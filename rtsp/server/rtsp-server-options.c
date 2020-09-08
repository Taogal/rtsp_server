//#include "rtsp-server-internal.h"
//
//// RFC 2326 10.1 OPTIONS (p30)
//int rtsp_server_options(struct rtsp_server_t* rtsp, const char* uri)
//{
//	(void)uri;
//	return rtsp_server_reply2(rtsp, 200, "Public: DESCRIBE,SETUP,TEARDOWN,PLAY,PAUSE,ANNOUNCE,RECORD\r\n");
//}
#include "rtsp-server-internal.h"
//这部分代码未使用新版本的option处理方式，仍使用旧版本，可处理option
int rtsp_server_options(struct rtsp_server_t* rtsp, const char* uri)
{
	static const char* methods = "OPTIONS, DESCRIBE, SETUP, TEARDOWN, PLAY, PAUSE, GET_PARAMETER, SET_PARAMETER ANNOUNCE";
	int len;
	(void)uri;

	if (rtsp->handler.onoptions) {
		int ret = rtsp->handler.onoptions(rtsp->param, rtsp, uri);
		if (ret < 0) {
			return 0;
		}
	}


	len = snprintf(rtsp->reply, sizeof(rtsp->reply),
		"RTSP/1.0 200 OK\r\n"
		"CSeq: %u\r\n"
		"Public: %s\r\n"
		"\r\n",
		rtsp->cseq, methods);

	return rtsp->handler.send(rtsp->sendparam, rtsp->reply, len);
}
