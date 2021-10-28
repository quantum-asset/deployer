#include <stdlib.h>

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "./daemonize-process/become_daemon.h"

#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	int child_server_pid = 0;
	int sleepTime = 100;
	char *argsForNewProcess[] = {"node index.js", NULL};
	//int amountOfDownloads =(argc>2)?atoi(argv[2]):128;

	int excecResponse = 0;
	//	int isDaemon = (argc>4)?(atoi(argv[4])):0;
	int status;
	//	if(isDaemon){

	//if (becomeDaemon(0) != 0)	return -1;

	//se convirtió en daemon correctamente
	// hacer fork
	system("sudo mkdir /quantum-logs");
	while (1)
	{

		child_server_pid = fork();
		switch (child_server_pid)
		{
		case -1:
			//error
			return -1;
		case 0:
			//child recieves 0 as pid
			excecResponse = execvp(argsForNewProcess[0], argsForNewProcess);
			if (excecResponse != 0)
			{
				return -1;
			}
			break; //child fall through
		default:
			//parent recieves the pid of child
			system("sudo echo Nuevo inicio del proceso con pid >> /quantum-logs/logs.txt");
			while (1)
			{
				//ckeck
				//waitpid
				//break
				waitpid(child_server_pid, &status, 0);
				//Option is 0 since I check it later

				if (WIFSIGNALED(status))
				{
					system("echo 'Error al terminar el proceso\n' >> /quantum-logs/logs.txt");
				}
				else if (WEXITSTATUS(status))
				{
					system("echo '* Termino correcto del proceso\n' >> /quantum-logs/logs.txt");
				}
				break;
			}
		}
	}
}
