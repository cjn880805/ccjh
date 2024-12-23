//was_shuangmu.h

NPC_BEGIN(CNwas_shuangmu);

virtual void create()
{
	set_name("˫ľ",  "shuang mu");
	set("gender", "����");
	set("age", 68);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 35);
	set("dex", 35);
	set("icon",old_man2);
	
	set("hp", 30500);
	set("max_hp", 30500);
	
	set("mp", 18500);
	set("max_mp", 18500);
	set("mp_factor", 200);

	set("combat_exp", 70000000);
	set("score", 500000);

	set_skill("cuff", 250);
	set_skill("force", 250);
	set_skill("dodge", 250);
	set_skill("parry", 250);
	set_skill("sword", 400);
	set_skill("strike",250);
	set_skill("unarmed", 250);
	set_skill("zixia_shengong", 250);
	set_skill("poyu_quan", 250);
	set_skill("huashan_sword", 300);
	set_skill("hunyuan_zhang", 250);
	set_skill("lonely_sword", 300);
	set_skill("huashan_shenfa",250);
	set_skill("literate", 220);
	set_skill("zhengqijue", 250);

	map_skill("cuff", "poyu_quan");
	map_skill("force", "zixia_shengong");
	map_skill("dodge", "huashan_shenfa");
	map_skill("parry", "lonely_sword");
	map_skill("sword", "lonely_sword");
	map_skill("strike", "hunyuan_zhang");
	
	create_family("��ɽ��", 13, "����");
	set("chat_chance_combat", 60);
	set("family/master_id", "feng qingyang");

	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
	
};

virtual char * chat_msg_combat()
{
	switch(random(5))
	{
	case 0:
		perform_action("force powerup", 0);
		break;
	case 1:
		perform_action("force recover", 0);
		break;
	case 2:
		perform_action("sword poqi", 1);
		break;
	case 3:
		perform_action("sword pozhang", 1);
		break;
	case 4:
		perform_action("sword pojian", 1);
		break;
	}

	return 0;
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query_temp("was/renwu1_2"))
	{
		if(! strlen(ask))
		{
			AddMenuItem("ѯ��Ӫ����������","liupai",me);
			SendMenu(me);
		}
		else if(!strcmp(ask, "liupai") )
		{
			say("˫ľ����������ǰ����������Χ�����������º󷽷���ԭ��һ�ж��ǻ�Ԫ�����ֳ�������ı������һ����ǰ�����ɸ��ֶ��ڹ�;������ʧ�٣�����Ǳ�������һ�������εĴ�����ʦ�ܣ�������ȥ��Ѱ��������ͼ�ȳ������ĸ��ɸ��֡�",me);
			if(!me->query_temp("was/renwu2_1"))
			{
				me->set_temp("was/renwu2_1",1);//���������ȱ�����
				CContainer * bot = load_item("was_leitinglin");
				bot->set("owner",me->id(1));
				bot->move(me);
				tell_object(me,"\n$HIC˫ľ��������1�������ȱ����ơ�\n");
			}
		}
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

NPC_END;