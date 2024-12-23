// yinchang_hong.h

//code by Fisho
//date:2000-12-23
//inherit F_MASTER;

NPC_BEGIN(CNyinchang_hong);

virtual void create()
{
	set_name("洪叫化", "hong qigong");
	set("nickname", "北丐");
	set("gender", "男性");
	set("age", 75);
        set("icon",old_man2);

	set("long", "他就是丐帮第十七任帮主，号称“北丐”的洪叫化老爷子。");
	set("attitude", "peaceful");
	set("class", "beggar");
	
	set("str", 30);
	set("int", 24);
	set("con", 30);
	set("dex", 24);
	
	set("chat_chance", 1);
	//	set("inquiry", ([
	//		"青竹林" : "东北西北东西北。",
	//		"丐帮" : "东北西北东西北。",
	//		"拜师" : "你可以去东城门的我帮总舵拜鲁有脚。",
	//	]));
	
	set("hp", 1000);
	set("max_hp", 3000);
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 300);
	
	set("combat_exp", 1000000);
	set("score", 200000);
	set("repute", 100000);
	
	set_skill("force", 150);             // 基本内功
	set_skill("huntian_qigong", 150);    // 混天气功
	set_skill("unarmed", 180);           // 基本拳脚
	set_skill("xianglong_zhang", 180);   // 降龙十八掌
	set_skill("dodge", 150);      	     // 基本躲闪
	set_skill("xiaoyaoyou", 150);        // 逍遥游
	set_skill("parry", 150);             // 基本招架
	set_skill("staff", 150);             // 基本棍杖
	set_skill("dagou_bang", 150);        // 打狗棒法
	set_skill("begging", 100);           // 叫化绝活
//	set_skill("checking", 100);          // 道听途说
	
	map_skill("force", "huntian_qigong");
	map_skill("unarmed", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "dagou_bang");
	map_skill("staff", "dagou_bang");
	
	create_family("丐帮", 17, "帮主");
	
	carry_object("yuzhu_zhang");
}

virtual char * chat_msg()
{
	switch (random(3))
	{
	case 0:
		return "洪叫化叹了口气道：“唉……何时能再吃到蓉儿做的「叫化鸡」啊……”";
	case 1:
		return "洪叫化说道：“俗话说「吃在江南」，所以老叫化特地跑来扬州看看。”";
	case 2:
		return "洪叫化喃喃道：“我们丐帮的「降龙十八掌」是天下最霸道的掌法。”";
	}
	return "";
}

NPC_END;
