#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t  BYTE;

int main(int argc, char *argv[])
{
    //open memory card
    FILE *f = fopen(argv[1], "r"); //returs adress of argv[1] i.e card.raw to file pointer
    //f contains adress of card so 512 blocks are in f,we have to use fread
    //fread(data,size,number,inptr)
    BYTE buffer[512];//each block is 512 bytes,i.e each buffer is a byte that we can later compare
    fread(buffer, 512, 1, f); //512 is size of each element that we want to read from f,1 block at a time

    //look for beginning of jpeg
    int jcounter = 0;
    FILE *img = NULL;
    char filename[50];//string
    while (fread(buffer, 512, 1, f) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //create a new file to write the data

            //if(firstjpeg)
            //{
            if (NULL != img)
            {
                fclose(img);
                img = NULL;
            }
            sprintf(filename, "%03i.jpg", jcounter);//creating string for our required file name
            //filename is name of the string 03i.jpg is content in that string which is filenmae
            img = fopen(filename,
                        "w");//to write data we opened a file called file name,filename string which is pointer contains our .jpg file nmae
            //write data to file
            //fwrite(data,size,number,outptr)
            fwrite(buffer, 512, 1, img);//writing to just opened jpeg from buffer which has 512 chucnk from card
            jcounter++;
            //}
            /*  if(jcounter>0)//already found jpeg
              {
                //open new ile to continue writing
                img = fopen(filename,"a"); //append that buffer block to current file with filename
                fwrite(buffer,512,1,img);
                fclose(img);*/
            // }
        }
        else //(found a jpeg already)//keep writing since every jepeg might take multiple block
        {
            //img = fopen(filename,"w");
            if (NULL != img)
            {
                fwrite(buffer, 512, 1, img);
            }

        }
    }

    //open new jpeg

    //write512 bytes until new jpeg
    //Close all files
    if (NULL != f)
    {
        fclose(f);
    }

    if (NULL != img)
    {
        fclose(img);
    }

    return 0;
}