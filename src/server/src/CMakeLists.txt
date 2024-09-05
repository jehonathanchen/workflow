project(server)

include_directories(
    ../include
    /home/zhchen/github/workflow/src/manager/include
    /home/zhchen/github/workflow/src/util/include
    /home/zhchen/github/workflow/src/kernel/include
    /home/zhchen/github/workflow/src/factory/include
    /home/zhchen/github/workflow/src/protocol/include
    /home/zhchen/github/workflow/src/nameservice/include
)

set(SRC
	WFServer.cc
)

if (NOT MYSQL STREQUAL "n")
	set(SRC
		${SRC}
		WFMySQLServer.cc
	)
endif ()

add_library(${PROJECT_NAME} OBJECT ${SRC})
