#include "rtsp-server-internal.h"

int rtsp_server_get_parameter(struct rtsp_server_t *rtsp, const char* uri)
{
    const char *psession;
    if(rtsp == NULL)
    {
    	assert(0);
    	return -1;
    }

    psession = http_get_header_by_name(rtsp->parser, "Session");

    rtsp->session.session[0] = 0; // clear session value
    if (!psession || 0 != rtsp_header_session(psession, &rtsp->session))
    {
        // 454 (Session Not Found)
        return rtsp_server_reply(rtsp, 454);
    }

    return rtsp->handler.ongetparameter(rtsp->param, rtsp, rtsp->session.session);
}

int rtsp_server_reply_get_parameter(struct rtsp_server_t *rtsp, int code, const char* sessionid)
{

	int len;
	char header[1024];

	// RTP/AVP;unicast;client_port=4588-4589;server_port=6256-6257
	len = snprintf(header, sizeof(header), "Session: %s\r\n",sessionid ? sessionid : "");
	if (len < 0 || len == sizeof(header))
	{
		assert(0); // transport or sessionid too long
		return -1;
	}
	return rtsp_server_reply2(rtsp, code, header);
}
