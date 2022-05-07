# Chat-application

A simple chat application in C language for windows OS using socket programming

To run it on your systems:

1. you have to execute the server file in a command prompt window, using:-
>gcc server.c -lws2_32 -o server.exe
>server.exe

2. execute the client file in a new command prompt window, using:-
>gcc client.c -lws2_32 -o client.exe
>client.exe 

3. enter the message in the command prompt window related to the client

4. when you want to exit from the infinite loop of "Enter message: ", hit CTRL+C to come out of the execution
