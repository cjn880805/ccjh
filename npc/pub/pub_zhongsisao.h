// pub_zhongsisao.c
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_zhongsisao);

virtual void create()
{
	set_name("钟四嫂","zhong sisao" );

	set("icon", young_woman3);
	set("gender", "女性");
	set("age", 35);
	set("long","她就是钟阿四的老婆。");
	set("combat_exp", 20000);
	set("shen_type", 1);
	set("attitude", "aggressive");
	set("apply/attack",  30);
	set("apply/defense", 30);
	set("chat_chance", 5);
 	set_skill("blade", 30);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("dodge", 50);
	
 	carry_object("caidao")->wield();
	carry_object("cloth")->wear();
}

virtual char * chat_msg()
{
	return "钟四嫂嘶哑着嗓子喊：‘不卖地，不卖地！没有偷，没有偷。’";
}

NPC_END;