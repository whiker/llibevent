#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char** argv) {
    // create socket
    int listenSocket = socket(AF_INET, SOCK_STREAM, 0);

    // bind
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddress.sin_port = htons(8080);
    bind(listenSocket, (sockaddr*)&serverAddress, sizeof(serverAddress));

    // listen
    listen(listenSocket, 8);
}
