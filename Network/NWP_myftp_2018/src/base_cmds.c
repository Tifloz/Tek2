/*
** EPITECH PROJECT, 2022
** NWP_myftp_2018
** File description:
** Created by Florian Louvet,
*/
#include <zconf.h>
#include <libnet.h>
#include <ftp.h>

int cmd_quit(int sock, client_t *login, char *buff)
{
    (void)buff;
    write(sock, "221 Goodbye.\r\n", 15);
    login->login = 0;
    if (login->user != NULL)
        free(login->user);
    if (login->pass != NULL)
        free(login->pass);
    free(login->p_dir);
    free(login->ip_serv);
    close(sock);
    return (0);
}

int cmd_help(int sock, client_t *client, char *buff)
{
    (void)buff;
    if (is_logged(sock, client)) {
        write(sock, "214-The following commands are recognized.\r\n", 44);
        write(sock, "CDUP CWD HELP NOOP PASS PWD QUIT USER\r\n", 39);
        write(sock, "214 Help OK.\r\n", 13);
    }
    return (1);
}

int cmd_user(int sock, client_t *client, char *buff)
{
    if (client->login == 84)
        write(sock, "530 Can't change from guest user.\r\n", 35);
    else {
        if (buff == NULL) {
            write(sock, "530 Permission denied.\r\n", 24);
            return (1);
        }
        to_lower_case(&buff);
        client->user = strdup(buff);
        client->login = 2;
        write(sock, "331 Please specify the password.\r\n", 34);
    }
    return (1);
}

int cmd_pass(int sock, client_t *client, char *buff)
{
    if (client->login == 94) {
        write(sock, "230 Already logged in.\r\n", 24);
        return (1);
    }
    if (client->login == 2) {
        if (buff == NULL || strcmp(buff, "")) {
            write(sock, "530 Login incorrect.\r\n", 22);
            return (1);
        }
        if (!strcmp(client->user, "anonymous")) {
            log_message(client->addr, " is known as Anonymous.\n");
            write(sock, "230 Login successful.\r\n", 23);
            client->login = 84;
            client->pass = strdup("");
        } else
            write(sock, "530 Login incorrect.\r\n", 22);
    } else
        write(sock, "332 Login with USER first\r\n", 27);
    return (1);
}

int cmd_pwd(int sock, client_t *client, char *buff)
{
    char *pwd;

    (void)buff;
    pwd = getpwd();
    if (is_logged(sock, client)) {
        write(sock, "257 \"", 5);
        write(sock, pwd, strlen(pwd));
        write(sock, "\"\r\n", 3);
    }
    free(pwd);
    return (1);
}