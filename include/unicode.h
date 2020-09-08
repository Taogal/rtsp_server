#ifndef _unicode_h_
#define _unicode_h_

#include <wchar.h>

#ifndef IN
#define IN 
#endif

#ifndef OUT
#define OUT
#endif

#ifdef  __cplusplus
extern "C" {
#endif

/// Unicode�ַ���ת����UTF-8�ַ���
/// @param[in] src Unicode�ַ���
/// @param[in] srcLen Unicode�ַ�������(length=wcslen(src)), srcLenΪ0ʱת�������ַ���(src�������ַ�'0'��β)
/// @param[out] tgt utf8�ַ���������
/// @param[in] tgtBytes in-����������, ��λ�ֽ�
/// @return ת�����ַ�������
int unicode_to_utf8(IN const wchar_t* src, IN size_t srcLen, OUT char* tgt, IN size_t tgtBytes);

/// UTF-8�ַ���ת����Unicode�ַ���
/// @param[in] src utf-8�ַ���
/// @param[in] srcLen utf-8�ַ�������(length=wcslen(src)), srcLenΪ0ʱת�������ַ���(src�������ַ�'0'��β)
/// @param[out] tgt unicode�ַ���������
/// @param[in] tgtBytes in-����������, ��λ�ֽ�
/// @return ת�����ַ�������
int unicode_from_utf8(IN const char* src, IN size_t srcLen, OUT wchar_t* tgt, IN size_t tgtBytes);

/// Unicode�ַ���ת���ɶ��ֽ��ַ���(Windowsƽ̨��Unicode UTF-16)
/// @param[in] src Unicode�ַ���
/// @param[in] srcLen �ַ�������, nΪ0ʱת�������ַ���(��ʱsrc�������ַ�'0'��β)
/// @param[out] tgt ���ֽ��ַ���������
/// @param[in] tgtBytes ���ֽ��ַ�������������, ��λ: �ֽ�
/// @return ת�����ַ�������
int unicode_to_mbcs(IN const wchar_t* src, IN size_t srcLen, OUT char* tgt, IN size_t tgtBytes);

/// ���ֽ��ַ���ת����Unicode�ַ���(Windowsƽ̨��Unicode UTF-16)
/// @param[in] src ���ֽ��ַ���
/// @param[in] srcLen �ַ�������, nΪ0ʱת�������ַ���(��ʱsrc�������ַ�'0'��β)
/// @param[out] tgt Unicode�ַ���������
/// @param[in] tgtBytes Unicode�ַ�������������, ��λ: �ֽ�
/// @return ת�����ַ�������
int unicode_from_mbcs(IN const char* src, IN size_t srcLen, OUT wchar_t* tgt, IN size_t tgtBytes);

/// ���ֽ��ַ���ת����Unicode�ַ���(Windowsƽ̨��Unicode UTF-16)
/// @param[in] charset ���ֽ��ַ�����������
/// @param[in] src ���ֽ��ַ���
/// @param[in] srcLen �ַ�������, nΪ0ʱת�������ַ���(��ʱsrc�������ַ�'0'��β)
/// @param[out] tgt Unicode�ַ���������
/// @param[in] tgtBytes Unicode�ַ�������������, ��λ: �ֽ�
/// @return
//int unicode_encode(IN const char* charset, IN const char* src, IN size_t srcLen, OUT wchar_t* tgt, IN size_t tgtBytes);

/// Unicode�ַ���ת���ɶ��ֽ��ַ���(Windowsƽ̨��Unicode UTF-16)
/// @param[in] charset ���ֽ��ַ�����������
/// @param[in] src Unicode�ַ���
/// @param[in] srcLen �ַ�������, nΪ0ʱת�������ַ���(��ʱsrc�������ַ�'0'��β)
/// @param[out] tgt ���ֽ��ַ���������
/// @param[in] tgtBytes ���ֽ��ַ�������������, ��λ: �ֽ�
/// @return
//int unicode_decode(IN const char* charset, IN const wchar_t* src, IN size_t srcLen, OUT char* tgt, IN size_t tgtBytes);

#define unicode_to_gb2312 unicode_to_gb18030
#define unicode_from_gb2312 unicode_from_gb18030
#define unicode_to_gbk unicode_to_gb18030
#define unicode_from_gbk unicode_from_gb18030

int unicode_to_gb18030(IN const wchar_t* src, IN size_t srcLen, OUT char* tgt, IN size_t tgtBytes);
int unicode_from_gb18030(IN const char* src, IN size_t srcLen, OUT wchar_t* tgt, IN size_t tgtBytes);

#ifdef  __cplusplus
} // extern "C" 
#endif

#endif /* _unicode_h_ */
