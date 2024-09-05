project(nameservice)

include_directories(
    ../include
    /home/zhchen/github/workflow/src/kernel/include
    /home/zhchen/github/workflow/src/factory/include
    /home/zhchen/github/workflow/src/manager/include
    /home/zhchen/github/workflow/src/util/include
    /home/zhchen/github/workflow/src/protocol/include
    /home/zhchen/github/workflow/src/client/include
)

set(SRC
	WFNameService.cc
	WFDnsResolver.cc
)

if (NOT UPSTREAM STREQUAL "n")
	set(SRC
		${SRC}
		WFServiceGovernance.cc
		UpstreamPolicies.cc
	)
endif ()

add_library(${PROJECT_NAME} OBJECT ${SRC})
