//taishan_weishi3.h
//code by sound
//2001-07-11

NPC_BEGIN(CNtaishan_weishi3);

virtual void create()
{
	set_name("青衣武士", "wei shi");
	set("gender", "男性");
	set("age", 35);
	set("long",
		"这是位青衣武士，身披钢甲，手执长剑，双目精光炯炯，警惕地巡视着四周的情形。");
	set("combat_exp", 60000);
        set("shen_type", 1);
	set("attitude", "heroism");

	set("str", 26);
	set("con", 22);
	set("int", 20);
	set("dex", 24);

	set("max_hp", 400);
	set("eff_qi", 400);
	set("qi", 400);
	set("hp", 200);
	set("jing", 200);
	set("mp", 300);
	set("max_mp", 300);
	set("mp_factor", 20);
	set("shen_type", 0);

	set_temp("apply/attack",  30);
	set_temp("apply/defense", 30);

	set_skill("sword", 60);
	set_skill("unarmed", 50);
	set_skill("parry", 60);
	set_skill("dodge", 60);

	setup();

        carry_object("/d/city/obj/changjian")->wield();
        carry_object("/d/city/obj/tiejia")->wear();
}

void init()
{
	object ob1, ob2, ob3;
	string mengzhu, shangshan, fae;
	
	if(!( ob1 = find_living("mengzhu")) )
	ob1 = load_object("/clone/npc/meng-zhu");
	mengzhu = ob1->query("winner");

	if(!( ob2 = find_living("shangshan")) )
	ob2 = load_object("/clone/npc/shang-shan");
	shangshan = ob2->query("winner");

	if(!( ob3 = find_living("fae")) )
	ob3 = load_object("/clone/npc/fa-e");
	fae = ob3->query("winner");

	if( this_player()->query("id") == mengzhu ) {
		message_vision(HIY "青衣武士举起长剑，向$N齐声大喊：盟主万岁，万岁，万万岁！\n" NOR, 
		this_player());
	}	
	else if( this_player()->query("id") == shangshan ) {
		message_vision(HIY "青衣武士举起长剑，向$N齐声大喊：赏善使者好！\n" NOR, 
		this_player());
	}	
	else if( this_player()->query("id") == fae ) {
		message_vision(HIY "青衣武士举起长剑，向$N齐声大喊：罚恶使者好！\n" NOR, 
		this_player());
	}	
}