#include "rtsp-server-internal.h"

int rtsp_server_handle(struct rtsp_server_t *rtsp)
{
	char protocol[8];
	int major, minor;
	const char* uri;
	const char* method;

	http_get_version(rtsp->parser, protocol, &major, &minor);
	if (1 != major && 0 != minor)
	{
		//505 RTSP Version Not Supported
		return rtsp_server_reply(rtsp, 505);
	}

	if (0 != http_get_header_by_name2(rtsp->parser, "CSeq", (int*)&rtsp->cseq))
	{
		// 400 Bad Request
		return rtsp_server_reply(rtsp, 400);
	}

	uri = http_get_request_uri(rtsp->parser);
	method = http_get_request_method(rtsp->parser);

	switch (*method)
	{
	case 'o':
	case 'O':
		if (0 == strcasecmp("OPTIONS", method))
			return rtsp_server_options(rtsp, uri);
		break;

	case 'd':
	case 'D':
		if (0 == strcasecmp("DESCRIBE", method))
			return rtsp_server_describe(rtsp, uri);
		break;

	case 's':
	case 'S':
		if (0 == strcasecmp("SETUP", method))
			return rtsp_server_setup(rtsp, uri);
		break;

	case 'p':
	case 'P':
		if (0 == strcasecmp("PLAY", method))
			return rtsp_server_play(rtsp, uri);
		else if (0 == strcasecmp("PAUSE", method))
			return rtsp_server_pause(rtsp, uri);
		break;

	case 't':
	case 'T':
		if (0 == strcasecmp("TEARDOWN", method))
			return rtsp_server_teardown(rtsp, uri);
		break;

    case 'a':
    case 'A':
        if (0 == strcasecmp("ANNOUNCE", method))
            return rtsp_server_announce(rtsp, uri);
        break;

    case 'r':
    case 'R':
        if (0 == strcasecmp("RECORD", method))
            return rtsp_server_record(rtsp, uri);
        break;
	}

	// 501 Not implemented
	return rtsp_server_reply(rtsp, 501);
}
