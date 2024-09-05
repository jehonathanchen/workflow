project(manager)

include_directories(
    ../include
    /home/zhchen/github/workflow/src/util/include
    /home/zhchen/github/workflow/src/kernel/include
    /home/zhchen/github/workflow/src/protocol/include
    /home/zhchen/github/workflow/src/factory/include
    /home/zhchen/github/workflow/src/nameservice/include
    /home/zhchen/github/workflow/src/client/include
    /home/zhchen/github/workflow/src/manager/include
)

set(SRC
	DnsCache.cc
	RouteManager.cc
	WFGlobal.cc
)

if (NOT UPSTREAM STREQUAL "n")
	set(SRC
		${SRC}
		UpstreamManager.cc
	)
endif ()

add_library(${PROJECT_NAME} OBJECT ${SRC})
