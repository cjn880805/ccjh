//juqinggusandao.h ����ɽ��
//�ز� 2002.3.8

ROOM_BEGIN(CRjuqinggusandao);

virtual void create()			
{
	set_name("�����ɽ��");
	set("monster_chance", 20);
	add_npc("pub_jueqingdizi");
	remove_all_doors();
	char msg[255];
	add_door("�����","�����","�����ɽ��");
	for(int i=1;i<9;i++)
	{
		add_door(snprintf(msg, 255,"�����ɽ��%d",i), snprintf(msg, 255,"�����ɽ��%d",i), "�����ɽ��");
	}
	
};

int valid_leave(CChar * me, const char * dir)
{
	if(me->query_temp("gumu/jq_y"))
		me->delete_temp("gumu/jq_y");
	return CRoom::valid_leave(me, dir);
}
/*
virtual void OnEnter(CContainer * me)
{

	remove_all_doors();
	char msg[255];
	for(int i=0;i<random(4)+1;i++)
	{
		int j=random(8)+1;
		add_door(snprintf(msg, 255,"�����ɽ��%d",j), snprintf(msg, 255,"�����ɽ��%d",j), "�����ɽ��");
	}
	me->set_temp("gumu/jq_count",random(10)+6);
	CChar * robber;
	CContainer * env = (CChar *)me->environment();
	CFightRoom * obj;
	obj = (CFightRoom *)env->present("fight_room_jueqing");
	if(! obj)
	{
		obj = (CFightRoom *)load_item("fight_room");		
		obj->set("room_locked", FIGHT_NO_JOIN);
		obj->set_name( "�����ս��", "fight_room_jueqing");		
		obj->move(env);
		(CChar *)me->move(obj);
		obj->Join_Team((CChar *)me, CFightRoom::FIGHT_TEAM_B);
	}
	static char tufei[18][20]={"pub_gaoming","pub_duguo","pub_guoda","pub_liuquan","pub_maxiaotian","pub_wanghu","pub_wuan","pub_zhuzhao","pub_sangyuan","pub_wangmu","pub_henmantian","pub_guochou","pub_zhaoba","pub_feiying","pub_huanhai","pub_xuecai","pub_youzhu","pub_zangma"};
	int j=random(2);
	for(int i=0;i<j+1;i++)
	{
		robber = load_npc(tufei[random(18)]);
		robber->set_name("����ȵ���", "jue qing dizi");
		robber->set("title", "��ɽʹ��");
		robber->move(obj);
		obj->Join_Team(robber, CFightRoom::FIGHT_TEAM_A);				
	}
	obj->Begin_Fight(0);
}
*/
ROOM_END;




