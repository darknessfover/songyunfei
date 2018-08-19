#include<reg52.h>
#define uchar unsigned char	
#define uint unsigned int

sbit duan = P3^0;  //��ѡ
sbit wei = P3^1;   //λѡ
sbit S1 = P1^0;        //��ͣ��
sbit S2 = P1^1;        //���Ӽ�
sbit S3 = P1^2;        //���ټ�
sbit S4 = P1^3; //�������ü�
sbit S5 = P1^4; //��������ֹͣ��


uchar code aaa[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};//����ܶ�0-9��10��
uchar temp,out = 1,qq = 0,ww = 0,H,M,S,j1,j2,k1,k2,l1,l2;
uchar H1 = 0,M1 = 0,Sa = 0,j10,j20,k10,k20,l10,l20,SS = 0;
uint UT;


/*********************************************/
/*********��ʱ����:����***********************/
void delayMS(x) //��ʱ��������λ����
{
        uint a , b;
        for(a = 0 ; a < x ; a++ )
        for(b = 0 ; b < 110 ; b++);
		}
		

/************************************/
/************��ʾʱ����**************/
void play(uint h1 , uint h2 , uint m1 , uint m2 , uint s1 , uint s2) //ʱ�������ʾ
{
        wei = 0; //ʱ��ʮλ
        P2 = 0xfe;
        wei = 1; 

        duan = 1;
        P0 = aaa[h1];
        duan = 0;
        delayMS(3);

        wei = 1; //ʱ�ĸ�λ
        P2 = 0xfd;
        wei = 0; 

        duan = 1;
        P0 = aaa[h2];
        duan = 0;        
        delayMS(3);

        wei = 1; //�ֵ�ʮλ
        P2 = 0xf7;
        wei = 0; 

        duan = 1;
        P0 = aaa[m1];
        duan = 0;
        delayMS(3);

        wei = 1; //�ֵĸ�λ
        P2 = 0xef;
        wei = 0; 

        duan = 1;
        P0 = aaa[m2];
        duan = 0;
        delayMS(3);

        wei = 1; //���ʮλ
        P2 = 0xbf;
        wei = 0; 

        duan = 1;
        P0 = aaa[s1];
        duan = 0;
        delayMS(3);

        wei = 1; //��ĸ�λ
        P2 = 0x7f; 
        wei = 0; 

        duan = 1;
        P0 = aaa[s2];
        duan = 0;
        delayMS(3); 
}
/***********************************/
/*************����������************/
void stopfunc() //S1������ ��ͣ
{
        if(S1 == 0)
        {
                while(!S1);
                qq++;
                out = 0; //��ͣ
                TR0 = 0;        
        }                
}


void WWS4() //��������
{
        if(S4 == 0)
        {
                while(!S4);
                ww++;
        }
}


void begin() //S5�� ����������ֹͣ
{
        if(S5 == 0)
        {
                while(!S5);
                SS = !SS;
        }
}



