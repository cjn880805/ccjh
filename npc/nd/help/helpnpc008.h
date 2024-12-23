//helpnpc008.h
//������
//George 2001-07-07

NPC_BEGIN(CNhelpnpc008);

void create()
{
	set_name("������", "xinqiji");

	set("title","��ѧ��");

	set("icon", young_man5);
	set("gender", "����" );
	set("age", 45);
	set("long","��������һ���飬��֪�����뵽��ʲô��");
	set("attitude", "friendly");  
	set("env/wimpy", 100);  
	set("no_talk",1);
}   
int do_talk(CChar * me, char * ask = NULL)
{

	static char hua1[5][100]=
	{
		"���겻ʶ����ζ�����ϲ�¥�����ϲ�¥������",
		"�������ѧϰ�ܶ�֪ʶ����ȻҲ����ѧ���ˡ�",
		"�õ��书û���鼮�����ǲ��������ɵġ�",
		"�кܶ�����Ҫһ��һ���ض�������",
		"�����ֶ���һ���飬�����ǳ��"
	};
	static char hua2[2][100]=
	{
		"�����˽�ʲô�飿",
		"�ҿ��Ը�����һЩ������á�"
	};
	static char hua3[82][100]=
	{

		"��ϼ��ܸ",
		"ʮ��ľż ",
		"������ ",
		"ʮ����ż",
		"��ɽ��÷�ַ�ͼ�Ͼ� ",
		"��ɽ��÷�ַ�ͼ�¾�",
		"����Ʒ��� ",
		"��Ů�ľ��ϲ� ",
		"��Ů�ľ��²�",
		"��Ů����",									//10

		"�׽",
		"�׾�ϵ��ƪ",
		"�׾�����ƪ",
		"�׾�˵��ƪ",
		"�׾�����ƪ",
		"����ɨҶ�ȷ� ",
		"ϴ�辭 ",
		"Τ�ӹ��� ",
		"��צ���� ",
		"�������ַ� ",									//20

		"��ɽ���� ",
		"��ɽ����2 ",
		"��ɽ����1 ",
		"һ��ָ��",
		"�Ʒ����� ",
		"�ȷ�ͨ�� ",
		"��Ƥ�� ",
		"��������",
		"������ʽ�ַ� ",
		"ȭ���ܾ� ",									//30		

		"��ʯ�� ",
		"�����潣���� ",
		"��Ƥ ",
		"��а���� ",
		"�м����� ",
		"�����ľ� ",
		"���ֿտ������ؼ�",
		"���¾Ž�����",
		"��ɽ�����Ʒ�ͼ�²� ",
		"��ɽ�����Ʒ�ͼ�ϲ� ",								//40

		"�������� ",
		"����",
		"ǧ����",
		"�ټ���",
		"���־� ",
		"���¾����ڰ��¡� ",
		"���¾����ڶ��¡� ",
		"���¾�����ʮ���¡� ",
		"���¾�����ʮ���¡� ",
		"���¾�����ʮ���¡� ",							//50

		"���¾�����һ�¡� ",
		"���������䡷�������İ� ",
		"�������澭���²� ",
		"�������澭���ϲ� ",
		"�������澭�����ľ� ",
		"�������澭�������� ",
		"�������澭���ڶ��� ",
		"�������澭����һ�� ",
		"����ͼ�� ",
		"��������ܸ���²� ",						//60

		"��������ܸ���в� ",
		"��������ܸ���ϲ� ",
		"���ĺ����� ",
		"���� ",
		"̫��ʮ���� ",
		"�����޶����²᡻",
		"�����޶����ϲ᡻ ",
		"�Ṧƪ ",
		"���¾����¾� ",
		"���¾����Ͼ� ",								//70

		"���¾�",
		"����Ƭ ",
		"ʯ�� ",
		"���� ",
		"�׽��ѧƪ ",
		"������ ",
		"���� ",
		"���ҵ��ײ�ƪ ",
		"�����项 ",
		"����ͼ�� "	,										//80

		"һ��ָ���� ",
		"���β��� " 													//82
	};
	static char hua4[82][100]=
	{
		"��ϼ�� 0-99",
		"�����ڹ� 60-99",
		"������  0-99  ",
		"�����ڹ� 30-59 ",
		"��ɽ��÷��  0-49 ",
		"��ɽ��÷��  100-149 ",
		"�����  0-80  ",
		"��Ů�ķ�  0-60 ",
		"��Ů�ķ�  0-100  ",
		"��Ů����  0-40  ",
		
		"�׽  0-200  ",
		"��������  75-100 ",
		"��������  50-75 ",
		"��������  25-50 ",
		"��������  0-25 ",
		"����ɨҶ��  30-99 1000 ",
		"�����޷�������ָ���������ַ��������ȷ�������צ���������Ʒ� 0-180",
		"������� �޳��ȷ� �ն��ȷ� ��ħ���� ��Ħ����  0-99 ",
		"ӥצ���� �黨ָ�� һָ���� �ȱ����� ���޵���  0-99 ",
		"����ǧҶ���ַ� ����ȭ�� �޺�ȭ�� �����Ʒ� ɢ���Ʒ�  0-99 ",

		"������  0-99  ",
		"��������  101-199 ",
		"��������  1-100 ",
		"һ��ָ  0-99 ",
		"�����Ʒ�  0-30 ",
		"�����ȷ�  30-99 ",
		"��������  100-149 ",
		"������  0-99 ",
		"������ʽ  0-60 ",
		"����ȭ��  50-99 ",

		"�������ҽ�  0-80 ",
		"�����潣  50-150 ",
		"Ǭ����Ų��  0-250 ��100����,max_mp>1500 ������Ҫ��ͬ�ȼ���",
		"��а����  0-100  ",
		"�����м�  0-19  ",
		"�����ķ�  0-99 ",
		"͵��֮��  0-20  ",
		"���¾Ž�  75-300 ��100���飩 ",
		"��ɽ������  100-149 ",
		"��ɽ������  10-49  ",

		"������  0-100 ",
		"����д��  110-120 ",
		"����д��  80-99  ",
		"����д��  50-79  ",
		"����д��  20-49 ",
		"��ѧ�ķ�  0-29 ",
		"��ѧ�ķ�  0-29 ",
		"��ѧ�ķ�  0-29 ",
		"��ѧ�ķ�  0-29 ",
		"��ѧ�ķ�  0-29 ",

		"��ѧ�ķ�  0-29 ",
		"��а����  0-200 ",
		"�����׹�צ  0-99 ",
		"�����ڹ�  100-199  ",
		"������  75-100 ",
		"������  50-75 ",
		"������  25-50 ",
		"������  0-25 500 ",
		"���㹦  0-60 ",
		"����������  0-200 ",

		"����׶  0-200 ",
		"���߽�  0-200 ",
		"����д��  ����ȭ��  100-350 ",
		"�����ַ�  0-29 ",
		"�����ڹ�  10-29 ",
		"��������  99-199 ",
		"��������  50-99 ",
		"�����Ṧ  0-100 ",
		"��ѧ�ķ�  0-99 ",
		"��ѧ�ķ�  0-49 ",

		"��ѧ�ķ�  0-99 ",
		"�����Ṧ  0-29 ",
		"����ָ��  ����צ��  �����Ʒ�  �����ȷ�  �����ַ�  0-29 ",
		"�����ڹ�  0-29 ",
		"����д��  10-19 ",
		"�����м�  0-29 ",
		"��ڤ��  0-100 ",
		"��������  30-99 ",
		"��������  100-149 ",
		"��������  40-69 ",

		"һ��ָ  0-150",
		"���β���  0-60 "
	};
	char xingbie[10];
	int myage=0;
	int mylevel=0;
	myage=me->query("age");
	mylevel=me->query("level");
	if(!strlen(ask))
	{
		char msg1[50];
		strcpy(xingbie,me->querystr("gender"));
		if(strcmp(xingbie,"Ů��")==0)
			strcpy(msg1,"С�㣬�������ˣ���Ҫ��æ��");
		else if(strcmp(xingbie,"����")==0)
			strcpy(msg1,"С�ֵ�,�������ˣ���Ҫ��æ��");
		else
			strcpy(msg1,"С����,�������ˣ���Ҫ��æ��");
		if(random(2))
			return 0;
		for(int i=0;i<5;i++)
		{
			if(!random(3))
				say(hua1[i],me);
		}
		say(hua2[random(2)],me);
		for(int ii=0;ii<82;ii++)
		{
			if(!random(10))
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
		case 34:return "34";
		case 35:return "35";
		case 36:return "36";
		case 37:return "37";
		case 38:return "38";
		case 39:return "39";
		case 40:return "40";
		case 41:return "41";
		case 42:return "42";
		case 43:return "43";
		case 44:return "44";
		case 45:return "45";
		case 46:return "46";
		case 47:return "47";
		case 48:return "48";
		case 49:return "49";
		case 50:return "50";
		case 51:return "51";
		case 52:return "52";
		case 53:return "53";
		case 54:return "54";
		case 55:return "55";
		case 56:return "56";
		case 57:return "57";
		case 58:return "58";
		case 59:return "59";
		case 60:return "60";
		case 61:return "61";
		case 62:return "62";
		case 63:return "63";
		case 64:return "64";
		case 65:return "65";
		case 66:return "66";
		case 67:return "67";
		case 68:return "68";
		case 69:return "69";
		case 70:return "70";
		case 71:return "71";
		case 72:return "72";
		case 73:return "73";
		case 74:return "74";
		case 75:return "75";
		case 76:return "76";
		case 77:return "77";
		case 78:return "78";
		case 79:return "79";
		case 80:return "80";
		case 81:return "81";
		case 82:return "82";
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
   else if(strcmp(y,"34")==0)
	   return 34;
   else if(strcmp(y,"35")==0)
	   return 35;
   else if(strcmp(y,"36")==0)
	   return 36;
   else if(strcmp(y,"37")==0)
	   return 37;
   else if(strcmp(y,"38")==0)
	   return 38;
   else if(strcmp(y,"39")==0)
	   return 39;
   else if(strcmp(y,"40")==0)
	   return 40;
   else if(strcmp(y,"41")==0)
	   return 41;
   else if(strcmp(y,"42")==0)
	   return 42;
   else if(strcmp(y,"43")==0)
	   return 43;
   else if(strcmp(y,"44")==0)
	   return 44;
   else if(strcmp(y,"45")==0)
	   return 45;
   else if(strcmp(y,"46")==0)
	   return 46;
   else if(strcmp(y,"47")==0)
	   return 47;
   else if(strcmp(y,"48")==0)
	   return 48;
   else if(strcmp(y,"49")==0)
	   return 49;
   else if(strcmp(y,"50")==0)
	   return 50;
   else if(strcmp(y,"51")==0)
	   return 51;
   else if(strcmp(y,"52")==0)
	   return 52;
   else if(strcmp(y,"53")==0)
	   return 53;
   else if(strcmp(y,"54")==0)
	   return 54;
   else if(strcmp(y,"55")==0)
	   return 55;
   else if(strcmp(y,"56")==0)
	   return 56;
   else if(strcmp(y,"57")==0)
	   return 57;
   else if(strcmp(y,"58")==0)
	   return 58;
   else if(strcmp(y,"59")==0)
	   return 59;
   else if(strcmp(y,"60")==0)
	   return 60;
   else if(strcmp(y,"61")==0)
	   return 61;
   else if(strcmp(y,"62")==0)
	   return 62;
   else if(strcmp(y,"63")==0)
	   return 63;
   else if(strcmp(y,"64")==0)
	   return 64;
   else if(strcmp(y,"65")==0)
	   return 65;
   else if(strcmp(y,"66")==0)
	   return 66;
   else if(strcmp(y,"67")==0)
	   return 67;
   else if(strcmp(y,"68")==0)
	   return 68;
   else if(strcmp(y,"69")==0)
	   return 69;
   else if(strcmp(y,"70")==0)
	   return 70;
   else if(strcmp(y,"71")==0)
	   return 71;
   else if(strcmp(y,"72")==0)
	   return 72;
   else if(strcmp(y,"73")==0)
	   return 73;
   else if(strcmp(y,"74")==0)
	   return 74;
   else if(strcmp(y,"75")==0)
	   return 75;
   else if(strcmp(y,"76")==0)
	   return 76;
   else if(strcmp(y,"77")==0)
	   return 77;
   else if(strcmp(y,"78")==0)
	   return 78;
   else if(strcmp(y,"79")==0)
	   return 79;
   else if(strcmp(y,"80")==0)
	   return 80;
   else if(strcmp(y,"81")==0)
	   return 81;
   else if(strcmp(y,"82")==0)
	   return 82;
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

