NPC_BEGIN(CNPub_bayi);

virtual void create()
{
	set_name("巴依","bayi");

	set("icon", pub_boss);
	set("gender", "男性");
	set("age", 55);
	
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 10);
	set("attitude","heroism");
	
	set_inquiry("金子" , "我照着阿凡提的办法种了好多金子，可什么也没长出来，连种子也没了。");
	set_inquiry("阿凡提" , "我把他关到我的客厅里了。");
	
	set("combat_exp", 25000);
	set("shen_type", -1);
	set("chat_chance", 10);
	
	carry_object("wcloth")->wear();
};

virtual char * chat_msg(CChar * me)
{
	switch(random(3))
	{
	case 0:
		return "巴依说道：沙子一筐子金子一屋子，金子一筐子沙子一屋子。";
	case 1:
		return "巴依说道：你站在我的树荫里得付我钱!";
	case 2:
		return "巴依说道：我们对着沙漠喊：金子，你在哪里?";
	}
	
	return "";
}

NPC_END;
