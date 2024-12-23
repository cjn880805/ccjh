//wugui.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_wugui);

virtual void create()
{
		set_name("乌龟","wu gui");

        set("race", "野兽");
        set("age", 10);
        set("long", "一只大乌龟，看来岁数不小了。");
        set("attitude", "peaceful");

        set("str", 26);
        set("cor", 30);

        set("combat_exp", 1000);

		CVector v;

		v.append("bite");
		v.append("poke");
		set("verbs", v);

        set_temp("apply/attack", 15);
        set_temp("apply/damage", 6);
        set_temp("apply/armor", 2);
};

virtual void die()
{
        CContainer * ob;
	
        message_vision("$N翻转身，死了！", this);
        ob =load_item("guijia");
        ob->move(environment());
        DESTRUCT_OB(this, "animal_wugui::die");
}

NPC_END;
