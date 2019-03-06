/* by gunnarpope
* 3/06/19
*/

#include <stdio.h>
#include <stdint.h>
#include "../circular_queue.c"

int main(){

queue_init();

data_t a,b,c,d,e,f,g,h,i;
a.value = 1;
b.value = 2;
c.value = 3;
d.value = 4;
e.value = 5;
f.value = 6;
g.value = 7;
h.value = 8;
i.value = 9;

printf("%s", "QUEUE_LEN IS:");
printf("%i\n", QUEUE_LEN);

// add one to the buffer and retrieve it
add_queue(&a);

data_t dout;
dout = get_queue();
printf("%s\n","write 1 -> read 1" );
printf("%i\n",dout.value );
// add two to the buffer, read one, add two read all

add_queue(&b);
add_queue(&c);
printf("%s\n", "write 2,3 -> read 2");
printf("%i\n", get_queue().value);


printf("%s\n", "write 4,5,6 -> read all");
add_queue(&d);
add_queue(&e);
add_queue(&f);

while(queue.samples)
  printf("%i\n", get_queue().value);

printf("%s\n","write 7,8,9,10,11,12,13-> test overflow" );

uint16_t vec[7] = {7,8,9,10,11,12,13};

for (uint8_t i = 0;i<7;i++){
  data_t ac;
  ac.value = vec[i];
  add_queue(&ac);
  if (queue.overflow)
    printf("%s: %i\n", "QUEUE OVERFLOW!", vec[i]);

}

printf("%s\n","Read all values in queue and test if data was overwritten" );
printf("%s\n","(Correct output should be 7,8,9,10,11)" );

while(queue.samples)
  printf("%i\n", get_queue().value);

return 0;
}
