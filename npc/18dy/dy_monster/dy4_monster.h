//dy4_monster.h ������4�����
//wuqing 2005-1-05
#define MAX_NPC_NUM 15

MONSTER_BEGIN(CNdy4_monster);

void create()
{
	CNmonsternpc::create();
	set("monster_level",4);
	static struct{
		char name[20], id[20],gender[20];		//��������
		int	 icon,age;			//ͼ��
	}mon[MAX_NPC_NUM] = {
		{"����", "dong cheng","����",young_woman8,28,},
		{"��ֱ", "cao zhi","����", young_woman1,38,},
		{"��ڤ", "dong ming","����", young_woman8,18,},
		{"����", "sun niang","Ů��", young_man3,32,},
		{"����", "dong zhu", "����", young_woman8,21,},
		{"���ﻢ", "gong sun hu", "����",young_woman1,37,},
		{"����Զ", "gong sun yuan", "����",young_woman2,24,},
		{"�����","gong sun feng", "Ů��",young_man4,18,},
		{"����", "guan yu", "����",young_woman4,27,},
		{"������", "gong sun long", "����",young_woman5,28,},
		{"����ս", "gong sun zhan", "����",young_woman2,34,},
		{"������", "huang pu she", "����",young_woman6,24,},
		{"����", "liu ai", "����",young_woman4,16,},
		{"����", "liu feng", "����",young_woman1,16,},
		{"����", "liu yun", "����",young_woman2,31,},
	};

	int lvl=random(MAX_NPC_NUM);
	set_name( mon[lvl].name, mon[lvl].id);
	set("icon", mon[lvl].icon);
	set("gender", mon[lvl].gender);

	set("per",random(21)+10);
	set("title", "���Ź��ػ���");
	set("level", 95+random(5));

	set("max_hp", 19400+random(1000));
	set("max_mp", 6000+random(200));
	set("mp_factor", 90);

	set("combat_exp", 4665600+random(100000));
	set("max_exp",50000000);

	set("str", 47+random(5));
	set("con", 38+random(5));
	set("int", 39+random(5));
	set("dex", 45+random(5));

	set_skill("sun_finger", 316+random(10));
	set_skill("finger", 316+random(10));
	set_skill("tiannan_step", 316+random(10));
	set_skill("dodge", 316+random(10));
	set_skill("kurong_changong", 316+random(10));
	set_skill("force", 316+random(10));

	map_skill("finger", "sun_finger");
	map_skill("dodge", "tiannan_step");
	map_skill("force", "kurong_changong");

	prepare_skill("finger", "sun_finger");

	set("apply/armor", 190+random(10));
	set("apply/damage", 220+random(10));

	create_family("����μ�", 4, "����");
	set("chat_chance_combat", 5);

}

char * chat_msg_combat()
{
	switch(random(3))
	{
	case 0:
		perform_action("finger qiankun", 1);
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