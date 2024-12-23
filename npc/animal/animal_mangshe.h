//mangshe.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_mangshe);

virtual void create()
{
	set_name("蟒蛇","mang she");
	set("icon", snake);

	set("animal", "snake");

	set("race", "野兽");
	set("age", 5);
	set("long", "一只昂首直立，吐着长舌芯的大蟒蛇。");
	set("attitude", "peaceful");

	set("str", 26);
	set("cor", 30);

	set("combat_exp", 5000);

	CVector v;

	v.append("bite");
		
	set("verbs", v);

	set_temp("apply/attack", 25);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 18);
	set_temp("apply/defence",20);
};

virtual void die()
{
	CContainer * ob;

	message_vision("$N倒在地上，死了！", this);
	ob =load_item("shepi");
	ob->move(environment());
	DESTRUCT_OB(this, "animal_mangshe::die");
}
NPC_END;
