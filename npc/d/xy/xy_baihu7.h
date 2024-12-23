//xy_baihu7.h 白虎塔七层守卫
//秦波 2002、12、12

NPC_BEGIN(CNxy_baihu7);

virtual void create()
{    
	set_name("白虎尊者", "qinglong zhunzhe");
	set("long","已经修炼成仙白虎圣兽，法力无边。");	
	
	set("title","南方大帝");
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
	set_skill("unarmed", 350);
	set_skill("dodge", 350);
	set_skill("parry", 350);

    set_skill("shenzhao_gong", 350);
	set_skill("celestrike", 350);
	set_skill("tiexue_steps", 350);
    
    map_skill("force", "shenzhao_gong");
    map_skill("dodge", "tiexue_steps");
    map_skill("unarmed", "celestrike");
    map_skill("parry", "celestrike");
    
    set("apply/armor", 200);
    set("apply/damage",150);


}

void init(CChar * me)
{
	CNpc::init(me);
	if (me->query("xy/renwu4_3") && !is_fighting() ) 
	{
		tell_object(me,"\n$HIC白虎尊者愤怒地吼道：“是谁如此无礼，惊醒了我千年的美梦，还不快快前来受死！”");
		kill_ob(me);
	}
}

virtual void die()
{
	//char msg[255];
	CChar * me = (CChar *)find_object(query_temp("last_damage_from"), 1);
	if(me)
	{
		if(me->query("xy/renwu4_3") && !me->query("xy/renwu4_52"))
		{
			me->set("xy/renwu4_52",1);//击败白虎尊者，取得白虎绝尘靴
			load_item("baihu_xue")->move(environment());
			tell_object(me, "\n$HIC在你凌厉的攻式之下，白虎尊者身受数处重创，终于不支，神力一散露出了原形。");
			tell_object(me, "$HIC白虎发出一声惊天动地的巨吼，塔顶内立时狂风大作，风沙迷得人无法睁眼。风沙过后，白虎已不见，只见原地留下一双$HIR白虎绝尘靴$HIC。\n");
		}
	}
	CNpc::die();
}


NPC_END;




