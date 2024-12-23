//zaohongma.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_zaohongma);

virtual void create()
{
	set_name("枣红马","zao hong ma");

	set("icon", tiger);

    set("long","一匹骏马，全身火红，无一根杂毛。玩家可以骑上它去指定的地方(ride)。");
    set("race", "野兽");
    set("age", 5);
	set("ridable", 1);
	set("int", 30);
	set("hp", 300);
	set("max_hp", 900);
	
	set("combat_exp",50000);
	set("attitude", "peaceful");

//	set("limbs", ({ "头部", "腹部", "尾巴","后腿","前腿" }) );
	CVector v;

	v.append("bite");
	v.append("hoof"); 
	set("verbs", v);

	set_temp("apply/attack", 50);
	set_temp("apply/armor", 15);
	set_temp("apply/damage", 25);
};

NPC_END;
