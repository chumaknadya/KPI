#include <stdio.h>
#include <stdlib.h>
#include <progbase/net.h>
#include <progbase/list.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_LEN 1024
  typedef struct {
	char string[1000];
	char nickname[100];
 } Request;
 Request parseRequest(const char * msgStr) {
	Request req = {
		.string = " ",
		.nickname = " ",

    };
	int n = 0;
	while(isalnum(msgStr[n]) || isspace(msgStr[n]) || msgStr[n] == '.') n++;

	strncpy(req.string, msgStr, n);
	req.string[n] = '\0';

	char *space = strstr(msgStr, "-");
	int nicknameLen = strlen(msgStr) - n - 1;
	strncpy(req.nickname, &space[1], nicknameLen + 1);

	return req;
}
void printRequest(Request * req) {
	printf("Request: `%s` `%s`\n",
		req->string,
		req->nickname);
}

int main(void) {
    //
    // create UDP server
    UdpClient * server = UdpClient_init(&(UdpClient){});
    IpAddress * address = IpAddress_initAny(&(IpAddress){}, 9999);
    if (!UdpClient_bind(server, address)) {
        perror("Can't start server");
        return 1;
    }
    printf("Udp server started on port %d\n",
        IpAddress_port(UdpClient_address(server)));

    NetMessage * message = NetMessage_init(
        &(NetMessage){},  // value on stack
        (char[BUFFER_LEN]){},  // array on stack
        BUFFER_LEN);

    IpAddress clientAddress;
	List * list = List_new();
    while (1) {
        puts("Waiting for data...");
        //
        // blocking call to receive data from clients
        UdpClient_receiveFrom(server, message, &clientAddress);
        printf("Received message from %s:%d (%d bytes): `%s`\n",
            IpAddress_address(&clientAddress),  // client IP-address
            IpAddress_port(&clientAddress),  // client port
            NetMessage_dataLength(message),
            NetMessage_data(message));

        // @todo Process clients input and send response


		    const char * msgStr = NetMessage_data(message);
        	Request req = parseRequest(msgStr);
            printRequest(&req);

		    List_add(list,req.string);
		    char tmp[1000];
		    tmp[strlen(tmp)-1] = '\n';
	        char * getString = (char *)List_get(list,List_count(list) - 1);
	        strcat(tmp,getString);


	    	NetMessage_setDataString(message, tmp);


        //
        // send echo response
         UdpClient_sendTo(server, message, &clientAddress);
    }
    //
    // close server
    UdpClient_close(server);
	List_free(&list);
    return 0;
}
