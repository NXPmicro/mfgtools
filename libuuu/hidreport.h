/*
* Copyright 2018 NXP.
*
* Redistribution and use in source and binary forms, with or without modification,
* are permitted provided that the following conditions are met:
*
* Redistributions of source code must retain the above copyright notice, this
* list of conditions and the following disclaimer.
*
* Redistributions in binary form must reproduce the above copyright notice, this
* list of conditions and the following disclaimer in the documentation and/or
* other materials provided with the distribution.
*
* Neither the name of the NXP Semiconductor nor the names of its
* contributors may be used to endorse or promote products derived from this
* software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
*/
#include <string>
#include <vector>
#include "libcomm.h"
#include "libuuu.h"
#include "trans.h"
#include <string.h>

#pragma once

using namespace std;

class HIDReport
{
	size_t m_size_in;
	size_t m_size_out;
	size_t m_size_payload;
public:
	TransBase * m_pdev;
	vector<uint8_t> m_out_buff;
	size_t m_postion_base;
	size_t m_notify_total;
	size_t get_out_package_size() { return m_size_out; }
	bool m_skip_notify;
	void init();
	void set_out_package_size(int sz)
	{
		m_size_out = sz;
		m_out_buff.resize(m_size_out + m_size_payload);
	}
	HIDReport()
	{
		init();
	}

	HIDReport(TransBase *trans)
	{
		init();
		m_pdev = trans;
	}

	int read(vector<uint8_t> &buff);

	virtual void notify(size_t index, uuu_notify::NOTIFY_TYPE type);

	int write(void *p, size_t sz, uint8_t report_id);

	int write(vector<uint8_t> &buff, uint8_t report_id)
	{
		return write(buff.data(), buff.size(), report_id);
	}

};