void buttfunc() //S2����S3������ ��ʱ
{
        
        if(qq == 1) //��һ�ΰ�S1ʱ������
        {
                if(S2 == 0)
                {
                        while(!S2);
                        if(S < 59)
                        {
                                S++;
                        }
                        else
                        {
                                S = 0;        
                        }
                        delayMS(5);
                }
                if(S3 == 0)
                {
                        while(!S3);
                        if(S > 0)
                        {                                        
                                S--;
                        }
                        else
                        {
                                S = 59;
                        }
                        delayMS(5);
                }
                        j1=H%10;
                        j2=H/10;
                        k1=M%10;
                        k2=M/10;
                        l1=S%10;
                        l2=S/10;
                        play(j2,j1,k2,k1,l2,l1);
        }
        if(qq == 2) //�ڶ��ΰ�S1ʱ������
        {
                if(S2 == 0)
                {
                        while(!S2);
                        if(M < 59)
                        {
                                M++;
                        }
                        else
                        {
                                M = 0;
                        }
                        delayMS(5);
                }
                if(S3 == 0)
                {
                        while(!S3);
                        if(M > 0)
                        {                                        
                                M--;
                        }
                        else
                        {
                                M = 59;
                        }
                        delayMS(5);
                }
                        j1=H%10;
                        j2=H/10;
                        k1=M%10;
                        k2=M/10;
                        l1=S%10;
                        l2=S/10;
                        play(j2,j1,k2,k1,l2,l1);
        }
        if(qq == 3) //�����ΰ�S1ʱ����ʱ
        {
                if(S2 == 0)
                {
                        while(!S2);
                        if(H < 23)
                        {
                                H++;
                        }
                        else
                        {
                                H = 0;
                        }
                        delayMS(5);
                }
                if(S3 == 0)
                {
                        while(!S3);
                        if(H > 0)
                        {                                        
                                H--;
                        }
                        else
                        {
                                H = 23;
                        }
                        delayMS(5);
                }
                        j1=H%10;
                        j2=H/10;
                        k1=M%10;
                        k2=M/10;
                        l1=S%10;
                        l2=S/10;
                        play(j2,j1,k2,k1,l2,l1);
        }
        if(qq == 4) //���Ĵ� ,������
        {
                j10=H1%10;
                j20=H1/10;
                k10=M1%10;
                k20=M1/10;
                l10=Sa%10;
                l20=Sa/10;
                play(j20,j10,k20,k10,l20,l10);
                if(ww == 1)
                {
                        if(S2 == 0)
                        {
                                while(!S2);
                                if(M1 < 59)
                                {
                                        M1++;
                                }
                                else
                                {
                                        M1 = 0;
                                }
                                delayMS(5);
                        }
                        if(S3 == 0)
                        {
                                while(!S3);
                                if(M1 > 1)
                                {
                                        M1--;
                                }
                                else
                                {
                                        M1 = 59;
                                }
                        }
                }
                if(ww == 2)
                {
                        if(S2 == 0)
                        {
                                while(!S2);
                                if(H1 < 23)
                                {
                                        H1++;
                                }
                                else
                                {
                                        H1 = 0;
                                }
                                delayMS(5);
                        }
                        if(S3 == 0)
                        {
                                while(!S3);
                                if(H1 > 1)
                                {
                                        H1--;
                                }
                                else
                                {
                                        H1 = 23;
                                }
                        }
                 }                        
        }
        
        if(qq == 5) //����ΰ�S1ʱ��������ʱ
        {
                while(!S1);
                qq = 0;
                ww = 0;
                out = 1;
        }
}

 /************������****************/
void main()
{
        TMOD = 0x01; //��ʱ��0
        IE = 0x83; //�жϴ򿪣����ⲿ�ж�0�Ͷ�ʱ��0�ж�
        TH0 = (65536 - 46080)/256; //��ֵ��2^16=65536   11.0592*10^6 * 50*10^(-3)=46080 ������*�ж�ʱ�䣩 
        TL0 = (65536 - 46080)%256;
        while(1)
        {
                stopfunc();
                begin();
                
                if(out == 1)
                {
                        TR0 = 1;
                        if(UT == 20) //1���ӵ���----20*50=1000ms
                        {        
                                UT = 0;
                                S++;
                                if(S == 60)
                                {
                                        S=0;
                                        M++;
                                        if(M == 60)
                                        {
                                                M = 0;
                                                H++;
                                                if(H == 24) //24Сʱ��
                                                {
                                                        H = 0;
                                                }
                                        }
                                }
                        }
                
                        j1=H%10;
                        j2=H/10;
                        k1=M%10;
                        k2=M/10;
                        l1=S%10;
                        l2=S/10;
                        play(j2,j1,k2,k1,l2,l1);
                
                }
                else
                {                
                        WWS4();
                        buttfunc();        
                }
        }
}
/**********************��ʱ��*********************/
void TIME() interrupt 1
{
        TH0 = (65536 - 46080)/256; //��װ��ֵ
        TL0 = (65536 - 46080)%256;
        UT++;
}
													  													  													  	