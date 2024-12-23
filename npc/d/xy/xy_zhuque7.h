//xy_zhuque7.h 朱雀塔七层守卫
//秦波 2002、12、12

NPC_BEGIN(CNxy_zhuque7);

virtual void create()
{    
	set_name("朱雀尊者", "qinglong zhunzhe");
	set("long","浴火重生的凤凰，已经修炼成仙，法力无边。");	
	
	set("title","北方大帝");
	set("str", 32); 
    set("int", 32);
    set("con", 32);
    set("dex", 32);

	set("icon",young_woman9);

    set("max_hp", 25000);
    set("mp", 12000);
    set("max_mp", 12000);
    set("mp_factor", 100); 
    set("combat_exp", 10000000); 
	
	set("no_kill",1);

    set_skill("force", 350);
	set_skill("unarmed", 350);
	set_skill("dodge", 350);
	set_skill("parry", 350);

    set_skill("shenzhao_gong", 350);
	set_skill("hanxing_bada", 350);
	set_skill("fengyu_bu", 350);
	set_skill("douzhuan_xingyi", 350);
    
    map_skill("force", "shenzhao_gong");
    map_skill("dodge", "fengyu_bu");
    map_skill("unarmed", "hanxing_bada");
    map_skill("parry", "douzhuan_xingyi");
    
    set("apply/armor", 200);
    set("apply/damage",150);
	
	carry_object("arrow1")->wield();

}

void init(CChar * me)
{
	CNpc::init(me);
	if (me->query("xy/renwu4_3") && !is_fighting() ) 
	{
		tell_object(me,"\n$HIC朱雀尊者愤怒地吼道：“是谁如此无礼，惊醒了我千年的美梦，还不快快前来受死！”");
		kill_ob(me);
	}
}

virtual void die()
{
	//char msg[255];
	if(query("重生"))
	{
		CChar * me = (CChar *)find_object(query_temp("last_damage_from"), 1);
		if(me)
		{
			if(me->query("xy/renwu4_3") && !me->query("xy/renwu4_54"))
			{
				me->set("xy/renwu4_54",1);//击败朱雀尊者，取得逍遥朱雀巾
				load_item("zhuque_jin")->move(environment());
				tell_object(me, "\n$HIC在你凌厉的攻式之下，朱雀尊者身受数处重创，终于不支，神力一散露出了原形。");
				tell_object(me, "$HIC一片耀眼的火光闪现，炽热的火焰中，凤凰升腾而起，从它的翅膀上掉落一根五彩的羽毛，细看时，却是一条$HIR逍遥朱雀巾$HIC。\n");
			}
		}
		CNpc::die();
	}
	else
	{
		revive(1);
		set("重生",1);
		set("hp",query("max_hp"));
		set("eff_hp",query("max_hp"));
		set("mp",query("max_mp"));
		message_vision("$HIC朱雀尊者倒下的刹那，从她身体里喷射而出的鲜血熊熊燃烧了起来。\n火光中，朱雀尊者再一次获得了生命。\n",this);
	}
}


NPC_END;




