#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int main() {
	void * util_handle;
	void * my_lib_handle;
	int (*some_func)();

	if (!(util_handle = dlopen("/home/iwagner/NSA_CodeBreak/task_1/libclient_crypt.so", RTLD_LAZY))) {
		fprintf(stderr, "util %s\n", dlerror());
		exit(EXIT_FAILURE);
	}

	if (!(my_lib_handle = dlopen("/home/iwagner/NSA_CodeBreak/task_1/libclient_comms.so", RTLD_NOW))) {
		fprintf(stderr, "lib %s\n", dlerror());
		exit(EXIT_FAILURE);
	}

	if (!(some_func = (int (*)()) dlsym(my_lib_handle,"start_client"))) {
		fprintf(stderr, "function %s\n", dlerror());
		exit(EXIT_FAILURE);
    	}
	if(some_func==NULL) {
		/* ERROR HANDLING */
	}
	printf("Return code is %i\n",(*some_func)());
	return 0;
}
