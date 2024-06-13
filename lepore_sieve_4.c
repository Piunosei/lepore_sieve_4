/*
lepore_sieve_4  is free software
lepore_sieve_4  is Alberico Lepore creation
this file is free software
The lepore_sieve_4  is free software; you can redistribute it and/or modify
it under the terms of either:
    the GNU Lesser General Public License as published by the Free
    Software Foundation; either version 3 of the License, or (at your
    option) any later version.
You should have received copies of the
GNU Lesser General Public License here https://www.gnu.org/licenses/.
*/







/* gmp_version -- 6.1.2
Copyright 1996, 1999-2001 Free Software Foundation, Inc.
This file is part of the GNU MP Library.
The GNU MP Library is free software; you can redistribute it and/or modify
it under the terms of either:
  * the GNU Lesser General Public License as published by the Free
    Software Foundation; either version 3 of the License, or (at your
    option) any later version.
or
  * the GNU General Public License as published by the Free Software
    Foundation; either version 2 of the License, or (at your option) any
    later version.
or both in parallel, as here.
The GNU MP Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.
You should have received copies of the GNU General Public License and the
GNU Lesser General Public License along with the GNU MP Library.  If not,
see https://www.gnu.org/licenses/.  */





#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <gmp.h>

#define interval_size 100


int prendi_numero(char in[]);


