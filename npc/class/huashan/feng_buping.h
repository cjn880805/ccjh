//feng_buping.h
//Lanwood 2000-01-08

NPC_BEGIN(CNhuashan_feng_buping);

virtual void create()
{
	set_name("�ⲻ̹",  "feng butan");
	set("nickname", "���콣");
	set("gender", "����");
	set("class", "swordsman");
	set("title", "��ɽ���ڵ�ʮ��������");
	set("age", 45);
	set("long",
		"�ⲻ̹�ǻ�ɽ���ڵ�һ���֣���������һ�Żƽ�������Ƥ��");
	set("attitude", "peaceful");
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);
	set("icon",young_man1);
	
	set("mp", 2400);
	set("max_mp", 2400);
	set("mp_factor", 30);
	set("max_hp",6000);
	
	set("combat_exp", 1000000);
	set("repute", -200000);
	set("apprentice_available", 3);
	
	set("chat_chance_combat", 80);
	
	set_skill("unarmed", 180);
	set_skill("sword", 230);
	set_skill("force", 160);
	set_skill("parry", 160);
	set_skill("dodge", 160);
	set_skill("literate", 150);
	set_skill("huashan_sword", 180);
	set_skill("kuangfeng_jian", 230);
	set_skill("zixia_shengong", 160);
	set_skill("huashan_shenfa", 170);
	
	map_skill("sword", "kuangfeng_jian");
	map_skill("parry", "kuangfeng_jian");
	map_skill("force", "zixia_shengong");
	map_skill("dodge", "huashan_shenfa");
	
	create_family("��ɽ��", 13, "����");
	
	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
	
				
	remove_call_out(do_reset);
	call_out(do_reset, 900, 0);
};

virtual char * chat_msg_combat()
{
	switch(random(2))
	{
	case 0:
			perform_action("force powerup", 0);
			break;
	case 2:
			perform_action("sword feilong", 1);
			break;
	}
	return 0;
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[255];

    if( query("apprentice_available") ) 
	{
        if( me->query_int() < 20 )
		{
             say(snprintf(msg, 255, "�һ�ɽ���Խ���Ϊ�������ҿ�%s���ʺ���ѧ������", query_respect(me)), me);
		}
		else 
		{
			say("�ã��ã��ã��ܺá�");
			command(snprintf(msg, 80, "recruit %ld", me->object_id()) );
			me->set("title", "��ɽ���ڵ�ʮ�Ĵ�����");
			add("apprentice_availavble", -1);
			me->UpdateMe();
			return;
        } 
	}
	else
        say("�Ϸ�����Ѿ������������ӣ���������ͽ�ˡ�", me);
      
	SendMenu(me);
}

static void do_reset(CContainer * ob, LONG param1, LONG param2)
{
	ob->set("apprentice_available", 3);
}

NPC_END;
