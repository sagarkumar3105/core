/*
*	MetaCall++ Library by Parra Studios
*	Copyright (C) 2016 - 2017 Vicente Eduardo Ferrer Garcia <vic798@gmail.com>
*	Copyright (C) 2016 Federico Agustin Alvarez Bayon <loopzer@gmail.com>
*
*	High performance, type safe and exception safe object oriented
*	front-end for MetaCall library.
*
*/

#ifndef METACALLPP_METAFUNCTION_HPP
#define METACALLPP_METAFUNCTION_HPP 1

/* -- Headers -- */

#include <metacallpp/metacallpp_api.h>

#include <metacallpp/Metacall.h>
#include <metacallpp/common.h>
#include <metacallpp/IScopeBase.h>
#include <metacallpp/ICall.h>
#include <metacallpp/IReturn.h>

#include <string>

namespace Beast {
	template <typename T>
	class MetaFunction :
		public Metacall
	{
	public:
		METACALLPP_API MetaFunction()
		{

		}

		METACALLPP_API ~MetaFunction() {

		}

		METACALLPP_API T * Invoke() {
			T * v = new T();
			ICall * call = this->Prepare();
			IReturn *ret = call->Invoke();
			ret->Get(v);
			delete ret;
			delete call;
			return v;
		}

		METACALLPP_API static MetaFunction<T> * MakeFunction(IScopeBase *scope, const char * functionName) {
			MetaFunction<T> * m = new MetaFunction<T>(scope, functionName);
			m->state = MetacallStates::Ready;
			return m;
		}
	protected:
		METACALLPP_API MetaFunction(IScopeBase *scope, const char * functionName) :Metacall(scope, functionName) {

		}
	};
}

#endif /* METACALLPP_METAFUNCTION_HPP */
