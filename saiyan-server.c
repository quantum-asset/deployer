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
	
	char* arr[] = {"node","index.js", NULL};

	//char *argsForNewProcess[] = {"node index.js", NULL};
	//int amountOfDownloads =(argc>2)?atoi(argv[2]):128;

	int excecResponse = 0;
	//	int isDaemon = (argc>4)?(atoi(argv[4])):0;
	int status;
	//	if(isDaemon){

printf("Iniciando servidor\n");
fflush(stdout);	
//if (
	becomeDaemon(0); 
printf("ERROR EN DAEMONIZION\n");
	fflush(stdout);
//!= 0)	return -1;

	//se convirtió en daemon correctamente
	// hacer fork
//	system("sudo mkdir /quantum-logs");
int i=0;	
while (1)
	{
	i++;	
	printf("INIT NUMERO %d\n",i);
	fflush(stdout);

		child_server_pid = fork();
		switch (child_server_pid)
		{
		case -1:
			printf("ERROR EN FORK %d\n",i);
			fflush(stdout);
			//error
			return -1;
		case 0:
			printf("Se logro forj¿k===AAAA>>>> %d\n",i);
			fflush(stdout);	
			//child recieves 0 as pid
			system("sudo node /home/ubuntu/backend/index.js");
			//excecResponse = execv("node", "node", "indexjs",NULL);//execvp("node","index.js",NULL);
			//sleep(5);
			//system("echo ERRORRRR");
			//if (excecResponse != 0)
			//	{
			//		return -1;
			//}
			//break; //child fall through
			return 0;
		default:
			//parent recieves the pid of child
//			system("sudo echo Nuevo inicio del proceso con pid >> /quantum-logs/logs.txt");
			//|while (1)
			//{
				//ckeck
				//waitpid
				//break
				waitpid(child_server_pid, &status, 0);
				//Option is 0 since I check it later

				if (WIFSIGNALED(status))
				{
					system("sudo echo 'Error al terminar el proceso\n' >> /home/ubuntu/quantum-logs/logs.txt");
				}
				else if (WEXITSTATUS(status))
				{
					system("sudo echo '* Termino correcto del proceso\n' >> /home/ubuntu/quantum-logs/logs.txt");
				}
				break;
			//}
		}
	}
return 0;
}
