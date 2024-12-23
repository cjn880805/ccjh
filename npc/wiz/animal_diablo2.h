//wubushe.h
//code by zwb
//12-16

NPC_BEGIN(CNanimal_diablo2);

void create()
{
	set_name("旺财","diablo2");

	set("long","这是一只扬州所产的巨犬，肌肉强壮，骨凌出峰，十分恐怖。");
        set("title",  "后犬");
	set("race", "野兽");
	set("age", 23);
	set("attitude", "peaceful");
        set_inquiry("银铃","你见过她吗？你可以带我去找她吗？");
	set("max_hp", 4999);
        set("class", "swordman");
        set("icon", dog);

		set("animal", "wolf");

	set("str", 10);
	set("con", 50);
	set("dex", 50);
	set("per", 23);
	set_skill("dodge", 100);
	set_skill("parry", 100);
        carry_object("cycle")->wear();
        carry_object("goupi")->wear();
        carry_object("gourou");
        add_money(78);
	CVector v;
        v.append("claw");
	v.append("bite");
	set("verbs", v);


	set_temp("apply/attack", 50);
	set_temp("apply/damage", 50);
	set_temp("apply/armor", 50);

	set("combat_exp", 10000);
	set("no_huan",1);
};



const char * hit_ob(CChar * npc, CChar * victim, LONG damage)
{
    if (victim->query_combat_exp() > 300000) return 0;
	if( random(damage) > victim->query_temp("apply/armor") 	&&	victim->query_condition("dog_poison") < 10 ) 
	{
		victim->apply_condition("dog_poison", 100);
        tell_object(victim, "你的伤口一阵火辣辣地疼！");
	}
	return 0;
}

int accept_object(CChar * who, CContainer * ob)
{
	if ( DIFFERSTR(ob->querystr("id"), "yinling") || DIFFERSTR(ob->querystr("name"), "银铃" ))
	{	
		say("是你把她救出来的吗？太谢谢", who);
		SendMenu(who);
		return 0;
	}

	DESTRUCT_OB(ob, "animal_diablo2");
	
	CContainer * obj=load_item("gouroutang");

	obj->set_name( "狗肉汤", "gouroutang");

	message_vision("$N充满崇拜和感谢之情地给$n一样东西。", this, who);
	obj->move(who);

	return 1;
}

NPC_END;
