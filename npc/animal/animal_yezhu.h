//yezhu.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_yezhu);

virtual void create()
{
		set_name("野猪","ye zhu");

        set("race", "野兽");
        set("age", 4);
        set("long","这是一只凶猛的野猪，长得极为粗壮，嘴里还不断发出可怕的哄声。");
        set("attitude", "peaceful");

        set("str", 26);
        set("cor", 30);

        set("shen_type", -1);

		CVector v;

		v.append("bite");
		v.append("knock");
		set("verbs", v);

        set("max_hp",12000);

        set("combat_exp", 300000);
        set_temp("apply/attack", 150);
        set_temp("apply/defense", 250);
        set_temp("apply/armor", 200);
		set_temp("apply/damage", 180);
		set_temp("apply/dodge", 200);
		set_temp("apply/parry", 200);
};

virtual void init(CChar * player)
{
	kill_ob(player);
}

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

virtual void die()
{
	//CContainer * ob;
	message_vision("$N哇呀地惨嚎一声，死了！", this);
	//ob = load_item("pigdie");
	//ob->move(environment());
	DESTRUCT_OB(this, "animal_yezhu::die");
}


NPC_END;
