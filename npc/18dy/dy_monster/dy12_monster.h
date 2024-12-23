//dy12_monster.h 地狱第12层怪物
//wuqing 2005-1-05

#define MAX_NPC_NUM 14

MONSTER_BEGIN(CNdy12_monster);

void create()
{
	CNmonsternpc::create();
	set("monster_level",12);
	static struct{
		char name[20], id[20],gender[20];		//怪物名称
		int	 icon,age;			//图标
	}mon[MAX_NPC_NUM] = {
		{"倩雯", "qing wen","女性",young_woman2,26,},
		{"纤纤", "qina qian","女性", young_woman2,28,},
		{"云裳", "yun shang","女性", young_woman3,38,},
		{"花弄月", "hua nong yue","女性", young_woman2,22,},
		{"柳随风", "liu sui feng", "男性", young_man1,25,},
		{"闻天赐", "wen tian ci", "男性",young_man2,37,},
		{"白杨", "bai yang", "男性",young_man3,44,},
		{"周惠", "zhou hui", "男性",young_man1,18,},
		{"刘元明", "liu yuan ming", "男性",old_man1,67,},
		{"白飞飞", "bai fei fei", "女性",young_woman1,17,},
		{"沈郎", "shen lang", "男性",young_man3,44,},
		{"王恋花", "wang lian hua", "男性",young_man2,24,},
		{"金无望", "jin wu wang", "男性",young_man3,36,},
		{"朱八", "zhu ba", "男性",young_man1,19,},
	};

	int lvl=random(MAX_NPC_NUM);
	set_name( mon[lvl].name, mon[lvl].id);
	set("icon", mon[lvl].icon);
	set("gender", mon[lvl].gender);

	set("per",random(21)+10);
	set("title", "地狱守护者");
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
	
	create_family("桃花", 2, "弟子");
	
	carry_object("changjian")->wield();
	set("chat_chance_combat", 5);
	set("门派/thd/hua",1);

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