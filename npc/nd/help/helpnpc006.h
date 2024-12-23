//helpnpc006.h
//槼�
//George 2001-07-07

NPC_BEGIN(CNhelpnpc006);

void create()
{
	set_name("槼�", "daji");
	set("title","��Ϳ��Ĩ");

	set("icon", girl1);
	set("gender", "Ů��" );
	set("age", 19);
	set("long","����");
	set("attitude", "friendly");   
	set("env/wimpy", 100);  
	set("no_talk",1);
} 
int do_talk(CChar * me, char * ask = NULL)
{

	static char hua1[5][100]=
	{
		"��ս���У�ʳ��͵��߿����𵽺ܴ�����á�",
		"�кܶ�������Ʒ��ҪŬ��Ѱ�ҲŻ�õ���",
		"����ҩƷ��ʳƷ�ںܶ�ط������ۡ�",
		"��Щ������Ϊ�Ҳ�����ҩ��ʹ�ж����",
		"һ��Ҫ�˽�һЩҩ���ʳƷ�����ò����ڽ����д�����"
	};
	static char hua2[2][100]=
	{
		"�㻹Ҫ�˽�ʲô��",
		"�����Ը�����һЩ��"
	};
	static char hua3[33][100]=
	{
		"����",
		"���⴮",
		"����ɢ",
		"ѩ��",
		"����ү",
		"�����Ϻ�ɢ",
		"���������",
		"�ߵ���",
		"��ɽ��",
		"��Ц��ңɢ",

		"�ɺ�ҩ",
		"������",
		"��Ѽ",
		"����",
		"��Ҷ��",
		"������",
		"���Ŀڷ�Һ",
		"���������",
		"�����ܵ���",
		"��ѩ����",
		
		"ҩ��",
		"��ҩ",
		"ѩ����󸵤",
		"�쾦���",
		"���㻨",
		"ʱ�մ�����",
		"�س̾���",
		"��ӡħ��",
		"ͬ��ӡ",
		"ԭʼ����",
		
		"��ɫ������",
		"���",
		"����������"

	};
	static char hua4[33][200]=
	{
		"������������ӣ�����������Ҷ����һ�����㣬ζ�������������ԡ�",
		"����������⴮������մ������Ȼ�������棬���������ǧ��������",
		"���޶��Ľ�ҩ",
		"Ч���ǳ��ã����Կ������ˡ�",
		"����������������ҩ������֮����Ҫ����������������ү�Ƶġ���˵������������������",
		"һ��ǿ�ҵĴ�ҩ���������ʳ������������������",
		"����һ�к�ɫ�����˸�ҩ�����Բ�Ϳ��smear��",
		"�������Ʒ���ߵ��ࡻ��С�����˼����HP",
		"�����кܶ���ɽ����Ҳ��������ҩ��",
		"��һ����ɫ�ķ�ĩ, �㿴�������Ӿ�֪������Ѱ����Ʒ. ���޵���Ц��",
		
		"ʹ�˻�˯��һ��ҩƷ���ܶ���Ǯ�˼ҵĻ������Ӿ�������Я��",
		"�����˿�����Ϊ�����˵�ʳƷ��",
		"��ͨʳƷ���Թ���֪���ˡ�",
		"���ʱ�����͵�ʳƷ��ζ���ܺá�",
		"ϲ�ƣ�ҪС�����ã��ǳ��������ˡ�",
		"С�ԣ��ܶ��˶��ܰ��ԡ�",
		"Ů������Ҫ���ģ���������ħ������������������Խ����������嶾���ƵĶ���",
		"���������Ƶĵĺ��������,��˵������������",
		"������ʿ�������������ʥҩ��",
		"�����Ժ������ʳ��������",
		
		"ר�����˵�ҩ�ۡ�ֻ��ר���ɶԸ����������ơ����书���˲���Ҫ������ҩ��",
		"�����е�����ҩ�����Ǽ�Ǯ����һ�㡣",
		"�ܽ��ʮ���ֶ�����ҩ��Ҳ������ΪĿǰ�ö����˲��࣬���Լ۸񲻹��ڸ���ҩ��������ۡ�",
		"�ܽ�ٶ�����ҩ�����ǲ���ô�����ҵ���",
		"�����MP 5��",
		"����ħ���϶��µĶ��������Դ���ռ䣬�ڱ��������ݣ����գ����ޣ�����Ȫ�ݵȵ�����������",
		"��������ڵĺö��������������ӵ���ȫ�ĵط���������ļһ������������̵Ŀ�ջ���ö���������ʵ��",
		"ͬ���ǽ��ڻ�,���Խ�һ�����ӷ�ס��һ����˴򲻿���Ҳ�������ⶫ���⿪��ӡ��",
		"����ʹ�ú�Ů��ʹ�ã��ͽ��ඣ��������ඣ�",
		"���������ԭ���ϣ��ڷ�ɽ�����Ȫ������������͵Ĺ���Ȼ�������������Ҫ�����ͻ�����������Я���ı��������������ս���ɳ���",
		
		"��ĳЩ�����õĶ�����",
		"����ı�����ߣ���ĳ��ʹ��֮��Ϳ��԰���߻����������ӣ������Ժ�ɾ�����Ҳû���ϵ��㣬",
		"����������������������۸���ߣ�������������һ���ʳƷҩƷ��������ʱ�������Ե�ҩƷ�������кö�����"
	};
	if(!strlen(ask))
	{
		if(random(2))
			return 0;
		for(int i=0;i<5;i++)
		{
			if(!random(2))
				say(hua1[i],me);
		}
		say(hua2[random(2)],me);
		for(int ii=0;ii<33;ii++)
		{
			if(!random(4))
			AddMenuItem(hua3[ii], zifu(ii), me);
		}
		SendMenu(me);
		return 1;
	}
	say(hua4[shuzi(ask)],me);
	SendMenu(me);
	return 1;
}
char * zifu(int x)
{
   switch(x)
   {
		case 0:return "0";
		case 1:return "1";
		case 2:return "2";
		case 3:return "3";
		case 4:return "4";
		case 5:return "5";
		case 6:return "6";
		case 7:return "7";
		case 8:return "8";
		case 9:return "9";
		case 10:return "10";
		case 11:return "11";
		case 12:return "12";
		case 13:return "13";
		case 14:return "14";
		case 15:return "15";
		case 16:return "16";
		case 17:return "17";
		case 18:return "18";
		case 19:return "19";
		case 20:return "20";
		case 21:return "21";
		case 22:return "22";
		case 23:return "23";
		case 24:return "24";
		case 25:return "25";
		case 26:return "26";
		case 27:return "27";
		case 28:return "28";
		case 29:return "29";
		case 30:return "30";
		case 31:return "31";
		case 32:return "32";
		case 33:return "33";
		default:return "00";
   }
}
int shuzi(char * y)
{
   if(strcmp(y,"0")==0)
	   return 0;
   else if(strcmp(y,"1")==0)
	   return 1;
   else if(strcmp(y,"2")==0)
	   return 2;
   else if(strcmp(y,"3")==0)
	   return 3;
   else if(strcmp(y,"4")==0)
	   return 4;
   else if(strcmp(y,"5")==0)
	   return 5;
   else if(strcmp(y,"6")==0)
	   return 6;
   else if(strcmp(y,"7")==0)
	   return 7;
   else if(strcmp(y,"8")==0)
	   return 8;
   else if(strcmp(y,"9")==0)
	   return 9;
   else if(strcmp(y,"10")==0)
	   return 10;
   else if(strcmp(y,"11")==0)
	   return 11;
   else if(strcmp(y,"12")==0)
	   return 12;
   else if(strcmp(y,"13")==0)
	   return 13;
   else if(strcmp(y,"14")==0)
	   return 14;
   else if(strcmp(y,"15")==0)
	   return 15;
   else if(strcmp(y,"16")==0)
	   return 16;
   else if(strcmp(y,"17")==0)
	   return 17;
   else if(strcmp(y,"18")==0)
	   return 18;
   else if(strcmp(y,"19")==0)
	   return 19;
   else if(strcmp(y,"20")==0)
	   return 20;
   else if(strcmp(y,"21")==0)
	   return 21;
   else if(strcmp(y,"22")==0)
	   return 22;
   else if(strcmp(y,"23")==0)
	   return 23;
   else if(strcmp(y,"24")==0)
	   return 24;
   else if(strcmp(y,"25")==0)
	   return 25;
   else if(strcmp(y,"26")==0)
	   return 26;
   else if(strcmp(y,"27")==0)
	   return 27;
   else if(strcmp(y,"28")==0)
	   return 28;
   else if(strcmp(y,"29")==0)
	   return 29;
   else if(strcmp(y,"30")==0)
	   return 30;
   else if(strcmp(y,"31")==0)
	   return 31;
   else if(strcmp(y,"32")==0)
	   return 32;
   else if(strcmp(y,"33")==0)
	   return 33;
   else 
	   return 100;
}

virtual int accept_fight(CChar * me)
{
	char msg[255];
	say(snprintf(msg,255," %s����ô�Ǵ����Ķ����أ�",query_respect(me) ));
	return 0;
}
/*
virtual void die()
{
	revive(1);
//	message_vision("$N��������������˿�����", this);
	set("max_hp",30000);
	set("eff_hp",30000);
	set("hp",30000);
}
*/
NPC_END;

