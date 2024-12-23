//jieduwan.h 解毒清心丸

FOOD_BEGIN(CIjieduwan);

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name("解毒清心丸", "jiedu wan");
	
	set_weight(20);
	
	set("long","这是一粒解毒清心丸,可解百毒。");
	set("value", 1);      
	set("unit", "粒");
	
};

virtual int do_use(CChar * me, CContainer * ob)
{
	CChar * npc = NULL;
	
	if(ob && ob->is_character())
		npc = (CChar *)ob;
	
	if(! npc || npc == me || userp(npc))
		return notify_fail("你要对谁使用？");
	
	if (me->is_fighting())
		return notify_fail("现在无法使用解毒清心丸！");
	
	if(EQUALSTR(npc->querystr("name"), "石甘露") && EQUALSTR(npc->querystr("id"), "shi ganlu")  && me->query_temp("xy/renwu1_41"))
	{
		//npc->enable_player();
		//npc->delete_temp("apply/name");
		//npc->UpdateMe();
		//npc->del("昏迷");
		me->set_temp("xy/renwu1_42",1);//帮石甘露解毒
		tell_object(me,"\n你小心奕奕地喂石甘露服下了解毒清心丸。");
		tell_object(me,"只见石甘露腿上的淤肿逐渐消退，石甘露“哎哟”一声呻吟，终于醒了过来。\n");
		
		destruct(this);
		me->start_busy(1);
		return 1;
	}
	return 0;
}
    
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp