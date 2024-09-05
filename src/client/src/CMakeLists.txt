project(client)

include_directories(
    ../include
    /home/zhchen/github/workflow/src/util/include
    /home/zhchen/github/workflow/src/factory/include
    /home/zhchen/github/workflow/src/protocol/include
    /home/zhchen/github/workflow/src/kernel/include
    /home/zhchen/github/workflow/src/manager/include
    /home/zhchen/github/workflow/src/nameservice/include
)

set(SRC
	WFDnsClient.cc
)

if (NOT REDIS STREQUAL "n")
	set(SRC
		${SRC}
		WFRedisSubscriber.cc
	)
endif ()

if (NOT MYSQL STREQUAL "n")
	set(SRC
		${SRC}
		WFMySQLConnection.cc
	)
endif ()

if (NOT CONSUL STREQUAL "n")
	set(SRC
		${SRC}
		WFConsulClient.cc
	)
endif ()

add_library(${PROJECT_NAME} OBJECT ${SRC})

if (KAFKA STREQUAL "y")
	set(SRC
		WFKafkaClient.cc
	)
	add_library("client_kafka" OBJECT ${SRC})
endif ()

