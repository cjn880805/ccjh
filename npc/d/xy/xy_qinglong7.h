//xy_qinglong7.h 青龙塔七层守卫
//秦波 2002、12、12

NPC_BEGIN(CNxy_qinglong7);

virtual void create()
{    
	set_name("青龙尊者", "qinglong zhunzhe");
	set("long","已经修炼成仙的青龙圣兽，法力无边。");	
	
	set("title","东方大帝");
	set("str", 32); 
    set("int", 32);
    set("con", 32);
    set("dex", 32);

	set("icon",officer);

    set("max_hp", 25000);
    set("mp", 12000);
    set("max_mp", 12000);
    set("mp_factor", 100); 
    set("combat_exp", 10000000); 
	
	set("no_kill",1);

    set_skill("force", 350);
	set_skill("blade", 350);
	set_skill("dodge", 350);
	set_skill("parry", 350);

    set_skill("shenzhao_gong", 350);
	set_skill("shengji_blade", 350);
	set_skill("feixian_bu", 350);
    
    map_skill("force", "shenzhao_gong");
    map_skill("dodge", "feixian_bu");
    map_skill("blade", "shengji_blade");
    map_skill("parry", "shengji_blade");
    
    set("apply/armor", 200);
    set("apply/damage",150);

	carry_object("gangdao")->wield();

}

void init(CChar * me)
{
	CNpc::init(me);
	if (me->query("xy/renwu4_3") && !is_fighting() ) 
	{
		tell_object(me,"\n$HIC青龙尊者愤怒地吼道：“是谁如此无礼，惊醒了我千年的美梦，还不快快前来受死！”");
		kill_ob(me);
	}
}

virtual void die()
{
	//char msg[255];
	CChar * me = (CChar *)find_object(query_temp("last_damage_from"), 1);
	if(me)
	{
		if(me->query("xy/renwu4_3") && !me->query("xy/renwu4_51"))
		{
			me->set("xy/renwu4_51",1);//击败青龙尊者，取得青龙书生袍
			load_item("qinglong_pao")->move(environment());
			tell_object(me, "\n$HIC在你凌厉的攻式之下，青龙尊者身受数处重创，终于不支，神力一散露出了原形。");
			tell_object(me, "$HIC只见平地一声惊雷，青龙破顶而出，一片巨大的粼片从它身上脱落下来，变成了一件$HIR青龙书生袍$HIC。\n");
		}
	}
	CNpc::die();
}


NPC_END;




