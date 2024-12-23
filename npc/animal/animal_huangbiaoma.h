//huangbiaoma.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_huangbiaoma);

virtual void create()
{
	set_name("黄骠马","huang biao ma");

	set("icon", tiger);

	

	set("race", "野兽");
	set("gender", "雄性");
	set("age", 2+random(3));
	set("long", "这是一匹黄骠骏马，全身金黄，没有一丝杂毛。玩家可以骑上它去指定的地方");
	set("ridable", 1);
	set("int", 30);
	set("hp", 300);
	set("max_hp", 900);
	
	set("combat_exp",50000);
	set("attitude", "peaceful");

//	set("limbs", ({ "头部", "腹部", "尾巴","后腿","前腿" }) );
//	set("verbs", ({ "bite","hoof" }) );
	CVector v;

	v.append("bite");
	v.append("hoof");
	set("verbs", v);

	set_temp("apply/attack", 50);
	set_temp("apply/armor", 15);
	set_temp("apply/damage", 25);
	
};



NPC_END;
