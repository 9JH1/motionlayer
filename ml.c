#include <stdio.h> 
#include <stdlib.h>
#include "lib/plib.h"

#define VERSION "2.3"

void _exit(int code);
void help(void);
int post(void);

pl_arg  *help_a, *xine_a, *geom_a, *zoom_a, *volm_a, *plib_a, *prog_a;

// handle arguments
int main(const int argc, const char *argv[]){
	// SET ARGUMENTS ==========================
	help_a = PL_A("--help","show this dialog"); 
	plib_a = PL_A("--plib-version","Show plib version");
	prog_a = PL_A("--version", "Show version");
	xine_a = PL_A("--dual","fills wallpaper over two monitors", .catagory = "Video");
	geom_a = PL_A("--geometry","set custom mpv geometry eg 1920x1070+0+0",TAKES_VALUE,"Video");
	zoom_a = PL_A("--zoom","set video zoom, default 0.0",TAKES_VALUE, "Video");
	volm_a = PL_A("--volume","set video volume, default 0",TAKES_VALUE, "Video");
	
	// INIT PLIB ==============================
	const pl_return_type ret = PL_PROC();
	if(ret != PL_SUCCESS){
		help();
		
		// HANDLE ERROR =========================
		printf("%s caused by '%s'\n",
				pl_return_type_string[ret], 
				PL_LAST_ARG);
		exit(1);
	} else exit(post());
	exit(0);
}

void help() {
	printf("motionlayer [\033[3moptions\033[0m]\n\n");
	pl_help();
}

void _exit(int code){
	printf("exiting\n");
	pl_exit();
	exit(code);
}


int post(){
	if(pl_arg_run(help_a) == PL_SUCCESS) {
		help();
		return 0;
	}

	if(pl_arg_run(prog_a) == PL_SUCCESS){
		printf("motionlayer %s\n",VERSION);
		return 0;
	}

	if(pl_arg_run(plib_a) == PL_SUCCESS){
		printf("plib %s\n",PL_VERSION);
		return 0;
	}

	return 0;
}