int main(){

 mpf_set_default_prec(1000);/*set this value*/

 mpz_t N,m[interval_size+1],n[interval_size],min_interval,max_interval,zero,uno,due,tre,quattro,cinque,otto,nove,dodici,trentasei,settantadue,centoquarantaquattro,temp1,temp2,temp3,min_m,max_m,i,min_n,max_n,j,p,a,b,resto,mcd,P;

 mpf_t temp1_f,temp2_f,zero_f,uno_f,tre_f,quattro_f,dodici_f;
   
 mpz_init(N);

 char numero_N[10000];/*set this value*/
 prendi_numero(numero_N);
 mpz_init_set_str(N, numero_N, 10);

 gmp_printf ("\ninput=%Zd\n",N);
 mpz_init_set_str (zero, "0", 10);
 mpz_init_set_str (uno, "1", 10);
 mpz_init_set_str (due, "2", 10);
 mpz_init_set_str (tre, "3", 10);
 mpz_init_set_str (quattro, "4", 10);
 mpz_init_set_str (cinque, "5", 10);
 mpz_init_set_str (otto, "8", 10);
 mpz_init_set_str (nove, "9", 10);
 mpz_init_set_str (dodici, "12", 10);
 mpz_init_set_str (trentasei, "36", 10);
 mpz_init_set_str (settantadue, "72", 10);
 mpz_init_set_str (centoquarantaquattro, "144", 10);
 mpz_init(temp1);
 mpz_init(temp2);
 mpz_init(temp3);
 mpz_init(min_m);
 mpz_init(max_m);
 mpz_init (i);
 mpz_init(min_n);
 mpz_init(max_n);
 mpz_init(j);
 mpz_init(p);
 mpz_init(a);
 mpz_init(b);
 mpz_init(resto);
 mpz_init(mcd);
 mpz_init(P);
 
 mpf_init(temp1_f);
 mpf_init(temp2_f);
 mpf_init_set_str (zero_f, "0.0", 10);
 mpf_init_set_str (uno_f, "1.0", 10);
 mpf_init_set_str (tre_f, "3.0", 10);
 mpf_init_set_str (quattro_f, "4.0", 10);
 mpf_init_set_str (dodici_f, "12.0", 10);
 
 unsigned long long int k=0;



 int occurrences[interval_size];

 for (k = 0; k < interval_size; k++) {
   mpz_init_set_str (m[k],"0",10);
   mpz_init_set_str (n[k],"0",10);
   occurrences[k]=0;
}

 mpz_sub(N,N,cinque);
 mpz_div(N,N,dodici);
 mpz_mul(N,N,dodici);
 mpz_add(min_interval,N,cinque);

 mpz_mul_ui (temp1,dodici,interval_size);
 mpz_add(max_interval,temp1,min_interval);

 gmp_printf ("\nmin_interval=%Zd\nmax_interval=%Zd\n",min_interval,max_interval);

 mpz_mul(temp1,due,max_interval);
 mpz_sub(temp1,temp1,uno);
 mpf_set_z(temp1_f,temp1);
 mpf_sqrt(temp1_f,temp1_f);
 mpf_sub(temp2_f,temp1_f,tre_f);
 mpf_div(temp2_f,temp2_f,dodici_f);
 mpz_set_f(max_m,temp2_f);

 mpf_sub(temp1_f,zero_f,temp1_f);
 mpf_sub(temp2_f,temp1_f,tre_f);
 mpf_div(temp2_f,temp2_f,dodici_f);
 mpz_set_f(min_m,temp2_f);
 
 //gmp_printf ("\nmin_m=%Zd\nmax_m=%Zd\n",min_m,max_m);
 mpz_set(i,min_m);


 mpz_mul(temp1,max_interval,due);

 while(mpz_cmp(i,max_m)<=0){
   mpz_mul(temp1,max_interval,due);
   mpz_mul(temp2,i,i);
   mpz_mul(temp2,temp2,centoquarantaquattro);
   mpz_mul(temp3,i,settantadue);
   mpz_add(temp2,temp2,temp3);
   mpz_add(temp2,temp2,nove);
   mpz_sub(temp1,temp1,temp2);
   mpf_set_z(temp1_f,temp1);
   mpf_sqrt(temp1_f,temp1_f);
   mpf_sub(temp2_f,temp1_f,uno_f);
   mpf_div(temp2_f,temp2_f,quattro_f);
   mpz_set_f(max_n,temp2_f);

   mpf_sub(temp2_f,zero_f,temp1_f);
   mpf_sub(temp2_f,temp2_f,uno_f);
   mpf_div(temp2_f,temp2_f,quattro_f);
   mpz_set_f(min_n,temp2_f);

   //gmp_printf ("\nmin_n=%Zd\nmax_n=%Zd\n",min_n,max_n);   

   mpz_set(j,min_n);
   
   while(mpz_cmp(j,zero)<0){

     mpz_mul(temp1,i,i);
     mpz_mul(temp1,temp1,settantadue);
     mpz_mul(temp2,trentasei,i);
     mpz_add(temp1,temp1,temp2);
     mpz_mul(temp2,j,j);
     mpz_mul(temp2,temp2,otto);
     mpz_add(temp1,temp1,temp2);
     mpz_mul(temp2,quattro,j);
     mpz_add(temp1,temp1,temp2);
     mpz_add(p,temp1,cinque);

     if(mpz_cmp(p,min_interval)<0){
       break;
     }else{
       //gmp_printf ("\ni=%Zd   j=%Zd\n",i,j);

     mpz_sub(temp1,p,min_interval);
     mpz_div(temp1,temp1,dodici);
     k=mpz_get_ui (temp1);
     if(occurrences[k]==0){
        occurrences[k]++;
	mpz_set(m[k],i);
	mpz_set(n[k],j);
     }else if(occurrences[k]==1){
        occurrences[k]++;
     } 
      
     
     }
     mpz_add(j,j,uno);
   }
  
   mpz_set(j,max_n);
   
   while(mpz_cmp(j,zero)>=0){

     mpz_mul(temp1,i,i);
     mpz_mul(temp1,temp1,settantadue);
     mpz_mul(temp2,trentasei,i);
     mpz_add(temp1,temp1,temp2);
     mpz_mul(temp2,j,j);
     mpz_mul(temp2,temp2,otto);
     mpz_add(temp1,temp1,temp2);
     mpz_mul(temp2,quattro,j);
     mpz_add(temp1,temp1,temp2);
     mpz_add(p,temp1,cinque);

      if(mpz_cmp(p,min_interval)<0){
       break;
     }else{
	//gmp_printf ("\ni=%Zd   j=%Zd\n",i,j);

     mpz_sub(temp1,p,min_interval);
     mpz_div(temp1,temp1,dodici);
     k=mpz_get_ui (temp1);
     if(occurrences[k]==0){
        occurrences[k]++;
	mpz_set(m[k],i);
	mpz_set(n[k],j);
     }else if(occurrences[k]==1){
        occurrences[k]++;
     } 
      
     }
     mpz_sub(j,j,uno);
   }

   
   mpz_add(i,i,uno);
 }
 
 k=0;
 while(k<=interval_size){
 if(occurrences[k]==1){
   mpz_mul(temp1,quattro,m[k]);
   mpz_add(temp1,temp1,uno);
   if(mpz_cmp(temp1,zero)<0){
     mpz_sub(temp1,zero,temp1);
   }
   mpz_mul(temp2,quattro,n[k]);
   mpz_add(temp2,temp2,uno);
   if(mpz_cmp(temp2,zero)<0){
     mpz_sub(temp2,zero,temp2);
   }

   if(mpz_cmp(temp1,temp2)>=0){
     mpz_set(a,temp1);
     mpz_set(b,temp2);
   }else{
     mpz_set(a,temp2);
     mpz_set(b,temp1);
   }
 
   while(mpz_cmp(b,zero)>0){
     mpz_mod(resto,a,b);
     mpz_set(a,b);
     mpz_set(b,resto);
   }
   mpz_set(mcd,a);

   if(mpz_cmp(mcd,uno)==0){
     mpz_set_ui (temp1,k);
     mpz_mul(temp1,temp1,dodici);
     mpz_add(P,temp1,min_interval);
     gmp_printf("\nPRIME=%Zd\n",P);
   }
   
     } 


   k++;
 }
 
}






int prendi_numero(char in[]){

    char decimale[1000];
    int numero_di_cifre_decimali=0;
    FILE *fp;
    int i=0;

    fp = fopen("input.txt", "r");
    if (fp==NULL){
        printf("\nImpossibile aprire file\n");
        system("PAUSE");
        exit(1);
    }
    while(!feof(fp)){
        fscanf(fp,"%s",decimale);

    }
    fclose(fp);

    numero_di_cifre_decimali=strlen(decimale)-1;
    while(i<=numero_di_cifre_decimali){
        in[i]=decimale[i];
        i++;
    }
    return numero_di_cifre_decimali;
}
