//dy12_monster.h ������12�����
//wuqing 2005-1-05

#define MAX_NPC_NUM 14

MONSTER_BEGIN(CNdy12_monster);

void create()
{
	CNmonsternpc::create();
	set("monster_level",12);
	static struct{
		char name[20], id[20],gender[20];		//��������
		int	 icon,age;			//ͼ��
	}mon[MAX_NPC_NUM] = {
		{"ٻ��", "qing wen","Ů��",young_woman2,26,},
		{"����", "qina qian","Ů��", young_woman2,28,},
		{"����", "yun shang","Ů��", young_woman3,38,},
		{"��Ū��", "hua nong yue","Ů��", young_woman2,22,},
		{"�����", "liu sui feng", "����", young_man1,25,},
		{"�����", "wen tian ci", "����",young_man2,37,},
		{"����", "bai yang", "����",young_man3,44,},
		{"�ܻ�", "zhou hui", "����",young_man1,18,},
		{"��Ԫ��", "liu yuan ming", "����",old_man1,67,},
		{"�׷ɷ�", "bai fei fei", "Ů��",young_woman1,17,},
		{"����", "shen lang", "����",young_man3,44,},
		{"������", "wang lian hua", "����",young_man2,24,},
		{"������", "jin wu wang", "����",young_man3,36,},
		{"���", "zhu ba", "����",young_man1,19,},
	};

	int lvl=random(MAX_NPC_NUM);
	set_name( mon[lvl].name, mon[lvl].id);
	set("icon", mon[lvl].icon);
	set("gender", mon[lvl].gender);

	set("per",random(21)+10);
	set("title", "�����ػ���");
	set("level", 155+random(5));

	set("max_hp", 64000+random(1000));
	set("max_mp", 16000+random(200));
	set("mp_factor", 150);

	set("combat_exp", 27234500+random(100000));
	set("max_exp",140000000);
	
	set("str", 73+random(5));
	set("con", 66+random(5));
	set("int", 68+random(5));
	set("dex", 75+random(5));
	
	set_skill("force", 580+random(10));             
	set_skill("claw", 580+random(10));              
	set_skill("hand", 580+random(10));              
	set_skill("finger", 580+random(10));            
	set_skill("unarmed", 580+random(10));           
	set_skill("strike", 580+random(10));            
	set_skill("leg", 580+random(10));	           
	set_skill("dodge", 580+random(10));             
	set_skill("parry", 580+random(10));             
	set_skill("sword", 580+random(10));             
	
	set_skill("anying_fuxiang", 580+random(10));    
	set_skill("tanzhi_shentong", 580+random(10));   
	set_skill("xuanfeng_leg", 580+random(10));      
	set_skill("luoying_shenzhang", 580+random(10));     
	set_skill("bibo_shengong", 580+random(10));     
	set_skill("luoying_shenjian", 580+random(10));  
	set_skill("yuxiao_jianfa", 580+random(10));       
	set_skill("lanhua_shou", 580+random(10));       
	set_skill("literate", 580+random(10));          
	
	map_skill("force"  , "bibo_shengong");
	map_skill("finger" , "tanzhi_shentong");
	map_skill("hand"   , "lanhua_shou");
	map_skill("unarmed", "luoying_shenzhang");
	map_skill("strike", "luoying_shenzhang");
	map_skill("leg", "xuanfeng_leg");
	map_skill("dodge"  , "anying_fuxiang");
	map_skill("parry"  , "tanzhi_shentong");
	map_skill("sword"  , "yuxiao_jianfa");
	
	prepare_skill("finger", "tanzhi_shentong");
	prepare_skill("hand", "lanhua_shou");
	
	set("apply/armor", 340+random(10));
	set("apply/damage", 370+random(10));
	
	create_family("�һ�", 2, "����");
	
	carry_object("changjian")->wield();
	set("chat_chance_combat", 5);
	set("����/thd/hua",1);

}

virtual char * chat_msg_combat()
{
	CContainer * item = PresentName("changjian", IS_ITEM);
	CContainer * item1 = PresentName("flower_leaf", IS_ITEM);
	if(query_weapon() == item && item)
	{
		switch(random(3))
		{
		case 0:
			perform_action("sword hua", 1);
			break;
		case 1:
			perform_action("force powerup", 0);
			break;
		case 2:
			perform_action("force recover", 0);
			break;
		}
	}
	else if(query_weapon() == item1 && item1)
	{
		switch(random(3))
		{
		case 0:
			perform_action("finger hua", 1);
			break;
		case 1:
			perform_action("force powerup", 0);
			break;
		case 2:
			perform_action("force recover", 0);
			break;
		}
	}
	else
	{
		switch(random(5))
		{
		case 0:
			perform_action("force recover", 0);
			break;
		case 1:
			perform_action("finger hui", 1);
			break;
		case 2:
			perform_action("finger jinglei", 1);
			break;
		case 3:
			perform_action("hand fuxue", 1);
			break;
		case 4:
			carry_object("flower_leaf")->wield();
			break;
		}
	}
	return 0;
}

MONSTER_END;

#undef MAX_NPC_NUM