#include<iostream>
#include<string.h>
#include<cmath>
#include <iomanip>
using namespace std;
int main()
{
	double w13,w14,w23,w24,w35,w45,learningRate,b3,b4,b5,e;
	w13=0.5;w14=0.9;w23=0.4;w24=1.0;w35=-1.2;w45=1.1;
	b3=0.8; b4=-0.1; b5=0.3;learningRate=0.1;e=2.718281828;
	double Etotal[4]={0,0,0,0};
	int x1[4]={0,0,1,1};
	int x2[4]={0,1,0,1};
	int Yd[4]={0,1,1,0};
	double InNode3;
	double OutNode3;
	double InNode4;
	double OutNode4;
	double InNode5;
	double Y5[4];
	//--------------------------------------------------
	double Ew13,Ew14,Ew23,Ew24,Ew35,Ew45;
	double EY5,Y5InNode5,InNode5w35,InNode5w45;
	
	double InNode5OutNode3,OutNode3InNode3,InNode3w13;
	double InNode3w23;
	
	double InNode5OutNode4,OutNode4InNode4,InNode4w14;
	double InNode4w24;
	//----------------------------------------------------
	static 	int counter=1;
	int i;
	int j;
	int k;
    static int epoch=1;
    string space=" ";
    static	int Ecounter=0;
    //---------------------------------------
     cout<<"Epoch"<<"   "<<"Iteration"<<"     "<<"Inputs"<<"     "<<"Desired outputs"<<"       "<<"                                          Initial weights"<<"                                                 "<<"Actual outputs"<<"        "<<"Error"<<"       "<<"\n";	
     cout<<"     "<<"   "<<"         "<<"     "<<"x1  x2"<<"     "<<"       Yd      "<<"       "<<"  w13               w23               w14               w24                w35               w45"<<"          "<<"      Y       "<<"        "<<"  e  "<<"       "<<"\n";
    //-------------------------------------   
    for(k=0;k<=9;k++){
   	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
   	if ((counter-1)%4==0){
   		if(epoch<=9){
		cout<<"  "<<epoch<<" ";}
		else{
			cout<<"  "<<epoch;
		}
	epoch++;
}
//-------------------------------
//Forward Passes
	for(i=0;i<=3;i++){
	
	Ecounter=0;
	if((counter)>9){
	space="";}
	if ((counter-1)%4==0){
	cout<<"        "<<counter<<"        "<<space<<x1[i]<<"   "<<x2[i]<<"             "<<Yd[i]<<"              "<<fixed <<setprecision(6)<<w13<<"          "<<w23<<"          "<<w14<<"          "<<w24<<"          "<<w35<<"          "<<w45;} 
	else {
	cout<<"            "<<counter<<"        "<<space<<x1[i]<<"   "<<x2[i]<<"             "<<Yd[i]<<"              "<<fixed <<setprecision(6)<<w13<<"          "<<w23<<"          "<<w14<<"          "<<w24<<"          "<<w35<<"          "<<w45;}	
	counter++;
	//------------------------------

	InNode3=(x1[i]*w13+x2[i]*w23)+b3;
    
	OutNode3=(1/(1+pow(e,-InNode3)));

		
	
	//----------------------------------

	InNode4=((x1[i]*w14)+(x2[i]*w24))+b4;
	OutNode4=(1/(1+(pow(e,-InNode4))));
		
	
	
	//--------------------------------------

	InNode5=(OutNode3*w35+OutNode4*w45)+b5;
	Y5[i]=0;
	Y5[i]=(1/(1+pow(e,-InNode5)));
	cout<<"          "<<Y5[i];
	Etotal[i]=0;
	Etotal[i]=0.5*(pow((Yd[i]-Y5[i]),2));
	cout<<"          "<<Etotal[i]<<"\n";
	//------------------------------------
	//Backward Passes
	EY5=Y5[i]-Yd[i];
	Y5InNode5=(1/(1+pow(e,-InNode5)))*(1-(1/(1+pow(e,-InNode5))));
	InNode5w35=OutNode3;
	InNode5w45=OutNode4;
	
	
	//----------------------
	InNode5OutNode3=w35;
	InNode5OutNode4=w45;
	//------------------
	OutNode3InNode3=(1/(1+pow(e,-InNode3)))*(1-(1/(1+pow(e,-InNode3))));
	OutNode4InNode4=(1/(1+pow(e,-InNode4)))*(1-(1/(1+pow(e,-InNode4))));
	
	//-----------------------------------
	InNode3w13=x1[i];
	InNode3w23=x2[i];
	//-----------
	InNode4w14=x1[i];
	InNode4w24=x2[i];
	//---------------------------------------------------------------
	Ew35=EY5*Y5InNode5*InNode5w35;
	Ew45=EY5*Y5InNode5*InNode5w45;
	
	
	Ew13=EY5*Y5InNode5*InNode5OutNode3*OutNode3InNode3*InNode3w13;
	
	Ew23=EY5*Y5InNode5*InNode5OutNode3*OutNode3InNode3*InNode3w23;
	Ew14=EY5*Y5InNode5*InNode5OutNode4*OutNode4InNode4*InNode4w14;
	Ew24=EY5*Y5InNode5*InNode5OutNode4*OutNode4InNode4*InNode4w24;


	//------------------------------------------------------------
	w13=w13-learningRate*Ew13;
	w14=w14-learningRate*Ew14;
	w23=w23-learningRate*Ew23;
	w24=w24-learningRate*Ew24;
	w35=w35-(0.1*Ew35);
	w45=w45-learningRate*Ew45;	
} 	
    }
}
    	
	

