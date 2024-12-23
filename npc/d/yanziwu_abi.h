// yanziwu_abi.c

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNyanziwu_abi);

virtual void create()
{
	set_name("阿珊",  "abi");
	set("long","这是个身穿绿衣的女郎，约十六七岁年纪，满脸都是温柔， ");
	set("gender", "女性");
	set("age", 16);
        set("icon",girl1);

	set("shen_type", 1);
	
	set("mp", 200);
	set("max_mp", 200);
	set("max_hp", 480);
	set_skill("force", 40);
	set_skill("unarmed", 40);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_skill("sword", 30);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	set_temp("apply/damage", 5);
	
	set("combat_exp", 10000);
	set_inquiry("曼陀山庄","我才不敢去曼陀山庄，王夫人太霸道了! ");
	set_inquiry("王姑娘","哎，只有她才配得上我们公子，也不知她现在怎么样了! ");
	set_inquiry("阿丹","那小妮子只大我一岁，整天就喜欢扮别人玩。 ");
	
	carry_object("goldring")->wear();
	carry_object("necklace")->wear();
	carry_object("changjian")->wield();
	carry_object("green_cloth")->wear();
	carry_object("flower_shoe")->wear();
}

NPC_END;