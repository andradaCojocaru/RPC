struct token {
	string token_value<>;
	int ttl;
	int is_signed;
	int crt_permissions;
	int is_automatic_refreshed;
};

struct file_permission {
	string file<>;
	string permission<>;
};

struct approval {
	file_permission list_permissions<>;
	int no_permissions;
};

struct user_in_db {
	string user_id<>;
	token user_token;
};

struct request_authorization {
    int status;
    string request_token<>;
};

struct request_access_token_params {
	string id<>;
    token user_token;
};

struct request_access_token {
    string request_token<>;
    string access_token<>;
	string refresh_token<>;
	int status;
};

struct validate_action_params {
    int ttl;
	string operation<>;
	string resource<>;
	string access_token<>;
};

program TEMA1_PROG {
	version TEMA1_VERS {
		request_authorization REQUEST_AUTHORIZATION(string) = 1;
        token APPROVE_REQUEST_TOKEN(string) = 2;
		request_access_token REQUEST_ACCESS_TOKEN(request_access_token_params) = 3;
		int VALIDATE_DELEGATED_ACTION(validate_action_params) = 4;
	} = 1;
} = 0x3123456;