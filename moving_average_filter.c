#include <stdio.h>
#include <stdint.h>
#define BOXLEN 5

float average(float x[], uint16_t len){
    uint16_t j;
	float accum = 0;
    for(j=0;j<len;j++){ accum += x[j];} 
    return accum/len;
}

int main(){


float box[BOXLEN] = {0};

uint16_t box_index = 0;

for (uint16_t i = 0; i <20;i++){
	box[i%BOXLEN] = i;
	
float accum = 0;
	for(uint16_t j=0;j<BOXLEN;j++){
      printf("box[%i]=%f\r\n",j,box[j]);
	}

float av;
av = average(box,BOXLEN);

printf("mean(box)=%f\r\n\r\n", av);
}

return 0;
}
