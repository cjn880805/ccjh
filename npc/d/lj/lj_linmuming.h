// lj_linmuming.h 林暮明
// dieer 2002-7-31

NPC_BEGIN(CNlj_linmuming);

virtual void create()
{
	set_name("林暮明", "lin muming");
	set("title", "男装");
	set("long", "这人二十七八岁年纪，穿一件石青色长衫，头顶青巾上镶着块白玉，衣履精雅，背负包裹，皮色白腻，一张脸白里透红，俊秀异常。");
	set("gender", "女性");
	set("age", 27);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",16);				//设置人物形象
	set("per",36);
	
	set("str", 41);
	set("int", 47);
	set("con", 42);
	set("dex", 41);

	set("combat_exp", 5000000);
	
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("no_kill",1);
}

NPC_END;
