//helpnpc009.h
//����
//George 2001-07-07

NPC_BEGIN(CNhelpnpc009);

void create()
{
	set_name("����", "renren");

	set("title","�����п�");

	set("icon", young_man5);
	set("gender", "����" );
	set("age", 50);
	set("long","̧ͷ������գ�һ����㯵ı��顣");
	set("attitude", "friendly");   
	set("env/wimpy", 100);    
	set("no_talk",1);
}   
int do_talk(CChar * me, char * ask = NULL)
{
	if(random(2))
		return 0;

	static char hua1[4][100]=
	{
		"����ɽ���������ҵ����콣��",
		"��һ��ɽ������˵��������书�ؼ��ر�࣬���ǿ���ʯ���ϵġ�",
		"�����кܶ�Ǯׯ���ϰ嶨�ڻᷢǮ����Ǯ��������ˡ�",
		"�����ǽ�����һ���ޣ������ɱ��������ү�ά�����ܶ���ӣ������ڻ���û����׽ס����"
	};
	say(hua1[random(4)],me);
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

