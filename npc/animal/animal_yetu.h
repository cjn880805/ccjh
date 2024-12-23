//yetu.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_yetu);

virtual void create()
{
	set_name("野兔","ye tu");

	set("icon", dog);

	set("animal", "rabbit");

	set("race", "野兽");
	set("age", 5);
    set("long", "一只好可爱的小野兔，你似乎看到了香喷喷的兔肉。");
	set("attitude", "peaceful");

	set("combat_exp", 500);

	CVector v;

	v.append("bite");
	v.append("hoof");
	set("verbs", v);

	set_temp("apply/attack", 2);
	set_temp("apply/defense", 5);
	set_temp("apply/damage", 2);
	set_temp("apply/armor", 1);
};

virtual void die()
{
	CContainer * ob;
	message_vision("$N凄惨的嚎了几声，死了。", this);
    if( random(3) >1 )
	{
       	ob = load_item("turou");
        ob->move(environment());
    }
    else    
       message_vision("天空中突然出现一只秃鹫，把$N叼走了。", this);

	DESTRUCT_OB(this, "animal_yetu::die");
}


NPC_END;
