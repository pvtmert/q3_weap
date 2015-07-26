#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <stdbool.h>
#include <string.h>

#define C_PREFIX "comp_"
#define DC_PREFIX "fix_"
#define LDEF true
#define PROC "Processing: %s/%s: "
#define OUTSEP1 ';'
#define OUTSEP2 '\n'
#define INSEP '\\'

void do_comp(char *fname)
{
	FILE *input = fopen(fname,"rb");
	if(!input)
		return;
	char *dir = dirname(fname);
	char *base = basename(fname);
	char *buffered_fname = (char*)malloc(sizeof(char)*(strlen(C_PREFIX)+strlen(fname)+1));
	sprintf(buffered_fname,"%s/%s%s",dir,C_PREFIX,base);
	FILE *output = fopen(buffered_fname,"wb+");
	free(buffered_fname);
	printf(PROC,dir,base);
	while(!feof(input))
	{
		char c = fgetc(input);
		if(feof(input)) break;
		if(c == OUTSEP1 || c == OUTSEP2)
		{
			fputc(INSEP,output);
			putc('.',stdout);
		}else
			fputc(c,output);
		continue;
	}
	fseek(output,-1,SEEK_CUR);
	ftruncate(fileno(output),ftell(output));
	fclose(input);
	fclose(output);
	printf(" DONE \n");
	return;
}

void do_decomp(char *fname)
{
	FILE *input = fopen(fname,"rb");
	if(!input)
		return;
	char *dir = dirname(fname);
	char *base = basename(fname);
	char *buffered_fname = (char*)malloc(sizeof(char)*(strlen(DC_PREFIX)+strlen(fname)+1));
	sprintf(buffered_fname,"%s/%s%s",dir,DC_PREFIX,base);
	FILE *output = fopen(buffered_fname,"wb+");
	free(buffered_fname);
	bool nl = LDEF;
	printf(PROC,dir,base);
	while(!feof(input))
	{
		char c = fgetc(input);
		if(feof(input)) break;
		if(c == INSEP)
		{
			if(nl)
				fputc(OUTSEP2,output);
			else
				fputc(OUTSEP1,output);
			nl = !nl;
			putc('.',stdout);
		}else
			fputc(c,output);
	}
	fputc(OUTSEP2,output);
	fclose(input);
	fclose(output);
	printf(" DONE \n");
	return;
}

int main(int argc, char *argv[])
{
	if(argc < 2)
		return 1;
	for(int i=1;i<argc;i++)
		if(argv[i][0] == '-')
			do_comp(argv[i]+1);
		else
			do_decomp(argv[i]);
	return 0;
}
