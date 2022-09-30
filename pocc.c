#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<malloc.h>
const int xL=4;
const double pOcc=0.5;
const unsigned int rseed=9998;
int nsites=xL*xL;
int xV[4];
int yV[4];
int fneighbour[16][4];
int main(){
  int im,jm,km;
  double ra;
  int *sitestat;
  FILE*FPL;
  // neighbours
  xV[0]=-1,xV[1]=0;xV[2]=1,xV[3]=0;
  yV[0]=0;yV[1]=1;yV[2]=0;yV[3]=-1;
  for(im=0;im< nsites;im++){
    fneighbour[im][0]=im-1;
    fneighbour[im][1]=im+xL;
    fneighbour[im][2]=im+1;
    fneighbour[im][3]=im-xL;
    if(im%xL==0){
      fneighbour[im][0]+=xL;
      
    }
    if(im>(nsites-xL-1)){
      fneighbour[im][1]-=nsites;
    }
    if((im+1)%xL==0){
      fneighbour[im][2]-=xL;
    }
    if(im<xL){
      fneighbour[im][3]+=nsites;
    }
       
  }
  for(int im=0;im<nsites;im++){
    for(int i=0;i<4;i++){
      
      printf("%d  %d %d  ",im ,i, fneighbour[im][i]);
      
    }
    printf("\n");
  }
  exit(1);
  //nsites=xL*xL;//
  sitestat=malloc(nsites*sizeof(int));
  srand(rseed);
  for(int im=0;im<xL;im++){
    for(int jm=0;jm<xL;jm++){
      km=jm+im*xL;
      ra=(double)rand()/RAND_MAX;
      //    printf("%e %i\n",ra,RAND_MAX);
       if(ra<pOcc){
	sitestat[km]=1;
      }
      else{
	sitestat[km]=0;
      }
    }
  }
  for(im=0;im<nsites;im++){
    // printf("%d\n",sitestat[im]);
  }
  
    
  //EPS code
  int eScl=20;
  FPL=fopen("snapShot.eps","w");
  fprintf(FPL,"%%!PS-Adobe-2.0\n");
  fprintf(FPL,"%%Title:Percolation\n");
  fprintf(FPL,"%%%%BoundingBox:%d %d %d %d\n",-eScl,-eScl,xL*eScl+1,xL*eScl+1);
  fprintf(FPL,"%%Pages:1\n");
  fprintf(FPL,"%%EndComments\n");
  fprintf(FPL,"%%Pages:1 1\n");
  fprintf(FPL,".2 setflat\n");
  fprintf(FPL,"/C {newpath 0.4 0 360 arc 0.1 setgray fill}def\n");
  fprintf(FPL,"/D {newpath 0.05 0 360 arc 0.1 setgray fill}def\n");
  fprintf(FPL,"0 0 translate\n");
  fprintf(FPL,"%d %d scale 0.2 setlinewidth\n",eScl,eScl);

  for(im=0;im<xL;im++){
    for(jm=0;jm<xL;jm++){
      km=jm+xL*im;
      if(sitestat[km]==1){
	
	fprintf(FPL,"%d %d C\n",im,jm);
      }
      else{
	
        fprintf(FPL,"%d %d D\n",im,jm);
      }
    }
  }
  fprintf(FPL,"showpage\n");
  fclose(FPL);
  
  
  
 



  
}
   
  
