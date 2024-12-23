//helpnpc011.h
//С����
//George 2001-07-07

NPC_BEGIN(CNhelpnpc011);

void create()
{
	set_name("С����", "xiaosunzi");

	set("title","ıʿ");

	set("icon", young_man5);
	set("gender", "����" );
	set("age", 60);
	set("long","һ����һ�ߺ���ʲô������");
	set("attitude", "friendly");   
	set("env/wimpy", 100); 
	set("no_talk",1);
}   
int do_talk(CChar * me, char * ask = NULL)
{

	static char hua1[3][100]=
	{
		"��ս��׬Ǯ������Ҫ�������ѡ��",
		"���ܺͼ���Ҳ������Ҫ��Ҫ���ź����Ż�������",
		"һ��Ҫ����ѵİ��ţ��ڽ����вŻ����ͷ�ء�"
	};
	static char hua2[2][100]=
	{
		"�ǲ��ǲ����ף�",
		"��������׿������ҡ�"
	};
	static char hua3[24][100]=
	{

		"���׬Ǯ��",
		"�����칤�ʵĵط���",
		"��֪�������б�����",
		"���书�ٳ�������",
		"��ʲô���������׷��",
		"�ǲ��Ǳ���ս������",
		"�ǲ���ÿ��ս����Ҫ����ʤ������",
		"ս������ν��еģ�",
		"MP��ʲô��",
		"ʲô��AP��",

		"ս��������εþ���ģ�",
		"�һ��ǲ�̫���ʲô��NK���顣",
		"������˵PK˭��PK��ʲô��",
		"��ô�Ҿ�������������ֵ����",
		"������˭��̣�",
		"�ǲ���һ��Ҫ��ʦ��ѧϰ�أ�",
		"�߼��ڹ���ô��ϰ��",
		"ΪʲôҪѧϰ�߼��ڹ���",
		"���ֹ�����ʲô�ô���",
		"�ڹ��ǲ���ֻ���������ˣ�",

		"�����ǲ���ѧ��Խ��Խ�ã�",
		"������100(+120)��ʲô��˼��",
		"��ս������������ô�죿",
		"���˶���ô�죿"
	};
	static char hua4[24][250]=
	{

		"����������һЩ�������µ��˲��ں�һЩ����װ��ʲô�ģ�����ɱ��NPCֻҪǮ����Ҫװ�����������õĻ������ܼ���Щ���ã�Ȼ������������Ҳδ������������֮����",
		"��ֻ֪���д�������Ϊ�佫����Զ����칤�ʣ��Ի�����",
		"֪������һ��ңԶ�ĵط�������������",
		"���٣��ڽ����������ر���Ҫ��������˵�е��书ֻҪ�л�Ե�����ǿ���Ѹ�ٳ����ġ�",
		"�ܶ࣬���Կ���꣬�����꣬ҩ�꣬�ȿ��Գ���Ҳ���Է��ۣ��������Լ����������кܶ࣬�������ͻ�֪���ˡ�",
		"������ǽ�ɫ�ɳ�������Ҫ��һ��ָ�롣���˾���㣬���ܹ�ʹ��Ľ�ɫ����������ѧϰ��������ա���þ��飬ս��������Ҫ��һ��;������Ȼ������ѧϰ����ļ��ܣ�Ҳ��Ϊ����ս����սʤ��ǿ��ĵ��ˡ�",
		"ս�������֣�һ�������д裬һ�����ھ������д����յ㵽Ϊֹ��һ�㲻��ɥ���������Ƿ�Ҫ�ֳ��������һ�ģ��������ѣ��´μ����Իᡰ�����������ۺ족�ģ���ˣ���NPCս�������������д����������������а���ɱ���Է�������ֱ�Ӷ�����KILLָ�ɱ�����֡�",
		"ս�����Զ����еġ���ս���Ĺ����У������ʹ�÷���������ˡ�������Ҫ�ķ�MP��AP�ġ�ͬʱ����ս���У���������ʹ����Ʒ����װ�����������������ܣ�����Ҫ�����㹻��APֵ������ɡ�",
		"MPָ����������ͨ��������ߡ�ǰ���������߱���ĳ���ڹ���ʹ�÷���Ҫ����һ����MP����ҥҲҪMP����Щħ����Ʒ��ʹ��Ҳ��Ҫ���㹻��MP���С���ˣ�����MP�����ǳɳ���һ������Ҫ�Ĺ��̡�",
		"AP�����ж���������ֻ��ս������Ч��ÿ�غϳ���ʱ�Զ��ۼӣ��ۼ��������500��ͨ������Խ�ߵ��ˣ���ս���г��ֵ��ٶ�Խ�죬ÿ�غ�AP������Խ�ࡣ",

		"��ս���Ĺ����У�����ķ������ڶ��ֵĹ�����ͬʱ���ֳɹ����мܻ�����˹�ȥ�������л������������顣��Ȼ�������Ĺ������ڶ��ֵķ�����ͬʱ���ֳɹ��������˶��֣���ô���ɻ���Ը�Щ�ľ��顣",
		"�����ɱ����NPC����ֵ����ߣ��Ҳ�����ͬ���ɣ���ô�㽫���һ���ľ��齱������νNK���顣",
		"PK�������ɱ����һ�õľ����ˡ�",
		"�磺1001/2000 (465)���ʾ�������֧�侭����1001�����п�������ѧ���ܵľ�����465�㡣��ɫ������Ҫ2000�㡣",
		"�����Լ�ʦ��ֱ����̣�Ҳ��ת��ͬ��������ʦ�������������ʦ��",
		"���ĳ������������ʦ�����ᣬ��ô����ȥ�ɶ���ţ��ݸ����ʷ�����һ��ѧ�ѣ������ʦ������ѧϰ��",
		"�߼��ڹ�һ���ǲ�����ϰ�ģ�ֻ����ʦ����̡�",
		"׼���˸߼��ڹ��󣬾Ϳɴ����ˡ�����������MP��;����",
		"һ����ֹ��򶼿�׼��������ȭ���ϣ���ս��ʱ����ʹ�á���Щ���ֹ��������Ŀ��ֹ�����ϣ��ɷ��Ӹ����������",
		"������ս��ʱ�������˵С������������ˣ���Ҫ�ڻ������������ü���ϵ������ν����ϵ������������ü��������˵С�",

		"һ���˲������ƵĿ���ѧϰ���20�ּ��ܡ�����20�ּ��ܺ�ÿ��һ�֣�ѧϰ���Ѷ�����10%��",
		"��һ���������Լ������Ĺ��������ڶ����������������ӵĹ�������",
		"���˿������ҩ���ԣ�Ҳ��������������Ұ����㡣�������֣����̣���Ĺ����ɽ����ü���ڹ�����Ϊ�����˵ķ�����",
		"��Щ����˯һ���û���ˣ�Ϊ�˰�ȫ��������ǳ�һЩҩƷ�ȽϺã�ÿ�ֶ��Ľⷨ����һ������������������������Ǿ��鷳�ˡ�"
	};
	if(!strlen(ask))
	{
		if(random(2))
			return 0;
		for(int i=0;i<3;i++)
		{
		//	if(!random(3))
				say(hua1[i],me);
		}
		say(hua2[random(2)],me);
		for(int ii=0;ii<24;ii++)
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
