//helpnpc015.h
//������
//George 2001-07-07

NPC_BEGIN(CNhelpnpc015);

void create()
{
	set_name("������", "longjiaojiao");
	set("title","��֮��Ů");

	set("icon", girl1);
	set("gender", "Ů��" );
	set("age", 18);
	set("long","������");
	set("attitude", "friendly");  
	set("env/wimpy", 100);  
	set("no_talk",1);
}   
int do_talk(CChar * me, char * ask = NULL)
{

	static char hua1[5][100]=
	{
		"˭˵Ů�ӾͲ������ʵ��ˣ�",
		"�����кܶ�Ů���������书��������֮�ϡ�",
		"Ů���кܶ��书ǿ�����ӵģ�ֻ�Ǻܶ��˲�֪����",
		"��Ҫ�������ס�",
		"�ҷ���һ�����ܣ������������кܶ��书�Ĵ�ʼ����Ů�ӡ�"
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

