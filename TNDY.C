#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>
#include <conio.h>

int main(int argc, char *argv[]){
        int i=0;
        int port;

        int num = atoi(argv[1]);

        if (argc==1){
        help();
        return 0;
        }

        if (num == 0){
        help();
        return 0;
        }

        if (num > 9){
        help();
        return 0;
        }

        if (num == 1){
        port=0x0C0;
        }
        if (num == 2){
        port=0x0E0;
        }      
        if (num == 3){
        port=0x1C0;
        }
        if (num == 4){
        port=0x1E0;
        }
        if (num == 5){
        port=0x2C0;
        }

        if (num == 6){
        port=0x2E0;
        }
        if (num == 7){
        port=0x378;
        }
        if (num == 8){
        port=0x3BC;
        }
        if (num == 9){
        port=0x2F8;
        }


        printf("3TOOL - TNDY 3-Voice Soundgenerator enabler/channel muting\n");
        printf("07/2020 matze79, thx to dragonsphere, dreamblaster, darius and pdewacht\n");
        printf("enable SN76489 @ %x\n",port);

        if (num == 7){
        outp(0x37A,0xE5);
        }
        if (num == 8){
        outp(0x3BE,0xE5);
        }
        if (num == 9){
        outp(0x27A,0xE5);
        }

        while(i <= 10) {
        outp(port,0x9F);
        outp(port,0xBF);
        outp(port,0xDF);
        outp(port,0xFF);
        delay(50);
        i=i+1;
        }
return 0;
}

int help(){
printf("USAGE: 3tool.exe 123456\n");
printf("Parameters\n");
printf("TNDY 3-Voice:\n");
printf("1 - 0C0h  2 - 0E0h 3 - 1E0h\n");
printf("4 - 1C0h  5 - 2C0h 6 - 2E0h\n\n");
printf("Tandy Nano and Serdaco TNDY 3-Voice\n");
printf("1 - XT    5 - AT\n\n");
printf("Serdaco TNDLPT Adapter:\n");
printf("7 - 378h  8 - 3BC 9 - 2F8\n");
printf("Its highly recommend you run this program to ensure all voices are \nmuted properly.\n");
return 0;

}
