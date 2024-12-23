// pub_cunzhang.c
//code by Fisho
//date : 2000-12-13

NPC_BEGIN(CNpub_cunzhang);

virtual void create()
{
	set_name("桃花村长","cun zhang");

	set("icon", drugstore_boss);
	set("gender", "男性");
	set("age", random(10) + 40);
	set("str", 25);
	set("dex", 16);
	set("per", 20);
	set("long", "他是桃花村长，谁想在桃花村造屋安家，都要经过他老人家的同意。他是个面目慈善的老汉。很得全村人的尊重。");
	set("combat_exp", 75000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	
	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("sword", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);
	
	set("mp", 400); 
	set("max_mp", 400);
	set("mp_factor", 10);

//	set_inquiry("$0zao $1" , "", "我想造屋");
//	set_inquiry("修屋" , "$C=xiu");/
	//set_inquiry("$0chai $1" , "", "我想拆屋");
	
	carry_object("cloth")->wear();
}

NPC_END;
