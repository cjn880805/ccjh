//dy20_monster.h ������20�����
//wuqing 2005-1-05

MONSTER_BEGIN(CNdy20_monster);

void create()
{
	CNmonsternpc::create();
	set("monster_level",20);
	static struct{
		char name[20], id[20],gender[20];		//��������
		int	 icon,age;			//ͼ��
	}mon[15] = {
		{"��һ��", "dong yi jian","����",young_man3,28,},
		{"��һ��", "xi yi jian","����", young_man1,38,},
		{"�н�", "can jin","����", young_man2,18,},
		{"����", "dua yu","Ů��", young_woman3,32,},
		{"����", "zhao lei", "����", young_man5,21,},
		{"�ﻢ", "tian hu", "����",young_man6,37,},
		{"��Զ", "guan yuan", "����",young_man2,24,},
		{"�·�","chen feng", "Ů��",young_woman4,18,},
		{"����", "guan yu", "����",young_man4,27,},
		{"����", "tian long", "����",young_man5,28,},
		{"��ս", "zuo zhan", "����",young_man2,34,},
		{"���θ�", "huang pu gao", "����",young_woman6,24,},
		{"����", "bei ai", "����",young_man4,16,},
		{"����", "chen feng", "����",young_man1,16,},
		{"����", "jing yun", "����",young_man2,31,},
	};

	int lvl=random(15);
	set_name( mon[lvl].name, mon[lvl].id);
	set("icon", mon[lvl].icon);
	set("gender", mon[lvl].gender);

	set("per",random(21)+10);
	set("title", "�����ػ���");
	set("level", 195+random(5));

	set("max_hp", 109000+random(1000));
	set("max_mp", 9000+random(200));
	set("mp_factor", 90);

	set("combat_exp", 246650600+random(100000));
	set("max_exp",400000000);

	set("str", 99+random(5));
	set("con", 99+random(5));
	set("int", 99+random(5));
	set("dex", 95+random(5));

	set_skill("sun_finger", 800+random(10));
	set_skill("finger", 800+random(10));
	set_skill("tiannan_step", 800+random(10));
	set_skill("dodge", 800+random(10));
	set_skill("kurong_changong", 800+random(10));
	set_skill("force", 800+random(10));

	map_skill("finger", "sun_finger");
	map_skill("dodge", "tiannan_step");
	map_skill("force", "kurong_changong");

	prepare_skill("finger", "sun_finger");

	set("apply/armor", 560+random(10));
	set("apply/damage", 600+random(10));

	create_family("����μ�", 4, "����");
	

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