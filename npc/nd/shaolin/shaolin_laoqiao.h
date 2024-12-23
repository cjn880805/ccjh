// laoqiao.c ÇÇÈý»±

//code by sound
//date:2001-07-12

NPC_BEGIN(CNshaolin_laoqiao);

virtual void create()
{
	set_name("ÇÇËÄ»±", "lao qiao");
	set("gender", "ÄÐÐÔ");
	set("age", 55 );
        set("icon",old_man2);

	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set("hp", 400);
	set("max_hp", 400);

}
NPC_END;