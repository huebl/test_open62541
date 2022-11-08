#include <open62541/plugin/log_stdout.h>
#include <open62541/client.h>
#include <open62541/client_config_default.h>

#include <signal.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    UA_Client *client = UA_Client_new();
    /*UA_ClientConfig_setDefault(UA_Client_getConfig(client));*/
    UA_ClientConfig_setDefaultEncryption(UA_Client_getConfig(client), NULL);

    UA_Client_getConfig(client)->clientDescription.applicationUri = UA_STRING_ALLOC("urn:open62541.server.application");
    UA_Client_getConfig(client)->securityPolicyUri = UA_STRING_ALLOC("http://opcfoundation.org/UA/SecurityPolicy#Basic256Sha256");
    UA_Client_getConfig(client)->securityMode = UA_MESSAGESECURITYMODE_SIGNANDENCRYPT;


    /* Connect to a server */
    /* anonymous connect would be: retval = UA_Client_connect(client, "opc.tcp://localhost:4840"); */
    /*UA_StatusCode retval = UA_Client_connectUsername(client, "opc.tcp://Laptop:4840", "user1", "password");*/
    UA_StatusCode retval = UA_Client_connect(client, "opc.tcp://Laptop:4840");
    if(retval != UA_STATUSCODE_GOOD) {
        UA_Client_delete(client);
        return EXIT_FAILURE;
    }

    sleep(5);

    UA_Client_disconnect(client);
    UA_Client_delete(client);

    return 0;
}
