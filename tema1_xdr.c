/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "tema1.h"

bool_t
xdr_file_permission (XDR *xdrs, file_permission *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, &objp->file, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->permission, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_approval (XDR *xdrs, approval *objp)
{
	register int32_t *buf;

	 if (!xdr_array (xdrs, (char **)&objp->list_permissions.list_permissions_val, (u_int *) &objp->list_permissions.list_permissions_len, ~0,
		sizeof (file_permission), (xdrproc_t) xdr_file_permission))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->no_permissions))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_user_in_db (XDR *xdrs, user_in_db *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, &objp->user_id, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->token, ~0))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->is_automatic_refreshed))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_request_authorization (XDR *xdrs, request_authorization *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->status))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->request_token, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_approve_request_token (XDR *xdrs, approve_request_token *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, &objp->request_token, ~0))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->is_signed))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_request_access_token_params (XDR *xdrs, request_access_token_params *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, &objp->id, ~0))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->is_signed))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->request_token, ~0))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->is_automatic_refreshed))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_request_access_token (XDR *xdrs, request_access_token *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, &objp->request_token, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->access_token, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->refresh_token, ~0))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->ttl))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->status))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_validate_action_params (XDR *xdrs, validate_action_params *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->ttl))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->operation, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->resource, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->access_token, ~0))
		 return FALSE;
	return TRUE;
}
