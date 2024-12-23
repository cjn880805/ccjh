//yan.h
//�Դ��������ܣΣУá���ɽ�����վ����Ѷ�5��
//Teapot 2001-02-07

MONSTERHUASHAN_BEGIN(CNhuashan_yan);

virtual void create()
{
	set_name("�Դ���", "yan daning");
	set("title", "ѩ��ƽ��");
	set("gender", "����");
	set("age", 47);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("icon", old_man1);
	set("level",80);

	set("str", 35);
	set("int", 35);
	set("con", 35);
	set("dex", 35);
	
	set("hp", 7500);
	set("max_hp", 15000);
	
	set("mp", 1500);
	set("max_mp", 1500);
	set("mp_factor", 200);

	set("combat_exp", 9000000);
	set("score", 200000);

	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("literate", 300);
	set_skill("unarmed", 300);

	set_skill("shenzhao_gong", 200);
	set_skill("piaoyibu", 200);
	set_skill("doomsword", 200);
	set_skill("changquan", 200);

	map_skill("force", "shenzhao_gong");
	map_skill("dodge", "piaoyibu");
	map_skill("sword", "doomsword");
	map_skill("parry", "doomsword");
	map_skill("unarmed", "changquan");
	
	set("chat_chance_combat", 30);

	set("no_���־�",1);
	set_temp("apply/no_�ƺ�����",1);
	set("bigboss",1);

	carry_object("sword_3")->wield();

};

virtual void die()
{
	CChar * me;
	me=(CChar *)find_object(query_temp("last_damage_from"), 1);

	if(! me) 
	{
		CNpc::die();
		return;
	}

	if (!me->query_temp("teapot/lcj2") || me->query_temp("teapot/lcj2") == 0)
	{
		revive(1);
		message_vision("$N��������������˿�����", this);
		set("max_hp",30000);
		set("eff_hp",30000);
		set("hp",30000);
		set_temp("apply/damage", query_temp("apply/damage")+60);			//����NPC���ӹ�����
		set_temp("apply/armor", query_temp("apply/armor")+60);			//����NPC���ӷ�����
		set_temp("apply/attack", query_temp("apply/attack")+60);
		set_temp("apply/defense", query_temp("apply/defense")+60);
		return;
	}

	me->set_temp("teapot/lcj3",1);

	message_vision("$Nһ�����ܵ��ˡ�", this);
	destruct(this);
	return;
}

MONSTERHUASHAN_END;

// Group: * Mei,Qi,Yan,Wang,* PoemBook,* PlumSword,DoomSword,ShenZhaoGong.