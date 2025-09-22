#include <stdio.h> 
#include <stdlib.h>
#include "lib/plib.h"

void _exit(int code);
void help(void);
int post(void);

pl_arg  *help_a, *xine_a, *geom_a, *zoom_a, *volm_a;

// handle arguments
int main(const int argc, const char *argv[]){
	// SET ARGUMENTS ==========================
	help_a = PL_A("--help","Show this dialog"); 
	xine_a = PL_A("--dual","fills wallpaper over two monitors");
	geom_a = PL_A("--geometry","set custom mpv geometry eg 1920x1070+0+0",TAKES_VALUE);
	zoom_a = PL_A("--zoom","set video zoom, default 0.0",TAKES_VALUE);
	volm_a = PL_A("--volume","set video volume, default 0",TAKES_VALUE);
	
	// INIT PLIB ==============================
	const pl_return_type ret = PL_PROC();
	if(ret != PL_SUCCESS){
		help();
		
		// HANDLE ERROR =========================
		printf("%s caused by '%s'\n",
				pl_return_type_string[ret], 
				PL_LAST_ARG);
		exit(1);
	} else {
		// argument parse completed move on.. 
		exit(post());
	}

	exit(0);
}

void help() {
	printf("motionlayer [options]\noptions:\n");
	pl_help();
}

void _exit(int code){
	printf("exiting\n");
	pl_exit();
	exit(code);
}


int post(){
	if(pl_arg_run(help_a) == PL_SUCCESS) 
		help();

	return 0;
}
