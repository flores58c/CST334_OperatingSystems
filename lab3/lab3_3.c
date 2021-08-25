#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

// main 
int main(){
	int fds[2]; //pipe represented by array
	pipe(fds); //pipe initialized
	/*child 1 duplicates downstream into stdin */
	if(fork() == 0){
	dup2(fds[0],0); //redirect std to read end of pipe
	close(fds[1]);
	//filters input
	execlp("grep","grep","root",0);
	
	}
	/*child 2 duplicates upstream into stdout */ 
	else if(fork() ==0){
	dup2(fds[1],1); //redirect std to writing end of pipe
	close(fds[0]);
	
	//outputs the filtered input from grep
	execlp("cat","cat","/etc/passwd",0);
	}else{ /*parent closes both ends and wait for children*/
	close(fds[0]);
	close(fds[1]);
	wait(0);
	wait(0);
	}
	return 0;
	}
	
	/*
	root:x:0:0:root:/root:/usr/bin/zsh
nm-openvpn:x:126:131:NetworkManager OpenVPN,,,:/var/lib/openvpn/chroot:/usr/sbin/nologin
*/
	

