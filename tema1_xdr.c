/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "tema1.h"

bool_t
xdr_token (XDR *xdrs, token *objp)
{
	register int32_t *buf;


	if (xdrs->x_op == XDR_ENCODE) {
		 if (!xdr_string (xdrs, &objp->token_value, ~0))
			 return FALSE;
		 if (!xdr_string (xdrs, &objp->refresh_token, ~0))
			 return FALSE;
		buf = XDR_INLINE (xdrs, 4 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->ttl))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->is_signed))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->crt_permissions))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->is_automatic_refreshed))
				 return FALSE;
		} else {
			IXDR_PUT_LONG(buf, objp->ttl);
			IXDR_PUT_LONG(buf, objp->is_signed);
			IXDR_PUT_LONG(buf, objp->crt_permissions);
			IXDR_PUT_LONG(buf, objp->is_automatic_refreshed);
		}
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		 if (!xdr_string (xdrs, &objp->token_value, ~0))
			 return FALSE;
		 if (!xdr_string (xdrs, &objp->refresh_token, ~0))
			 return FALSE;
		buf = XDR_INLINE (xdrs, 4 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->ttl))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->is_signed))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->crt_permissions))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->is_automatic_refreshed))
				 return FALSE;
		} else {
			objp->ttl = IXDR_GET_LONG(buf);
			objp->is_signed = IXDR_GET_LONG(buf);
			objp->crt_permissions = IXDR_GET_LONG(buf);
			objp->is_automatic_refreshed = IXDR_GET_LONG(buf);
		}
	 return TRUE;
	}

	 if (!xdr_string (xdrs, &objp->token_value, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->refresh_token, ~0))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->ttl))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->is_signed))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->crt_permissions))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->is_automatic_refreshed))
		 return FALSE;
	return TRUE;
}

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
	 if (!xdr_token (xdrs, &objp->user_token))
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
xdr_request_access_token_params (XDR *xdrs, request_access_token_params *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, &objp->id, ~0))
		 return FALSE;
	 if (!xdr_token (xdrs, &objp->user_token))
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
	 if (!xdr_int (xdrs, &objp->status))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_validate_action_params (XDR *xdrs, validate_action_params *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, &objp->operation, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->resource, ~0))
		 return FALSE;
	 if (!xdr_array (xdrs, (char **)&objp->user_token.user_token_val, (u_int *) &objp->user_token.user_token_len, ~0,
		sizeof (token), (xdrproc_t) xdr_token))
		 return FALSE;
	return TRUE;
}
