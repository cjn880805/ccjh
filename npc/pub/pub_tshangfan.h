//tshangfan.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_tshangfan);

void create()
{
	set_name("台夷商贩","tshangfan");

	set("icon", waiter);
	set("gender", "男性" );
	set("age", 22);
	set("long", "一位台夷族的商贩，正在贩卖一竹篓刚打上来的活蹦乱跳的鲜鱼。");
	set("combat_exp", 3000);
    set("per", 17);
    set("str", 17);
    set("dex", 20);
    set("con", 17);
    set("int", 22);
	set("attitude", "friendly");

	carry_object("ttoujin")->wear();
	carry_object("tduanqun")->wear();
	add_money(100);

};

NPC_END;
