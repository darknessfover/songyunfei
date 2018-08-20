#include<reg52.h>
#define uchar unsigned char	
#define uint unsigned int

sbit duan = P3^0;  //段选
sbit wei = P3^1;   //位选
sbit S1 = P1^0;        //暂停键
sbit S2 = P1^1;        //增加键
sbit S3 = P1^2;        //减少键
sbit S4 = P1^3; //闹钟设置键
sbit S5 = P1^4; //闹钟启用停止键


uchar code aaa[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};//数码管段0-9（10）
uchar temp,out = 1,qq = 0,ww = 0,H,M,S,j1,j2,k1,k2,l1,l2;
uchar H1 = 0,M1 = 0,Sa = 0,j10,j20,k10,k20,l10,l20,SS = 0;
uint UT;


/*********************************************/
/*********延时函数:毫秒***********************/
void delayMS(x) //延时函数，单位毫秒
{
        uint a , b;
        for(a = 0 ; a < x ; a++ )
        for(b = 0 ; b < 110 ; b++);
		}
		

/************************************/
/************显示时分秒**************/
void play(uint h1 , uint h2 , uint m1 , uint m2 , uint s1 , uint s2) //时分秒的显示
{
        wei = 0; //时的十位
        P2 = 0xfe;
        wei = 1; 

        duan = 1;
        P0 = aaa[h1];
        duan = 0;
        delayMS(3);

        wei = 1; //时的个位
        P2 = 0xfd;
        wei = 0; 

        duan = 1;
        P0 = aaa[h2];
        duan = 0;        
        delayMS(3);

        wei = 1; //分的十位
        P2 = 0xf7;
        wei = 0; 

        duan = 1;
        P0 = aaa[m1];
        duan = 0;
        delayMS(3);

        wei = 1; //分的个位
        P2 = 0xef;
        wei = 0; 

        duan = 1;
        P0 = aaa[m2];
        duan = 0;
        delayMS(3);

        wei = 1; //秒的十位
        P2 = 0xbf;
        wei = 0; 

        duan = 1;
        P0 = aaa[s1];
        duan = 0;
        delayMS(3);

        wei = 1; //秒的个位
        P2 = 0x7f; 
        wei = 0; 

        duan = 1;
        P0 = aaa[s2];
        duan = 0;
        delayMS(3); 
}
/***********************************/
/*************按键及功能************/
void stopfunc() //S1键函数 暂停
{
        if(S1 == 0)
        {
                while(!S1);
                qq++;
                out = 0; //暂停
                TR0 = 0;        
        }                
}


void WWS4() //闹钟设置
{
        if(S4 == 0)
        {
                while(!S4);
                ww++;
        }
}


void begin() //S5键 闹钟启动和停止
{
        if(S5 == 0)
        {
                while(!S5);
                SS = !SS;
        }
}



void buttfunc() //S2键、S3键函数 调时
{
        
        if(qq == 1) //第一次按S1时，调秒
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
        if(qq == 2) //第二次按S1时，调分
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
        if(qq == 3) //第三次按S1时，调时
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
        if(qq == 4) //第四次 ,设闹钟
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
        
        if(qq == 5) //第五次按S1时，继续计时
        {
                while(!S1);
                qq = 0;
                ww = 0;
                out = 1;
        }
}

 /************主函数****************/
void main()
{
        TMOD = 0x01; //定时器0
        IE = 0x83; //中断打开，打开外部中断0和定时器0中断
        TH0 = (65536 - 46080)/256; //初值：2^16=65536   11.0592*10^6 * 50*10^(-3)=46080 （晶振*中断时间） 
        TL0 = (65536 - 46080)%256;
        while(1)
        {
                stopfunc();
                begin();
                
                if(out == 1)
                {
                        TR0 = 1;
                        if(UT == 20) //1秒钟到了----20*50=1000ms
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
                                                if(H == 24) //24小时制
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
/**********************定时器*********************/
void TIME() interrupt 1
{
        TH0 = (65536 - 46080)/256; //重装初值
        TL0 = (65536 - 46080)%256;
        UT++;
}
													  													  													  	