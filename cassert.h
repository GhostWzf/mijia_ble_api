

#ifndef __CASSERT_H__
#define __CASSERT_H__



#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include "ke_mem.h"
#include "uart.h"
#include "arch_console.h"



int COMPrintf_hexdump(uint8_t *parr,uint8_t len);

//���ʹ��ͬ����ӡ
#ifdef CFG_SYNC_PRINTF
		int COMPrintf(const char* fmt, ...);
		#undef arch_printf
		int arch_printf(const char *fmt, ...);
#else		//�첽��ӡ���߲���ӡ
		#ifndef CFG_PRINTF
				#undef arch_printf
		#endif
		#define COMPrintf    arch_printf
		//����ӡ��ʽ(����lib����Ĭ�ϵ��ǵ��� arch_printf ������arch_printf�����Ժ����ķ�ʽʵ��)
		#ifndef CFG_PRINTF_UART2
				int arch_printf(const char *fmt, ...);
		#endif
		
#endif





#endif

