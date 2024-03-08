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
		cvector sync_accounter;//同步订阅，在发布者支持同步条件下会同步调用
		cvector async_accounter;//由topic线程转发的

	}abus_topic_t;
	int abus_topic_init(abus_topic_t* topic);
#ifdef __cpluscplus
}
#endif
#endif