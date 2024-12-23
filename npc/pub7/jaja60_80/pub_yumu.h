// lev1_yumu.h 愚木
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_yumu);

virtual void create()
{
	set_name("愚木", "yu mu");
	set("title", "深山隐士");
	set("gender", "男性");
	set("age", 80);
	set("level", 100);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",19);				//设置人物形象
	set("repute", 5000);
	
	set("str", 21);
	set("int", 23);
	set("con", 23);
	set("dex", 21);
	
	set("chat_chance_combat", 5);		//设置NPC使用绝招的几率
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//设置NPC加力参数
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 190+random(30));			// 基本内功
	set_skill("wuzheng_xinfa", 190+random(30));		// 无争心法
	set_skill("finger", 190+random(30));			// 基本指法
	set_skill("xuantian_zhi", 190+random(30));			// 玄天无情指
	set_skill("dodge", 190+random(30));			// 基本躲闪
	set_skill("qingfu_shenfa", 190+random(30));		// 青蝠身法
	set_skill("parry", 190+random(30));			// 基本招架
	set_skill("sword", 190+random(30));		        // 基本剑法
	set_skill("wuyun_jianfa", 190+random(30));			// 五韵七弦剑

	map_skill("force", "wuzheng_xinfa");	//设置NPC当前内功为无争心法
	map_skill("sword", "wuyun_jianfa");	        //设置NPC的基本剑法装备五韵七弦剑
	map_skill("dodge", "qingfu_shenfa");		//设置NPC的基本躲闪装备青蝠身法
	map_skill("parry", "wuyun_jianfa");		//设置NPC的基本招架装备五韵七弦剑
	map_skill("finger", "xuantian_zhi");		//设置NPC的基本指法装备玄天无情指

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 60);			//设置NPC附加攻击力

	carry_object("changjian")->wield();

	prepare_skill("finger", "xuantian_zhi");
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
			//自动吸气
		break;
	case 1:
			//自动吸气
		break;
	case 2:
			//自动吸气
		break;
	case 3:
			//自动吸气
		break;
	case 4:
			//自动吸气
		break;
	case 5:
			//自动吸气
		break;
	}	
	return 0;
}

LEV1_END;
