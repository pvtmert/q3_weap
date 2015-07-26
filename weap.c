#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <stdbool.h>
#include <string.h>

#define PREFIX "fix_"
#define LDEF true

void do_job(const char *fname)
{
	FILE *input = fopen(fname,"r");
	if(!input)
		return;
	char *dir = dirname(fname);
	char *base = basename(fname);
	char *buffered_fname = (char*)malloc(sizeof(char)*(strlen(PREFIX)+strlen(fname)+1));
	sprintf(buffered_fname,"%s/%s%s",dir,PREFIX,base);
	FILE *output = fopen(buffered_fname,"w");
	free(buffered_fname);
	bool nl = LDEF;
	printf("Processing: %s/%s\n",dir,base);
	while(!feof(input))
	{
		char c = fgetc(input);
		if(c == '\\')
		{
			if(nl)
				fputc('\n',output);
			else
				fputc(':',output);
			nl = !nl;
		}else
			fputc(c,output);
	}
	fclose(input);
	fputc('\n',output);
	fclose(output);
}

int main(int argc, char *argv[])
{
	if(argc < 2)
		return 1;
	for(int i=1;i<argc;i++)
		do_job(argv[i]);
	return 0;
}
