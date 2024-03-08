#ifndef ABUS_TOPIC_H
#define ABUS_TOPIC_H
#ifdef __cpluscplus
extern "C" {
#endif

#define ABUS_TOPIC_STATIC(name,_struct_)

#include "cvector.h"
	typedef struct abus_accounter abus_accounter_t;
	typedef struct subscriber abus_subscriber_t;
	typedef int(*sub_callback)(abus_subscriber_t* sub);
	typedef struct abus_accounter {
		const char* name;
	}abus_accounter_t;
	typedef struct subscriber{
		abus_accounter_t* accounter;
			sub_callback acllback;
	}abus_subscriber_t;
	typedef struct abus_topic{
		const char* name;
		cvector sync_accounter;//ͬ�����ģ��ڷ�����֧��ͬ�������»�ͬ������
		cvector async_accounter;//��topic�߳�ת����

	}abus_topic_t;
	int abus_topic_init(abus_topic_t* topic);
#ifdef __cpluscplus
}
#endif
#endif