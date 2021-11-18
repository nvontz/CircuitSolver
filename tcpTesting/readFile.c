#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	FILE* fp;
	int fileLength;
	char* buffer; // buffer to store string

	fp = fopen("Netlist.net", "r");
	if(!fp)
	{
		printf("failed to read...\n");
		return -1;
	}

	fseek(fp, 0, SEEK_END);
	fileLength = (int)ftell(fp);

	buffer = malloc(fileLength + 1);
	printf("File length: %d\n", fileLength);

	rewind(fp);

	if(buffer)
	{
		fread(buffer, fileLength, 1, fp);
		for(int i = 0; i < fileLength + 1; i++)
		{
			printf("%c", buffer[i]);
		}
		printf("\n");
	}

}
