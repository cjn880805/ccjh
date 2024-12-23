//lj_shuxia.h	���չ�����
//�ز� 2002��6��1

NPC_BEGIN(CNlj_shuxia1);

void create()
{
	if(random(2))
		set_name("����","dao zhu");
	else
		set_name("����","dong zhu");

	set("title", "���չ�����");
	if(random(2))
	{
		set("gender", "����");
	}
	else
	{
		set("gender", "Ů��");
	}
	set("age", 43);
	set("attitude", "peaceful");
	set("icon",random(53));
	set("per", 10);
	set("str", 40);
	set("int", 25);
	set("con", 40);
	set("dex", 30);
	set_weight(50000000);

	set("max_hp", 15000);
	set("mp", 8000);
	set("max_mp", 8000);
	set("mp_factor", 160);
	set("no_kill",1);
	set("chat_chance", 80);

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

	call_out(do_die, 300);
	set("no_kill",1);
	
};

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	destruct(me);
}

virtual void die()
{
	tell_room(environment(), "�����ǲ���Ź����ǵģ�");
	destruct(this);
}

NPC_END;