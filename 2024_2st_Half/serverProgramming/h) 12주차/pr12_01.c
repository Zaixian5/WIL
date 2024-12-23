// pr12_01.c

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(){ 
    struct servent *port;
    int num;

    printf("Input port number: ");
    scanf("%d", &num);

    uint16_t net_port = htons(num);

    setservent(0);
    port = getservbyport(net_port, "tcp");

    printf("Name = %s, Port = %d\n", port->s_name, ntohs(port->s_port));
    endservent();

    return 0;
}

