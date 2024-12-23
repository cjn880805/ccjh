//xy_xuanwu7.h 玄武塔七层守卫
//秦波 2002、12、12

NPC_BEGIN(CNxy_xuanwu7);

virtual void create()
{    
	set_name("玄武尊者", "xuanwu zhunzhe");
	set("long","一只人面蛇身的赤色神兽，具有呼风唤雨之能。");	
	
	set("title","北方大帝");
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
	set_skill("club", 350);
	set_skill("dodge", 350);
	set_skill("parry", 350);

    set_skill("shenzhao_gong", 350);
	set_skill("duanhun_qiang", 350);
	set_skill("huanhua_bu", 350);
    
    map_skill("force", "shenzhao_gong");
    map_skill("dodge", "huanhua_bu");
    map_skill("club", "duanhun_qiang");
    map_skill("parry", "duanhun_qiang");
    
    set("apply/armor", 200);
    set("apply/damage",150);

	carry_object("huaji")->wield();

}

void init(CChar * me)
{
	CNpc::init(me);
	if (me->query("xy/renwu4_3") && !is_fighting() ) 
	{
		tell_object(me,"\n$HIC玄武尊者愤怒地吼道：“是谁如此无礼，惊醒了我千年的美梦，还不快快前来受死！”");
		kill_ob(me);
	}
}

virtual void die()
{
	//char msg[255];
	CChar * me = (CChar *)find_object(query_temp("last_damage_from"), 1);
	if(me)
	{
		if(me->query("xy/renwu4_3") && !me->query("xy/renwu4_53"))
		{
			me->set("xy/renwu4_53",1);//击败玄武尊者，取得玄武玉指环
			load_item("xuanwu_huan")->move(environment());
			tell_object(me, "\n$HIC在你凌厉的攻式之下，玄武尊者身受数处重创，终于不支，神力一散露出了原形。");
			tell_object(me, "$HIC只见缠于龟身的长蛇渐渐松脱，分离为一龟一蛇，一阵烟雾过后龟蛇皆不见，只留下一枚$HIR玉指环$HIC在原地。\n");
		}
	}
	CNpc::die();
}


NPC_END;




