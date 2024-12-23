//laofu.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_laofu);

virtual void create()
{
		set_name("老虎","laofu");
	set("icon", tiger);

        set("race", "野兽");
        set("age", 20);
        set("long","一只斑斓猛虎，雄伟极了。");
        set("attitude", "aggressive");
        set("shen_type", -1);

//        set("limbs", ({ "虎头", "虎身", "前爪", "后抓", "尾巴" }) );
//        set("verbs", ({ "bite", "claw" }) );

		CVector v;

		v.append("bite");
		v.append("claw");
		set("verbs", v);

        set("combat_exp", 30000);
        set("mp",800);
        set("mp_factor",100);
        set("max_mp",800);
        set("hp",500);
        set("max_hp", 1500);

        set_temp("apply/attack", 20000);
        set_temp("apply/defense", 300);
        set_temp("apply/armor", 1000);
	
};

NPC_END;
