/* define size of a line */
#define LINESIZE 50
/* define size of a user id */
#define SIZE_USER_ID 15
/* define size of max resource name */
#define SIZE_RESOURCE_NAME 20
/* define size of max permissions */
#define SIZE_PERMISSION 10

/*
 * general structure for token to be used in:
 * database with the users
 * request access
 * approve request
 */
struct token {
	/* value of the acces token */
	string token_value<>;
	/* value of the refresh token */
	string refresh_token<>;
	/* value of the remaining time for the token */
	int ttl;
	/* it is or not accepted by user */
	int is_signed;
	/* value of the index of permission in the permission database */
	int crt_permissions;
	/* it is or not auto refreshed */
	int is_automatic_refreshed;
};

/*
 * files with specific permissions to be used in:
 * approval to make a list of this
 */
struct file_permission {
	/* name of the file */
	string file<>;
	/* what permission is per file */
	string permission<>;
};

/*
 * struct for all approvals of a user
 */
struct approval {
	/* list with all permissions */
	file_permission list_permissions<>;
	/* number of permissions to know how much to go in the search */
	int no_permissions;
};

/*
 * files with specific permissions to be used in:
 * approval to make a list of this
 */
struct user_in_db {
	string user_id<>;
	token user_token;
};

/*
 * files with specific permissions to be used in:
 * approval to make a list of this
 */
struct request_authorization {
	/* get the status of the request (1 User_not_found; 0 accepted) */
    int status;
	/* get the request token value */
    string request_token<>;
};

/*
 * files with specific permissions to be used in:
 */
struct request_access_token_params {
	string id<>;
    token user_token;
};

/*
 * return struct for request_access_token
 */
struct request_access_token {
	/* value of the request_token to be displayed in client */
    string request_token<>;
	/* value of the access_token to be displayed in client */
    string access_token<>;
	/* value of the refresh_token to be displayed in client */
	string refresh_token<>;
	/* status of the request -> (0 DENIED; 1 ACCEPT) */
	int status;
};

/*
 * files with specific permissions to be used in:
 * approval to make a list of this
 */
struct approve_request_params {
	string token_value<>;
	int is_automatic_refreshed;
};

/*
 * struct for call validate_action
 */
struct validate_action_params {
	/* operation that should be made */
	string operation<>;
	/* file on which the operation should be made */
	string resource<>;
	/* user that should make the operation */
	string user_id<>;
};

program TEMA1_PROG {
	version TEMA1_VERS {
		/* return the request token and a status of the operation */
		request_authorization REQUEST_AUTHORIZATION(string) = 1;
		/* return a token with permissions and sign the token or not,
		 * put the ttl of token 
		 */
        token APPROVE_REQUEST_TOKEN(approve_request_params) = 2;
		/* return a token with data about access token and refresh
		 * token(if it is the case)  
		 */
		request_access_token REQUEST_ACCESS_TOKEN(request_access_token_params) = 3;
		/* return a response of the user making an operation */
		int VALIDATE_DELEGATED_ACTION(validate_action_params) = 4;
	} = 1;
} = 0x3123457;