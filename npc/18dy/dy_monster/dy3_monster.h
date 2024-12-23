//dy3_monster.h ������3�����
//wuqing 2005-1-05
#define MAX_NPC_NUM 15

MONSTER_BEGIN(CNdy3_monster);

void create()
{
	CNmonsternpc::create();
	set("monster_level",3);
	static struct{
		char name[20], id[20],gender[20];		//��������
		int	 icon,age;			//ͼ��
	}mon[MAX_NPC_NUM] = {
		{"������", "ding de shui","����",young_woman8,28,},
		{"����", "cao zhen","����", young_woman1,38,},
		{"�ܸ�", "cao gai","����", young_woman8,18,},
		{"������", "ba san liang","Ů��", young_man3,32,},
		{"�", "yang chun", "����", young_woman8,21,},
		{"����", "du xing", "����",young_woman1,37,},
		{"����", "hua long", "����",young_woman2,24,},
		{"�˴���","gu da liang", "Ů��",young_man4,18,},
		{"����", "guan sheng", "����",young_woman4,27,},
		{"������", "gong sun sheng", "����",young_woman5,28,},
		{"����", "huang xin", "����",young_woman2,34,},
		{"����", "jiang jing", "����",young_woman6,24,},
		{"�ⱥ", "jie bao", "����",young_woman4,16,},
		{"����", "hai sha", "����",young_woman1,16,},
		{"ԪС��", "yuan xiao er", "����",young_woman2,31,},
	};

	int lvl=random(MAX_NPC_NUM);
	set_name( mon[lvl].name, mon[lvl].id);
	set("icon", mon[lvl].icon);
	set("gender", mon[lvl].gender);

	set("per",random(21)+10);
	set("title", "�κ����ػ���");
	set("level", 83+random(5));

	set("max_hp", 18000+random(1000));
	set("max_mp", 5500+random(200));
	set("mp_factor", 90);

	set("combat_exp", 3709700+random(100000));
	set("max_exp",38000000);

	set("str", 45+random(5));
	set("con", 36+random(5));
	set("int", 37+random(5));
	set("dex", 44+random(5));

	set_skill("yanxing_dao", 287+random(10));
	set_skill("blade", 287+random(10));
	set_skill("jiuyin_zhua", 287+random(10));
	set_skill("claw", 287+random(10));
	set_skill("zhutian_bu", 287+random(10));
	set_skill("dodge", 287+random(10));
	set_skill("linji_zhuang", 287+random(10));
	set_skill("force", 287+random(10));

	map_skill("blade", "yanxing_dao");
	map_skill("claw", "jiuyin_zhua");
	map_skill("dodge", "zhutian_bu");
	map_skill("force", "linji_zhuang");

	prepare_skill("claw", "jiuyin_zhua");

	set("apply/armor", 166+random(10));
	set("apply/damage", 196+random(10));

	create_family("������", 4, "����");

	carry_object("caidao")->wield();
	set("chat_chance_combat", 5);

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