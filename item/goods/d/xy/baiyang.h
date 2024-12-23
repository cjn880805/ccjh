//baiyang.h 逍遥任务特殊道具
NPC_BEGIN(CNbaiyang)

virtual void create()
{
	set_name("白羊", "bai yang");
	set("long",	"农家饲养之肥羊，下菜之极品。");
	
	set("icon", dog);
	
	set("race", "野兽");
	set("age", 20);
	set("attitude", "peaceful");
	set("shen_type", -1);
	
	CVector v;
	
	v.append("bite");
	v.append("claw");
	v.append("knock");
	set("verbs", v);
	
	set("max_hp",15000);
	
	set_temp("apply/attack", 150);
	set_temp("apply/defense", 250);
	set_temp("apply/armor", 200);
	set_temp("apply/damage", 400);
	set_temp("apply/dodge", 200);
	set_temp("apply/parry", 200);
};

virtual void die()
{
	CContainer * ob = 0, * corpse = 0;
	
	message_vision("$N凄惨的发出一声哀嚎，慢慢委顿在地，死了！", this);
	if((corpse =CCorpse::MakeCorpse(this, NULL)) )
		ob = load_item("yangshuei");
	ob->move(corpse);
	corpse->move(environment());
	DESTRUCT_OB(this, "baiyang::die");
}

NPC_END;




