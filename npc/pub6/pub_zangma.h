//pub_zangma.h 妖狐藏马
//wjc 2002-02-24

NPC_BEGIN(CNpub_zangma);


virtual void create()
{
	set_name("藏马", "zang ma");
	set("nickname", "妖狐");
	set("gender", "男性");
	set("age", 20);
	set("long", "看起来不象是中土人士，仿佛是一个来自地狱的恐怖杀手。");
	
	set("attitude", "peaceful");		//设置NPC态度
	set("icon",young_man4);			    //设置人物形象
	
	set("str", 35);
	set("int", 34);
	set("con", 35);
	set("dex", 40);
	
	set("chat_chance", 5);			    //设置自动聊天触发率
	set("chat_chance_combat", 10);		//设置NPC使用绝招的几率
	
	set("hp", 15000);
	set("max_hp", 15000);
	set("mp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 50);
	
	set("combat_exp", 1200000);
	set("score", 50000);

	set_skill("force", 170);			       // 基本内功
	set_skill("huntian_qigong", 170);          
	set_skill("whip", 170);			           // 基本鞭法
	set_skill("yunlong_bian", 170);		       // 云龙鞭法
	set_skill("dodge", 170);			       // 基本躲闪
	set_skill("yunlong_shenfa", 170);	       // 云龙身法
	set_skill("parry", 170);			       // 基本招架
	set_skill("unarmed", 170);
	set_skill("xianglong_zhang", 170);
	
	map_skill("force", "huntian_qigong");		
	map_skill("whip", "yunlong_bian");	        //设置NPC的基本鞭法装备云龙鞭法
	map_skill("dodge", "yunlong_shenfa");		//设置NPC的基本轻工装备云龙身法
	map_skill("parry", "yunlong_bian");		    //设置NPC的基本招架装备云龙鞭法
	map_skill("unarmed", "xianglong_zhang");	//设置NPC的基本拳脚装备降龙掌

	prepare_skill("unarmed","xianglong_zhang");
	set("apply/armor", 100);
    set("apply/damage", 40);
	carry_object("changbian")->wield();
	
}


virtual char * chat_msg_combat()			    //NPC自动发绝招
{
	switch(random(5))
	{
	case 0:
		perform_action("whip chan", 1);	       //云龙鞭法的缠字诀
		break;
	case 1:
		perform_action("force recover", 0);	   //自动吸气
		break;
	
	}	
	return 0;
}

virtual void die()
{
	message_vision("$HIR风紧，兄弟们，我先扯乎！", this);
	destruct(this);
}

char * chat_msg()
{
	message_vision("$N吹了声口哨，晃悠晃悠的远远离去。", this);
	DESTRUCT_OB(this, "pub_zangma::chat_msg");
	return 0;

}
NPC_END;




