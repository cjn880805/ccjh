//helpnpc018.h
//δ��֪
//George 2001-07-07

NPC_BEGIN(CNhelpnpc018);

void create()
{
	set_name("δ��֪", "weibuzhi");
	
	set("title","��������");

	set("icon", young_man5);
	set("gender", "����" );
	set("age", 80);
	set("long","�۾��з��ţ�����͵͵�ؿ���ʲô������");
	set("attitude", "friendly");  
	set("env/wimpy", 100);    
	set("no_talk",1);
} 

int do_talk(CChar * me, char * ask = NULL)
{

	static char hua1[5][100]=
	{
		"�����Ҷ�����Ĺ۲죬����������������һ���ش�������֡�",
		"�ƺ�һ��������֮�ڱ���ˮ�֡�",
		"���ɵķ������Ͼ�Ҫ��ʼ�ˡ�",
		"�ҿ����ڱ�������һƬ�������˸������",
		"�кܶ�����Ҫ��������ʱ���Ҿ�֪���ˡ�"
	};
	say(hua1[random(5)],me);
	SendMenu(me);
	return 1;
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

