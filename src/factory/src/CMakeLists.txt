project(factory)

include_directories(
    ../include
    /home/zhchen/github/workflow/src/kernel/include
    /home/zhchen/github/workflow/src/protocol/include
    /home/zhchen/github/workflow/src/util/include
    /home/zhchen/github/workflow/src/manager/include
    /home/zhchen/github/workflow/src/nameservice/include
    /home/zhchen/github/workflow/src/server/include
)

set(SRC
	WFGraphTask.cc
	DnsTaskImpl.cc
	WFTaskFactory.cc
	Workflow.cc
	HttpTaskImpl.cc
	WFResourcePool.cc
	WFMessageQueue.cc
	FileTaskImpl.cc
)

if (NOT MYSQL STREQUAL "n")
	set(SRC
		${SRC}
		MySQLTaskImpl.cc
	)
endif ()

if (NOT REDIS STREQUAL "n")
	set(SRC
		${SRC}
		RedisTaskImpl.cc
	)
endif ()

add_library(${PROJECT_NAME} OBJECT ${SRC})

if (KAFKA STREQUAL "y")
	set(SRC
		KafkaTaskImpl.cc
	)
	add_library("factory_kafka" OBJECT ${SRC})
	set_property(SOURCE KafkaTaskImpl.cc APPEND PROPERTY COMPILE_OPTIONS "-fno-rtti")
endif ()
