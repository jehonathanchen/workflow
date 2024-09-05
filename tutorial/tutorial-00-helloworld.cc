#include <stdio.h>
#include "workflow/WFHttpServer.h"

int main()
{
    auto req = [](WFHttpTask *task) {
                    task->get_resp()->append_output_body("<html>Hello World!</html>");
                };
    WFHttpServer server(req);

    if (server.start(10086) == 0) { 
        getchar(); // press "Enter" to end.
        server.stop();
    }

    return 0;
}

