//lj_hajuba.h	���ް�
//�ز� 2002��6��1

NPC_BEGIN(CNlj_hajuba);

void create()
{
	set_name("���ް�","haju ba");
	set("long", "��������һ�ɣ�����һΧ�������Ǹ�������һ��ľ��ˡ�");
	set("title", "����������");
	set("gender", "����");
	set("age", 43);
	set("attitude", "peaceful");
	set("icon",old_man1);
	set("per", 10);
	set("str", 40);
	set("int", 25);
	set("con", 40);
	set("dex", 30);
	set("no_kill",1);
	set_weight(50000000);

	set("max_hp", 15000);
	set("mp", 8000);
	set("max_mp", 8000);
	set("mp_factor", 160);

	set("combat_exp", 800000);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("hammer",100);
	set_skill("unarmed", 100);
	set_skill("yujiamu_quan", 100);
	set_skill("shenkong_xing",100);
	set_skill("xiaowuxiang", 100);
	set_skill("riyue_lun", 100);
  
	map_skill("force", "xiaowuxiang");
    map_skill("dodge", "shenkong_xing");
    map_skill("unarmed", "yujiamu_quan");
	map_skill("parry", "riyue_lun");
	map_skill("hammer", "riyue_lun");

	prepare_skill("unarmed", "yujiamu_quan");
	set("no_talk",1);
	set("no_huan",1);
};

int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query("lj/renwu3"))
	{
		if(!me->query("lj/renwu31"))
			AddMenuItem("���ּ���", "$0ask1 $1", me);
		if(me->query("lj/renwu3_tiaojian"))
			AddMenuItem("����", "$0ask11 $1", me);
		if(me->query("lj/renwu31"))
			AddMenuItem("����", "$0ask12 $1", me);
		SendMenu(me);	
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

int handle_action(char *comm, CChar *me, char * arg)
{
	if(me->query("lj/renwu3"))
	{
		if(strcmp(comm, "ask1") == 0)
			return do_ask1(me);	
		if(strcmp(comm, "ask11") == 0)
			return do_ask11(me);	
		if(strcmp(comm, "ask12") == 0)
			return do_ask12(me);
	}
	if(me->query("lj/renwu4"))
	{
		say("���ް�˵��������������˸����ּһ�ķ��Ͼ͸������������ϴ���ϵ������", me);
		say("���ް�˵����������ɴ��������ټ��ģ������ƺ���û�����ص��ʱ�䣬��Ҳ��������������", me);
		say("���ް�˵������������֪��������ڤ������������Ǻ����ϴ��ϵ�ܺã���ȥ�������ɣ�", me);
		SendMenu(me);
	}
	return CNpc::handle_action(comm, me, arg);
}

int do_ask1(CChar * me)
{
	say("���ް�˵�������ּ��᣿����ȷʵ֪���ò��٣�ֻҪ���ܰﰳһ���£����������޷���",  me);
	SendMenu(me);
	me->set("lj/renwu3_tiaojian",1);
	return 1;
}
int do_ask11(CChar * me)
{
	say("���ް�˵�������˳��ôִ�������ȴû���ֵı��У���ﰳ�Ҹ����õļһ��",  me);
	SendMenu(me);
	me->set("lj/renwu3_wuqi",1);
	return 1;
}

int do_ask12(CChar * me)
{
	tell_object(me, "���ް������˵��������ҵ����������֣������ǹ����п�����");

	CFightRoom * obj;
	CContainer * env = environment();
	obj = (CFightRoom *)load_item("fight_room");		
	
	obj->set("room_locked", FIGHT_NO_JOIN);
	obj->set_name( "���ްԵ�����ս��", "fight_room");		
	obj->move(env);
	me->move(obj);
	obj->Join_Team(me, CFightRoom::FIGHT_TEAM_B);
	this->move(obj);
	obj->Join_Team(this, CFightRoom::FIGHT_TEAM_A);
	obj->Begin_Fight(0);

	return 1;
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if(!who->query("lj/renwu3_wuqi"))	return 0;
	if(DIFFERSTR(ob->querystr("skill_type"), "hammer"))
	{
		tell_object(who, "���ް�ҡ��ҡͷ��˵����������˴󴸣������������ò��ߣ�");
		return 0;
	}
	if(DIFFERSTR(ob->querystr("name"), "�Ͻ�")&&DIFFERSTR(ob->querystr("name"), "����ͭ��")&&DIFFERSTR(ob->querystr("name"), "������") )
	{
		tell_object(who, "���ް�ҡ��ҡͷ��˵����̫���ˣ�");
		return 0;
	}
	tell_object(who, "$HIR\n���ް������˵������������֣������ǹ����п�����\n");
	
	who->set("lj/renwu31",1);
	who->set("lj/renwu31_wuqi",ob->querystr("base_name"));

	who->del("lj/renwu3_tiaojian");
	who->del("lj/renwu3_wuqi");

	carry_object(ob->querystr("base_name"))->wield();
	CFightRoom * obj;
	CContainer * env = environment();
	obj = (CFightRoom *)load_item("fight_room");		
	
	obj->set("room_locked", FIGHT_NO_JOIN);
	obj->set_name( "���ްԵ�����ս��", "fight_room");		
	obj->move(env);
	who->move(obj);
	obj->Join_Team(who, CFightRoom::FIGHT_TEAM_B);
	this->move(obj);
	obj->Join_Team(this, CFightRoom::FIGHT_TEAM_A);
	obj->Begin_Fight(0);

	return 1;
}

void die()
{
	CContainer * env = environment();
	DTItemList * list = env->Get_ItemList();  
	POSITION p = list->GetHeadPosition(); 
	CChar * me;
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		if(! obj->is_character()) continue; 
		me = (CChar *)obj; 
		if(!userp(me)) continue;
		if(me->query_temp("fight/is_fighting") && is_fighting(me)!=is_fighting(this)) 
		{
			if(me->query("lj/renwu31"))
			{
				me->set("lj/renwu4",1);
				me->del("lj/renwu3");
				me->del("lj/renwu31");
				me->del("lj/renwu31_wuqi");
				set("ok",1);
				set("hp",15000);
				set("eff_hp",15000);
				set("mp",8000);
				delete_temp("disabled");
				((CFightRoom *)env)->End_Fight();
				me->add("combat_exp",500);
				me->UpdateMe();
				tell_object(me, "���ް������˵�����ǺǺǣ�������");
				tell_object(me, "���ް�˵��������������˸����ּһ�ķ��Ͼ͸������������ϴ���ϵ������");
				tell_object(me, "���ް�˵����������ɴ��������ټ��ģ������ƺ���û�����ص��ʱ�䣬��Ҳ��������������");
				tell_object(me, "���ް�˵������������֪��������ڤ������������Ǻ����ϴ��ϵ�ܺã���ȥ�������ɣ�");
				tell_object(me, "\n$HIR������ˡ�����ް�Ѱ�������������񣬻����500��ľ��齱����\n");
				break;
			}
		}
		break;
	}
	if(!query("ok"))
		destruct(this);
	else
		del("ok");
}
NPC_END;




