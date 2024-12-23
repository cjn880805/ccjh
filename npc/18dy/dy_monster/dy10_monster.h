//dy10_monster.h ������10�����
//wuqing 2005-1-05
#define MAX_NPC_NUM 15

MONSTER_BEGIN(CNdy10_monster);

void create()
{
	CNmonsternpc::create();
	set("monster_level",10);
	static struct{
		char name[20], id[20],gender[20];		//��������
		int	 icon,age;			//ͼ��
	}mon[MAX_NPC_NUM] = {
		{"����", "yun qing","Ů��",young_woman1,18,},
		{"ҹɫ", "ye shai","Ů��",young_woman2,21,},
		{"Ҷ��", "ye ling","Ů��",young_woman3,23,},
		{"���", "xiang er","Ů��",young_woman6,18,},
		{"�±�", "wen bi","Ů��",young_woman7,18,},
		{"��˪", "qing shuang","Ů��",young_woman8,18,},
		{"����", "li mei", "Ů��",young_woman9,18,},
		{"����", "lan xiang", "Ů��",young_woman11,18,},
		{"����", "hua yu","Ů��",young_woman12,18,},
		{"����", "hong yan", "Ů��",young_woman1,18,},
		{"����", "bai lian","Ů��",young_woman2,18,},
		{"�׺���", "bai hudie","Ů��",young_woman3,18,},
		{"��Ƿ�", "yan fei fei","Ů��",young_woman4,18,},
		{"����Ҷ", "xu yue ye","Ů��",young_woman5,18,},
		{"�����", "leng bing er", "Ů��",young_woman10,18,},
	};

	int lvl=random(MAX_NPC_NUM);
	set_name( mon[lvl].name, mon[lvl].id);
	set("icon", mon[lvl].icon);
	set("gender", mon[lvl].gender);

	set("per",random(21)+10);
	set("title", "�����ػ���");
	set("level", 145+random(5));

	set("max_hp", 60000+random(1000));
	set("max_mp", 12000+random(200));
	set("mp_factor", 140);

	set("combat_exp", 21234500+random(100000));
	set("max_exp",120000000);

	set("str", 67+random(5));
	set("con", 60+random(5));
	set("int", 61+random(5));
	set("dex", 71+random(5));
	
	set_skill("force", 520+random(10));
	set_skill("unarmed", 520+random(10));
	set_skill("dodge", 520+random(10));
	set_skill("parry", 520+random(10));
	set_skill("hand",520+random(10));
	set_skill("strike", 520+random(10));
	set_skill("sword",520+random(10));
	
	set_skill("zhemei_shou",520+random(10));
	set_skill("liuyang_zhang",520+random(10));
	set_skill("tianyu_qijian",520+random(10));
	set_skill("yueying_wubu",520+random(10));
	set_skill("bahuang_gong", 520+random(10));
	
	map_skill("force", "bahuang_gong");
	map_skill("strike","liuyang_zhang");
	map_skill("dodge", "yueying_wubu");
	map_skill("unarmed", "liuyang_zhang");
	map_skill("strike","liuyang_zhang");
	map_skill("hand", "zhemei_shou");
	map_skill("parry", "liuyang_zhang");
	map_skill("sword","tianyu_qijian");
	
	prepare_skill("strike","liuyang_zhang");
	prepare_skill("hand", "zhemei_shou");
	
	set("apply/armor", 300+random(10));
	set("apply/damage", 330+random(10));

	create_family("����", 2, "����");

	carry_object("changjian")->wield();
	set("chat_chance_combat", 5);

}

char * chat_msg_combat()
{
	switch(random(3))
	{
	case 0:
		perform_action("sword san", 1);
		break;
	case 1:
		perform_action("force powerup", 0);
		break;
	case 2:
		perform_action("force recover", 0);
		break;
	}
	return 0;
}

MONSTER_END;

#undef MAX_NPC_NUM