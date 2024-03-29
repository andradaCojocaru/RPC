/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "tema1.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

request_authorization *
request_authorization_1(char *arg1,  CLIENT *clnt)
{
	static request_authorization clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, REQUEST_AUTHORIZATION,
		(xdrproc_t) xdr_wrapstring, (caddr_t) &arg1,
		(xdrproc_t) xdr_request_authorization, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

token *
approve_request_token_1(approve_request_params arg1,  CLIENT *clnt)
{
	static token clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, APPROVE_REQUEST_TOKEN,
		(xdrproc_t) xdr_approve_request_params, (caddr_t) &arg1,
		(xdrproc_t) xdr_token, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

request_access_token *
request_access_token_1(request_access_token_params arg1,  CLIENT *clnt)
{
	static request_access_token clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, REQUEST_ACCESS_TOKEN,
		(xdrproc_t) xdr_request_access_token_params, (caddr_t) &arg1,
		(xdrproc_t) xdr_request_access_token, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

int *
validate_delegated_action_1(validate_action_params arg1,  CLIENT *clnt)
{
	static int clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, VALIDATE_DELEGATED_ACTION,
		(xdrproc_t) xdr_validate_action_params, (caddr_t) &arg1,
		(xdrproc_t) xdr_int, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}
