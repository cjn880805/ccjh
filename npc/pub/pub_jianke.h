NPC_BEGIN(CNpub_jianke);

virtual void create()
{
	set_name("剑客","jianke");

	set("icon", taoist_with_sword);
	set("gender", "男性");
	set("age", 45);
	set("long","这是位中年武人，肩背长剑，长长的剑穗随风飘扬，看来似乎身怀绝艺。");
	set("combat_exp", 20000);
        set("shen_type", -1);
	set("attitude", "heroism");

	set("apply/attack",  30);
	set("apply/defense", 30);

	set_skill("sword", 60);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("dodge", 50);


    carry_object("changjian")->wield();
    carry_object("cloth")->wear();
	add_money(20);


};

virtual void init(CChar * me)
{
	const char * mengzhu = "";
	CChar * ob;
	
	CContainer * r = load_room("泰山封禅台");
	
	if(( ob = (CChar *)r->PresentName("mengzhu", IS_CHAR)) )
		mengzhu = ob->querystr("winner");

	if( EQUALSTR(me->querystr("id"), mengzhu) ) 
	{
		message_vision("剑客向$N躬身为礼，说道：盟主您老人家好！", me);
	}	
}

NPC_END;
