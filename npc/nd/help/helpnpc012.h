//helpnpc012.h
//С��
//George 2001-07-07

NPC_BEGIN(CNhelpnpc012);

void create()
{
	set_name("С��", "xiaochou");
	set("title","��Ŀ���");

	set("icon", young_man5);
	set("gender", "����" );
	set("age", 25);
	set("long","��������");
	set("attitude", "friendly");  
	set("env/wimpy", 100);   
	set("no_talk",1);
}   
int do_talk(CChar * me, char * ask = NULL)
{

	static char hua1[4][100]=
	{
		"����Ϸ��Ҫע��ܶ������֪�����С�",
		"Ҫ������Ϸ���ɡ�",
		"����Ϸ������ȫ���ɵģ�������ǣ������Ϸ�⡣",
		"����Ϸ��PK���ǿ��Եģ����PK̫��ᱻѲ��׷ɱ��"
	};
	static char hua2[2][100]=
	{
		"��Ҫ��ʲô��",
		"��ʲô�����׾�˵��",
	};
	static char hua3[10][100]=
	{
		"�������Լ��ĳ�����",
		"�Ұ����ѽ��տ��԰�",
		"����ͬʱ���Ƽ�������",
		"������ɱ��",
		"��Ҫ����ɱ�֡�",
		"�¶����ҵĳ��",
		"������Ҳ��ᱻ�߰ɣ�",
		"��ƭ��",
		"�����ҷ�����bug.",
		"��Ҫÿ��PK�ܶ���ҡ�"
	};
	static char hua4[10][100]=
	{
		"����Ϸ�в�׼ʹ�÷ǹٷ����Զ��M���Զ����򣬷������Ը���",
		"й©��Ϸ���ܹؼ��Ľⷨ�Ǿ��Խ�ֹ�ġ�",
		"������ͬʱ���������������ϵĽ�ɫ������Ϸ�� ",
		"���ԡ�",
		"�Ͷ��ٸ���û���⡣",
		"����ͷ����س��ɡ�",
		"����Ϸ�а�����ԣ�����������ID�����������⵵���������ò���ʹ�á�",
		"ƭ˭�����ԣ��㲻��׷ɱ�Ϳ��ԡ�",
		"����ñ��棬������������������ҵ��������⵵������",
		"ֻҪ���Ƕ���PK���֣�����ͬһ��PKͬһ���������ϡ�����������PK���������ġ�"
	};
	if(!strlen(ask))
	{
		if(random(2))
			return 0;
		for(int i=0;i<4;i++)
		{
			if(!random(2))
				say(hua1[i],me);
		}
		say(hua2[random(2)],me);
		for(int ii=0;ii<10;ii++)
		{
			if(!random(3))
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
