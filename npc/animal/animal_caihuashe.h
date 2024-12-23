//caihuashe.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_caihuashe);

virtual void create()
{
		set_name("菜花蛇","caihuashe");
		set("icon", snake);

		set("animal", "snake");

        set("race", "野兽");
        set("age", 1);
        set("long", "一只青幽幽的菜花蛇，头部呈椭圆形。");
        set("attitude", "peaceful");
 
        set("str", 15);
        set("cor", 16);


		CVector v;

		v.append("bite");
		set("verbs", v);

        set("combat_exp", 100+random(50));

        set_temp("apply/attack", 7);
        set_temp("apply/damage", 4);
		set_temp("apply/defence",6);
		set_temp("apply/armor",5);
};

virtual void die()
{
	CContainer * ob;
	
	message_vision("$N抽搐两下，$N死了。", this);
	ob = load_item("sherou");
	ob->move(environment());
	DESTRUCT_OB(this, "animal_caihuashe::die");
}

NPC_END;
