//dy16_monster.h ������16�����
//wuqing 2005-1-05
#define MAX_NPC_NUM 15
MONSTER_BEGIN(CNdy16_monster);

void create()
{
	CNmonsternpc::create();
	set("monster_level",16);
	static struct{
		char name[20], id[20],gender[20];		//��������
		int	 icon,age;			//ͼ��
	}mon[MAX_NPC_NUM] = {
		{"����", "ding ling","Ů��",young_man4,28,},
		{"�ܻ�", "cao hua","Ů��", young_man1,38,},
		{"����", "lan xin","Ů��", young_man3,18,},
		{"���", "li fei","Ů��", young_man3,32,},
		{"����", "chun chun", "Ů��", young_man1,21,},
		{"����", "du yue", "Ů��",young_man1,37,},
		{"����", "hua hua", "Ů��",young_man2,24,},
		{"����", "wang ya", "Ů��",young_man4,18,},
		{"÷��", "mei zi", "Ů��",young_man4,27,},
		{"����", "a ya", "Ů��",young_man5,28,},
		{"�ƾ�", "huang jun", "Ů��",young_man2,34,},
		{"����", "jiang yu", "Ů��",young_man6,24,},
		{"������", "lv si niang", "Ů��",young_man4,16,},
		{"��ɫ", "lan shai", "Ů��",young_man1,16,},
		{"ԲԲ", "yuan yuan", "Ů��",young_man2,31,},
	};

	int lvl=random(MAX_NPC_NUM);
	set_name( mon[lvl].name, mon[lvl].id);
	set("icon", mon[lvl].icon);
	set("gender", mon[lvl].gender);

	set("per",random(21)+10);
	set("title", "�����ػ���");
	set("level", 175+random(5));

	set("max_hp", 100000+random(1000));
	set("max_mp", 40000+random(200));
	set("mp_factor", 150);

	set("combat_exp", 133709700+random(100000));
	set("max_exp",200000000);

	set("str", 45+random(5));
	set("con", 36+random(5));
	set("int", 37+random(5));
	set("dex", 44+random(5));

	set_skill("yanxing_dao", 700+random(10));
	set_skill("blade", 700+random(10));
	set_skill("jiuyin_zhua", 700+random(10));
	set_skill("claw", 700+random(10));
	set_skill("zhutian_bu", 700+random(10));
	set_skill("dodge", 700+random(10));
	set_skill("linji_zhuang", 700+random(10));
	set_skill("force", 700+random(10));

	map_skill("blade", "yanxing_dao");
	map_skill("claw", "jiuyin_zhua");
	map_skill("dodge", "zhutian_bu");
	map_skill("force", "linji_zhuang");

	prepare_skill("claw", "jiuyin_zhua");

	set("apply/armor", 450+random(10));
	set("apply/damage", 480+random(10));

	create_family("������", 4, "����");

	carry_object("caidao")->wield();

}

char * chat_msg_combat()
{
	switch(random(3))
	{
	case 0:
		perform_action("blade huanying", 1);
		break;
	case 1:
		perform_action("force powerup", 0);
		break;
	case 2:
		perform_action("force reserver", 1);
		break;
	}
	return 0;
}

MONSTER_END;
#undef MAX_NPC_NUM