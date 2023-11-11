struct file_permission {
	string file<>;
	string permission<>;
};

struct approval {
	file_permission list_permissions<>;
	int no_permissions;
};

struct request_authorization {
    int status;
    string request_token<>;
};

struct approve_request_token {
	string request_token<>;
	int is_signed;
};

struct request_access_token_params {
	string id<>;
    int is_signed;
	string request_token<>;
	int is_automatic_refreshed;
};

struct request_access_token {
    string request_token<>;
    string access_token<>;
	string refresh_token<>;
    int ttl;
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
        approve_request_token APPROVE_REQUEST_TOKEN(string) = 2;
		request_access_token REQUEST_ACCESS_TOKEN(request_access_token_params) = 3;
		int VALIDATE_DELEGATED_ACTION(validate_action_params) = 4;
	} = 1;
} = 0x3123456;