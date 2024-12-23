//dy15_monster.h ������15�����
//wuqing 2005-1-05
#define MAX_NPC_NUM 15

MONSTER_BEGIN(CNdy15_monster);

void create()
{
	CNmonsternpc::create();
	set("monster_level",15);
	static struct{
		char name[20], id[20],gender[20];		//��������
		int	 icon,age;			//ͼ��
	}mon[MAX_NPC_NUM] = {
		{"Ʈѩ", "piao xue","����",young_woman7,23,},
		{"��Ȩ", "zuo quan","����", young_woman4,21,},
		{"Ǯ����", "qian ma zi","����", young_woman3,18,},
		{"�޶�", "luo dong","����", young_woman2,22,},
		{"���", "li jin", "����", young_woman1,15,},
		{"é��", "mao du", "����",young_woman5,17,},
		{"����", "wen ling", "����",young_woman6,15,},
		{"��ͬ", "zhou tong", "����",young_woman2,18,},
		{"������", "ling nan tian", "����",young_woman4,17,},
		{"����", "du zhong", "����",young_woman1,17,},
		{"�ƺ�", "huang he", "����",young_woman3,24,},
		{"����", "leng yue", "����",young_woman5,22,},
		{"����", "wu ming", "����",young_woman2,16,},
		{"�ž�", "zhang jun", "����",young_woman3,16,},
		{"���", "li guang", "����",young_woman7,19,},
	};

	int lvl=random(MAX_NPC_NUM);
	set_name( mon[lvl].name, mon[lvl].id);
	set("icon", mon[lvl].icon);
	set("gender", mon[lvl].gender);

	set("per",random(21)+10);
	set("title", "�����ػ���");
	set("level", 170+random(5));

	set("max_hp", 95000+random(1000));
	set("max_mp", 37000+random(200));
	set("mp_factor", 150);

	set("combat_exp", 100234500+random(100000));
	set("max_exp",170000000);

	set("str", 90+random(5));
	set("con", 83+random(5));
	set("int", 81+random(5));
	set("dex", 84+random(5));
	
	set_skill("force", 670+random(10));                      
	set_skill("dodge", 670+random(10));
	set_skill("unarmed", 670+random(10));
	set_skill("strike", 670+random(10));
	set_skill("parry", 670+random(10));
	set_skill("staff", 670+random(10));
	set_skill("sword", 670+random(10));
	set_skill("literate", 670+random(10));
	
	set_skill("shenlong_xinfa", 670+random(10));
	set_skill("yixingbu", 670+random(10));
	set_skill("shenlong_bashi", 670+random(10));
	set_skill("huagu_mianzhang", 670+random(10));
	set_skill("shedao_qigong", 670+random(10));
	
	map_skill("force", "shenlong_xinfa");
	map_skill("dodge", "yixingbu");
	map_skill("unarmed", "shenlong_bashi");
	map_skill("strike", "huagu_mianzhang");
	map_skill("parry", "shedao_qigong");
	map_skill("sword", "shedao_qigong");

	prepare_skill("strike", "huagu_mianzhang");
	prepare_skill("unarmed", "shenlong_bashi");
	
	set("apply/armor", 430+random(10));
	set("apply/damage", 450+random(10));

	create_family("������", 2, "����");

	carry_object("changjian")->wield();

}

char * chat_msg_combat()
{
	switch(random(3))
	{
	case 0:
		perform_action("parry chang3", 1);
		break;
	case 1:
		perform_action("unarmed yingxiong", 1);
		break;
	case 2:
		perform_action("strick hua", 1);
		break;
	}
	return 0;
}

MONSTER_END;
#undef MAX_NPC_NUM