/*
  Copyright (c) 2019 Sogou, Inc.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  Author: Xie Han (xiehan@sogou-inc.com)
*/

#ifndef _EXECREQUEST_H_
#define _EXECREQUEST_H_

#include "SubTask.h"
#include "Executor.h"

class ExecRequest : public SubTask, public ExecSession
{
public:
	ExecRequest(ExecQueue *queue, Executor *executor) {
		_executor = executor;
		_queue = queue;
	}

	ExecQueue *get_request_queue() const { return _queue; }
	void set_request_queue(ExecQueue *queue) { _queue = queue; }

public:
	virtual void dispatch()
	{
		if (_executor->request(this, this->_queue) < 0)
			handle(ES_STATE_ERROR, _error);
	}

protected:
	int _state;
	int _error;

protected:
	ExecQueue* _queue;
	Executor* _executor;

protected:
	virtual void handle(int state, int error) {
		_state = state;
		_error = error;
		subtask_done();
	}
};

#endif

