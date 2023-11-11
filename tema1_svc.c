/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "tema1.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif

approval **all_approvals;
char **users, **resources;
int no_users, no_resources, token_valability, no_approvals;
char buf[LINESIZE];

static request_authorization *
_request_authorization_1 (char * *argp, struct svc_req *rqstp)
{
	return (request_authorization_1_svc(*argp, rqstp));
}

static approve_request_token *
_approve_request_token_1 (char * *argp, struct svc_req *rqstp)
{
	return (approve_request_token_1_svc(*argp, rqstp));
}

static request_access_token *
_request_access_token_1 (request_access_token_params  *argp, struct svc_req *rqstp)
{
	return (request_access_token_1_svc(*argp, rqstp));
}

static int *
_validate_delegated_action_1 (validate_action_params  *argp, struct svc_req *rqstp)
{
	return (validate_delegated_action_1_svc(*argp, rqstp));
}

static void
tema1_prog_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		char *request_authorization_1_arg;
		char *approve_request_token_1_arg;
		request_access_token_params request_access_token_1_arg;
		validate_action_params validate_delegated_action_1_arg;
	} argument;
	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case REQUEST_AUTHORIZATION:
		_xdr_argument = (xdrproc_t) xdr_wrapstring;
		_xdr_result = (xdrproc_t) xdr_request_authorization;
		local = (char *(*)(char *, struct svc_req *)) _request_authorization_1;
		break;

	case APPROVE_REQUEST_TOKEN:
		_xdr_argument = (xdrproc_t) xdr_wrapstring;
		_xdr_result = (xdrproc_t) xdr_approve_request_token;
		local = (char *(*)(char *, struct svc_req *)) _approve_request_token_1;
		break;

	case REQUEST_ACCESS_TOKEN:
		_xdr_argument = (xdrproc_t) xdr_request_access_token_params;
		_xdr_result = (xdrproc_t) xdr_request_access_token;
		local = (char *(*)(char *, struct svc_req *)) _request_access_token_1;
		break;

	case VALIDATE_DELEGATED_ACTION:
		_xdr_argument = (xdrproc_t) xdr_validate_action_params;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) _validate_delegated_action_1;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	return;
}

void read_clients(char *filename_clients)
{
	FILE *file_clients = fopen(filename_clients, "r");

	if (file_clients == NULL) {
		printf("Cannot open %s\n", filename_clients);
		exit(1);
	}

	fscanf(file_clients, "%d", &no_users);
	printf("no_users %d\n", no_users);
	users = (char **) calloc(no_users, sizeof(char *));

	if (!users) {
		printf("Allocation failed\n");
		exit(1);
	}

	for (int i = 0; i < no_users; i++) {
		users[i] = (char *) calloc(SIZE_USER_ID, sizeof(char));
		if (!users[i]) {
			printf("Allocations failed\n");
			exit(1);
		}

		fscanf(file_clients, "%s", users[i]);
		printf("%s\n", users[i]);
	}
	fclose(file_clients);
}

void read_resources(char *filename_resouces)
{
	FILE *file_resources = fopen(filename_resouces, "r");

	if (file_resources == NULL) {
		printf("Cannot open %s\n", filename_resouces);
		exit(1);
	}

	fscanf(file_resources, "%d", &no_resources);
	printf("no_resources %d\n", no_resources);
	resources = (char **) calloc(no_resources, sizeof(char *));

	if (!resources) {
		printf("Allocation failed\n");
		exit(1);
	}

	for (int i = 0; i < no_resources; i++) {

		resources[i] = (char *) calloc(SIZE_RESOURCE_NAME, sizeof(char));
		if (!resources[i]) {
			printf("Allocations failed\n");
			exit(1);
		}

		fscanf(file_resources, "%s", resources[i]);
		printf("%s\n", resources[i]);
	}
	fclose(file_resources);
}

void read_approvals (char *filename_approvals)
{
	FILE *file_approvals = fopen(filename_approvals, "r");

	if (file_approvals == NULL) {
		printf("Cannot open %s\n", filename_approvals);
		exit(1);
	}

	approval app;
	no_approvals = 0;
	no_it = 0;
	all_approvals = (approval **) calloc(1, sizeof(approval *));
	while (fgets(buf, LINESIZE, file_approvals)) {
		app.file = strtok(buf, ",");
		app.permission = strtok(NULL, ",");

		all_approvals[no_approvals] = (approval *) calloc(1, sizeof(approval));
		while(app.file != NULL) {

			all_approvals[i] = (approval *) calloc(1, sizeof(approval));
			all_approvals[i].file = (char *) calloc(SIZE_RESOURCE_NAME, sizeof(char));
			all_approvals[i].permission = (char *) calloc(SIZE_PERMISSION, sizeof(char));

			memcpy(approval[i].file, app.file, SIZE_RESOURCE_NAME);
			memcpy(approval[i].permission, app.permission, SIZE_PERMISSION);

			printf("%s %s", );

			app.file = strtok(buf, ",");
			app.permission = strtok(NULL, ",");
		}

		

		all_approvals = (approval *) realloc((no_approvals + 1), sizeof(approval));
	}
	fclose(file_approvals);
}

void read_token_valability (char *tokens_valability_file)
{
	FILE *file_tokens_valability = fopen(tokens_valability_file, "r");

	if (file_tokens_valability == NULL) {
		printf("Cannot open %s\n", tokens_valability_file);
		exit(1);
	}

	char *text, *number;

	while (fgets(buf, LINESIZE, file_tokens_valability)) {
		text = strtok(buf, "=");
		number = strtok(NULL, "=");

		token_valability = atoi(number);
		printf("Token valab %d\n", token_valability);
	}

	fclose(file_tokens_valability);
}

int
main (int argc, char **argv)
{
	if (argc < 5) {
		printf ("usage: %s fisier_clienti fisier_resurse fisier_aprobari valabilitate_jetoane\n", argv[0]);
		exit (1);
	}

	char *filename_clients, *filename_resouces, *filename_approvals, *tokens_valability_file;
	filename_clients = argv[1];
	filename_resouces = argv[2];
	filename_approvals = argv[3];
	tokens_valability_file = argv[4];

	read_clients(filename_clients);
	read_resources(filename_resouces);
	read_approvals(filename_approvals);
	read_token_valability(tokens_valability_file);

	register SVCXPRT *transp;

	pmap_unset (TEMA1_PROG, TEMA1_VERS);

	transp = svcudp_create(RPC_ANYSOCK);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create udp service.");
		exit(1);
	}
	if (!svc_register(transp, TEMA1_PROG, TEMA1_VERS, tema1_prog_1, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (TEMA1_PROG, TEMA1_VERS, udp).");
		exit(1);
	}

	transp = svctcp_create(RPC_ANYSOCK, 0, 0);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create tcp service.");
		exit(1);
	}
	if (!svc_register(transp, TEMA1_PROG, TEMA1_VERS, tema1_prog_1, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (TEMA1_PROG, TEMA1_VERS, tcp).");
		exit(1);
	}

	svc_run ();
	fprintf (stderr, "%s", "svc_run returned");
	exit (1);
	/* NOTREACHED */
}