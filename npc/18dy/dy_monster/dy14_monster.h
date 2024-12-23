//dy14_monster.h ������14�����
//wuqing 2005-1-05
#define MAX_NPC_NUM 15

MONSTER_BEGIN(CNdy14_monster);

void create()
{
	CNmonsternpc::create();
	set("monster_level",14);
	static struct{
		char name[20], id[20],gender[20];		//��������
		int	 icon,age;			//ͼ��
	}mon[MAX_NPC_NUM] = {
		{"��ѩ", "xu xue","����",young_woman7,23,},
		{"����", "zuo ling","����", young_woman4,21,},
		{"Ǯ��", "qian san","����", young_woman3,18,},
		{"�޳�", "luo cheng","����", young_woman2,22,},
		{"�ν�", "song jin", "����", young_woman1,15,},
		{"é��", "mao sai", "����",young_woman5,17,},
		{"����", "wen wen", "����",young_woman6,15,},
		{"�ܴ�", "zhou da", "����",young_woman2,18,},
		{"�Ϲ���", "shang guan nan", "����",young_woman4,17,},
		{"����", "du lin", "����",young_woman1,17,},
		{"�ƺ�", "huang hai", "����",young_woman3,24,},
		{"��ս", "leng zhan", "����",young_woman5,22,},
		{"���", "wu de", "����",young_woman2,16,},
		{"����", "zhang ming", "����",young_woman3,16,},
		{"��ʤ", "li sheng", "����",young_woman7,19,},
	};

	int lvl=random(MAX_NPC_NUM);
	set_name( mon[lvl].name, mon[lvl].id);
	set("icon", mon[lvl].icon);
	set("gender", mon[lvl].gender);

	set("per",random(21)+10);
	set("title", "�����ػ���");
	set("level", 165+random(5));

	set("max_hp", 75000+random(1000));
	set("max_mp", 27000+random(200));
	set("mp_factor", 150);

	set("combat_exp", 70234500+random(100000));
	set("max_exp",160000000);

	set("str", 80+random(5));
	set("con", 73+random(5));
	set("int", 71+random(5));
	set("dex", 79+random(5));
	
	set_skill("force", 640+random(10));                      
	set_skill("dodge", 640+random(10));
	set_skill("unarmed", 640+random(10));
	set_skill("strike", 640+random(10));
	set_skill("parry", 640+random(10));
	set_skill("staff", 640+random(10));
	set_skill("sword", 640+random(10));
	set_skill("literate", 640+random(10));
	
	set_skill("shenlong_xinfa", 640+random(10));
	set_skill("yixingbu", 640+random(10));
	set_skill("shenlong_bashi", 640+random(10));
	set_skill("huagu_mianzhang", 640+random(10));
	set_skill("shedao_qigong", 640+random(10));
	
	map_skill("force", "shenlong_xinfa");
	map_skill("dodge", "yixingbu");
	map_skill("unarmed", "shenlong_bashi");
	map_skill("strike", "huagu_mianzhang");
	map_skill("parry", "shedao_qigong");
	map_skill("sword", "shedao_qigong");

	prepare_skill("strike", "huagu_mianzhang");
	prepare_skill("unarmed", "shenlong_bashi");
	
	set("apply/armor", 400+random(10));
	set("apply/damage", 430+random(10));

	create_family("������", 2, "����");

	carry_object("changjian")->wield();
	set("chat_chance_combat", 5);

}

char * chat_msg_combat()
{
	switch(random(3))
	{
	case 0:
		perform_action("sword chang3", 1);
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