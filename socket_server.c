#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 55999
#define BUFFER_SIZE 65536 // 64kb

int main ()
{
        const char 
        *FILENAME = "index.html",
        *MSG_ERROR_Z = "ERROR AO CONECTAR",
        *MSG_SUCCESS_Z = "CONEXAO ESTABELECIDA";

        int 
        _socket_listen,
        _socket_connect,
        n;

        struct sockaddr_in
        _address;

        socklen_t 
        addrlen = sizeof(_address);

        unsigned char 
        buffer[BUFFER_SIZE];
         // instancio o socket pra escutar conexoes
        _socket_listen = socket(AF_INET, SOCK_STREAM, 0);

        // prencho o addr com informacoes do endereco servidor
        _address.sin_addr.s_addr = inet_addr("192.168.0.12");//INADDR_ANY;
        _address.sin_family = AF_INET;
        _address.sin_port = htons(PORT);

        // chamo a funcao bind pra ligar meu socket a o endereco addr e trato erro
        if (bind( _socket_listen, (struct sockaddr *)&_address, sizeof(_address)) < 0) {
                perror("bind");
                close(_socket_listen);
                return 1;
        };

        while (1)
        {
        
                // chamo a funcao listen pra deixar o socket escutando
                if (listen(_socket_listen, 5) < 0) {
                        perror("listen");
                        close(_socket_listen);
                        return 1;
                };
                // chamo funcao pra aceitar conexoes e associo ao outro socket assim 
                // liberando o primeiro pra escutar novas conexoes
                _socket_connect = accept(_socket_listen, (struct sockaddr *)&_address, &addrlen);
                if (_socket_connect < 0) {
                        perror("accept");
                        close(_socket_listen);
                        return 1;
                };

                // comunicar com o cliente
                while ((n = recv(_socket_connect, buffer, sizeof buffer - 1, 0)) > 0) {
                        buffer[n] = '\0';
                        printf("recebido: %s", buffer);
                        // Verifica se a mensagem HTTP está completa
                        if (strstr(buffer, "\r\n\r\n"))
                                break;
                                
                }

                // Enviar resposta ao cliente
                char *resposta = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 21\n\n<h1>Hello world!</h1>";
                send(_socket_connect, resposta, strlen(resposta), 0);
        }
        
        close(_socket_listen);
        close(_socket_connect);

        return 0;

};
