//dy19_monster.h 地狱第19层怪物
//wuqing 2005-1-05

MONSTER_BEGIN(CNdy19_monster);

void create()
{
	CNmonsternpc::create();
	set("monster_level",19);
	static struct{
		char name[20], id[20],gender[20];		//怪物名称
		int	 icon,age;			//图标
	}mon[15] = {
		{"张娜", "zhang na","女性",young_woman2,26,},
		{"纤云", "qina yun","女性", young_woman2,28,},
		{"红月", "hong yue","女性", young_woman3,38,},
		{"蝶舞", "die wu","女性", young_woman2,22,},
		{"柳三", "liu san", "男性", young_man1,25,},
		{"文浪", "wen lang", "男性",young_man2,37,},
		{"红石", "hong shi", "男性",young_man3,44,},
		{"天眼", "tian yan", "男性",young_man1,18,},
		{"沈明", "shen ming", "男性",old_man1,67,},
		{"无双", "wu shuang", "女性",young_woman1,17,},
		{"断剑", "dua jian", "男性",young_man3,44,},
		{"剑心", "jian xin", "男性",young_man2,24,},
		{"金达", "jin da", "男性",young_man3,36,},
		{"朱九", "zhu jiu", "男性",young_man1,19,},
	};

	int lvl=random(15);
	set_name( mon[lvl].name, mon[lvl].id);
	set("icon", mon[lvl].icon);
	set("gender", mon[lvl].gender);

	set("per",random(21)+10);
	set("title", "地狱守护者");
	set("level", 190+random(5));

	set("max_hp", 104000+random(1000));
	set("max_mp", 76000+random(200));
	set("mp_factor", 150);

	set("combat_exp", 207234500+random(100000));
	set("max_exp",350000000);

	set("str", 99+random(5));
	set("con", 99+random(5));
	set("int", 99+random(5));
	set("dex", 99+random(5));
	
	set_skill("force", 780+random(10));             
	set_skill("claw", 780+random(10));              
	set_skill("hand", 780+random(10));              
	set_skill("finger", 780+random(10));            
	set_skill("unarmed", 780+random(10));           
	set_skill("strike", 780+random(10));            
	set_skill("leg", 780+random(10));	           
	set_skill("dodge", 780+random(10));             
	set_skill("parry", 780+random(10));             
	set_skill("sword", 780+random(10));             
	
	set_skill("anying_fuxiang", 780+random(10));    
	set_skill("tanzhi_shentong", 780+random(10));   
	set_skill("xuanfeng_leg", 780+random(10));      
	set_skill("luoying_shenzhang", 780+random(10));     
	set_skill("bibo_shengong", 780+random(10));     
	set_skill("luoying_shenjian", 780+random(10));  
	set_skill("yuxiao_jianfa", 780+random(10));       
	set_skill("lanhua_shou", 780+random(10));       
	set_skill("literate", 780+random(10));          
	
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
	
	set("apply/armor", 530+random(10));
	set("apply/damage", 570+random(10));

	create_family("桃花岛", 2, "弟子");

	carry_object("changjian")->wield();

}

char * chat_msg_combat()
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

	return 0;
}

MONSTER_END;