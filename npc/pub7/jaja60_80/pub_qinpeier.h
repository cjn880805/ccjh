// lev1_qinpeier.h 泰佩儿
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_qinpeier);

virtual void create()
{
	set_name("泰佩儿", "qin peier");
	set("title", "冰雪仙罗");
	set("gender", "女性");
	set("age", 24);
	set("level", 100);
	set("long", 
		"她脸色是苍白的，因为终年都见不到阳光，但这种苍白的脸色，看来却更楚楚动人。她双眸漆黑，鼻子挺直而秀气。她的嘴唇虽很薄，却很有韵致，不说话的时候也带着动人的表情。\n");
	set("attitude", "peaceful");		//设置NPC态度
	set("icon",8);				//设置人物形象
	set("repute", 1000);
	
	set("str", 23);
	set("int", 21);
	set("con", 21);
	set("dex", 22);
	
	set("chat_chance_combat", 5);		//设置NPC使用绝招的几率
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//设置NPC加力参数
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 190+random(30));			// 基本内功
	set_skill("yunv_xinjing", 190+random(30));			// 玉女心经
	set_skill("unarmed", 190+random(30));			// 基本拳脚
	set_skill("meinv_quan", 190+random(30));			// 美女拳
	set_skill("dodge", 190+random(30));			// 基本躲闪
	set_skill("yunv_shenfa", 190+random(30));			// 玉女身法
	set_skill("parry", 190+random(30));			// 基本招架
	set_skill("sword", 190+random(30));		        // 基本剑法
	set_skill("yunv_jian", 190+random(30));			// 玉女剑
	set_skill("yunv_xinfa", 190+random(30));			// 玉女心法
	set_skill("tianluo_diwang", 190+random(30));		// 天罗地网
	set_skill("quanzhen_jian", 190+random(30));		// 全真剑法

	map_skill("force", "yunv_xinjing");		//设置NPC当前内功为玉女心经
	map_skill("sword", "yunv_jian");	        //设置NPC的基本剑法装备玉女剑
	map_skill("dodge", "yunv_shenfa");		//设置NPC的基本轻工装备玉女身法
	map_skill("parry", "yunv_jian");		//设置NPC的基本招架装备全真剑法
	map_skill("unarmed", "meinv_quan");		//设置NPC的基本拳脚装备美女拳


	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 10);			//设置NPC附加攻击力

	carry_object("shunvjian")->wield();	
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("sword he", 1);		//玉女剑法双剑合壁
		break;
	case 1:
		perform_action("unarmed you", 1);	//美女拳绝招古墓幽居
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

