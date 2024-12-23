//baitu.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_baitu);

virtual void create()
{
		set_name("白兔","baitu");

		set("icon", dog);

        set("race", "野兽");
        set("age", 2);
        set("long", "一只雪白的小白兔，可爱之致。");
        set("attitude", "peaceful");
 
        set("str", 15);
        set("cor", 16);

		CVector v;

		v.append("bite");
		v.append("hoof");
		set("verbs", v);

 
        set("combat_exp", 200);

        set_temp("apply/attack", 5);
        set_temp("apply/damage", 3);
		set_temp("apply/defence",5);
		set_temp("apply/armor",2);
};

virtual void die()
{
	CContainer * ob;
	
	message_vision("$N两腿一蹬，$N死了。", this);
	ob =load_item("turou");
	ob->move(environment());
	DESTRUCT_OB(this, "animal_baitu::die");
}


NPC_END;
